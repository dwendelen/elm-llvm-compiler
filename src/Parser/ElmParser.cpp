//
// Created by xtrit on 13/08/17.
//

#include "ElmParser.hpp"
#include "Parser.h"

ParsedFile ElmCompiler::ElmParser::parse() {
    Parser parser;
    parser.parse();
    return ParsedFile();
}
