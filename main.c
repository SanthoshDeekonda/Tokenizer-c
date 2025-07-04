#include <stdio.h>
#include "headers/util.h"

FILE* INPUT_FILE;
char** FILE_PATHS;


int main(int argc, char* argv[]){

    FILE_PATHS = getargs(argc, argv);
    INPUT_FILE = getfile(FILE_PATHS[0]);    
    writefile(INPUT_FILE,FILE_PATHS[1]);

    fclose(INPUT_FILE);
    
    return 0;

}