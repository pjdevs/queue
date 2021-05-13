#include <queue/queue.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned nb_test_passed = 0;
static unsigned nb_test_count = 0;

void test_case(const char *msg, int (*test_func)())
{
    int passed = test_func();

    printf("%s...%s\033[39m\n", msg, passed ? "\033[32mPASSED" : "\033[31mFAILED");

    if (passed)
        ++nb_test_passed;
    ++nb_test_count;
}

void test_print_total()
{
	printf("\033[32mPASSED (%d/%d)\033[39m \033[31mFAILED (%d/%d)\033[39m\n",
		nb_test_passed, nb_test_count,
		nb_test_count - nb_test_passed, nb_test_count);
}

int test_queue_init()
{
    int passed = 1;

    queue_t* q = queue_init(10);

    if (queue_size(q) != 0)
        passed = 0;

    if (!queue_is_empty(q))
        passed = 0;

    queue_free(q);

    return passed;
}

int test_queue_push_capacity()
{
    int passed = 1;

    int e1 = 2;
    int e2 = 12;

    queue_t* q = queue_init(1);
    
    if (!queue_push(q, (const void*)&e1))
        passed = 0;

    if (!queue_push(q, (const void*)&e2))
        passed = 0;

    if (queue_top(q) != (const void*)&e1)
        passed = 0;

    if (!queue_pop(q))
        passed = 0;

    if (queue_top(q) != (const void*)&e2)
        passed = 0;

    queue_free(q);

    return passed;
}

int test_pop_double_capacity_till_empty()
{
    int passed = 1;

    int a = 1, b = 2, c = 3;
    queue_t* q = queue_init(2);

    queue_push(q, (const void*)&a);
    queue_push(q, (const void*)&b);
    queue_push(q, (const void*)&c);

    if (!queue_pop(q))
        passed = 0;

    if (!queue_pop(q))
        passed = 0;

    if (!queue_pop(q))
        passed = 0;

    if (!queue_is_empty(q))
        passed = 0;

    queue_free(q);

    return passed;
}

int test_queue_is_empty()
{
    int passed = 1;

    int a = 1;
    queue_t* q = queue_init(2);

    if (!queue_is_empty(q))
        passed = 0;

    queue_push(q, (const void*)&a);

    if (queue_is_empty(q))
        passed = 0;

    queue_free(q);

    return passed;
}

int test_queue_top()
{
    int passed = 1;

    int a = 12;
    queue_t* q = queue_init(2);

    if (queue_top(q) != NULL)
        passed = 0;

    queue_push(q, (const void*)&a);

    if (queue_top(q) != (const void*)&a)
        passed = 0;

    queue_free(q);

    return passed;
}

int test_queue_resize()
{
    int passed = 1;

    int a, b, c;
    queue_t* q = queue_init(2);

    if (!queue_is_empty(q))
        passed = 0;

    queue_push(q, (const void*)&a);
    queue_push(q, (const void*)&b);
    queue_push(q, (const void*)&c);

    queue_resize(q, 2);

    if (queue_size(q) != 2)
        passed = 0;

    queue_free(q);

    return passed;
}

int main()
{
    test_case("queue_init returns a valid and empty queue", test_queue_init);
    test_case("queue_push more elements than capacity in right order", test_queue_push_capacity);
    test_case("queue_pop until half capacity and until empty queue", test_pop_double_capacity_till_empty);
    test_case("queue_is_empty returns a correct value for empty and non empty queue", test_queue_is_empty);
    test_case("queue_top returns good adresses and NULL when empty", test_queue_top);
    test_case("queue_resize resizes the size of queue", test_queue_resize);

    test_print_total();

    return nb_test_passed == nb_test_count ? EXIT_SUCCESS : EXIT_FAILURE;
}

