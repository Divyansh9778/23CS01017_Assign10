#include <stdio.h>
union Data
{
    int a;
    float b;
    char c;
};

int main()
{
    union Data data;

    data.a = 10;
    printf("Integer value: %d\n", data.a);

    data.b = 3.14;
    printf("Floating point value: %.2f\n", data.b);

    data.c = 'A';
    printf("Character value: %c\n", data.c);

    return 0;
}