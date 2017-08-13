//
// Created by xtrit on 13/08/17.
//

#include "Main.hpp"
#include <Parser/ElmParser.hpp>

using namespace ElmCompiler;

int main(int argCount, char** args) {
    if(argCount != 2) {
        return 1;
    }

    ElmParser parser;
    parser.parse();
}