#include <stdio.h>
#include "math_utils.h"
#include "config.h"
#include "stats.h"


int main(void)

{
    for (int i = 0; i < 3; i++)
    {
        int calls = record_request();

        printf("Calls: %d | Requests: %d\n",
               calls, total_requests);
    }

    int a = 50;
    int b = 20;
    request_count++;
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));

    return 0;
}
