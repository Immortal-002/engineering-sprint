#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_initialized = 100;
int global_uninitialized;

int main(void)
{
    static int static_initialized = 200;
    static int static_uninitialized;

    int local_variable = 10;

    int *heap_variable = malloc(sizeof(int));

    if (heap_variable == NULL)
        return 1;

    *heap_variable = 500;

    printf("PID: %d\n", getpid());

    printf("Global initialized: %p\n",
           (void *)&global_initialized);

    printf("Global uninitialized: %p\n",
           (void *)&global_uninitialized);

    printf("Static initialized: %p\n",
           (void *)&static_initialized);

    printf("Static uninitialized: %p\n",
           (void *)&static_uninitialized);

    printf("Local variable: %p\n",
           (void *)&local_variable);

    printf("Heap variable: %p\n",
           (void *)heap_variable);

    fflush(stdout);

    sleep(60);

    free(heap_variable);

    return 0;
}
