//
// Created by xtrit on 13/08/17.
//

#ifndef ELM_LLVM_COMPILER_PARSER_HPP
#define ELM_LLVM_COMPILER_PARSER_HPP

#include <string>
#include <Parser.h>
#include "ParsedFile.hpp"

namespace ElmCompiler {
    class ElmParser {
    public:
        ElmParser() {};
        ParsedFile parse();
    private:
    };
}
#endif //ELM_LLVM_COMPILER_PARSER_HPP
