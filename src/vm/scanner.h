#pragma once
#ifndef clox_scanner_h
#define clox_scanner_h

#include "../common/common.h"

typedef enum {
    
    TOKEN_LEFT_PAREN_V1, TOKEN_RIGHT_PAREN_V1,
    TOKEN_LEFT_BRACKET_V1, TOKEN_RIGHT_BRACKET_V1,
    TOKEN_LEFT_BRACE_V1, TOKEN_RIGHT_BRACE_V1,
    TOKEN_COLON_V1, TOKEN_COMMA_V1,
    TOKEN_MINUS_V1, TOKEN_MODULO_V1,
    TOKEN_PIPE_V1, TOKEN_PLUS_V1,
    TOKEN_QUESTION_V1, TOKEN_SEMICOLON_V1,
    TOKEN_SLASH_V1, TOKEN_STAR_V1,
    
    TOKEN_BANG_V1, TOKEN_BANG_EQUAL_V1,
    TOKEN_EQUAL_V1, TOKEN_EQUAL_EQUAL_V1,
    TOKEN_GREATER_V1, TOKEN_GREATER_EQUAL_V1,
    TOKEN_LESS_V1, TOKEN_LESS_EQUAL_V1,
    TOKEN_DOT_V1, TOKEN_DOT_DOT_V1,
    
    TOKEN_IDENTIFIER_V1, TOKEN_STRING_V1, TOKEN_INTERPOLATION_V1, TOKEN_NUMBER_V1, TOKEN_INT_V1,
    
    TOKEN_AND_V1, TOKEN_AS_V1, TOKEN_ASYNC_V1, TOKEN_AWAIT_V1, TOKEN_BREAK_V1,
    TOKEN_CASE_V1, TOKEN_CATCH_V1, TOKEN_CLASS_V1, TOKEN_CONTINUE_V1,
    TOKEN_DEFAULT_V1, TOKEN_ELSE_V1, TOKEN_FALSE_V1, TOKEN_FINALLY_V1, TOKEN_FOR_V1,
    TOKEN_FUN_V1, TOKEN_IF_V1, TOKEN_NAMESPACE_V1, TOKEN_NIL_V1, TOKEN_OR_V1,
    TOKEN_REQUIRE_V1, TOKEN_RETURN_V1, TOKEN_SUPER_V1, TOKEN_SWITCH_V1, TOKEN_THIS_V1,
    TOKEN_THROW_V1, TOKEN_TRAIT_V1, TOKEN_TRUE_V1, TOKEN_TRY_V1, TOKEN_USING_V1,
    TOKEN_VAL_V1, TOKEN_VAR_V1, TOKEN_WHILE_V1, TOKEN_WITH_V1, TOKEN_YIELD_V1,

    TOKEN_ERROR_V1, TOKEN_EOF_V1
} TokenSymbolV1;

typedef struct {
    TokenSymbolV1 type;
    const char* start;
    int length;
    int line;
} TokenV1;

typedef struct {
    const char* start;
    const char* current;
    int line;
    int interpolationDepth;
} Scanner;

void initScanner(Scanner* scanner, const char* source);
TokenV1 synthesizeToken(const char* text);
TokenV1 scanNextToken(Scanner* scanner);

#endif // !clox_scanner_h