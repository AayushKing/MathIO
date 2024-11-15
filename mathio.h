#ifndef MATHIO_H
#define MATHIO_H

/**
 * Adds two integers.
 * @param x First integer.
 * @param y Second integer.
 * @return Sum of x and y.
 */
int add(int x, int y);

/**
 * Subtracts the second integer from the first.
 * @param x First integer.
 * @param y Second integer.
 * @return Result of x - y.
 */
int subtract(int x, int y);

/**
 * Multiplies two integers.
 * @param x First integer.
 * @param y Second integer.
 * @return Product of x and y.
 */
int multiply(int x, int y);

/**
 * Divides the first integer by the second.
 * @param x Dividend.
 * @param y Divisor.
 * @return Result of x / y.
 */
int divide(int x, int y);

/**
 * Prints a string to the console.
 * @param string The string to print.
 */
void print(const char *string);

#endif // MATHIO_H
