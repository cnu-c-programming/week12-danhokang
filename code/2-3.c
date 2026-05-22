#include <stdio.h>

void logger(char *message) {
    FILE *fp = fopen("log.txt", "a");

    if (fp == NULL) {
        return;
    }

    fprintf(fp, "%s\n", message);

    fclose(fp);
}

int job(void) {
    return 1;
}

int main(int argc, const char *argv[]) {
    if (job() == 1) {
        logger("success");
    } else {
        logger("fail");
    }

    return 0;
}
