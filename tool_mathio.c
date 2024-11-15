#include "mathio.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * Checks if a string represents a valid integer.
 * @param str The string to check.
 * @return 1 if valid, 0 otherwise.
 */
int is_valid_integer(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (!*str) return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void print_help() {
    printf("MathIO - A simple command-line math tool.\n\n");
    printf("Usage:\n");
    printf("  mathio add <num1> <num2>\n");
    printf("  mathio subtract <num1> <num2>\n");
    printf("  mathio multiply <num1> <num2>\n");
    printf("  mathio divide <num1> <num2>\n");
    printf("  mathio print <message>\n");
}

int main(int argc, char *args[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcasecmp(args[1], "help") == 0 || strcasecmp(args[1], "--help") == 0 || strcasecmp(args[1], "-h") == 0) {
        print_help();
        return 0;
    }

    if (strcasecmp(args[1], "add") == 0 || 
        strcasecmp(args[1], "subtract") == 0 || 
        strcasecmp(args[1], "multiply") == 0 || 
        strcasecmp(args[1], "divide") == 0) {
        
        if (argc < 4) {
            fprintf(stderr, "Error: Insufficient arguments for '%s'.\n", args[1]);
            print_help();
            return 1;
        }

        if (!is_valid_integer(args[2]) || !is_valid_integer(args[3])) {
            fprintf(stderr, "Error: Arguments must be valid integers.\n");
            return 1;
        }

        int num1 = atoi(args[2]);
        int num2 = atoi(args[3]);

        if (strcasecmp(args[1], "add") == 0) {
            printf("%d\n", add(num1, num2));
        }
        else if (strcasecmp(args[1], "subtract") == 0) {
            printf("%d\n", subtract(num1, num2));
        }
        else if (strcasecmp(args[1], "multiply") == 0) {
            printf("%d\n", multiply(num1, num2));
        }
        else if (strcasecmp(args[1], "divide") == 0) {
            if (num2 == 0) {
                fprintf(stderr, "Error: Division by zero is undefined.\n");
                return 1;
            }
            printf("%d\n", divide(num1, num2));
        }
    }
    else if (strcasecmp(args[1], "print") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: Insufficient arguments for 'print'.\n");
            print_help();
            return 1;
        }
        print(args[2]);
    }
    else {
        fprintf(stderr, "Error: Unknown command '%s'.\n", args[1]);
        print_help();
        return 1;
    }

    return 0;
}
