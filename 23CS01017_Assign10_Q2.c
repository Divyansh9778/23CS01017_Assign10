#include <stdio.h>
#include <string.h>
struct StructPerson
{
    char name1[20];
    int dob1;
    int age1;
};
union UnionPerson
{
    char name2[20];
    int dob2;
    int age2;
};

int main()
{
    struct StructPerson person1;
    union UnionPerson person2;

    strcpy(person1.name1, "John Doe");
    person1.dob1 = 31998;
    person1.age1 = 30;
    printf("Name_1: %s\nDOB_1: %d\nAge_1: %d\n", person1.name1, person1.dob1, person1.age1);

    strcpy(person2.name2, "Jane Doe");
    printf("Name_2: %s\n", person2.name2);
    person2.dob2 = 31999;
    printf("DOB_2: %d\n", person2.dob2);
    person2.age2 = 31;
    printf("Age_2: %d\n", person2.age2);

    printf("Size of Struct: %zu bytes\n", sizeof(person1));
    printf("Size of Union: %zu bytes\n", sizeof(person2));
    return 0;
}