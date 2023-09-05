#include <stdio.h>

void main(){
    int c = ' ';
    printf("Enter a char [Type 'x' to end]: ");
    
    while (c != 'x'){  
        c = getc(stdin);
        putchar(c);
    }
}