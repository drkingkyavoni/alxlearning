#include <stdio.h>

void main(){
    int a;

    while (a != 0){
        printf("Enter a number (0 to end): ");
        scanf("%d", &a);
        if (a % 2 == 0) printf("\n %d is an even number \n", a);
        else printf("\n %d is an odd number \n", a);
    }
}