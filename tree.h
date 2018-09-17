#include "vector.h"
#include "string.h"
#ifndef UNIXFILESYSTEM_TREE_H
#define UNIXFILESYSTEM_TREE_H

typedef struct node
{
    int is_dir; //equals to 1 when is dir, equals to 0 if file
    vector kids;
    struct node *parent;
    struct node *root;
    void **key;
} NODE;
NODE *init_root( void *key);
NODE *insert(NODE *parent, void *key, int is_dir);
int isNode(NODE *node, void *key);
vector list_kids_v(NODE *parent);
char* list_kids_s(NODE *current);

/// Given a node returns all its ancestors in reversed order
/// \param current given node
/// \return vector of pointers to ancestors' nodes
vector list_parents_v(NODE *current);
/// Given a node returns all its ancestors in right order and string format: e.g. /dir1/dir2
/// \param current given node
/// \return string
char * list_parents_s(NODE *current);
int node_remove(NODE *remove);


#endif //UNIXFILESYSTEM_TREE_H
