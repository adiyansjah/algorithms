#include <stdlib.h>

#include "unity/unity.h"
#include "list/linked_list_double.h"

void test_init_linked_list()
{
    DLinkedList *ll = (DLinkedList *)malloc(sizeof(DLinkedList));
    dll_init(ll);

    TEST_ASSERT_EQUAL_INT(0, ll->size);
    TEST_ASSERT_NULL(ll->head);
    TEST_ASSERT_NULL(ll->tail);
}

void test_insert_head()
{
    DLinkedList *dll = (DLinkedList *)malloc(sizeof(DLinkedList));
    dll_init(dll);

    int *value_1 = (int *)malloc(sizeof(int)); *value_1 = 10;    
    int *value_2 = (int *)malloc(sizeof(int)); *value_2 = 20;

    dll_insert_head(dll, value_1);

    TEST_ASSERT_EQUAL_INT(1, dll->size);
    TEST_ASSERT_NULL(dll->head->prev);
    TEST_ASSERT_NULL(dll->tail->next);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->head->data);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->tail->data);

    Element *prev_head = dll->head;

    dll_insert_head(dll, value_2);

    TEST_ASSERT_EQUAL_INT(2, dll->size);
    TEST_ASSERT_NULL(dll->head->prev);
    TEST_ASSERT_EQUAL_PTR(prev_head, dll->head->next);
    TEST_ASSERT_EQUAL_PTR(value_2, dll->head->data);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->tail->data);
}

void test_insert_tail()
{
    DLinkedList *dll = (DLinkedList *)malloc(sizeof(DLinkedList));

    dll_init(dll);

    int *value_1 = (int *)malloc(sizeof(int)); *value_1 = 10;    
    int *value_2 = (int *)malloc(sizeof(int)); *value_2 = 20;

    dll_insert_tail(dll, value_1);

    TEST_ASSERT_EQUAL_INT(1, dll->size);
    TEST_ASSERT_NULL(dll->head->prev);
    TEST_ASSERT_NULL(dll->tail->next);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->head->data);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->tail->data);

    Element *prev_tail = dll->tail;

    dll_insert_tail(dll, value_2);

    TEST_ASSERT_EQUAL_INT(2, dll->size);
    TEST_ASSERT_NULL(dll->head->prev);
    TEST_ASSERT_NULL(dll->tail->next);
    TEST_ASSERT_EQUAL_PTR(prev_tail, dll->head);
    TEST_ASSERT_EQUAL_PTR(prev_tail, dll->tail->prev);
    TEST_ASSERT_EQUAL_PTR(value_1, dll->head->data);
    TEST_ASSERT_EQUAL_PTR(value_2, dll->tail->data);
}


int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_init_linked_list);
    RUN_TEST(test_insert_head);
    RUN_TEST(test_insert_tail);
    return UNITY_END();
}