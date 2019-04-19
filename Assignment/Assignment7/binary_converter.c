#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int n);

int main(){
    int a;
    char *data = getenv("QUERY_STRING");
    sscanf(data, "decimal=%d", &a);

    printf("Content-Type:text/html\n\n");
    printf("<html>");
    printf("<head><title>Binary Converter</title></head>");

    printf("Your number in binary is:\t");
    convertToBinary(a);

    printf("</html>");
    return 0;
}

void convertToBinary(int n){
    int* arr = (int*)malloc(100*sizeof(int));
    int j,k,i = 0;
    if (n == 0){
	    printf("0");
    } else if (n < 0) {
	    printf("Can't change negative number into binary");
    } else {
    	while (n > 0){
       	 arr[i] = n%2;
      	  n = n/2;
     	   i++;
   	 }
 	   k = i;
	    i--;
	    for (j = 0; j < k; j++){
	        printf("%d\t", arr[i]);
	        i--;
	    }
 	   printf("\n");
	}
}
