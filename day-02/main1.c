#include <stdio.h>
#include "stats.h"

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        int calls = record_request();

        printf("Calls: %d | Requests: %d\n",
               calls, total_requests);
    }

    return 0;
}
