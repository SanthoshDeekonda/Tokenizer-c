#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char** getargs(int argc, char* argv[]);
FILE* getfile(const char* INPUT_FILE_PATH);
void writefile(FILE* INPUT_FILE, const char* OUTPUT_FILE_PATH);
void clean_text(char* word);

#endif