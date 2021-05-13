#include <queue/queue.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    queue_t* q = queue_init(10);
    const void* p = 0;

    for (size_t i=0; i<100000000; ++i)
    {
        queue_push(q, p);
        queue_push(q, p);
        queue_top(q);
        queue_size(q);
        queue_pop(q);
        queue_is_empty(q);
    }

    queue_free(q);

    return 0;
}