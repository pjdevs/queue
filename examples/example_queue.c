#include <queue/queue.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int values[] = {1, 2, 4};

    queue_t* queue = queue_init(10);

    printf("Pushing values %d and %d", values[0], values[1]);
    queue_push(queue, (const void*)&values[0]);
    queue_push(queue, (const void*)&values[1]);

    printf("Top is %d\n", *((int*)queue_top(queue)));
    printf("Pushing %d\n", values[2]);
    queue_push(queue, (const void*)&values[2]);
    printf("Size is %ld\n", queue_size(queue));
    printf("Poping all values...\n");
    
    while (!queue_is_empty(queue))
        queue_pop(queue);

    printf("Size is %ld\n", queue_size(queue));

    queue_free(queue);   

    return 0;
}