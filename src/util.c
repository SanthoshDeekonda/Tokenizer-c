#include "headers/util.h"


char** getargs(int argc, char* argv[]){
    static char* files[2] = {NULL, NULL};

    for(int i=1; i<argc; i++){
        char* temp = argv[i];
        if(strcmp(temp, "-f") == 0){
            files[0] = argv[++i];
        }else if(strcmp(temp, "-o") == 0){
            files[1] = argv[++i];
        }else{
            fprintf(stderr, "Argument Error: invalid arguments");
        }
    }

    return files;
}

FILE* getfile(const char* INPUT_FILE_PATH){
    static FILE* input_file = NULL;

    if(INPUT_FILE_PATH){
        input_file = fopen(INPUT_FILE_PATH, "r");

        if(!input_file){
            perror("ERROR OPENING FILE");
            return NULL;
        }

    }else{
        fprintf(stderr, "INVALID FILE PATH");
    }

    return input_file;

}

void writefile(FILE* INPUT_FILE, const char* OUTPUT_FILE_PATH){
    static FILE* output_file = NULL;
    char buffer[256];
    
     if(OUTPUT_FILE_PATH){
        output_file = fopen(OUTPUT_FILE_PATH, "w");

        if(!output_file){
            perror("ERROR OPENING DESTINATION FILE");
            return;
        }

    }else{
        fprintf(stderr, "INVALID FILE PATH");
        return;
    }

    while (fscanf(INPUT_FILE, "%255s", buffer) == 1) {
        clean_text(buffer);
        if (strlen(buffer) > 0) {
            fprintf(output_file,"%s,",buffer);
        }
    }

    fclose(output_file);

}

void clean_text(char* word) {
    int j = 0;
    for (int i = 0; word[i]; i++) {
        if (isalnum(word[i])) {
            word[j++] = word[i];
        }else if(word[i] == '\n'){
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}