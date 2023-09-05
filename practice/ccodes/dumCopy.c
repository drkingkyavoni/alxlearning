#include <string.h>
#include <stdio.h>

void main(){
    char name[50];
    //strcpy(name, "Alice in Wonderland");
    printf("\nEnter your name: ");
    gets(name);
    printf("Hello, %s\n", name);
}