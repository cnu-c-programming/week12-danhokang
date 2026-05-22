#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    const char *filename = "numbers.txt";

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char buffer[256];
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *endptr;

        int num = (int)strtol(buffer, &endptr, 10);

        if (endptr == buffer) {
            buffer[strcspn(buffer, "\n")] = '\0';
            fprintf(stderr, "invalid input %s\n", buffer);
        } else {
            sum += num;
        }
    }

    printf("sum: %d\n", sum);

    fclose(fp);

    return 0;
}
