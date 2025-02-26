#include <iostream>

int main()
{
    int val = 10;
    char * ptr = (char *)&val;

    for(int i=0; i < sizeof(int); ++i) 
    {
        printf("%d ", *ptr++);
    }

    printf("\n");

    return 0;
}
