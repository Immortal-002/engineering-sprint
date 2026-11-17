#include <stdio.h>
#include "math_utils.h"
#include "config.h"
int main(void)
{
    int a = 50;
    int b = 20;
    request_count++;
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));

    return 0;
}
