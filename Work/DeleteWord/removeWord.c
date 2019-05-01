#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *t = fopen("file.txt", "rt");
    FILE *temp = fopen("copy.txt", "wt");
    if ((t==NULL) || (temp == NULL)){
        exit(1);
    }
    char* c = "Word";
    removeword(t,temp, c);
    fclose(t);
    system("rm file.txt; mv copy.txt file.txt");
}

void removeword(FILE *source, FILE *dest, char *word){
    char arr[1000];
    
    fgets(arr, 999, source);
    while(!feof(source)){
        int i = 0,size = strlen(word);
        // Read character by character from the array
        for (i = 0; i < strlen(arr); i++){
            // If the word looking for is in the array jump 4 slots
            if (wordPeep(word, &arr[i], size)){
                i+=size;
            }
            // Put into the file
            fputc(arr[i],dest);
        }
        fgets(arr, 999, source);
    }
}

// Check if the words are the same
int wordPeep(char* p, char *q, int length){
    int i = 0;
    for (i = 0; i < length; i++){
        if (*(q+i) != *(p+i)){
            return 0;
        }
    }
    return 1;
}