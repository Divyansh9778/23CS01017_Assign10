#include <stdio.h>
#include <string.h>

union EmpDetails
{
    double hourwage;
    float salary; // If bigger bit is stored before smaller, then both will be stored
};

struct Employee
{
    int ID;
    char name[20];
    union EmpDetails emp_det;
};

int main()
{
    struct Employee emp;

    emp.ID = 101;
    strcpy(emp.name, "Deborah Logan");

    emp.emp_det.salary = 25000.00;
    emp.emp_det.hourwage = 20.00; // Exchange these

    printf("Employee ID: %d\n", emp);
    printf("Employee Name: %s\n", emp.name);
    printf("Hourly Wage: %.2lf\n", emp.emp_det.hourwage);
    printf("Fixed Salary: %.2f\n", emp.emp_det.salary);

    return 0;
}