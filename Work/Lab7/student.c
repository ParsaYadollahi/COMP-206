#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct STUDENT_RECORD {
    char name[50];
    int age;
    float gpa;
};

int main(){
    struct STUDENT_RECORD student;
    struct STUDENT_RECORD students[10];
    struct STUDENT_RECORD *s = (struct STUDENT_RECORD *) malloc(sizeof(struct STUDENT_RECORD));

        student.name[0] = 'M';
        student.name[1] = 'a';
        student.name[2] = 'r';
        student.name[3] = 'y';
        student.age = 18;
        student.gpa = 3.8;
        s->age = 20;
        s->name[0] = "J";
        s->name[1] = "T";
        s->gpa = 2.8;
        students[0].age = 32;
        printf("%d\n", s->age);
        printf("%d\n", students[0].age);
}