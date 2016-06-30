#include "DubblyList.h"
#include "dbg.h"

DubblyList *create_dubbly_list()
{
    return calloc(1, sizeof(DubblyList));
}

int dub_slap(DubblyList *list, void *value) // add value to the end of the list
{
    DubblyNode *node = calloc(1, sizeof(DubblyNode));
    check(node != NULL, "Failed to allocate memory to Node.");
    node->value = value;

    if(list->head == NULL && list->tail == NULL) { // if the list is empty
        list->head = node;
        list->tail = node;

    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->length++;
    return 1;

error:
    return 0;
}

int dub_shift(DubblyList *list, void *value) // add value at the beginning of list
{
    DubblyNode *node = calloc(1, sizeof(DubblyNode));
    check(node != NULL, "Failed to allocate memory to Node.")
    node->value = value;

    if(list->head == NULL && list->tail == NULL) { // if the list is empty
        list->head = node;
        list->tail = node;

    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->length++;
    return 1;

error:
    return 0;
}

int dub_pop(DubblyList *list) // remove value from end of list
{
    if(list->length > 0) { // if not empty
        DubblyNode *node = list->tail;
        list->tail = list->tail->prev;
        free(node);
        list->tail->next = NULL;
        list->length--;
    } else {
        printf("The list is empty.\n");
    }

    return 1;

}

int dub_slice(DubblyList *list) // remove value from the front of the list
{
    if(list->length > 0) { // if not empty
        DubblyNode *node = list->head;
        list->head = list->head->next;
        free(node);
        list->head->prev = NULL;
        list->length--;
    } else {
        printf("The list is empty.\n");
    }

    return 1;
}

int dub_length(DubblyList *list) // return the length of the list
{
    return list->length;
}

int dub_clear(DubblyList *list) // clears the nodes in the list
{
    for_dubbly(list, tail, prev, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->tail);

    list->length = 0;

    return 1;
}

int dub_destroy(DubblyList *list)
{

    for_dubbly(list, tail, prev, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    list->length = 0;

    free(list->tail);
    free(list);

    return 1;

}

int main(int argc, char const *argv[])
{

    DubblyList *list = create_dubbly_list();
    DubblyList *new = create_dubbly_list();

    printf("%d\n", dub_length(new));

    dub_slap(list, 4);
    dub_slap(list, 7);
    dub_slap(list, 9);
    dub_slap(list, 6);

    dub_shift(list, 96);
    dub_shift(list, 10001);

    dub_pop(list);

    dub_slice(list);

    dub_length(list);

    for_dubbly(list, tail, prev, cur) {
        printf("%d\n", cur->value);
    }

    dub_destroy(list);


    return 0;

}
