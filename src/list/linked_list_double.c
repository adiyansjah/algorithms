#include <stdlib.h>

#include "list/linked_list_double.h"


void dll_init(DLinkedList* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void dll_free(DLinkedList* list) {
    void* data;
    while(list->size != 0) {
        dll_remove_head(list, data); free(data);
    }
}

int dll_insert_head(DLinkedList* list, void* data) {
    Element* element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return -1;

    element->data = data;
    element->next = list->head;
    element->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = element;
    }

    if (list->tail == NULL) {
        list->tail = element;
    }

    list->head = element;
    list->size++; return 0;
}

int dll_insert_tail(DLinkedList* list, void* data) {
    Element* element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return -1;

    element->data = data;
    element->next = NULL;
    element->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = element;
    }

    if (list->head == NULL) {
        list->head = element;
    }

    list->tail = element;
    list->size++; return 0; 
}

int dll_remove_head(DLinkedList* list, void** data) {
    if (list->size == 0) return -1;

    Element* elem = list->head;

    if (list->size == 1) {
        list->head = list->tail = NULL;
    }

    if (list->size > 1) {
        list->head = list->head->next;
        list->head->prev = NULL;
    }

    *data = elem->data; free(elem);
    list->size--; return 0;
}

int dll_remove_tail(DLinkedList* list, void** data) {
    if (list->size == 0) return -1;

    Element* elem = list->tail;

    if (list->size == 1) {
        list->head = list->tail = NULL;
    }

    if (list->size > 1) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }

    *data = elem->data; free(elem);
    list->size--; return 0;
}

// int insert_element_next(DLinkedList* list, Element* selected, void* data);
// int insert_element_prev(DLinkedList* list, Element* selected, void* data);
// int remove_element_next(DLinkedList* list, Element* selected, void** data);
// int remove_element_prev(DLinkedList* list, Element* selected, void** data);