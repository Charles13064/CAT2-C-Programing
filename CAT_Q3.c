/*
Name: Odanga Charles Muhanji
Reg No: PA106//G/28735/25
Description: A c program that You are required to develop a C program that reads a list of integers from a file, processes the integers, and writes the results to a different file. The program should perform the following tasks:
            1. Has function that prompts the user to input 10 integers and stores them in a file named "input.txt". 
            2. Write a function that reads the integers from "input.txt" and calculates the sum and average oF Flag the numbers. Then, write the sum and average to another file named "output.txt". 
            3. Write a function that reads and displays the contents of both "input.txt" and "output.txt" in a formatted manner. 
            4. Ensure appropriate error handling when opening, reading, or writing to files. 


#include <stdio.h>

//function that prompts the user to enter 10 integer;
int integer_func()
{   
    
    //Declaration of File name in a pointer where the interegers are to be stored
    FILE* Location;

    //Location pointer will be contain the path of the location of input.txt file
    Location = fopen("C:\\Users\\Administrator\\Desktop\\input.txt", "a");
    
    //Display of Error massage when error arises while opening the file 
    if (Location == NULL)
    {
        printf("Opps❗Error opening the file!");
    }

    //Declaration of the array which will store the integers entered by the user!
    int integers_array[10] = {0};

     
    for (int i = 0; i < 10 ; i++)
    {
        //Prompting the user to enter the 10 integers
        printf("Enter the integer: ");
        scanf("%d",integers_array[i] );
        

    }
    fprintf(Location,"%d",integers_array);   
    
    
    //Closing the file.
    fclose(Location);
    
}

//Main function
int main()
{
    integer_func();
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

//A macro having the input file
#define INPUT_FILE "input.txt"
//A macro having the output file
#define OUTPUT_FILE "output.txt"
//A macro having the number of integers
#define NUM_INTEGERS 10

// FUnction that prompts user for 10 integers and write to input.txt
void writeInputFile() {

    //Declaration of File name in a pointer where the interegers are to be stored
    FILE *fp = fopen(INPUT_FILE, "w");
    //Display of Error massage when error arises while opening the file 
    if (fp == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
}

    int num;
    printf("Enter %d integers:\n", NUM_INTEGERS);
    for (int i = 0; i < NUM_INTEGERS; i++) {
        printf("Integer %d: ", i + 1);
        if (scanf("%d", &num)!= 1) {
            printf("Invalid input. Exiting.\n");
            fclose(fp);
            exit(EXIT_FAILURE);
}
        fprintf(fp, "%d\n", num);
}

    fclose(fp);
}

//Function to Read integers from input.txt, calculate sum and average, write to output.txt
void processInputFile() {
    FILE *fp_in = fopen(INPUT_FILE, "r");
    // To Ensure appropriate error handling when opening fp_in files.
    if (fp_in == NULL) {
        
        perror("Error opening input file");
        exit(EXIT_FAILURE);
}

    FILE *fp_out = fopen(OUTPUT_FILE, "w");
    //Display of Error massage when error arises while opening the file 
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp_in);
        exit(EXIT_FAILURE);
}

    int num, sum = 0, count = 0;
    while (fscanf(fp_in, "%d", &num) == 1) {
        //To find the total of the integers
        sum += num;
        count++;
}
    //To ensure appropriate error handling when reading fp_out

    if (count == 0) {
        fprintf(fp_out, "No data to process.\n");
} else {
        //To find the avarage of the ten integers
        double average = (double)sum / count;
        fprintf(fp_out, "Sum: %d\nAverage: %.2f\n", sum, average);
}

    //Ensure appropriate Correct closing of the files to files; fp_in and  fp_out
    fclose(fp_in);
    fclose(fp_out);
}

// Function to  Display contents of both files
void displayFiles() {
    FILE *fp_in = fopen(INPUT_FILE, "r");
    FILE *fp_out = fopen(OUTPUT_FILE, "r");

    //Display of Error massage when error arises while opening the fp_in and fp_out files
    if (fp_in == NULL || fp_out == NULL) {
        perror("Error opening files for display");
        if (fp_in) fclose(fp_in);
        if (fp_out) fclose(fp_out);
        exit(EXIT_FAILURE);
}

    printf("\nContents of %s:\n", INPUT_FILE);
    int num;
    int i = 1;
    //To out put the integers input by the user from fp_in file
    while (fscanf(fp_in, "%d", &num) == 1) {
        printf("Integer %d: %d\n", i++, num);
}

    printf("\nContents of %s:\n", OUTPUT_FILE);
    char ch;

    //For printing all the information in the fp_out file
    while ((ch = fgetc(fp_out)) != EOF) {
        putchar(ch);
}

    //Ensure appropriate Correct closing of the files to files; fp_in and  fp_out
    fclose(fp_in);
    fclose(fp_out);
}

int main() {
    //Calling of the all the functions
    writeInputFile();
    processInputFile();
    displayFiles();
    return 0;
}

