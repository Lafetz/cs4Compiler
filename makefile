run:
	flex ./smina/tokens.l
	g++ lex.yy.c -o output
	./output

