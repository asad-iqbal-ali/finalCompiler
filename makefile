OUTPUT=cstr
LEXFILE=scanner.l
YACCFILE=parser.y
CC=gcc


all: $(OUTPUT)

$(OUTPUT): lex.yy.c y.tab.c y.tab.h symbol.h
	$(CC) -o $(OUTPUT) lex.yy.c y.tab.c 

lex.yy.c: $(LEXFILE)
	lex $(LEXFILE)

y.tab.c: $(YACCFILE)
	yacc -d $(YACCFILE)

clean:
	-@rm -f lex.yy.c y.tab.c y.tab.h $(OUTPUT)
