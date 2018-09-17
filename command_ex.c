#include <stdio.h>
#include "command_ex.h"
void* read_command_1(SYSTEM *s, char *string){
    if (strcmp(string, "ls")==0) ls_no_path(s);
    if (strcmp(string, "cd")==0) cd_no_path(s);
    if (strcmp(string, "pwd")==0) pwd(s);
}
void* read_command_2(SYSTEM *s, char *string, char *string1){
    if (strcmp(string, "ls")==0) ls(s, string1);
    if (strcmp(string, "cd")==0) cd(s, string1);
    if (strcmp(string, "mkdir")==0) mkdir(s, string1);
    if (strcmp(string, "rmdir")==0) rmdir(s, string1);
    if (strcmp(string, "create")==0) create(s, string1);
    if (strcmp(string, "rm")==0) rm(s, string1);
}

void *execute_command(SYSTEM *s, char * string){
    vector command;
    vector_init(&command);
    command = parse_command(string);
    int argn = vector_size(&command);
    char * c;
    char * c1;
    switch (argn)
    {
        case 0:
            break;
        case 1:
            c = vector_get(&command, 0);
            read_command_1(s, c);
            break;
        case 2:
            c = vector_get(&command, 0);
            c1 = vector_get(&command, 1);
            read_command_2(s, c, c1);
            break;
        default:
            printf("Invalid command");
            break;
    }
}


