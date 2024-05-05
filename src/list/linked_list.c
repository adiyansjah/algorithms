#include <stdlib.h>

#include "list/linked_list.h"


/**
 * Initializes an empty LinkedList.
 *
 * @param list The LinkedList to initialize.
 */
void init_linked_list(LinkedList* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

/**
 * Inserts a new element at the head of the LinkedList.
 *
 * @param list The LinkedList to insert into.
 * @param data The data to insert.
 * @return 0 on success, -1 on failure.
 */
int insert_head(LinkedList* list, void* data) {
    Element* element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return -1;

    element->data = data;
    element->next = list->head;

    list->head = element;

    if (list->tail == NULL) {
        list->tail = element;
    }

    list->size++; return 0;
}

/**
 * Removes the first element of the LinkedList and stores its data in the
 * provided pointer.
 *
 * @param list The LinkedList to remove from.
 * @param data A pointer to store the removed data into.
 * @return 0 on success, -1 when the list is empty.
 */
int remove_head(LinkedList* list, void** data) {
    if (list->size == 0) return -1;

    Element* temp = list->head;

    if (list->size == 1) {
        list->head = list->tail = NULL;
    }

    if (list->size > 1) {
        list->head = list->head->next;
    }

    *data = temp->data; free(temp);
    list->size--; return 0;
}

/**
 * Inserts a new element at the tail of the LinkedList.
 *
 * @param list The LinkedList to insert into.
 * @param data The data to insert.
 * @return 0 on success, -1 on failure.
 */
int insert_tail(LinkedList* list, void* data) {
    Element* element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return -1;

    element->data = data;
    element->next = NULL;

    if (list->size != 0) {
        list->tail->next = element;
    }

    if (list->size == 0) {
        list-> head = element;
    }

    list->tail = element;
    list->size++; return 0;
}

/**
 * Inserts a new element after the specified element.
 *
 * @param list The LinkedList to insert into.
 * @param selected The element to insert after.
 * @param data The data to insert.
 * @return 0 on success, -1 on failure.
 */
int insert_element_next(LinkedList* list, Element* selected, void* data) {
    if (list->size == 0 || selected == NULL) {
        return insert_head(list, data);
    }
    
    Element* element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return -1;
    
    element->data = data;
    element->next = selected->next;

    selected->next = element;

    if (list->tail == selected) {
        list->tail = element;
    }

    list->size++; return 0;
}


/**
 * Removes the element after the specified element and stores its data in
 * the provided pointer.
 *
 * @param list The LinkedList to remove from.
 * @param selected The element to remove after.
 * @param data A pointer to store the removed data into.
 * @return 0 on success, -1 when the selected element is NULL or there is no
 *         next element.
 */
int remove_element_next(LinkedList* list, Element* selected, void** data) {
    if (list->size == 0) return -1;
    if (selected != NULL && selected->next == NULL) return - 1;

    if (selected == NULL) {
        return remove_head(list, data);
    }
    
    Element* temp = selected->next;
    selected->next = temp->next;
    
    *data = temp->data; free(temp);
    list->size--; return 0;
}


/**
 * Frees all the memory used by the LinkedList. The data in each element is
 * also freed.
 *
 * @param list The LinkedList to free.
 */
void free_linked_list(LinkedList* list) {
    void* data;
    while(list->size != 0) {
        remove_head(list, data); free(data);
    }
}
