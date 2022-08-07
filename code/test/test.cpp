#include <stdio.h> // printf, tmpfile
#include <stdlib.h> // exit, malloc
#include <string.h> // memcmp
#include <dirent.h> // DIR, opendir

#include "../scanner.h"
#include "../scanner.cpp"

#include "../file.h"
#include "../file.cpp"

int compareStreamToGoldenFile(FILE *actual, char *golden) {
    FILE *expected = openFile(golden);
    char actualLine[256];
    char expectedLine[256];
    int line = 1;
    while (fgets(actualLine, 256, actual) != NULL && fgets(expectedLine, 256, expected) != NULL) {
        if (strcmp(actualLine, expectedLine) != 0) {
            return line;
        }
        line++;
    }
    if (strcmp(actualLine, expectedLine) != 0) {
        return line;
    } else {
        return 0;
    }
}

void scannerTest(const char* path) {
    char* source = readFile(path);

    Scanner scanner;
    initScanner(&scanner, source);

    FILE* tmp = tmpfile();

    Token next;
    while ((next = nextToken(&scanner)).type != TOKEN_EOF) {
        write_token(tmp, next);
    }

    rewind(tmp);
    int error = compareStreamToGoldenFile(tmp, (char *)path);
    if (error != 0) {
        printf("FAIL\n");
        printf("  Output differs on line %d.\n", error);
    } else {
        printf("OK\n");
    }

}

void scannerTests(const char* testRoot) {
    char scannerTestRoot[1024];
    strcpy(scannerTestRoot, testRoot);
    strcat(scannerTestRoot, "/scanner");

    DIR *d;
    struct dirent *dir;
    d = opendir(scannerTestRoot);
    if (d) {
        while((dir = readdir(d)) != NULL) {
            char *dot = strrchr(dir->d_name, '.');
            if (dot && (strcmp(dot, ".tig") == 0)) {
                char testFile[1024];
                strcpy(testFile, scannerTestRoot);
                strcat(testFile, "/");
                strcat(testFile, dir->d_name);

                scannerTest(testFile);
            }
        }
        closedir(d);
    }
}

int main(int argc, char **argv) {
    const char* testRoot = argv[1];

    scannerTests(testRoot);
}