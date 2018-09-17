#include "tree.h"

NODE *init_root( void *key){
    NODE *tempNode = (NODE *)malloc(sizeof(NODE));
    vector kids;
    vector_init(&kids);
    tempNode->is_dir = 1;
    tempNode->key = key;
    tempNode->parent = tempNode;
    tempNode->root = tempNode;
    tempNode->kids = kids;
    return tempNode;
}

NODE *insert( NODE *parent, void *key, int is_dir)
{
    NODE *tempNode = (NODE *)malloc(sizeof(NODE));
    vector kids;
    vector_init(&kids);
    tempNode->is_dir = is_dir;
    tempNode->key = key;
    tempNode->kids = kids;
    tempNode->root = parent->root;
    tempNode->parent = parent;
    vector_add(&parent->kids, tempNode);
    return tempNode;
}
int node_remove(NODE *remove)
{
    int sib_num = remove->parent->kids.size;
    int i = 0;
    int is_remove;
    for ( i = 0; i < sib_num; i++) {
        is_remove = isNode(vector_get(&remove->parent->kids, i), remove->key );
        if(is_remove > 0) break;
    }
    vector_delete(&remove->parent->kids, i);
    free(remove);
}


vector list_kids_v(NODE *parent){
    return  parent->kids;
}

 char* list_kids_s(NODE *current){
    size_t strl;
    NODE *temp;
    char  string[1000] = "\n";
    char  *string1;
    int i;
    vector v = list_kids_v(current);
     if (vector_size(&v) < 1) return NULL;
    for (i = 0; i < vector_size(&v); i++){
        temp = (NODE*) vector_get(&v, i);
        string1 = (char *) temp->key;
        strcat(string, string1);
        strcat(string, "\n");
    }
    strl = strlen(string);

    char *ret = malloc((int)strl*sizeof(char));
    if(!ret)
        return NULL;
    for (i = 0; i < strl; i++)
        ret[i] = string[i];
    return ret;
}

vector list_parents_v(NODE *current){
    vector ret;
    vector_init(&ret);
    do{
        vector_add(&ret, current);
        current = current->parent;
    }while (current->root != current);
    vector_add(&ret, current);
    return ret;
}
 char * list_parents_s(NODE *current){
    size_t strl;
    NODE *temp;
    char  string[1000] = "\n";
    char  *string1;
    int i;
    vector v = list_parents_v(current);
    for (i =  vector_size(&v) -2; i > -1; i--){
        strcat(string, "/");
        temp = (NODE*) vector_get(&v, i);
        string1 = (char *) temp->key;
        strcat(string, string1);
    }
    strl = strlen(string);
    char *ret = malloc((int)strl*sizeof(char));
    if(!ret){
        return NULL;}
    for (i = 0; i < strl; i++){
        ret[i] = string[i];
    }
     return  ret;
 }

int isNode(NODE *node, void *key){
    if (node->key == key) return 1; else return -1;
}
