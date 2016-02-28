#define MAXIDLEN 100
int yywrap();

void yyerror(const char *str);

enum type_ {
	LSHIFT,
	RSHIFT,
	ADD,
	SUB,
	MULT,
	DIV,
	MOD,
	SET,
	INTEG,
	RETURN,
	STRIN,
	FUNC,
	BLOCK_JUMP,
	VOID
} ;

enum scope_type {
	ARG,
	STACK,
	GLOBAL
	
};

typedef struct symbol_{
	char id[MAXIDLEN];
	enum type_ type;
	enum type_ *args;
	int location;
	struct symbol_ *next;
	enum scope_type scope;
} symbol;

typedef struct exp_{
	enum type_ type;
	char *data;
	struct exp_ *args;
	char **a_names;
	struct exp_ *next;
	struct instr_ *block;
} expr;


typedef struct sym_table_ {
	symbol **table;
	struct sym_table_ *prev;
	struct sym_table_ *next;
	int size;
	int arg_size;
} sym_table;

typedef struct instr_{
	struct exp_ *list;
	char *function;
	struct symbol_ *args;
	int stack_size;
	struct instr_ *prev;
	struct exp_ *prev_ins;

} instr;

typedef struct declar_{
	char id[MAXIDLEN];
	struct exp_ *set;
	struct symbol_ *args;
	struct declar_ *next;

} declar;

int hash_sym(char *sym);
int find_symbol(char *sym, symbol **out, sym_table *t);
void print_sym(char *sym, symbol **table);
symbol *add_symbol(char *name, enum type_ t, enum type_ *a, enum scope_type scope, sym_table *tbl);

char *print_type(enum type_ t);

void print_instructions(instr *block);
void print_table(sym_table *t);

sym_table *create_table(sym_table *loc);
sym_table *destroy_table(sym_table *loc);