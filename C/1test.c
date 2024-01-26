#include <stdio.h>
#include <string.h>

void findMaxAndSecondMax(char *str[], int n, char **max, char **secondMax) {
    *max = *secondMax = str[0];
    for (int i = 1; i < n; i++) {
        if (strcmp(str[i], *max) > 0) {
            *secondMax = *max;
            *max = str[i];
        }
        else if (strcmp(str[i], *secondMax) > 0 && strcmp(str[i], *max) != 0) {
            *secondMax = str[i];
        }
    }
}

int main() {
    char *str[] = { "apple", "banana", "cherry", "date", "elderberry" };
    int n = sizeof(str) / sizeof(str[0]);
    char *max;
    char *secondMax;
    findMaxAndSecondMax(str, n, &max, &secondMax);
    printf("最大值: %s\n", max);
    printf("次大值: %s\n", secondMax);
    return 0;
}
