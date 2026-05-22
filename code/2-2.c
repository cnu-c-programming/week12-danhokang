#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[10];
    int score;
} Student;

int main(int argc, const char *argv[]) {
    FILE *fp = fopen("student.txt", "r");

    if (fp == NULL) {
        return 0;
    }

    Student s;
    int count = 0;
    int sum = 0;
    int max = 0;

    while (fscanf(fp, "%9s %d", s.name, &s.score) == 2) {
        if (count == 0 || s.score > max) {
            max = s.score;
        }

        sum += s.score;
        count++;
    }

    fclose(fp);

    if (count > 0) {
        printf("max: %d\n", max);
        printf("avg: %.2f\n", (double)sum / count);
    }

    return 0;
}
