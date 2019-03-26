#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <convert_to_csv.h>

void load_and_convert(const char* filename) {
    int i;
    char array[1000];
    char names[1000][1000];
    char age[1000][1000];
    char city[1000][1000];
    char* temp1;
    char* temp2;
    char* temp3;
    FILE *f = fopen(filename, "rt");
    FILE *output = fopen("output.txt", "wt");

    if (f == NULL) {
        exit(1);
    }

// Insert names into array
    fgets(array,999,f);
    insert_to_array(array, names);
// Insert ages into array
    fgets(array,999,f);
    insert_to_array(array, age);
// Insert city into array
    fgets(array,999,f);
    insert_to_array(array, city);

    while (i < 5){
        fputs(names[i], output);
        fputs(", ", output);
        fputs(age[i], output);
        fputs(", ", output);
        fputs(city[i], output);
        fputs("\n", output);
        i++;
    }

    fclose(f);
    fclose(output);
}

void insert_to_array(char array[1000], char words[1000][1000]){
    int i=0,j=0,cnt=0;

    for (i = 0; i < strlen(array); i++){
        if (array[i] == ' ' || array[i] == '\0\n'){
            words[cnt][j] = '\0';
            cnt++;
            j = 0;
        } else {
            words[cnt][j] = array[i];
            j++;
        }
    }
}

int main() {
    load_and_convert("input.txt");
}