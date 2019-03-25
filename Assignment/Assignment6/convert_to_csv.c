#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <convert_to_csv.h>

void load_and_convert(const char* filename) {
    int i,j, namec,cityc,agec;
    char array[1000];
    char *data;
    FILE *f = fopen(filename, "rt");
    FILE *output = fopen("output.txt", "wt");

    if (f == NULL) {
        exit(1);
    }

    char *names[1000];
    char *age[1000];
    char *city[1000];

    fgets(array, 999, f);
    while (!feof(f)) {

        data = strtok(array, " ");
        j = 0;
        if (i == 0){
            while (data != NULL) {
                names[j] = data;
                printf("%s\t", data);
                printf("%s", names[j]);
                printf("\n");
                j++;
                data = strtok(NULL, " ");
                namec++;
            }
        }
        // printf("gang %s\n", names[1]);
        j = 0;
        if (i == 1){
            while (data != NULL) {
                age[j] = data;
                // printf("%s\t", age[j]);

                j++;
                data = strtok(NULL, " ");
                // printf("\n");
                agec++; 
            }
        }
        j = 0;
        if (i == 2) {
            while (data != NULL) {
                city[j] = data;
                // printf("%s\t", city[j]);

                j++;
                data = strtok(NULL, " ");
                // printf("\n");
                cityc++;
            }
        }
        i++;
        fgets(array, 999, f);
    }
    if (namec != agec || agec != cityc || namec != cityc){
        printf("The input file is missing data\n");
    }

    // printf("%s\n", names[0]);

    for (i = 0; i < namec; i++){
        // fputs("hello", output);
        fputs(names[i], output);
        fputs(", ", output);
        fputs(age[i], output);
        fputs(", ", output);
        fputs(city[i], output);
        fputs("\n", output);
    }
    fclose(f);
    fclose(output);
}

int main() {
    load_and_convert("input.txt");
}