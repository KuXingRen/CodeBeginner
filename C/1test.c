#include <stdio.h>
#include <string.h>

void replaceSpaces(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] == ' ') {
            printf("%%020");
        }
        else {
            printf("%c", str[i]);
        }
        i++;
    }
}

int main() {
    char str[] = "hello  a   world how";
    replaceSpaces(str);
    return 0;
}
