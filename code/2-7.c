#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char inputFilename[64];
    int options;
    char sectionName[64];
    unsigned long long address;
} Config;

void config_parser(Config *config_ptr) {
    FILE *fp = fopen("config.txt", "r");

    if (fp == NULL) {
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL) {
        char key[64];
        char value[128];

        if (sscanf(line, "%63[^=]=%127s", key, value) == 2) {
            if (strcmp(key, "InputFilename") == 0) {
                strcpy(config_ptr->inputFilename, value);
            } else if (strcmp(key, "Options") == 0) {
                config_ptr->options = atoi(value);
            } else if (strcmp(key, "SectionName") == 0) {
                strcpy(config_ptr->sectionName, value);
            } else if (strcmp(key, "Address") == 0) {
                config_ptr->address = strtoull(value, NULL, 10);
            }
        }
    }

    fclose(fp);
}

int main(int argc, const char *argv[]) {
    Config config = {0};

    config_parser(&config);

    printf("config: %s %d %s %llu\n",
           config.inputFilename,
           config.options,
           config.sectionName,
           config.address);

    return 0;
}
