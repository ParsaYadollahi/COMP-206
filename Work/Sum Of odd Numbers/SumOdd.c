#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, numbers[5], sum;
    puts("First number: ");
    scanf("%d", &numbers[0]);
    puts("Second number: ");
    scanf("%d", &numbers[1]);
    puts("Third number: ");
    scanf("%d", &numbers[2]);
    puts("Fourth number: ");
    scanf("%d", &numbers[3]);
    puts("Fifth number: ");
    scanf("%d", &numbers[4]);

    for( i = 0; i < 5; i++)
    {
        if (numbers[i]%2 != 0)
        {
            sum+=numbers[i];
        }
    }
    printf("%d\n", sum);
    return EXIT_SUCCESS;
}