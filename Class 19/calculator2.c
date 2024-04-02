/* CALCULATOR PROGRAM BROKEN UP INTO 3 FUNCTIONS
   (get_input, parse_input, execute_operation)   */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INPUT 256

void get_input(void);
void parse_input(unsigned int *, char [], char [], unsigned int *);
double execute_operation(char, double, double);

void main() {
    printf("\nTo use this calculator, enter any expression without spaces");
    printf("\nAn expression may include the operators:");
    printf("\n           +, -, *, /, %%, or ^(raise to a power).");
    printf("\nUse = at the beginning of a line to operate on ");
    printf("\nthe result of the previous calculation.");
    printf("\nUse quit by itself to stop the calculator.\n\n");

    get_input();
}

void get_input() {
    char input[MAX_INPUT];
    char number_string[30];
    char op = 0;

    unsigned int index = 0;
    unsigned int to = 0;
    size_t input_length = 0;
    unsigned int number_length = 0;
    double result = 0.0;
    double number = 0.0;

    /* The main calculator loop */
    while (strcmp(fgets(input, MAX_INPUT-1, stdin), "quit\n") != 0) {
        input_length = strlen(input)-1;
        *(input+input_length) = '\0';
        index = 0;
        if (input[index]== '=')
            { index++; }
        else {
            parse_input(&number_length, input, number_string, &index);

            if (number_length>0)
            { result = atof(number_string); }
        }

        /* Now look for 'op number' combinations */
        while (index < input_length) { 
            op = *(input+index++);
            parse_input(&number_length, input, number_string, &index);

            number = atof(number_string);

            result = execute_operation(op, result, number);
        }
        /* Output the result */
        printf("= %f\n", result);
    }
}

void parse_input(unsigned int *number_length, char input[], char number_string[], unsigned int *index) {
    unsigned int num_length;
    unsigned int i;
    i = *index;

    /* Initialize length      */
    num_length = 0;
    if (input[i]=='+' || input[i]=='-')
    { *(number_string+num_length++) = *(input+i++); }

    /* Copy all following digits */
    for ( ; isdigit(*(input+i)) ; i++)
    { *(number_string+num_length++) = *(input+i); }

    /* Copy any fractional part */
    if (*(input+i)=='.') {
        *(number_string+num_length++) = *(input+i++);
        for ( ; isdigit(*(input+i)) ; i++)
        { *(number_string+num_length++) = *(input+i); }
    }
    *(number_string+num_length) = '\0';
    *number_length = num_length;
    *index = i;
}

double execute_operation(char op, double result, double number) {
    /* Execute operation, as 'result op= number' */
    switch (op) {
        case '+':
            result += number;
            break;
        case '-':
            result -= number;
            break;
        case '*':
            result *= number;
            break;
        case '/':
            /* Check second operand for zero */
            if (number == 0)
            { printf("\n\n\aDivision by zero error!\n"); }
            else
            { result /= number; }
            break;
        case '%':
            /* Check second operand for zero */
            if ((long)number == 0)
            { printf("\n\n\aDivision by zero error!\n"); }
            else
            { result = (double)((long)result % (long)number); }
            break;
        case '^':
            result = pow(result, number);
            break;
        default:
            printf("\n\n\a'%c'Illegal operation!\n", op);
    }
    return(result);
}