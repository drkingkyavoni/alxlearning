#include <stdio.h>

#define taxLimit1 15000.00
#define taxLimit2 35000.00

#define taxVal1 .10
#define taxVal2 .20
#define taxVal3 .25

void main(){
    float grossSalary, taxableIncome, taxAmount;
    printf("\nThis is a tax calculator");
    printf("\n-----------------\n");
    printf("\nType in your gross salary (USD): ");
    scanf("%f", &grossSalary);

    taxableIncome = 0.8*grossSalary;
    if (taxableIncome < taxLimit1) taxAmount = taxVal1*taxableIncome;
    else if (taxLimit1 >= taxableIncome && taxableIncome < taxLimit1) taxAmount = taxVal2*(taxableIncome-taxLimit1) + taxVal1*taxLimit1;
    else taxAmount = taxVal3*(taxableIncome-taxLimit2) + taxVal2*(taxLimit2-taxLimit1) + taxVal1*taxLimit1;

    printf("\nYour gross salary is USD %.2f", grossSalary);
    printf("\nYour total tax is USD %.2f", taxAmount);
    printf("\nYour average tax is %.2f percent", taxAmount*100/grossSalary);
}