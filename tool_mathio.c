#include <mathio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *args[]) {
    if (argc > 1) {
        if (strcasecmp(args[1], "add") == 0 && args[2] && args[3]) {
            printf("%d\n", add(atoi(args[2]), atoi(args[3])));
        }
        else if (strcasecmp(args[1], "subtract") == 0 && args[2] && args[3]) {
            printf("%d\n", subtract(atoi(args[2]), atoi(args[3])));
        }
        else if (strcasecmp(args[1], "multiply") == 0 && args[2] && args[3]) {
            printf("%d\n", multiply(atoi(args[2]), atoi(args[3])));
        }
        else if (strcasecmp(args[1], "divide") == 0 && args[2] && args[3]) {
            printf("%d\n", divide(atoi(args[2]), atoi(args[3])));
        }
        else if (strcasecmp(args[1], "print") == 0 && args[2]) {
            print(args[2]);
        }
    }
    return 0;
}