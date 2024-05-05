#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct Element {
    void*            data;
    struct Element*  next;
} Element;

typedef struct LinkedList
{
    int       size;
    Element*  head;
    Element*  tail;
} LinkedList;

void init_linked_list(LinkedList* list);
void free_linked_list(LinkedList* list);
int insert_head(LinkedList* list, void* data);
int insert_tail(LinkedList* list, void* data);
int remove_head(LinkedList* list, void** data);
int insert_element_next(LinkedList* list, Element* selected, void* data);
int remove_element_next(LinkedList* list, Element* selected, void** data);

#endif