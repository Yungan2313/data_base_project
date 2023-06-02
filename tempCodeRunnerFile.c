#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *p;
    p = fopen("test.txt", "r");
    if (p == NULL)
    {
        printf("xxx!\n");
        return 0;
    }
}