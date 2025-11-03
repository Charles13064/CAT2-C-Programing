/*
Name: Odanga Charles Muhanji
Reg No: PA106//G/28735/25
Description: A c program that requests the user to enter hours worked and the hourly wage. The program should then print the gross pay, the taxes, and the net pay. Assume teh following
    1. Overtime(in excess of 40 hours for a week) = 1.5 x normal_pay
    2. Tax rate 15% of the first $600, 20% of the rest.
*/


#include <stdio.h>
//A macro having the tax rate value 15%
#define TAXRATE1 0.15
//A macro having the tax rate value 20%
#define TAXRATE2 0.20
int main()
{   
    //Definition of hours_worked variable
    int hours_worked;
    //Definition of hourly wage variable
    int hourly_wage;
    
    //Decalrion and initialization of the normal pay
    float normal_pay = 1000;

    float tax, gross_pay , net_pay;

    //Prompting the user to enter hours worked and to storing the input in the hours_worked variable
    printf("Enter hours worked in the week: \t");
    scanf("%d", &hours_worked);

    //Prompting the user to enter hourly wage and to storing the input in the hourly_wage variable
    printf("Enter hourly wage: \t");
    scanf("%d", &hourly_wage);

    if (hours_worked > 40)
    {
        float overtime = 1.5  * normal_pay;
        float new_normal_pay=overtime + normal_pay;
        
        
        //For the first $600, tax is 15%
        if (new_normal_pay > 0 && new_normal_pay <= 600 )
        {
            tax = new_normal_pay * TAXRATE1;
            gross_pay = new_normal_pay + tax;
            net_pay = gross_pay - tax;
            printf("Your gross pay is $ %.2f , tax is $ %.2f , net pay is $ %.2f ,",net_pay, tax, net_pay  );

        }

        //Above $600 tax is 20%
        else if (new_normal_pay > 600)
        {

            tax = 600 + new_normal_pay * TAXRATE2;
            gross_pay = new_normal_pay + tax;
            net_pay = gross_pay - tax;
            
            printf("Your gross pay is $ %.2f , tax is $ %.2f , net pay is $ %.2f ,",net_pay, tax, net_pay  );

            
        }  
            
    }
    
    return 0;
}