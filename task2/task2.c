#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exitProgram();
int invalidInput(int a, int b);


int main(void) {
    /* Array of function pointers */
    int (*operations[6])(int, int) = {add, subtract, multiply, divide, exitProgram, invalidInput};

    int operationIndex;

    /* Get user input */
    printf("Enter operation index (0-4): ");
    scanf("%d", &operationIndex);

    /* Validate input and perform operation */
    int result = operations[operationIndex](10, 5);
    printf("Result: %d\n", result);

    return 0;
}

/* Function definitions */
int add(int a, int b) {
    printf("Adding %d and %d\n", a, b);
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting %d from %d\n", b, a);
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying %d and %d\n", a, b);
    return a * b;
}

int divide(int a, int b) {
    printf("Dividing %d by %d\n", a, b);
    return a / b;
}

int exitProgram(){
	exit(0);
}

int invalidInput(int a, int b) {
    printf("Invalid input. Enter a number 0-4.\n");
    exit(0);  // Exit the program for invalid input
}



