#include "vector.h"

///Initialises vector
/// \param v Previously created vector v
/// \return  0 if success
int vector_init(vector* v)
{
    v->data = malloc(INIT_CAPACITY * sizeof(void *));
    if (!v->data) return -1;
    v->size = 0;
    v->capacity = INIT_CAPACITY;
    return 0; /* success */
}

int vector_size(vector * v)
{
    return v->size;
}
static void vector_resize(vector *v, int capacity)
{
    if (v->capacity < capacity){
        void **data = realloc(v->data, capacity*sizeof(void *));
        if(data){
            v->data = data;
            v->capacity = capacity;
        }
    }
}

void vector_add(vector *v, void * data)
{
    if (v->capacity==v->size)
        vector_resize(v, v->capacity * 2);
    v->data[v->size++] = data;
}
void vector_set(vector *v, int i, void *data)
{
    if (i >= 0 && i < v->size)
        v->data[i] = data;
}

void *vector_get(vector *v, int i)
{
    if (i >= 0 && i < v->size)
        return v->data[i];
    return NULL;
}
void vector_delete(vector *v, int i1)
{
    if (i1 < 0 || i1 >= v->size)
        return;

    v->data[i1] = NULL;

    for (int i = i1; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
        v->data[i + 1] = NULL;
    }

    v->size--;

    if (v->size > 0 && v->size == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}
