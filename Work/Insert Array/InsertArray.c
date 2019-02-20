#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100],i,n, insert, index;
    puts("Write the size of an Array: ");
    scanf("%d", &n);
    
    puts("Enter the elements: ");
    for(i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }  

    puts("Your current Array is: ");
    printf("[ ");
    for( i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("]");

    puts("What element would you like to insert: ");
    scanf("%d", &insert);

    puts("What position would you like to insert?: ");
    scanf("%d", &index);

    for (i=n-1; i>= index-1; i--){
        arr[i+1] = arr[i];
    }
    arr[index-1] = insert;

    puts("The array is then: ");
    printf("%s", "[ ");
    for (i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    }
    puts("]");

    return EXIT_SUCCESS;
}