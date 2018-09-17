#include <stdio.h>
#include "system.h"
SYSTEM *system_init(){
    SYSTEM *tempSys =  (SYSTEM *)malloc(sizeof(SYSTEM));
    NODE *root = init_root("/");
    vector nodes;
    vector_init(&nodes);
    vector_add(&nodes, root->key);
    tempSys->nodes = nodes;
    tempSys->current = root;
    return tempSys;
}
char *mkdir(SYSTEM *s, char * pathname) {
    vector p;
    int i;
    vector_init(&p);
    p = path_abs(pathname);
    char *key = vector_get(&p, vector_size(&p) - 1);
    for (i = 0; i < vector_size(&p); i++)
        printf("");
    printf("");
    vector_delete(&p, vector_size(&p) - 1);
    for (i = 0; i < vector_size(&p); i++)
        printf("");
    printf("");

    NODE *parent = find_node(s, &p);
    if(parent->is_dir!=0)
    {
        insert(parent, key, 1);
    } else printf("Cannot create directory in a file");

}

char *rmdir(SYSTEM *s, char * pathname){
    vector p;
    int i;
    vector_init(&p);
    p = path_abs(pathname);
    NODE *rm = find_node(s, &p);
    if(rm->is_dir==1 && (vector_size(&rm->kids) == 0)) //if rm is a dir && has no kids (folders or files)
    {
        if(s->current == rm){
            s->current = rm->parent;
        }
        node_remove(rm);
    } else printf("%s%s ", "Cannot remove ", pathname);
}
char *cd(SYSTEM *s, char * pathname){
    vector p;
    vector_init(&p);
    p = path_abs(pathname);
    s->current = find_node(s, &p);
}
char *cd_no_path(SYSTEM *s){
    s->current = s->current->root;
}
char *ls(SYSTEM *s, char *pathname){
    vector p;
    vector_init(&p);
    p = path_abs(pathname);
    NODE *parent = find_node(s, &p);
    if(parent->is_dir == 1){
        char *t1 = list_kids_s(parent);
        printf(t1);
        return t1;
    }

}
char *ls_no_path(SYSTEM *s){
    ls(s, "/");
}
char *pwd(SYSTEM *s){
    printf(list_parents_s(s->current));
}
void *create(SYSTEM *s, char *pathname)
{
    vector p;
    int i;
    vector_init(&p);
    p = path_abs(pathname);
    char *key = vector_get(&p, vector_size(&p) - 1);
    for (i = 0; i < vector_size(&p); i++)
                printf("");
    printf("");
    vector_delete(&p, vector_size(&p) - 1);
    for (i = 0; i < vector_size(&p); i++)
        printf("");
    printf("");
    NODE *parent = find_node(s, &p);
    if(parent->is_dir!=0)
    {
        insert(parent, key, 0);
    } else printf("Cannot create file in a file");


}
void *rm(SYSTEM *s, char *pathname){
    vector p;
    int i;
    vector_init(&p);
    p = path_abs(pathname);
    NODE *rm = find_node(s, &p);
    if(rm->is_dir==0) //if rm is a dir && has no kids (folders or files)
    {
        if(s->current == rm){
            s->current = rm->parent;
        }
        node_remove(rm);
    } else printf("%s%s ", "Cannot remove ", pathname);
};
NODE *find_node(SYSTEM *s, vector *pathname){
    int i;
    for (i = 0; i < vector_size(pathname); i++)
        printf("");
    printf("");
    int depth = vector_size(pathname);
    char *current_dir;
    char *key = vector_get(pathname,depth -1);
    NODE *current = s->current->root;
    vector kids;
    NODE *kid;
    char * cur_key = (char *) current->key;
    while (strcmp(cur_key, key) != 0){
        cur_key = (char *) current->key;
        if(strcmp(cur_key, key) == 0) break;
        kids = current->kids;
        for (i = 0; i < vector_size(&kids); i++){
            kid = (NODE *) vector_get(&kids, i);
            char *kid_key = (char *) kid->key;
            current_dir = vector_get(pathname, 1);
            if(strcmp(kid_key, current_dir) == 0) {
                current = kid;
                vector_delete(pathname, 0);
                break;
            }
        }

    }
    return current;
}
