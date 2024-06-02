%{
   
%}

%%
[a-z] {printf("char\n");}
. {printf("idk \n");}
\n {return 0;}
%%

int yywrap(){
    return 0;
}
int main(){
    printf("enter string:");
    yylex();
    return 0;
}