#include <stdlib.h>

#include "list/linked_list_circular.h"


// Implement init for circular linked list
void cll_init(CLinkedList* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

