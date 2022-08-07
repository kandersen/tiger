#ifndef SCANNER_H
#define SCANNER_H

enum TokenType {
    // Comments
    TOKEN_COMMENT, 

    // Whitespace
    TOKEN_SPACE,
    TOKEN_TAB,
    TOKEN_NEWLINE,
    TOKEN_CARRIAGERETURN,

    // Lexemes
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER_LITERAL,
    TOKEN_STRING_LITERAL,

    // Keywords
    TOKEN_WHILE, 
    TOKEN_FOR, 
    TOKEN_TO,
    TOKEN_BREAK, 
    TOKEN_LET,
    TOKEN_IN,
    TOKEN_END,
    TOKEN_FUNCTION,
    TOKEN_VAR,
    TOKEN_TYPE,
    TOKEN_ARRAY,
    TOKEN_IF,
    TOKEN_THEN,
    TOKEN_ELSE,
    TOKEN_DO,
    TOKEN_OF,
    TOKEN_NIL,

    // Punctuation
    TOKEN_COMMA,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_DOT,
    TOKEN_PLUS,
    TOKEN_DASH,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_EQ,
    TOKEN_INEQ,
    TOKEN_LT,
    TOKEN_LTEQ,
    TOKEN_GT,
    TOKEN_GTEQ,
    TOKEN_AMPERSAND,
    TOKEN_PIPE,
    TOKEN_COLONEQ,

    // Meta
    TOKEN_ERROR,
    TOKEN_EOF
};

typedef struct {
    TokenType type;
    char* begin;
    char* end;
} Token;

typedef struct {
    char* start;
    char* current;
} Scanner;

//

void write_token(FILE* handle, Token token);
const char* ppToken(Token token);

//

void initScanner(Scanner* scanner, const char* source);
/**
 * Eventually returns EOF
 */
Token nextToken(Scanner* scanner);

#endif