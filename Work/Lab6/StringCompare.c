#include <stdio.h>
#include <stdlib.h>
#define Success 0;
#define Fail 1;

int stringCompare(char *ptr1, char *ptr2){
    while (*ptr1 == *ptr2){
        if (*ptr1 == '\0' || *ptr2 == '\0'){
        break;
        }
        ptr1++;
        ptr2++;
    }
    if (*ptr1 == '\0' && *ptr2 == '\0'){
        return Success;
    } else {
        return Fail;
    }
}

int main(){
    char *s = "Testing compare string";
    char *t = "Testing compare string";
    printf("%d\n", stringCompare(s, t));
}