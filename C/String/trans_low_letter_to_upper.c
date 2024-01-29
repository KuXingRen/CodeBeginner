// 小写字母转大写
#include"func.h"

int main() {
    printf("输入字符串：\n");
    char c[256];
    while (gets(c) != EOF) {
        int i = 0;
        while (c[i]) {
            if (c[i] == ' ') {
                printf(" ");
                i++;
            }
            else {
                printf("%c", c[i] - 32);
                i++;
            }

        }
        putchar('\n');
    }
    return 0;
}