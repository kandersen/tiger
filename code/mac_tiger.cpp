#include <stdio.h> // printf
#include <stdlib.h> // exit, malloc
#include <string.h> // memcmp

#include "scanner.h"
#include "scanner.cpp"

#include "file.h"
#include "file.cpp"


int main(int argc, char **argv) {

    const char* path = argv[1];
    char* source = readFile(path);

    Scanner scanner;
    initScanner(&scanner, source);

    Token next;
    initScanner(&scanner, source);
    while ((next = nextToken(&scanner)).type != TOKEN_EOF) {
        write_token(stdout, next);
    }
}