#include <stdio.h>
#include <stdlib.h>

int arr[100];

int main(){
    int i,j;
    for (i = 0; i < 100; i++){
        arr[i] = (rand()%100);
    }
    int x,pid;
    printf("What Integer are you looking for?\n");
    scanf("%d", &x);
    pid = fork();
    if (pid == 0){
        for (i = 0; i < 50; i++){
            if (arr[i] == x){
                printf("Child\n");
                // printf("Integer is in the second half of the Array\n");
                printf("%d: In the array\n",arr[i]);
                exit(0);
                return;
            }
        }
    } else {
        for (j = 50; j < 100; j++){
            if (arr[j] == x){
                printf("Parent\n");
                // printf("Integer is in the first part of the Array\n");
                printf("%d: In the array\n",arr[j]);
                exit(0);
                return;
            }
        }
    }
    printf("TEST\n");
}