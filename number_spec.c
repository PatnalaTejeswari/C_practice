#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 5

int isEven(int num) {
    return (num % 2 == 0);
}

double squareRoot(double num) {
    return sqrt(num);
}

int isSquareNumber(int num) {
    int squareRoot = sqrt(num);
    return (squareRoot * squareRoot == num);
}

int reverseNumber(int num) {
    int reversed = 0;

    while (num != 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return reversed;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }

    return sum;
}

int isPalindrome(int num) {
    return (num == reverseNumber(num));
}

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int isArmstrong(int num) {
    int originalNum = num;
    int result = 0;
    int digits = 0;

    while (originalNum != 0) {
        originalNum /= 10;
        digits++;
    }

    originalNum = num;

    while (originalNum != 0) {
        int remainder = originalNum % 10;
        result += pow(remainder, digits);
        originalNum /= 10;
    }

    return (result == num);
}

unsigned long factorial(unsigned long num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int isComposite(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 1;
        }
    }

    return 0;
}

int isPerfectNumber(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return (sum == num);
}

void fibonacci(int num) {
    int first = 0;
    int second = 1;
    int next;

    printf("Fibonacci Series up to %d terms: ", num);

    for (int i = 1; i <= num; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    int inputs[ARRAY_SIZE];

    srand(time(NULL));

    printf("Random Inputs:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        inputs[i] = rand() % 100 + 1; // Generate random numbers between 1 and 100
        printf("Input %d: %d\n", i + 1, inputs[i]);
    }

    printf("\nOutput for Each Input:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int number = inputs[i];
        printf("Input of %d is %d:\n", i + 1, number);
        printf("Even/Odd: %s\n", isEven(number) ? "Even" : "Odd");
        printf("Square Root: %.2lf\n", squareRoot(number));
        printf("Square Number: %s\n", isSquareNumber(number) ? "Yes" : "No");
        printf("Reverse: %d\n", reverseNumber(number));
        printf("Sum of Digits: %d\n", sumOfDigits(number));
        printf("Palindrome: %s\n", isPalindrome(number) ? "Yes" : "No");
        printf("Prime: %s\n", isPrime(number) ? "Yes" : "No");
        printf("Armstrong: %s\n", isArmstrong(number) ? "Yes" : "No");
        printf("Factorial: %lu\n", factorial(number));
        printf("Composite: %s\n", isComposite(number) ? "Yes" : "No");
        printf("Perfect Number: %s\n", isPerfectNumber(number) ? "Yes" : "No");
        fibonacci(number);
        printf("\n");
    }

    return 0;
}
