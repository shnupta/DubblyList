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
    int count;
    DubblyNode *head;
    DubblyNode *tail;
} DubblyList;

DubblyList *createDubblyList();
int push(DubblyList *list, void *value);
int pop(DubblyList *list);
void peak(DubblyList *list);



#endif
