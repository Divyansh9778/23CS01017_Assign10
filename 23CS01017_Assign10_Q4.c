#include <stdio.h>

typedef union
{
    int intArray[3];
    float floatArray[3];
    char charArray[3];
} ArrayUnion;

int main()
{
    ArrayUnion unionArray;
    for (int i = 0; i < 3; i++)
        unionArray.intArray[i] = i;

    printf("Integer Array: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", unionArray.intArray[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        unionArray.floatArray[i] = i * 1.0;

    printf("Float Array: ");
    for (int i = 0; i < 3; i++)
        printf("%.2f ", unionArray.floatArray[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        unionArray.charArray[i] = 'A' + i;

    printf("Character Array: ");
    for (int i = 0; i < 3; i++)
        printf("%c ", unionArray.charArray[i]);
    printf("\n");

    return 0;
}