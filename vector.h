#ifndef UNIXFILESYSTEM_VECTOR_H
#define UNIXFILESYSTEM_VECTOR_H
#include <stdlib.h>
#define INIT_CAPACITY 5

typedef struct vector
{
    void **data;
    int capacity; /* total capacity */
    int size; /* number of elements in vector */
} vector;

int vector_init(vector *);
int vector_size(vector *);
static void vector_resize(vector *, int);
void vector_add(vector *, void *);
void vector_set(vector *, int, void *);
void *vector_get(vector *, int);
void vector_delete(vector *, int);
void vector_free(vector *);

#endif //UNIXFILESYSTEM_VECTOR_H
