#ifndef dubbly_list_h
#define dubbly_list_h

#include <stdio.h>
#include <stdlib.h>

struct DubblyNode;

typedef struct DubblyNode {
    void *value;
    struct DubblyNode *next;
    struct DubblyNode *prev;
} DubblyNode;

typedef struct DubblyList {
    int length;
    DubblyNode *head;
    DubblyNode *tail;
} DubblyList;

DubblyList *create_dubbly_list();
int dub_slap(DubblyList *list, void *value); // add value to the end of the list
int dub_shift(DubblyList *list, void *value); // add value to the front of the list
int dub_pop(DubblyList *list); // remove value from the end of the list
int dub_slice(DubblyList *list); // remove value from the front of the list
int dub_length(DubblyList *list); // return the length of the list
int dub_clear(DubblyList *list); // clear the nodes in the list
int dub_destroy(DubblyList *list); // completely delete the list and all nodes

// for loop iterator
#define for_dubbly(L, S, N, C) DubblyNode *_node = NULL;\
    DubblyNode *C = NULL;\
    for(C = _node = L->S; _node != NULL; C = _node = _node->N)


#endif
