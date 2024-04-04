#include <stdio.h>
#include <string.h>

enum Paytype
{
    Hourly,
    Salary
};

union EmpDetails
{
    double hourwage;
    float salary;
};

struct Employee
{
    int ID;
    char name[20];
    union EmpDetails emp_det;
    enum Paytype paytype;
};

int main()
{
    struct Employee emp[2];
    char paytype_str[10];

    for (int i = 0; i < 2; i++)
    {
        emp[i].ID = 101 + i;
        printf("Enter Paytype (Hourly or Salary): ");
        scanf("%s", paytype_str);
        if (strcmp(paytype_str, "Hourly") == 0)
        {
            emp[i].paytype = Hourly;
            printf("Enter Name & Hourly Wage: ");
            scanf("%s %lf", emp[i].name, &emp[i].emp_det.hourwage);
        }
        else
        {
            emp[i].paytype = Salary;
            printf("Enter Name & Salary: ");
            scanf("%s %f", emp[i].name, &emp[i].emp_det.salary);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Pay Type: %s\n", emp[i].paytype == Hourly ? "HOURLY" : "SALARY");
        printf("Employee ID: %d\n", emp[i].ID);
        printf("Employee Name: %s\n", emp[i].name);

        if (emp[i].paytype == Hourly)
            printf("Hourly Wage: $%.2f\n", emp[i].emp_det.hourwage);
        else
            printf("Salary: $%.2f\n", emp[i].emp_det.salary);
        printf("\n");
    }
    return 0;
}