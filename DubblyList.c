#include "DubblyList.h"
#include "dbg.h"

DubblyList *createDubblyList()
{
    return calloc(1, sizeof(DubblyList));
}

int push(DubblyList *list, void *value) // add value to the top of the list
{
    DubblyNode *node = calloc(1, sizeof(DubblyNode));
    check(node != NULL, "Node failed to create.");
    node->value = value;

    if(list->head == NULL && list->tail == NULL) { // if the list is empty
        list->head = node;
        list->tail = node;
        list->count++;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }

    return 1;

error:
    return 0;
}

int pop(DubblyList *list) // remove value from top of list
{
    DubblyNode *node = list->head;
    list->head = list->head->next;
    free(node);
    list->head->prev = NULL;

    return 1;

error:
    return 0;
}

int main(int argc, char const *argv[]) {

    DubblyList *list = createDubblyList();
    push(list, 4);
    push(list, 7);
    pop(list);

    
    return 0;
}
