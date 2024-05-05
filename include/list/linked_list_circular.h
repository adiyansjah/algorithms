#ifndef _LINKED_LIST_CIRCULAR_H_
#define _LINKED_LIST_CIRCULAR_H_

typedef struct Element {
    void*            data;
    struct Element*  next;
} Element;

typedef struct CLinkedList
{
    int       size;
    Element*  head;
} CLinkedList;

void cll_init(CLinkedList* list);
void cll_free(CLinkedList* list);
int cll_insert_head(CLinkedList *list, void *data);
int cll_remove_head(CLinkedList *list, void **data);
int cll_insert_element_next(CLinkedList *list, Element *selected, void *data);
int cll_insert_element_prev(CLinkedList *list, Element *selected, void *data);
int cll_remove_element_next(CLinkedList *list, Element *selected, void **data);
int cll_remove_element_prev(CLinkedList *list, Element *selected, void **data);

#endif