//%token INT
//%token FLOAT
%token ID
//%token LPARENT RPARENT
%token EQUALS
%token NEWLINE


%%
program:
      functionDefinition
    ;
functionDefinition:
      ID EQUALS NEWLINE expressionList NEWLINE
    | ID EQUALS expressionList NEWLINE
    ;
expressionList:
      expressionList expression
    | expression
    ;
expression:
//      LPARENT expressionList RPARENT
    | ID
//    | FLOAT
//    | INT
    ;

