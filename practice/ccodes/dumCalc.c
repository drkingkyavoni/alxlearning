#include <stdio.h>

void main(){
    int a,b;

    printf("enter the first number: ");
    scanf("%d", &a);
    printf("enter the second number: ");
    scanf("%d", &b);

    printf("The product of %d and %d is %d\n", a,b, a*b);
    printf("%d + %d = %d \n", a, b, a+b);
    printf("%d - %d = %d \n", a, b, a-b);
    printf("%d x %d = %d \n", a, b, a*b);
}