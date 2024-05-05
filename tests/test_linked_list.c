#include <stdlib.h>
#include "unity/unity.h"
#include "list/linked_list.h"

void test_init_linked_list() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    TEST_ASSERT_EQUAL_INT(0, ll->size);
    TEST_ASSERT_NULL(ll->head);
    TEST_ASSERT_NULL(ll->tail);
}

void test_insert_head() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;

    insert_head(ll, value_1);
    TEST_ASSERT_EQUAL_INT(1, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));

    insert_head(ll, value_2);
    TEST_ASSERT_EQUAL_INT(2, ll->size);
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));
}

void test_remove_head() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    TEST_ASSERT_EQUAL_INT(-1, remove_head(ll, NULL));

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;
    int *temp;

    insert_head(ll, value_1);
    insert_head(ll, value_2);

    remove_head(ll, (void**) &temp);
    TEST_ASSERT_EQUAL_INT(1, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));
    TEST_ASSERT_NOT_NULL(temp);
    TEST_ASSERT_EQUAL_INT(20, *temp);
    free(temp);

    remove_head(ll, (void**) &temp);
    TEST_ASSERT_EQUAL_INT(0, ll->size);
    TEST_ASSERT_NOT_NULL(temp);
    TEST_ASSERT_EQUAL_INT(10, *temp);
    free(temp);
}

void test_insert_tail() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;

    insert_tail(ll, value_1);
    TEST_ASSERT_EQUAL_INT(1, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));

    insert_tail(ll, value_2);
    TEST_ASSERT_EQUAL_INT(2, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->tail->data));
}

void test_insert_element_next() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;
    int *value_3 = (int*) malloc(sizeof(int)); *value_3 = 30;

    insert_element_next(ll, NULL, value_1);
    TEST_ASSERT_EQUAL_INT(1, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));

    insert_element_next(ll, ll->head, value_2);
    TEST_ASSERT_EQUAL_INT(2, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->head->next->data));
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->tail->data));

    insert_element_next(ll, ll->head, value_3);
    TEST_ASSERT_EQUAL_INT(3, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(30, *(int*)(ll->head->next->data));
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->head->next->next->data));
    TEST_ASSERT_EQUAL_INT(20, *(int*)(ll->tail->data));
}


void test_remove_element_next() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;
    int *value_3 = (int*) malloc(sizeof(int)); *value_3 = 30;

    insert_head(ll, value_1);
    insert_head(ll, value_2);
    insert_head(ll, value_3);

    Element *selected = ll->head;
    int* temp = NULL;

    remove_element_next(ll, selected, (void**) &temp);
    TEST_ASSERT_EQUAL_INT(2, ll->size);
    TEST_ASSERT_EQUAL_INT(30, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->tail->data));
    TEST_ASSERT_EQUAL_INT(20, *temp);

    free(temp);

    remove_element_next(ll, NULL, (void**) &temp);
    TEST_ASSERT_EQUAL_INT(1, ll->size);
    TEST_ASSERT_EQUAL_INT(10, *(int*)(ll->head->data));
    TEST_ASSERT_EQUAL_INT(30, *temp);
}

void test_free_linked_list() {
    LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
    init_linked_list(ll);

    int *value_1 = (int*) malloc(sizeof(int)); *value_1 = 10;
    int *value_2 = (int*) malloc(sizeof(int)); *value_2 = 20;
    int *value_3 = (int*) malloc(sizeof(int)); *value_3 = 30;

    insert_head(ll, value_1);
    insert_head(ll, value_2);
    insert_head(ll, value_3);

    free_linked_list(ll);
    TEST_ASSERT_EQUAL_INT(0, ll->size);
    TEST_ASSERT_NULL(ll->head);
    TEST_ASSERT_NULL(ll->tail);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_init_linked_list);
    RUN_TEST(test_insert_head);
    RUN_TEST(test_remove_head);
    RUN_TEST(test_insert_tail);
    RUN_TEST(test_insert_element_next);
    RUN_TEST(test_remove_element_next);
    RUN_TEST(test_free_linked_list);
    return UNITY_END();
}