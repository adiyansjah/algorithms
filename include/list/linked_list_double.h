#ifndef _LINKED_LIST_DOUBLE_H_
#define _LINKED_LIST_DOUBLE_H_

typedef struct Element {
    void*            data;
    struct Element*  next;
    struct Element*  prev;
} Element;

typedef struct DLinkedList
{
    int       size;
    Element*  head;
    Element*  tail;
} DLinkedList;

void dll_init(DLinkedList* list);
void dll_free(DLinkedList* list);
int dll_insert_head(DLinkedList* list, void* data);
int dll_insert_tail(DLinkedList* list, void* data);
int dll_remove_head(DLinkedList* list, void** data);
int dll_remove_tail(DLinkedList* list, void** data);
int dll_insert_element_next(DLinkedList* list, Element* selected, void* data);
int dll_insert_element_prev(DLinkedList* list, Element* selected, void* data);
int dll_remove_element_next(DLinkedList* list, Element* selected, void** data);
int dll_remove_element_prev(DLinkedList* list, Element* selected, void** data);

#endif