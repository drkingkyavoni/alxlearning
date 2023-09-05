#include <stdio.h>
#include <stdarg.h>

int add(int, ...);

void main(){
	printf("\n Sum of add(2,2,3) is %d \n", add(2,2,3));
	printf("\n Sum of add(3,3,8,5) is %d \n", add(3,3,8,5));
    printf("\n Sum of add(2,13,2) is %d \n", add(2,13,2));
}

int add(int numOfArgs, ...){
	va_list argList;
	va_start(argList, numOfArgs);
	
	int iCounter, sum = 0;
 
	for (iCounter=0; iCounter < numOfArgs; iCounter++){
        sum += va_arg(argList, int);
	}
	
	va_end(argList);
    return sum;
}