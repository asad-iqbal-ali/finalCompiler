%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "symbol.h"
	#define TABLESIZE 100
	#define WORDSIZE 4
	#define STLEN 128
	#define MAXEXPR 1024
	#define MAXSTRNGS 100
	#define MAXARGS 32
extern int yylineno;

int yywrap(){
	return 1;
}


void yyerror(const char *str){
	fprintf(stderr, "At line: %d\nerror: %s\n",yylineno,str);

}

//global symbol table
sym_table *global_table;

//the table we are currently processing from
sym_table *local_table;

//an array of strings literals read from the program, and a counter.
//These are printed as labels at the end of output.
char* glb_strings[MAXSTRNGS];
int str_counter = 0;

//A tracker for how many items are pushed on to the stack when processing
//expression structs (see README).
int stack_depth = 0;

//Some temporary pointers used in various calls below.
expr *tmp;
expr *tmp2;


//The major function instruction block, the current block being added to, and the
//block we just left. The major function block represents all the instructions for
//a function. Once it is complete, the instructions for it and its nested blocks
//get printed.
instr *f_def, *current_block, *last_block;

//A tracker for the last function read. Used so that we can add a function and 
//its arguments to the symbol table at the start of a block.
char current_function[MAXIDLEN];

//Used to track the last type read, so we know what type our function is.
//This was very tricky - recursive calls require that we have the function
//in our symbol table with the proper type before it's actually processed
//by the parser. Thus, this tracks the last type read, and the one before that.
//When a type is read, it updates both. If it then turns out to be just part of a parameter list,
//it is reset to the last type. Once the function ident is processed, it's added
//to the symbol table with the current type.
enum type_ current_type, last_type;

//Tracks the control flow flags for jump statements.
int flow_key = 0;

//More temporary pointers. current_args tracks the list of arguments just read
//So that they can be added to the symbol table for a function definition.
symbol *tmp_sym, *tmp_sym2, *current_args;

%}
%union{
 char *a;
 int fn;
 struct exp_ *e;
 enum type_ t;
 enum compr entier;
 struct symbol_ *s;
 struct declar_ *d;
 struct cond_ *con;
 struct instr_ *in;
 struct flow_ *f;
}
%token <t> INT
%token <t> STRING
%token <fn> CONST_INT
%token <a> CONST_STRING IDENT 


%token EXTERN

%token IF
%token ELSE
%token WHILE
%token DO
%token RETURN
%token FOR
%token THEN

%token assignment
%token INF
%token EGAL
%token SUP
%token INFEQUAL
%token SUPEQUAL
%token DIFF

%token PLUS
%token MINUS
%token MULTI
%token DIV

%token SHIFTRIGHT
%token SHIFTLEFT
%token MODULO

%type <e> primary_expression expression expression_additive unary_expression expression_postfixee expression_multiplicative argument_expression_list assignment_expression function_definition 
%type <s> parameter_declaration parameter_list
%type <t> type
%type <d> function_declarator declarator declarator_list declaration declaration_list
%type <entier> comparison_operator
%type <con> condition
%type <in> jump_instruction instruction compound_instruction expression_instruction iteration_instruction select_instruction instruction_list
%type <f> cond_instruction
%%

program :  
external_declaration 
| program external_declaration 
;

external_declaration :  
declaration 				
| EXTERN declaration { //Just change the scope of the function.
			declar *t = $2;
			int i;
			while(t != NULL){
				i = find_symbol($2->id, &tmp_sym, local_table);
				tmp_sym->scope = EXT;
				t = t->next;
			}
			}			
| function_definition 
;

function_definition :  
type function_declarator compound_instruction {								
						//execute the instruction block for the function.
						
						print_instructions(f_def);
						
						//Reset global pointers
						f_def = NULL;
						current_block = NULL;
						current_args = NULL;


						}
  
;


declaration :  
type declarator_list ';' 	{	
					declar *t = $2;
					int argcount = 1;
					enum type_ *argtypes = NULL;

					//track the list of "set" instructions we may have to build here.
					expr *last_instruction = NULL;
					expr *first_instruction = NULL;

					//walk through the list of declarators and add each to the symbol table
					while(t != NULL){
						//case for non-function idents
						if(t->args == NULL){
							tmp_sym = add_symbol(t->id, $1, NULL, STACK, local_table);

							//If the declar includes a "set" element, it also has to be set to a value.
							//Thus, add a "SET" expr to the current instruction block's expr list.
							if(t->set != NULL){
								if(last_instruction == NULL){
									last_instruction = t->set;
									first_instruction = t->set;
								}
								else 	
									last_instruction->next = t->set;

								int i = find_symbol(t->id, &tmp_sym, local_table);
								
								if(tmp_sym->type != t->set->ret_type){
									yyerror("conflicting types in assignment expression");
									return -1;
								}
									
								tmp = t->set;
								while(tmp != NULL){
									tmp2 = tmp;
									tmp = tmp->next;			
								}
								tmp2->next = malloc(sizeof(expr));
								tmp2 = tmp2->next;
								tmp2->type = SET;
		
								tmp2->data = malloc(sizeof(char)*MAXEXPR);
								tmp2->data[0] = '\0';
								if(tmp_sym->scope == GLOBAL){
									if(tmp_sym->type == INTEG)
										snprintf(tmp2->data, MAXEXPR, "  popl %s\n", t->id);
									else snprintf(tmp2->data, MAXEXPR, "  popl %%edx\n  pushl $%d\n  pushl %%edx\n  leal %s, %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, tmp_sym->id, STLEN-1);
								}
								else{
									if(tmp_sym->type == INTEG)
										snprintf(tmp2->data, MAXEXPR, "  popl -%d(%%ebp)\n", tmp_sym->location);
									else
										snprintf(tmp2->data, MAXEXPR, "  leal -%d(%%ebp), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", tmp_sym->location, STLEN-1);
								}
								tmp2->args = NULL;

								while(last_instruction->next != NULL)
									last_instruction = last_instruction->next;
							}
						}
						else{
							find_symbol(t->id, &tmp_sym, local_table);
							tmp_sym->type = $1;
						
						}
						
						t = t->next;
						
					}
					//add the list of set instructions to the current block
					if(first_instruction != NULL){

						last_instruction->next = NULL;		
						tmp = current_block->list;
						if(tmp == NULL){
							current_block->list = first_instruction;
						}
						else{
							while(tmp->next != NULL)
								tmp = tmp->next;
							tmp->next = first_instruction;

						}
				}
				$$ = $2;
				current_args = NULL;

				}
;

type :  
INT	{$$ = INTEG; last_type = current_type; current_type = $$;} 					
| STRING 	{$$ = STRIN; last_type = current_type; current_type = $$;}		
;

declarator_list :  
declarator 	{$$ = $1;}			// Propagate code
| declarator_list ',' declarator {declar *t = $1;
				while(t->next != NULL)
					t = t->next;
				t->next = $3;
				$$ = $1;}	
;

declaration_list :  
declaration 		{$$ = $1;}		// Set locals
| declaration_list declaration  {
					

			
				}	// Set locals
;

//A declar contains the ID read, any assignment necessary, and arguments. They are linked together and then processed as a list.

declarator :  
IDENT 			{
				int i = find_symbol($1, &tmp_sym, local_table);
				if(tmp_sym != NULL && i == 0){
					printf("symbol %s\n", $1);
					yyerror("symbol already declared");
					return -1;
				}
				
				$$ = malloc(sizeof(declar));
			 	strcpy($$->id, $1);
				$$->set = NULL;
				$$->args = NULL;
				$$->next = NULL;
			}		// Create Variable
| IDENT assignment expression {
				int i = find_symbol($1, &tmp_sym, local_table);
				if(tmp_sym != NULL && i == 0){
					printf("symbol %s\n", $1);
					yyerror("symbol already declared");
					return -1;
				}
				
				$$ = malloc(sizeof(declar));
			 	strcpy($$->id, $1);
				$$->set = $3;
				$$->args = NULL;
				$$->next = NULL;
				}	
| function_declarator {$$ = $1;}		        // Create Function
;

function_declarator :  
IDENT '(' ')' 			{	enum type_ *argtype;
					argtype = malloc(sizeof(enum type_));

					*argtype = VOID;
					
					strcpy(current_function, $1);
				
					$$ = malloc(sizeof(declar));
			 		strcpy($$->id, $1);
					$$->set = NULL;
					$$->args = NULL;
					$$->next = NULL;
					
		
						
					tmp_sym = add_symbol($1, current_type, argtype, GLOBAL, global_table);
	
				}	// Create function name
| IDENT '(' parameter_list ')'  {	int argcount = 1;
					enum type_ *argtypes;
					strcpy(current_function, $1);
					current_args = $3;

					
					$$ = malloc(sizeof(declar));
			 		strcpy($$->id, $1);

					$$->set = NULL;
					$$->args = $3;
					$$->next = NULL;

					tmp_sym = $3;
							
					while(tmp_sym != NULL){
						argcount++;
						tmp_sym = tmp_sym->next;
					}
					argtypes = malloc(sizeof(enum type_)*argcount);
					argcount = 0;
					tmp_sym = $3;
					while(tmp_sym != NULL){
						argtypes[argcount] = tmp_sym->type;
						argcount++;
						tmp_sym = tmp_sym->next;
					}
					argtypes[argcount] = VOID;
						
					tmp_sym = add_symbol($1, current_type, argtypes, GLOBAL, global_table);

	
				}	// Create partial function 
;

parameter_list :  
parameter_declaration 	{$$ = $1;}		
| parameter_list ',' parameter_declaration  {
						tmp_sym = $1;
						if($1 != NULL){
							while(tmp_sym->next != NULL)
								tmp_sym = tmp_sym->next;
							tmp_sym->next= $3;
							$$ = $1;
						}
						else $$ = $3;
						
					}// Insert parameters
;
parameter_declaration :  
type IDENT 			{
					$$ = malloc(sizeof(symbol));
					$$->type = $1;
					strcpy($$->id, $2);
					$$->next = NULL;
					current_type = last_type;
				}
						// Type declaration
;

instruction :  
';' {} 
| compound_instruction {$$=$1;}
| expression_instruction  {$$=$1;}
| iteration_instruction  {$$=$1;}
| select_instruction  {$$=$1;}
| jump_instruction {$$=$1;}
;

expression_instruction :              
expression ';'  {
			//create a new block, which will encapsulate this expression.
			//Start by finding the end of the current block's expression list
			//And adding a "BLOCK_JUMP" expression.
			tmp = current_block->list;
			if(tmp != NULL){			
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
			}
			else {
				current_block->list = malloc(sizeof(expr));
				tmp = current_block->list;
			}
			tmp->type = BLOCK_JUMP;
			tmp->next = NULL;
			tmp->block = malloc(sizeof(instr));
			tmp->block->f = NULL;
			tmp->block->prev = current_block;
			tmp->block->function = current_block->function;
			current_block = tmp->block;
			current_block->prev_ins = tmp;

			//Set the new block's list to this expression list.
			current_block->list = $1;
			current_block->stack_size = local_table->size;
			last_block = current_block;
			current_block = current_block->prev;

			$$ = last_block;
		}
| assignment_expression ';' {
				//same as above
				tmp = current_block->list;
				if(tmp != NULL){			
					while(tmp->next != NULL){
						tmp = tmp->next;
					}
					tmp->next = malloc(sizeof(expr));
					tmp = tmp->next;
				}
				else {
					current_block->list = malloc(sizeof(expr));
					tmp = current_block->list;
				}
				tmp->type = BLOCK_JUMP;
				tmp->next = NULL;
				tmp->block = malloc(sizeof(instr));
				tmp->block->f = NULL;
				tmp->block->prev = current_block;
				tmp->block->function = current_block->function;
				current_block = tmp->block;
				current_block->prev_ins = tmp;


				current_block->list = $1;
				current_block->stack_size = local_table->size;
				last_block = current_block;
				current_block = current_block->prev;

				$$ = last_block;
			    }
;

assignment_expression :  
IDENT assignment expression 	{ 
					//Check types
					int i = find_symbol($1, &tmp_sym, local_table);
					if(tmp_sym == NULL){
						yyerror("symbol not found 4");
						return -1;
					}
					if(tmp_sym->type != $3->ret_type){
						yyerror("conflicting types in assignment expression");
						return -1;
					}
					if(tmp_sym->args != NULL){
						yyerror("assigning value to function");
						return -1;
					}

					//Create a "SET" expression and add it to the end of the current
					//block's expression list.
					tmp = $3;
					while(tmp != NULL){
						tmp2 = tmp;
						tmp = tmp->next;			
					}
					tmp2->next = malloc(sizeof(expr));
					tmp2 = tmp2->next;
					tmp2->type = SET;
		
					tmp2->data = malloc(sizeof(char)*MAXEXPR);
					
					//The "SET" expression's 'data' is the set of instructions to pop
					//from the stack into the IDENT's location.
					if(tmp_sym->scope == GLOBAL){
						if(tmp_sym->type == INTEG)
							snprintf(tmp2->data, MAXEXPR, "  popl %s\n", $1);
						else snprintf(tmp2->data, MAXEXPR, "  popl %%edx\n  pushl $%d\n  pushl %%edx\n  leal %s, %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, $1, STLEN-1);
					}
					else{
						if(tmp_sym->type == INTEG)
							snprintf(tmp2->data, MAXEXPR, "  popl %s%d(%%ebp)\n", (tmp_sym->scope == ARG? "":"-"),tmp_sym->location);
						else
							snprintf(tmp2->data, MAXEXPR, "  popl %%edx\n  pushl $%d\n  pushl %%edx\n  leal %s%d(%%ebp), %%eax\n  pushl %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, (tmp_sym->scope == ARG? "":"-"), tmp_sym->location, STLEN-1);
					}
					tmp2->args = NULL;
					tmp2->next = NULL;
					$$ = $3;
				} 
;

compound_instruction :  
block_start declaration_list instruction_list block_end {
			$$=last_block;
			}
| block_start declaration_list block_end {$$=last_block;} 
| block_start instruction_list block_end {$$=last_block;}
| block_start block_end {$$=last_block;} 
;


block_start :  
'{'	{
		//creat a table, and initialize a new block.
		//if this is starting a function, initialize f_def
		local_table = create_table(local_table);
		if(f_def == NULL){
			f_def = malloc(sizeof(instr));
			f_def->f = NULL;
			f_def->prev = NULL;
			f_def->list = NULL;
			f_def->prev_ins = NULL;
			current_block = f_def;
			f_def->function = current_function;
			f_def->args = current_args;
			tmp_sym = current_args;
			while(tmp_sym != NULL){
				add_symbol(tmp_sym->id,tmp_sym->type,NULL,ARG,local_table);
				
				tmp_sym = tmp_sym->next;

			}
			
		}
		else{
			tmp = current_block->list;
			if(tmp != NULL){			
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
			}
			else {
				current_block->list = malloc(sizeof(expr));
				tmp = current_block->list;
			}
			tmp->type = BLOCK_JUMP;
			tmp->next = NULL;
			tmp->block = malloc(sizeof(instr));
			tmp->block->f = NULL;
			tmp->block->prev = current_block;
			tmp->block->function = current_block->function;
			current_block = tmp->block;
			current_block->prev_ins = tmp;
			current_block->list = NULL;
		}



	}
;

block_end :  
'}' 	{
		//destroy the table, and jump back to the previous block.
		if(local_table == global_table){
			yyerror("No block to close");
			return -1;
		}
		current_block->stack_size = local_table->size;
		last_block = current_block;
		current_block = current_block->prev;
		
		local_table = destroy_table(local_table);


	 
	}
;

instruction_list :  
instruction  {$$=$1;}
| instruction_list instruction 	{
				 
				}
;


//Conditionals essentially involve taking the instruction block handed to them,
//Setting the block's "f" element to themselves, wrapping the block in a new
//block, and passing that new block up the chain.
select_instruction :  
cond_instruction instruction {
				$2->f = $1;
				$$ = insert_block($2);
				}
| cond_instruction instruction ELSE instruction {
				$1->type = IE;
				$2->f = $1;
				//This function wraps the instruction block in a new block.
				//This is done by doing some unlinking/linking (see function
				//below).
				$$ = insert_block($2);

				flow *t = malloc(sizeof(flow));
				t->key = $1->key;			
				t->type = E;
				t->con = NULL;
				t->a1 = NULL;
				t->a2 = NULL;
				$4->f = t;

				//We have to ensure that the "else" statement's instruction block is also
				//included in the wrapping block, immediately after the if's statements.
				$$->list->next = malloc(sizeof(expr));
				$$->list->next->type = BLOCK_JUMP;
				$$->list->next->block = $4;
				$$->list->next->next = NULL;
				
				//unlink the jump to the "else" statement's instructions from its previous block.
				tmp = $4->prev->list;
				while(tmp->next != $4->prev_ins)
					tmp = tmp->next;
				tmp->next = tmp->next->next;
				free($4->prev_ins);

				$4->prev = $$;
				$4->prev_ins = $$->list->next;
				}

;

cond_instruction :  
IF '(' condition ')' {
			$$ = malloc(sizeof(flow));
			$$->key = flow_key;
			++flow_key;
			$$->type = I;
			$$->con = $3;
			$$->a1 = NULL;
			$$->a2 = NULL;
			} 
;

iteration_instruction :  
WHILE '(' condition ')' instruction {
					flow *t = malloc(sizeof(flow));
					t->key = flow_key;
					++flow_key;
					t->type = W;
					t->con = $3;
					t->a1 = NULL;
					t->a2 = NULL;
					$5->f = t;

					$$ = insert_block($5);					
					
					
					
					

					}// Handle while loop
| DO instruction WHILE '(' condition ')'  {flow *t = malloc(sizeof(flow));
					t->key = flow_key;
					++flow_key;
					t->type = D;
					t->con = $5;
					t->a1 = NULL;
					t->a2 = NULL;
					$2->f = t;
					$$ = insert_block($2);}
| FOR '(' assignment_expression ';' condition ';' assignment_expression ')' instruction  {

					flow *t = malloc(sizeof(flow));
					t->key = flow_key;
					++flow_key;
					t->type = F;
					t->con = $5;
					t->a1 = $3;
					t->a2 = $7;
					$9->f = t;
					$$ = insert_block($9);} 
;

jump_instruction:  
RETURN expression ';' {

			//As with other expressions ending in ';', create a block to wrap the 
			//expression list, and then link it to the current block being processed.
			tmp = current_block->list;
			if(tmp != NULL){			
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
			}
			else {
				current_block->list = malloc(sizeof(expr));
				tmp = current_block->list;
			}
			tmp->type = BLOCK_JUMP;
			tmp->next = NULL;
			tmp->block = malloc(sizeof(instr));
			tmp->block->f = NULL;
			tmp->block->prev = current_block;
			tmp->block->function = current_block->function;
			current_block = tmp->block;
			current_block->prev_ins = tmp;
			
			//Add a "RETURN" block, which pops the output to eax.
			//if it is a string, the output is copied to .strres

			tmp = $2;
			while(tmp != NULL){
				tmp2 = tmp;
				tmp = tmp->next;			
			}
			tmp2->next = malloc(sizeof(expr));
			tmp2->next->type = RET;
			if($2 != NULL){
				tmp2->next->data = malloc(sizeof(char)*MAXEXPR);
				if(tmp2->ret_type == STRIN){
					snprintf(tmp2->next->data, MAXEXPR, "  popl %%edx\n  pushl $%d\n  pushl %%edx\n  pushl $.strres\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, STLEN-1); 

				}
	
				else snprintf(tmp2->next->data, MAXEXPR, "  popl %%eax\n");
			}
			else{
				tmp2->next->data = malloc(sizeof(char));
				tmp2->next->data[0] = '\0';
			}
			tmp2->next->args = NULL;				
			tmp2->next->next = NULL;
			tmp = current_block->list;
			current_block->list = $2;

			current_block->stack_size = local_table->size;
			last_block = current_block;
			current_block = current_block->prev;

			$$ = last_block;
			
	
			}
;

condition :  
expression comparison_operator expression {
						$$ = malloc(sizeof(cond));
						$$->left = $1;
						$$->right = $3;
						$$->c = $2;
						}
;

comparison_operator :  
EGAL  {$$=EGA;}
| DIFF {$$=DIF;} 
| INF  {$$=INFE;}
| SUP  {$$=SU;}
| INFEQUAL {$$=INFEQUA;}
| SUPEQUAL {$$=SUPEQUA;} 
;

//These expressions all create an operator expression, join the two 
//lists of expressions for the operands, and add the operator block at the end.
expression :  
expression_additive {$$=$1;}
| expression SHIFTLEFT expression_additive {
								if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("left shift requires two integer values");
									return -1;
								}
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = LSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}
| expression SHIFTRIGHT expression_additive {
								if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("right shift requires two integer values");
									return -1;
								}
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
									tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = RSHIFT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}

expression_additive :  
expression_multiplicative {$$=$1;}
| expression_additive PLUS expression_multiplicative {
								
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								if($1->ret_type == INTEG){
									if($3->ret_type == INTEG)
										tmp->next->type = ADDII;
									else{
										tmp->next->type = ADDIS;
										$1->ret_type = STRIN;
									}
									
								}
								else{
									if($3->ret_type == STRIN)
										tmp->next->type = ADDSS;
									else{
										tmp->next->type = ADDSI;
										$3->ret_type = STRIN;
									}
								}
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}
| expression_additive MINUS expression_multiplicative {
								if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("subtraction requires two integer values");
									return -1;
								}
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = SUB;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}

expression_multiplicative :  
unary_expression{$$=$1;}
| expression_multiplicative MULTI unary_expression {		if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("mulitplication requires two integer values");
									return -1;
								}
								
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MULT;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}
| expression_multiplicative DIV unary_expression	{
								if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("division requires two integer values");
									return -1;
								}
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = DIVI;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}
| expression_multiplicative MODULO unary_expression	{
								if($1->ret_type != INTEG || $3->ret_type != INTEG){
								 	yyerror("modulus requires two integer values");
									return -1;
								}
								tmp = $3;
			 					tmp2 = tmp->next;
								while(tmp2 != NULL){
									tmp = tmp2;
									tmp2 = tmp2->next;
			 					}
			 					tmp->next = $1;
								while(tmp->next != NULL)
								tmp = tmp->next;
								tmp->next = malloc(sizeof(expr));
								tmp->next->type = MOD;
								tmp->next->data = NULL;
								tmp->next->args = NULL;				
								tmp->next->next = NULL;
								$$ = $3;

							}
								
;

//Subtract the value from 0.
unary_expression:  
expression_postfixee {$$=$1;}
| MINUS unary_expression {
			 	$$=$2;
				if($2->ret_type != INTEG){
					yyerror("minus requires an int");
					return -1;
				}
				tmp = $2;
			 	tmp2 = tmp->next;
				while(tmp2 != NULL){
					tmp = tmp2;
					tmp2 = tmp2->next;
			 	}
				tmp->next = malloc(sizeof(expr));
				tmp = tmp->next;
				tmp->type = INTEG;
				tmp->ret_type = INTEG;
				tmp->args = NULL;
				tmp->data = malloc(sizeof(char)*MAXEXPR);
				snprintf(tmp->data, MAXEXPR, "  pushl $0\n");
				
				tmp->next = malloc(sizeof(expr));
				tmp->next->type = SUB;
				tmp->next->data = NULL;
				tmp->next->args = NULL;	
			 					
				tmp->next->next = NULL;
				}
;

//create a function expression, which includes a list of argument expressions.
expression_postfixee :  
primary_expression {$$=$1;}
| IDENT '(' argument_expression_list')' {

						int i = find_symbol($1, &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found 3");
							return -1;
						}
						$$ = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						$$->type = tmp_sym->type;
						$$->ret_type = $$->type;
						$$->data = $1;
						$$->next = NULL;
						$$->args = $3;
						$$->func = 1;

					}
| IDENT '(' ')' 			{
						int i = find_symbol($1, &tmp_sym, local_table);
						if(tmp_sym == NULL){
							yyerror("symbol not found 1");
							return -1;
						}
						$$ = malloc(sizeof(expr));
						if(tmp_sym->args == NULL){
							yyerror("expected function call");
							return -1;
						}
						if(tmp_sym->args[1] != VOID){
							yyerror("function call types do not match function declaration");
							return -1;
						}
						$$->type = tmp_sym->type;
						$$->ret_type = $$->type;
						$$->data = $1;
						$$->next = NULL;
						$$->args = NULL;
						$$->func = 1;
					}//same as above
;


argument_expression_list:  
expression {$$ = $1;}
| argument_expression_list ',' expression {tmp = $3;
			 while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next= $1;
			$$ = $3;}
;

//Create an expression struct, containing all the info from the README.
primary_expression :  
IDENT  {

	int i = find_symbol($1, &tmp_sym, local_table);

	if(tmp_sym == NULL){
		yyerror("symbol not found 2");
		return -1;
	}

	$$ = malloc(sizeof(expr));
	$$->type = tmp_sym->type;
	$$->ret_type = tmp_sym->type;
	$$->args = NULL;
	$$->next = NULL; 

	$$->func = 0;
	$$->data = malloc(sizeof(char)*MAXEXPR);

	if(tmp_sym->scope == GLOBAL){
		if(tmp_sym->type == STRIN)	
			snprintf($$->data, MAXEXPR, "  leal %s, %%eax\n  pushl %%eax\n", $1);
		else snprintf($$->data, MAXEXPR, "  pushl %s\n", $1);
	}
	else{
		if(tmp_sym->type == STRIN)
			snprintf($$->data, MAXEXPR, "  leal %s%d(%%ebp), %%eax\n  pushl %%eax\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
		else snprintf($$->data, MAXEXPR, "  pushl %s%d(%%ebp)\n", (tmp_sym->scope == ARG? "":"-"), tmp_sym->location);
	}

	}
| CONST_INT	{
		$$ = malloc(sizeof(expr));
		$$->type = INTEG;
		$$->ret_type = INTEG;
		$$->args = NULL;
		$$->data = malloc(sizeof(char)*MAXEXPR);
		snprintf($$->data, MAXEXPR, "  pushl $%d\n", $1);
		$$->next = NULL;
		
		}
| CONST_STRING {
		$$ = malloc(sizeof(expr));
		$$->data = malloc(sizeof(char)*MAXEXPR);
		$$->type = STRIN;
		$$->ret_type = STRIN;
		$$->args = NULL;
		glb_strings[str_counter] = $1;
		snprintf($$->data, MAXEXPR, "  pushl $.s%d\n", str_counter);
		++str_counter;
		$$->next = NULL;
		}
| '(' expression ')'	{$$ = $2;}
;

%%

int main(int argc, char **argv) {

	
	int i;
	global_table = malloc(sizeof(sym_table));
	global_table->table = malloc(sizeof(symbol *)*TABLESIZE);
	for(i = 0; i < TABLESIZE; ++i)
		global_table->table[i] = NULL;
	global_table->prev = NULL;
	global_table->next = NULL;
	global_table->size = 0;
	local_table = global_table;

	f_def = NULL;
	current_block = NULL;

	local_table = global_table;
	

	yyparse();

	//print out the global vars
	for(i = 0; i < TABLESIZE; ++i){
		tmp_sym = global_table->table[i];
		while(tmp_sym != NULL){
			if(tmp_sym->args == NULL)
				printf("\t.comm %s,%d,%d\n", tmp_sym->id, (tmp_sym->type == STRIN? (STLEN*WORDSIZE):WORDSIZE), WORDSIZE);
			tmp_sym = tmp_sym->next;
		}
	}

	printf("\t.comm .stracc,%d,%d\n\n",STLEN*WORDSIZE*2,WORDSIZE);
	printf("\t.comm .strres,%d,%d\n\n",STLEN*WORDSIZE*2,WORDSIZE);

	//print the string literals
	if(str_counter > 0){
		printf(".section\t.rodata\n");
		for(i = 0; i < str_counter; ++i)
			printf("\t.s%d:\t.string\t%s\n", i, glb_strings[i]);
	}

	while(local_table != NULL)
		local_table = destroy_table(local_table);
		
	return 0;
}

int hash_sym(char *sym){
	unsigned int hash = 0;
	int i;

	for(i = 0; sym[i] != '\0'; ++i)
		hash = sym[i] + (hash << 6) + (hash << 16) - hash;
	return hash % TABLESIZE;
}

//returns the number of tables read through. This was more useful
//in earlier versions of the compiler. Now, that is mostly discarded.
//On return, *out is the symbol if found, or NULL if not.
int find_symbol(char *sym, symbol **out, sym_table *t){
	symbol *track;
	sym_table *ti = t;
	int depth = 0;
	
	int i = hash_sym(sym);
	
	while(ti != NULL){
		track = ti->table[i];
		while(track != NULL){
			if(!strcmp(track->id, sym)){
				*out = track;
				return depth;
			}
			else track = track->next;
		}
		ti = ti->prev;
		++depth;
	}
	*out = NULL;
	return -1;

}






symbol *add_symbol(char *name, enum type_ t, enum type_ *a, enum scope_type s, sym_table *tbl){
	symbol *symb = malloc(sizeof(symbol));
	strcpy(symb->id, name);
	symb->type = t;
	symb->args = a;
	symb->scope = (tbl->prev == NULL? GLOBAL:s);
	symb->next = NULL;

	int i = hash_sym(symb->id);
	
	symbol *track = tbl->table[i];
	symbol *prev = track;

	if(track == NULL){
		tbl->table[i] = symb;
		if(symb->args == NULL){

			//The symbol's location is used to track its distance from ebp. Thus,
			//It can either be based on the stack size or the current number of arguments.
			//The table tracks both, since arguments have the ARG scope.
			//For strings, the stack size still has to grow for arguments, since these are
			//copied to the stack.
			switch(t){
				case INTEG:
					if(s == STACK){		
						tbl->size += WORDSIZE;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						symb->location = tbl->arg_size + WORDSIZE;
					}
					
					break;
				case STRIN:
					if(s == STACK){
						tbl->size += STLEN;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						tbl->size += STLEN;
						symb->location = tbl->size;
						symb->scope = STACK;
					}
					break;

			}
			
			
		}
		return symb;
	}

	while(track != NULL){
		if(!strcmp(track->id, symb->id)){
			if(symb->type != track->type){
				yyerror("Conflicting definitions");
				return NULL;
			}
			if(track->args != NULL || symb->args != NULL){
				if(track->args == NULL || symb->args == NULL){
						yyerror("Conflicting function definitions 1");
						return NULL;
					}
				else{
					i = 0;
					while(track->args[i] != VOID && symb->args[i] != VOID){
						if(track->args[i] != symb->args[i]){
							yyerror("Conflicting function definitions 3");
							return NULL;
						}
					}
					if(track->args[i] != VOID || symb->args[i] != VOID){
							yyerror("Conflicting function definitions 2");
							return NULL;
					}
					
				}
			}
			return track;
		}
		prev = track;
		track = track->next;
	}
	
	track = prev;
	
	track->next = symb; 
	if(symb->args == NULL){
			switch(t){
				case INTEG:
					if(s == STACK){		
						tbl->size += WORDSIZE;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						symb->location = tbl->arg_size + WORDSIZE;
					}
					
					break;
				case STRIN:
					if(s == STACK){
						tbl->size += STLEN;
						symb->location = tbl->size;
					}
					else if(s == ARG){	
						tbl->arg_size += WORDSIZE;
						tbl->size += STLEN;
						symb->location = tbl->size;
						symb->scope = STACK;
					}
					break;
			}
			
			
	}
	return symb;



}


sym_table *create_table(sym_table *loc){

	int i;
	if(loc->next != NULL){
		yyerror("Creating table in middle of list");
		return NULL;
	}
	
	loc->next = malloc(sizeof(sym_table));
	loc->next->table = malloc(sizeof(symbol *)*TABLESIZE);

	for(i = 0; i < TABLESIZE; ++i)
		loc->next->table[i] = NULL;

	loc->next->prev = loc;
	loc->next->next = NULL;
	if(loc != global_table)
		loc->next->size = loc->size;
	else loc->next->size = 0;
	loc->next->arg_size = 0;

}

sym_table *destroy_table(sym_table *loc){

	symbol *s_track, *s_next;
	
	sym_table *ret = loc->prev;
	
	int i;
	for(i = 0; i < TABLESIZE; ++i){
		s_track = loc->table[i];
		while(s_track != NULL){
			s_next = s_track->next;
			free(s_track);
			s_track = s_next;
		}
	}
	if(ret != NULL && ret != global_table){
		ret->size = loc->size;

	}
	if(ret != NULL)
		ret->next = NULL;
	free(loc->table);
	free(loc);
	return ret;
}


//The workhorse of the compiler. Used to print instructions from a block.
void print_instructions(instr *block){

	expr *e;
	flow *fl;
	symbol *arg, *t;
	int i;
	int totalargs = 0;

	//print header info if this is the beginning of a function.
	if(block->prev == NULL){
		printf(".globl %s\n  .type %s,@function\n%s:\n", block->function, block->function, block->function);
		printf("  enter $%d, $0\n", block->stack_size);

		i = 0;
		arg = block->args;
		while(arg != NULL){
			++totalargs;
			//Copy string arguments to the stack.
			if(arg->type == STRIN){
				++i;
				find_symbol(arg->id, &t, local_table);
				printf("  pushl $%d\n  pushl %d(%%ebp)\n  leal -%d(%%ebp), %%eax\n  pushl %%eax\n  call strncpy\n  movb  $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, WORDSIZE*(totalargs+1),i*STLEN, STLEN-1);		
			}
			arg = arg->next;

		

		}
	}

	//Process control flow statements associated with the block, if any.
	fl = block->f;
	if(fl != NULL)
		switch(fl->type){
			case IE: 
				print_cond(fl->con, 1, block->function);
				printf(".no%d\n", fl->key);
				e = block->list;
					while(e != NULL){
						print_expr(e, block->function);
						e = e->next;
				}
				
				printf("  jmp .out%d\n", fl->key);
				printf("  .no%d:\n", fl->key); 
				break;
			case I: 
				print_cond(fl->con, 1, block->function);
				printf(".no%d\n", fl->key);
				e = block->list;
					while(e != NULL){
						print_expr(e, block->function);
						e = e->next;
				}
				printf("  .no%d:\n", fl->key); 
				break;
			case E: 
				e = block->list;
				while(e != NULL){
					print_expr(e, block->function);
					e = e->next;
				}
				printf("  .out%d:\n", fl->key);
				break;
			case F: 
				e = fl->a1;
				while(e != NULL){
					print_expr(e, block->function);
					e = e->next;
				}
				printf("  .loop%d:\n", fl->key);
			
				print_cond(fl->con, 1, block->function);
				printf(".skip%d\n",fl->key);
				e = block->list;
					while(e != NULL){
						print_expr(e, block->function);
						e = e->next;
				}
				e = fl->a2;
				while(e != NULL){
					print_expr(e, block->function);
					e = e->next;
				}
				printf("  jmp .loop%d\n", fl->key);
				printf("  .skip%d:\n", fl->key); 
				break;
			case W: 
				
				printf("  .loop%d:\n", fl->key);			
				print_cond(fl->con, 1, block->function);
				printf(".skip%d\n",fl->key);
				e = block->list;
					while(e != NULL){
						print_expr(e, block->function);
						e = e->next;
				}
				
				printf("  jmp .loop%d\n", fl->key);
				printf("  .skip%d:\n", fl->key); 
				break;
			case D: 
				
				printf("  .loop%d:\n", fl->key);			
				
				e = block->list;
					while(e != NULL){
						print_expr(e, block->function);
						e = e->next;
				}
				print_cond(fl->con, 0, block->function);
				printf(".loop%d\n",fl->key);
				break;
	


		}
	//Process the block's instructions.
	else{
		e = block->list;
		while(e != NULL){
			print_expr(e, block->function);
			e = e->next;
		}
	}

	//if the block is the major function block, print return statements.
	if(block->prev == NULL){
		printf(".%s_ret:\n  leave\n  ret\n\n", block->function);
		return;
	}

}

//Okay maybe this is the workhorse. Print an expression's data.
void print_expr(expr *e, char *function){
	expr *argslist[MAXARGS];
	expr *track;
	int argcounter;
	int i;
	switch(e->type){
			case LSHIFT:
				--stack_depth;
				printf("  popl %%eax\n  popl %%ecx\n  sall %%cl, %%eax\n  pushl %%eax\n");
				break;
			case RSHIFT:
				--stack_depth;	
				printf("  popl %%eax\n  popl %%ecx\n  sarl %%cl, %%eax\n  pushl %%eax\n");
				break;
			case DIVI:
				--stack_depth;
				printf("  movl $0, %%edx\n  popl %%eax\n  popl %%ecx\n  cltd\n  idivl %%ecx\n  pushl %%eax\n");
				break;
			case MOD:
				--stack_depth;
				printf("  movl $0, %%edx\n  popl %%eax\n  popl %%ecx\n  cltd\n  idivl %%ecx\n  pushl %%edx\n");
				break;
			case ADDII:
				--stack_depth;
				printf("  popl %%eax\n  popl %%ecx\n  addl %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case ADDSS:
				//Copy and concat strings to .stracc, then copy to the stack.
				--stack_depth;
				printf("  popl %%eax\n  movl %%esp, %%ebx\n  pushl $%d\n  pushl %%eax\n  pushl $.stracc\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n  pushl (%%ebx)\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $8, %%esp\n  subl $%d, %%esp\n  movl %%esp, %%eax\n  pushl $%d\n  pushl $.stracc\n  leal (%%eax), %%eax\n  push %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN, STLEN-1, STLEN-1,STLEN, STLEN, STLEN-1);
				for(i = stack_depth-1; i > 0; --i)
					printf("  push %d(%%ebx)\n", WORDSIZE*i);
				printf("  push %%eax\n");
				break;
			case ADDIS:
				//Same as above, but account for converting int to ascii value
				printf("  popl %%eax\n  movl %%esp, %%ebx\n  andw $0xff, %%ax\n  movw %%ax, .stracc\n  pushl (%%ebx)\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $8, %%esp\n  subl $%d, %%esp\n  movl %%esp, %%eax\n  pushl $%d\n  pushl $.stracc\n  leal (%%eax), %%eax\n  push %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", STLEN-1,STLEN,  STLEN, STLEN-1);
				for(i = stack_depth-1; i > 0; --i)
					printf("  push %d(%%ebx)\n", WORDSIZE*i);
				printf("  push %%eax\n");
				break;
			case ADDSI:
				//same as above, but account for different order of operands
				printf("  popl %%edi\n  popl %%eax\n  movl %%esp, %%ebx\n  subl $%d, %%ebx\n  andw $0xff, %%ax\n  movw %%ax, .stracc\n  sub $%d, %%esp\n  movl %%esp, %%ecx\n  pushl $.stracc\n  pushl %%ecx\n  call strcpy\n  addl $8, %%esp\n  pushl $%d\n  pushl  %%edi\n  pushl $.stracc\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n  pushl %%esp\n  pushl $.stracc\n  call strcat\n  movb $0, %d(%%eax)\n  addl $%d, %%esp\n  subl $%d, %%esp\n  movl %%esp, %%eax\n  pushl $%d\n  pushl $.stracc\n  leal (%%eax), %%eax\n  push %%eax\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n", WORDSIZE,STLEN, STLEN, STLEN-1,STLEN-1, 8+STLEN, STLEN, STLEN, STLEN-1 );
				for(i = stack_depth-1; i > 0; --i)
					printf("  push %d(%%ebx)\n", WORDSIZE*i);
				printf("  push %%eax\n");
				break;
			case SUB:
				--stack_depth;
				printf("  popl %%eax\n  popl %%ecx\n  subl %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case MULT:
				--stack_depth;
				printf("  popl %%eax\n  popl %%ecx\n  imull %%ecx, %%eax\n  pushl %%eax\n");
				break;
			case RET:
				printf("%s", e->data);
				printf("  jmp .%s_ret\n", function);
				break;

			case BLOCK_JUMP:
				//jump to a new set of instructions.
				stack_depth = 0;
				print_instructions(e->block);
				break;


			default :
				//For a simple ident, just print its value.
				if(!(e->func)){
					printf("%s", e->data);
					if(e->type == SET)
						--stack_depth;
					else ++stack_depth;
				}
				//For a function, process argument expressions in order, then call, then clean up the stack.
				else{
					argcounter = 0;
					int st = stack_depth;
					track = e->args;
					
					while(track != NULL){
						print_expr(track, function);
						if(track->type == STRIN || track->type == INTEG)
							++argcounter;
						else --argcounter;
						track = track->next;
					}
					
					printf("  call %s\n", e->data);
					printf("  addl $%d, %%esp\n", argcounter*WORDSIZE);

					if(e->type == STRIN){
						//if the function returned a string, copy the string to the stack.
						printf("  movl %%esp, %%ebx\n  subl $%d, %%ebx\n  subl $%d, %%esp\n  movl %%esp, %%edx\n  pushl $%d\n  pushl %%eax\n  leal (%%edx), %%edx\n  pushl %%edx\n  call strncpy\n  movb $0, %d(%%eax)\n  addl $12, %%esp\n",WORDSIZE,STLEN,STLEN,STLEN-1);
						for(i = st; i > 0; --i)
							printf("  push %d(%%ebx)\n", WORDSIZE*i);
						printf("  push %%eax\n");
						
					}
					else	printf("  pushl %%eax\n");

					stack_depth = st;
					++stack_depth;
						
				}
				break;
	 	}

}

//Print comparisons and conditional jump statements.
//To compare strings, use strcmp.
char *print_cond(cond *c, int opposite, char *function){
	
	expr *e;
	char *jump;

	
	switch(c->c){
			case INFE:
			 	jump = (opposite? "jge":"jl");
				break;
			case EGA:
				jump = (opposite? "jne":"je");
				break;
			case SU:
				jump = (opposite? "jle":"jg");
				break;
			case INFEQUA:
				jump = (opposite? "jg":"jle");
				break;
			case SUPEQUA:
				jump = (opposite? "jl":"jge");
				break;
			case DIF:
				jump = (opposite? "je":"jne");
				break;


	}

	if(c->left->ret_type == INTEG){
		e = c->left;
		while(e != NULL){
			print_expr(e, function);
			e = e->next;
		}
		e = c->right;
		while(e != NULL){
			print_expr(e, function);
			e = e->next;
		}
		printf("  popl %%ebx\n  popl %%eax\n");
		
		printf("  cmp %%ebx, %%eax\n  %s ", jump);
	}

	else{

		e = c->right;
		while(e != NULL){
			print_expr(e, function);
			e = e->next;
		}
		e = c->left;
		while(e != NULL){
			print_expr(e, function);
			e = e->next;
		}
		printf("  call strcmp\n  addl $8, %%esp\n  cmp $0, %%eax\n  %s ", jump );

	}
	


}

//Used to wrap an instruction block in an outer block.
instr *insert_block(instr *b){
					instr *newblock = malloc(sizeof(instr));
					newblock->f = NULL;
					newblock->function = NULL;
					newblock->args = NULL;
					newblock->stack_size = b->stack_size;
					newblock->prev = b->prev;
					newblock->prev_ins = b->prev_ins;

					newblock->list = malloc(sizeof(expr));
					newblock->list->type = BLOCK_JUMP;
					newblock->list->next = NULL;
					newblock->list->block = b;
					
					newblock->prev_ins->block = newblock;
				
					b->prev = newblock;
					b->prev_ins = newblock->list;	

					return newblock;

}


//Print a type. Usefule for debugging.
char *print_type(enum type_ t){
	switch(t){
		case INTEG:
		 return "integer";
		case STRIN:
		 return "string";
		case VOID:
		 return "void";
		default:
		 return "unknown";
	}

}

//Used for debugging.
void print_table(sym_table *t){


	int i, j;
	symbol *s;
	expr *a;

	printf("Symbol table size: %d", t->size);

	if(t->prev == NULL)
		printf(" GLOBAL\n");
	else printf("\n");

	printf("\n");

	printf("ID\t\t| type\t\t\t| Arguments\n");
	printf("------------------------------------------------------\n");

	for(i = 0; i < TABLESIZE; ++i){
		s = t->table[i];
		while(s != NULL){
			printf("%s\t\t| %s\t\t| ", s->id, print_type(s->type));
			if(s->args != NULL){
				j = 0;
				while(s->args[j] != VOID){
					printf("%s ", print_type(s->args[j]));
					++j;
				}
			}
			printf("\n");
			s = s->next;

		}


	}
	printf("\n");
}


