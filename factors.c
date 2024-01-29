#include <stdio.h>
#include <stdlib.h>

void factorize(int num) {
    int i, factor1 = 0, factor2 = 0;

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            factor1 = i;
            factor2 = num / i;
            break;
        }
    }

    if (factor1 && factor2) {
        printf("%d=%d*%d\n", num, factor1, factor2);
    } else {
        printf("%d=%d*%d\n", num, num, 1);
    }
}

void factors(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int number = atoi(buffer);
        factorize(number);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    factors(argv[1]);
    return EXIT_SUCCESS;
}

