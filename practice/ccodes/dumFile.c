#include <stdio.h>

void main(){
    int size;
    FILE * in = fopen("C:\\Sources\\ccode\\input", "r");

    printf("\nAttempting to read file\n");
    printf("*****************\n");
    size = ftell(in);

    printf("Size of the file is %d kb\n", size);

    if (in != 0) printf("File does not exist\n");
    else {
        
        int count, num, sum = 0;
        float avg = 0.00;

        printf("File exists.\n");
        fscanf(in, "%d", &num);
        FILE * out = fopen("output", "w");
        
        while (num != 0) {
            count++;
            sum += num;
            fscanf(in, "%d", &num);
        }

        printf("Saving to output file\n");
        printf("*****************\n");

        fprintf(out, "Total count: %d", count);
        fprintf(out, "Total sum of numbers: %d", sum);
        fprintf(out, "Average sum of numbers: %.2f", avg);
        fclose(in);
        fclose(out);
    }
}