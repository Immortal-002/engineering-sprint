#include "stats.h"

int total_requests = 0;

static int module_private = 0;

int record_request(void)
{
    static int call_count = 0;

    call_count++;
    total_requests++;
    module_private++;

    return call_count;
}
