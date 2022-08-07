const char* ppToken(Token token) {
    switch(token.type) {
    // Comments
        case TOKEN_COMMENT: return "COMMENT";

        // Whitespace
        case TOKEN_SPACE: return "SPACE";
        case TOKEN_TAB: return "TAB";
        case TOKEN_NEWLINE: return "NEWLINE";
        case TOKEN_CARRIAGERETURN: return "CARRIAGERETURN";

        // Lexemes
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_INTEGER_LITERAL: return "INTEGER_LITERAL";
        case TOKEN_STRING_LITERAL: return "STRING";

        // Keywords
        case TOKEN_WHILE: return "WHILE";
        case TOKEN_FOR: return "FOR";
        case TOKEN_TO: return "TO";
        case TOKEN_BREAK: return "BREAK";
        case TOKEN_LET: return "LET";
        case TOKEN_IN: return "IN";
        case TOKEN_END: return "END";
        case TOKEN_FUNCTION: return "FUNCTION";
        case TOKEN_VAR: return "VAR";
        case TOKEN_TYPE: return "TYPE";
        case TOKEN_ARRAY: return "ARRAY";
        case TOKEN_IF: return "IF";
        case TOKEN_THEN: return "THEN";
        case TOKEN_ELSE: return "ELSE";
        case TOKEN_DO: return "DO";
        case TOKEN_OF: return "OF";
        case TOKEN_NIL: return "NIL";

        // Punctuation
        case TOKEN_COMMA: return "COMMA";
        case TOKEN_COLON: return "COLON";
        case TOKEN_SEMICOLON: return "SEMICOLON";
        case TOKEN_LPAREN: return "LPAREN";
        case TOKEN_RPAREN: return "RPAREN";
        case TOKEN_LBRACKET: return "LBRACKET";
        case TOKEN_RBRACKET: return "RBRACKET";
        case TOKEN_LBRACE: return "LBRACE";
        case TOKEN_RBRACE: return "RBRACE";
        case TOKEN_DOT: return "DOT";
        case TOKEN_PLUS: return "PLUS";
        case TOKEN_DASH: return "DASH";
        case TOKEN_STAR: return "STAR";
        case TOKEN_SLASH: return "SLASH";
        case TOKEN_EQ: return "EQ";
        case TOKEN_INEQ: return "INEQ";
        case TOKEN_LT: return "LT";
        case TOKEN_LTEQ: return "LTEQ";
        case TOKEN_GT: return "GT";
        case TOKEN_GTEQ: return "GTEQ";
        case TOKEN_AMPERSAND: return "AMPERSAND";
        case TOKEN_PIPE: return "PIPE";
        case TOKEN_COLONEQ: return "COLONEQ";

        // Meta
        case TOKEN_ERROR: return "<ERR>";
        case TOKEN_EOF: return "<EOF>";
    }
}

void write_token(FILE* stream, Token token) {
    switch(token.type) {
        case TOKEN_COMMENT: {
            char* current = token.begin;
            while (current != token.end) {
                fputc(*current, stream);
                current++;
            }
            return;
        }

        // Whitespace
        case TOKEN_SPACE: {
            fputc(' ', stream);
            return;
        }
        case TOKEN_TAB: {
            fprintf(stream, "\t");
            return;
        }
        case TOKEN_NEWLINE: {
            fprintf(stream, "\n");
            return;
        }
        case TOKEN_CARRIAGERETURN: {
            fprintf(stream, "\r");
            return;
        }

        // Lexemes
        case TOKEN_IDENTIFIER: {
            char* current = token.begin;
            while (current != token.end) {
                fputc(*current, stream);
                current++;
            }
            return;
        }
        case TOKEN_INTEGER_LITERAL: {
            char* current = token.begin;
            while (current != token.end) {
                fputc(*current, stream);
                current++;
            }
            return;
        }
        case TOKEN_STRING_LITERAL: {
            char* current = token.begin;
            while (current != token.end) {
                fputc(*current, stream);
                current++;
            }
            return;
        }

        // Keywords
        case TOKEN_WHILE: {
            fprintf(stream, "while");
            return;
        }
        case TOKEN_FOR: {
            fprintf(stream, "for");
            return;
        }
        case TOKEN_TO: {
            fprintf(stream, "to");
            return;
        }
        case TOKEN_BREAK: {
            fprintf(stream, "break");
            return;
        }
        case TOKEN_LET: {
            fprintf(stream, "let");
            return;
        }
        case TOKEN_IN: {
            fprintf(stream, "in");
            return;
        }
        case TOKEN_END: {
            fprintf(stream, "end");
            return;
        }
        case TOKEN_FUNCTION: {
            fprintf(stream, "function");
            return;
        }
        case TOKEN_VAR: {
            fprintf(stream, "var");
            return;
        }
        case TOKEN_TYPE: {
            fprintf(stream, "type");
            return;
        }
        case TOKEN_ARRAY: {
            fprintf(stream, "array");
            return;
        }
        case TOKEN_IF: {
            fprintf(stream, "if");
            return;
        }
        case TOKEN_THEN: {
            fprintf(stream, "then");
            return;
        }
        case TOKEN_ELSE: {
            fprintf(stream, "else");
            return;
        }
        case TOKEN_DO: {
            fprintf(stream, "do");
            return;
        }
        case TOKEN_OF: {
            fprintf(stream, "of");
            return;
        }
        case TOKEN_NIL: {
            fprintf(stream, "nil");
            return;
        }

        // Punctuation
        case TOKEN_COMMA: {
            fprintf(stream, ",");
            return;
        }
        case TOKEN_COLON: {
            fprintf(stream, ":");
            return;
        }
        case TOKEN_SEMICOLON: {
            fprintf(stream, ";");
            return;
        }
        case TOKEN_LPAREN: {
            fputc('(', stream);
            return;
        }
        case TOKEN_RPAREN: {
            fputc(')', stream);
            return;
        }
        case TOKEN_LBRACKET: {
            fputc('[', stream);
            return;
        }
        case TOKEN_RBRACKET: {
            fputc(']', stream);
            return;
        }
        case TOKEN_LBRACE: {
            fputc('{', stream);
            return;
        }
        case TOKEN_RBRACE: {
            fputc('}', stream);
            return;
        }
        case TOKEN_DOT: {
            fputc('.', stream);
            return;
        }
        case TOKEN_PLUS: {
            fputc('+', stream);
            return;
        }
        case TOKEN_DASH: {
            fputc('-', stream);
            return;
        }
        case TOKEN_STAR: {
            fputc('*', stream);
            return;
        }
        case TOKEN_SLASH: {
            fputc('/', stream);
            return;
        }
        case TOKEN_EQ: {
            fputc('=', stream);
            return;
        }
        case TOKEN_INEQ: {
            fputs("<>", stream);
            return;
        }
        case TOKEN_LT: {
            fputc('<', stream);
            return;
        }
        case TOKEN_LTEQ: {
            fputs("<=", stream);
            return;
        }
        case TOKEN_GT: {
            fputc('>', stream);
            return;
        }
        case TOKEN_GTEQ: {
            fputs(">=", stream);
            return;
        }
        case TOKEN_AMPERSAND: {
            fputc('&', stream);
            return;
        }
        case TOKEN_PIPE: {
            fputc('|', stream);
            return;
        }
        case TOKEN_COLONEQ: {
            fputs(":=", stream);
            return;
        }
        // Meta
        case TOKEN_ERROR: {
            fputs("<ERR>", stream);
            return;
        }
        case TOKEN_EOF: {
            fputs("<EOF>>", stream);
            return;
        }
    }
}

bool isAtEnd(Scanner* scanner) {
    return *scanner->current == '\0';
}

char peek(Scanner* scanner) {
    return *scanner->current;
}

char peekNext(Scanner* scanner) {
    if (isAtEnd(scanner)) return '\0';
    return scanner->current[1];
}

bool match(Scanner* scanner, char expected) {
    if (isAtEnd(scanner)) return false;
    if (*scanner->current != expected) return false;

    scanner->current++;
    return true;
}

char advance(Scanner* scanner) {
    scanner->current++;
    return scanner->current[-1];
}

Token makeToken(Scanner* scanner, TokenType type) {
    Token token;
    token.type = type;
    token.begin = scanner->start;
    token.end = scanner->current;
    return token;
}

Token comment(Scanner* scanner) {
    while (!(peek(scanner) == '*' && peekNext(scanner) == '/') && !isAtEnd(scanner)) {
        advance(scanner);
    }
    if (isAtEnd(scanner)) return makeToken(scanner, TOKEN_ERROR);
    match(scanner, '*');
    match(scanner, '/');
    return makeToken(scanner, TOKEN_COMMENT);
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

bool isAlpha(char c) {
    return ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z');
}

TokenType checkKeyword(Scanner* scanner, int start, int length, const char* rest, TokenType type) {
    if(scanner->current - scanner->start == start + length && memcmp(scanner->start + start, rest, length) == 0) {
        return type;
    }
    return TOKEN_IDENTIFIER;
}
    
        
TokenType identifierType(Scanner* scanner) {
    switch(scanner->start[0]) {
        case 'a': return checkKeyword(scanner, 1, 4, "rray", TOKEN_ARRAY);
        case 'b': return checkKeyword(scanner, 1, 4, "reak", TOKEN_BREAK);
        case 'd': return checkKeyword(scanner, 1, 1, "o", TOKEN_DO);
        case 'e':
          if (scanner->current - scanner->start > 1) {
            switch(scanner->start[1]) {
                case 'l': return checkKeyword(scanner, 2, 2, "se", TOKEN_ELSE);
                case 'n': return checkKeyword(scanner, 2, 1, "d", TOKEN_END);
            }
          }
          break;
        case 'f':
          if (scanner->current - scanner->start > 1) {
            switch(scanner->start[1]) {
                case 'o': return checkKeyword(scanner, 2, 1, "r", TOKEN_FOR);
                case 'u': return checkKeyword(scanner, 2, 6, "nction", TOKEN_FUNCTION);
            }
          }
          break;
        case 'i':
          if (scanner->current - scanner->start > 1) {
            switch(scanner->start[1]) {
                case 'f': return checkKeyword(scanner, 2, 0, "", TOKEN_IF);
                case 'n': return checkKeyword(scanner, 2, 0, "", TOKEN_IN);
            }
          }
          break;
        case 'l': return checkKeyword(scanner, 1, 2, "et", TOKEN_LET);
        case 'n': return checkKeyword(scanner, 1, 2, "il", TOKEN_NIL);
        case 'o': return checkKeyword(scanner, 1, 1, "f", TOKEN_OF);
        case 't': 
          if (scanner->current - scanner->start > 1) {
            switch(scanner->start[1]) {
                case 'h': return checkKeyword(scanner, 2, 2, "en", TOKEN_THEN);
                case 'o': return TOKEN_TO;
                case 'y': return checkKeyword(scanner, 2, 2, "pe", TOKEN_TYPE);
            }
          }
          break;
        case 'v': return checkKeyword(scanner, 1, 2, "ar", TOKEN_VAR);
        case 'w': return checkKeyword(scanner, 1, 4, "hile", TOKEN_WHILE);
    }
    return TOKEN_IDENTIFIER;
}

Token string(Scanner* scanner) {
    while (peek(scanner) != '"' && !isAtEnd(scanner)) advance(scanner);
    if (isAtEnd(scanner)) return makeToken(scanner, TOKEN_ERROR);
    match(scanner, '"');
    return makeToken(scanner, TOKEN_STRING_LITERAL);
}

Token integer(Scanner* scanner) {
    while (isDigit(peek(scanner))) advance(scanner);
    return makeToken(scanner, TOKEN_INTEGER_LITERAL);
}

Token identifier(Scanner* scanner) {
    while (isAlpha(peek(scanner)) || isDigit(peek(scanner)) || (peek(scanner) == '_')) advance(scanner);
    return makeToken(scanner, identifierType(scanner));
}

void initScanner(Scanner* scanner, char* source) {
    scanner->start = source;
    scanner->current = source;
}

Token nextToken(Scanner* scanner) {
    scanner->start = scanner->current;

    if (isAtEnd(scanner)) {
        return makeToken(scanner, TOKEN_EOF);
    }

    char c = advance(scanner);
    if (isAlpha(c)) return identifier(scanner);
    if (isDigit(c)) return integer(scanner);
    if (c == '"') return string(scanner);
    
    switch (c) {
        case ' ': return makeToken(scanner, TOKEN_SPACE);
        case '\t': return makeToken(scanner, TOKEN_TAB);
        case '\n': return makeToken(scanner, TOKEN_NEWLINE);
        case '\r': return makeToken(scanner, TOKEN_CARRIAGERETURN);
        case ',': return makeToken(scanner, TOKEN_COMMA);
        case ';': return makeToken(scanner, TOKEN_SEMICOLON);
        case '(': return makeToken(scanner, TOKEN_LPAREN);
        case ')': return makeToken(scanner, TOKEN_RPAREN);
        case '[': return makeToken(scanner, TOKEN_LBRACKET);
        case ']': return makeToken(scanner, TOKEN_RBRACKET);
        case '{': return makeToken(scanner, TOKEN_LBRACE);
        case '}': return makeToken(scanner, TOKEN_RBRACE);
        case '.': return makeToken(scanner, TOKEN_DOT);
        case '+': return makeToken(scanner, TOKEN_PLUS);
        case '-': return makeToken(scanner, TOKEN_DASH);
        case '*': return makeToken(scanner, TOKEN_STAR);
        case '|': return makeToken(scanner, TOKEN_PIPE);
        case '&': return makeToken(scanner, TOKEN_AMPERSAND);
        case ':': 
            return match(scanner, '=') ? makeToken(scanner, TOKEN_COLONEQ) : makeToken(scanner, TOKEN_COLON);
        case '/': 
            return match(scanner, '*') ? comment(scanner) : makeToken(scanner, TOKEN_SLASH);
        case '=': return makeToken(scanner, TOKEN_EQ);
        case '<':
            if (match(scanner, '>')) {
                return makeToken(scanner, TOKEN_INEQ);
            } else if (match(scanner, '=')) {
                return makeToken(scanner, TOKEN_LTEQ);
            } else {
                return makeToken(scanner, TOKEN_LT);
            }
        case '>':
            return match(scanner, '=') ? makeToken(scanner, TOKEN_GTEQ) : makeToken(scanner, TOKEN_GT);          
        default: {
            return makeToken(scanner, TOKEN_ERROR);
        }
            
    }
}