// Generated by Bisonc++ V4.13.01 on Sun, 13 Aug 2017 20:28:05 +0200

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "Parserbase.h"
#include "Scanner.h"

#undef Parser
//dakkeCode22
class Parser : public ParserBase {

public:
    int parse();

private:
    Scanner d_scanner;

    void error(char const *msg);    // called on (syntax) errors
    int lex();                      // returns the next token from the
    // lexical scanner.
    void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
    void executeAction(int ruleNr);

    void errorRecovery();

    int lookup(bool recovery);

    void nextToken();

    void print__();

    void exceptionHandler__(std::exception const &exc);
};


#endif
