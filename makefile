run:
	flex tokens.l
	g++ lex.yy.c -o output
	./output

