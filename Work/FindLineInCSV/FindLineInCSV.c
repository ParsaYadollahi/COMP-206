#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    findWord("testing.txt", "f");
    return 0;
}
void findWord(char *fileName, char *c){
    int count = -1,check;
    FILE *t = fopen(fileName, "rt");
    if (t == NULL){
        exit(1);
    }
    char arr[1000];
    fgets(arr, 999, t);
    while (!feof(t)){
        count++;
        if (strstr(arr, c) != 0){ //If word is in array
            printf("The word is at line %d\n", count);
            check++; //Check if the word is in the line
        }
        fgets(arr, 999, t);
    }
    if (check = 0){
        printf("Word not in the file\n");
        fclose(t);
    }
}