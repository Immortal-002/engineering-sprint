#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Hello from a process!\n");
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());

    fflush(stdout);

    sleep(20);

    return 0;
}
