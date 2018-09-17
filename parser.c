#include <stdio.h>
#include "vector.h"
#include "parser.h"
vector path_abs(char *path){
    vector ret;
    vector_init(&ret);
    vector_add(&ret, "/");
    if(strcmp(path, "/") == 0){
        return ret;
    }
    char  string[1000] = "";
    strcat(string, path);
    const char delimiters[] = "/";
    char *token, *cp;
    cp = strdup(string);

    token = strtok (cp, delimiters);
    vector_add(&ret, token);

    while (token != NULL){
        token = strtok(NULL, delimiters);
        if(token != NULL) {
            vector_add(&ret, token);
        }
    }
    int i;
    return ret;

}

vector parse_command(char *path) {
    vector ret;
    vector_init(&ret);
    char  string[1000] = "";
    strcat(string, path);
    const char delimiters[] = " ";
    char *token, *cp;
    cp = strdup(string);

    token = strtok (cp, delimiters);
    vector_add(&ret, token);
    while (token != NULL){
        token = strtok(NULL, delimiters);
        if(token != NULL) {
            vector_add(&ret, token);
        }
    }
    return ret;
}


