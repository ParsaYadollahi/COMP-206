#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows 5
#define cols 5
#define randomInt rand()%100+1

void fillMatrix(int matrix[rows][cols]);
void printMatrix(int matrix[rows][cols]);
void transposeMatrix(int matrix[rows][cols]);
void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]);

int main(void)
{
    int matrix[rows][cols];
    fillMatrix(matrix); // Q1
    printMatrix(matrix); // Q2
    transposeMatrix(matrix); // Q3
    printMatrix(matrix);
    int matrix2[2][cols]={{0,1,2,3,4},{5,6,7,8,9}};
    int matrixResult[rows][cols];
    multiplyMatrix(matrix2, matrix, matrixResult); // Q4
    printMatrix(matrixResult);
    return 0;
}

void fillMatrix(int matrix[rows][cols])
{
    int i,j;
    srand(time(0));
    for(i = 0; i < rows; i++)
    {
        for (j = 0 ; j < cols; j++)
        {
            matrix[i][j] = randomInt;
        }
    }
}

void printMatrix(int matrix[rows][cols])
{
    int i,j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
            if (j == 4)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}

void transposeMatrix(int matrix[rows][cols]){
    int i,j,pointer;
    int *temp1,*temp2;
    for ( i = 0 ; i < cols ; i++)
    {
        for ( j = i; j < rows; j++)
        {
            temp1 = &matrix[i][j];
            temp2 = &matrix[j][i];
            pointer = *temp1;
            *temp1 = *temp2;
            *temp2 = pointer;
        }
    }
}

void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols])
{
    int i, j, k;
    int *p1, *p2, *p3;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i >= 2) {
                resultMatrix[i][j] = 0;
            } else {
                *p3 = 0;
                for (k = 0; k < cols; k++) {
                    p1 = &m1[i][k];
                    p2 = &m2[k][j];
                    
                    *p3 += *p1 * *p2;
                }
                resultMatrix[i][j] = *p3;
            }
        }
    }
}
