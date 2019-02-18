#include <stdio.h>

int main(void)
{
    double w1, i1,w2, i2, NumbItems, avg;
    puts("Weight if item 1");
    scanf("%lf", &w1);
    puts("Number of item 1");
    scanf("%lf", &i1);

    puts("Weight of item 2");
    scanf("%lf", &w2);
    puts("Number of item 2");  
    scanf("%lf", &i2);

    NumbItems = i1+i2;
    avg = (w1*i1)+(w2*i2)/NumbItems;
    printf("%f\n", avg);
    return 0;
}