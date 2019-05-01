#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    char *p = argv[1];
    int a = 0,b = 0,c = 0,d = 0,e = 0;
    char t;
    FILE *f = fopen(p, "rt");
    FILE *output = fopen("output.txt", "wt");
    if (f == NULL){
        exit(1);
    }
    t = fgetc(f);
    while(!feof(f)){
        a++;
        if (isalpha(t)){
            b++;
        } else if (isdigit(t)){
            c++;
        } else if (ispunct(t)){
            d++;
        } if (t == '.' || t == '?' || t == '!'){
            e++;
        }
        t = fgetc(f);
    }
    fprintf(output, "Number of characters: %d\n", a);
    fprintf(output, "Number of letters: %d\n", b);
    fprintf(output, "Number of digits: %d\n", c);
    fprintf(output, "Number of symbols: %d\n", d);
    fprintf(output, "Number of sentences: %d\n", e);

}