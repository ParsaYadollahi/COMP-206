#include <stdio.h>
#include <stdlib.h>

int buffer[100];
void add(int n);

int main(int argc, char* argv[]){
    int m = atoi(argv[1]);
    if (m <= 0 || m >= 100){
        printf("Invalid input\n");
        exit(1);
    }
    int i,x;
    for (i = 0; i < m; i++){
        printf("Input an integer\n");
        scanf("%d", &x);
        add(x);
    }
    for(i = 0; i < m; i++){
        printf("%d\t",buffer[i]);
    }
    printf("\n");
}
    void add(int x){
        int y = 0,i,j;
        while (buffer[y] != 0){ //Count size of array
            y++;
        }
        buffer[y] = x;
        // Bubble sort reversed
        for (i = 0; i <= y; i++){
            for (j = y; j >= 0; j--){
                if (buffer[j-1] > buffer[j]){
                    int temp = buffer[j-1];
                    buffer[j-1] = buffer[j];
                    buffer[j] = temp;
                }
            }
        }
}