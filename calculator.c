Program1: write a program for sum, subtraction, multiplication, division of two numbers using functions and the user input has to be only integer if character is provided program has to again ask to enter the integer value only in c

Certainly! Program that performs sum, subtraction, multiplication, and division of two numbers using functions in C. It prompts the user for integer inputs and asks for re-entry if a character is provided:
Explanation: 
In this program, the getIntegerInput function is used to get an integer input from the user. It uses a while loop to repeatedly prompt the user for input until a valid integer is provided. The input is converted to an integer using atoi and returned.
The add, subtract, multiply, and divide functions perform the respective operations on two integer inputs.
In the main function, the user is prompted for the first and second numbers using getIntegerInput. The program then performs the calculations using the functions and prints the results.
If a character input is provided, the program will keep asking for an integer until a valid input is given.
I hope this helps! Let me know if you have any further questions.

#include<stdio.h>
#include <stdlib.h>

// Function  definition to allow only integer if character inpuit is given.
int getIntegerInput() {
    char input[100];
    int value;

    while (1) {
        printf("Enter an integer: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] >= '0' && input[0] <= '9') {
            value = atoi(input);
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    }

    return value;
}
// Function definitions for addition, subratction, multiplication and division.
int add(int a, int b)
{
	int res= a+b;
	return res;
}
int sub(int a, int b)
{
	int res= a-b;
	return res;
}
int mul(int a, int b)
{
	int res= a*b;
	return res;
}
int divi(int a, int b)
{
	int res= a/b;
	return res;
}

// Program execution intialization.
int main()
{
	int num1, num2,res,user_input;
	printf("Enter first number\n");
    //scanf("%d", &num1);
	num1 = getIntegerInput();
	printf("Enter second number\n");
    //scanf("%d", &num2);
	num2 = getIntegerInput();
	printf("Press 1 for addition\n");
	printf("Press 2 for subtraction\n");
	printf("Press 3 for multiplication\n");
	printf("Press 4 for division\n");
	printf("enter the user input:");
	scanf("%d",&user_input);
	if (user_input==1)
	{
	res=add(num1, num2);
	printf("Addition of two numbers %d\n", res);
	//break;
	}
	else if (user_input==2)
	{
	res=sub(num1, num2);
	printf("Sub of two numbers %d\n", res);
	//break;
	}
	else if (user_input==3)
	{
	res=mul(num1, num2);
	printf("Mul of two numbers %d\n", res);
	//break;
	}
	else if (user_input==4)
	{
	res=divi(num1, num2);
	printf("Div of two numbers %d\n", res);
	}
	return 0;
}
