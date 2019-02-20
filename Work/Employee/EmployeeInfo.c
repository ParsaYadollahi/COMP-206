#include <stdio.h>

int main(void)
{
    int id, salary, hours;
    double totSalary;

    puts("Input Employee ID: ");
    scanf("%d", &id);
    puts("Input the working hours: ");
    scanf("%d", &hours);
    puts("Salary/hour: ");
    scanf("%d", &salary);

    totSalary = (salary*hours)*30;

    printf("The Total Salary per month for Employee %d is %.2lf\n", id,totSalary);
    return 0;
}