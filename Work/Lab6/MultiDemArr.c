#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    int j;
    int arr[3][2];
    for (; i < 3; i++){
        for (j = 0; j < 2; j++){
            printf("Enter a value for element [%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            printf("%d\t", *(*(arr+i)+j));
        } printf("\n");
    }
}