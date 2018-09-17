#include "tree.h"
#include "parser.h"
#ifndef UNIXFILESYSTEM_SYSTEM_H
#define UNIXFILESYSTEM_SYSTEM_H
typedef struct system
{
    vector nodes;
    NODE *current;

} SYSTEM;
SYSTEM * system_init();
char *mkdir(SYSTEM *s,char * pathname);
char *rmdir(SYSTEM *s, char * pathname);
char *cd(SYSTEM *s, char * pathname);
char *cd_no_path(SYSTEM *s);
char *ls(SYSTEM *s, char *pathname);
char *ls_no_path(SYSTEM *s);
char *pwd(SYSTEM *s);
void *create(SYSTEM *s, char *pathname);
void *rm(SYSTEM *s, char *pathname);
NODE *find_node(SYSTEM *s, vector *pathname);
#endif //UNIXFILESYSTEM_SYSTEM_H
