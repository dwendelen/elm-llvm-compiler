cmake_minimum_required (VERSION 3.0)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -std=c++11)
if(APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
endif(APPLE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project("elm-llvm-compiler")

CONFIGURE_FILE(src/Parser/Parser.h Parser.h COPYONLY)
CONFIGURE_FILE(src/Parser/Scanner.h Scanner.h COPYONLY)

#flexc++
find_package(FLEXCPP)
SET(FLEXCPP_OUTPUTS
        ${CMAKE_CURRENT_BINARY_DIR}/Scanner.ih
        ${CMAKE_CURRENT_BINARY_DIR}/Scannerbase.h
        ${CMAKE_CURRENT_BINARY_DIR}/lex.cc)
ADD_CUSTOM_COMMAND(OUTPUT ${FLEXCPP_OUTPUTS}
        COMMAND ${FLEXCPP_EXECUTABLE}
        ARGS --target-directory ${CMAKE_CURRENT_BINARY_DIR} src/Parser/lexer.l
        DEPENDS src/Parser/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/Scanner.h
        COMMENT "[FLEXCPP][${Name}] Building scanner with flexc++ ${FLEXCPP_VERSION}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#bisonc++
find_package(BISONCPP)
SET(BISONCPP_OUTPUTS
        ${CMAKE_CURRENT_BINARY_DIR}/Parser.ih
        ${CMAKE_CURRENT_BINARY_DIR}/Parserbase.h
        ${CMAKE_CURRENT_BINARY_DIR}/parse.cc)
ADD_CUSTOM_COMMAND(OUTPUT ${BISONCPP_OUTPUTS}
        COMMAND ${BISONCPP_EXECUTABLE}
        ARGS --target-directory ${CMAKE_CURRENT_BINARY_DIR} src/Parser/parser.y
        DEPENDS src/Parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/Parser.h
        COMMENT "[BISONCPP][${Name}] Building parser with bisonc++ ${BISONCPP_VERSION}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC src/Parser/ElmParser.cpp src/Parser/ElmParser.hpp src/Parser/ParsedFile.cpp src/Parser/ParsedFile.hpp src/Main.cpp src/Main.hpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(elm-llvm-compiler
    ${SRC}
    src/Parser/Scanner.h
    src/Parser/Parser.h
    ${BISONCPP_OUTPUTS}
    ${FLEXCPP_OUTPUTS}
)
