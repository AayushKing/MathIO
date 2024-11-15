#include <stdio.h>
#include "mathio.h"

/**
 * Adds two integers.
 * @param x First integer.
 * @param y Second integer.
 * @return Sum of x and y.
 */
int add(int x, int y) {
    return x + y;
}

/**
 * Subtracts the second integer from the first.
 * @param x First integer.
 * @param y Second integer.
 * @return Result of x - y.
 */
int subtract(int x, int y) {
    return x - y;
}

/**
 * Multiplies two integers.
 * @param x First integer.
 * @param y Second integer.
 * @return Product of x and y.
 */
int multiply(int x, int y) {
    return x * y;
}

/**
 * Divides the first integer by the second.
 * @param x Dividend.
 * @param y Divisor.
 * @return Result of x / y.
 * @note Returns 0 if division by zero is attempted.
 */
int divide(int x, int y) {
    if (y == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        return 0; // Or handle as appropriate
    }
    return x / y;
}

/**
 * Prints a string to the console.
 * @param string The string to print.
 */
void print(const char *string) {
    printf("%s\n", string);
}
