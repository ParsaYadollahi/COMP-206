#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *t = fopen("file.txt", "rt");
    FILE *temp = fopen("copy.txt", "wt");
    if ((t==NULL) || (temp == NULL)){
        exit(1);
    }
    char* c = "SMALL";
    removeword(t,temp, c);
    fclose(t);
}

void removeword(FILE *source, FILE *dest, char *word){
    char arr[1000];
    
    fgets(arr, 999, source);
    while(!feof(source)){
        int i = 0,z = strlen(word);
        for (i = 0; i < strlen(arr); i++){
            if (wordPeep(word, &arr[i], z)){
                i+=z;
            }
            fputc(arr[i],dest);
        }
        fgets(arr, 999, source);
    }
}

int wordPeep(char* p, char *q, int length){
    int i = 0;
    for (i = 0; i < length; i++){
        if (*(q+i) != *(p+i)){
            return 0;
        }
    }
    return 1;
}