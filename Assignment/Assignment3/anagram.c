#include <stdio.h>
#include <string.h>

void sortWord(char a[]){
    int i,j;
    int stringlength = strlen(a);
    char temp;
    for (i = 0; i < stringlength-1; ++i)
    {
        for (j = i+1; j < stringlength; ++j)
        {
                if (a[i] > a[j])
                {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                }
        }
    }
}
void removeSpaces(char a[])
{
    int i,j=0,stringLength = strlen(a);
    for( i = 0; i < stringLength; i++)
    {
        if (a[i] != ' ')
        {
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
}
void toLowerCase(char a[])
{
    int i,stringLength = strlen(a);
    for( i = 0; i < stringLength; i++){
        if ((a[i] >= 65) && (a[i] <= 90))
        {
            a[i] = a[i] + 32;
        }
    }
}


int main(int argc, char *argv[])
{
        char temp;
        int i,sum = 0;
        if(argc == 3)
        {
/* Store arrays in memore */
                char *a = argv[1];
                char *b = argv[2];
                removeSpaces(a);
                removeSpaces(b);
                toLowerCase(a);
                toLowerCase(b);
                sortWord(a);
                sortWord(b);
/* Find length of Strings */
                int stringlength1 = strlen(argv[1]);
                int stringlength2 = strlen(argv[2]);
/* Determine if both Strings are same size */
                if (stringlength1 == stringlength2)
                {
/* Loop to find if strings are anagrams */
                        for (i = 0; i < stringlength1; ++i)
                        {
                                if (argv[1][i] == argv[2][i])
                                {
                                        sum = sum + 1;
                                }
                        }
                        if (sum == stringlength1)
                        {
                                return 0;
                        }
                        else
                        {
                            return 1;
                        }
                }
                else
                {
                        return 1;
                }
        }
        else
        {
                return 1;
        }
}
