//输入一行字符串（单词和若干空格），输出该行单词（每个单词一行）

#include"func.h"

void printWord(char *pre, char *cur) {
    while (pre != cur) {
        putchar(*pre);
        pre++;
    }
    putchar('\n');
}

int main() {
    char s[100];
    int flag = 0;          // flag=0代表当前读取的字符是非空格
    char *pre = s, *cur = s;
    printf("请输入一个字符串\n");
    while (gets(s) != NULL) {
        // if (!ret) {
        //     printf("不是一个合法的输入\n");
        //     printf("\n请输入一个字符串\n");
        //     continue;
        // }
        pre = s, cur = s;
        flag = 1;
        while (*cur != '\0') {
            if (' ' == *cur) {
                if (0 == flag) {
                    printWord(pre, cur);
                    flag = 1;
                }
            }
            else {
                if (1 == flag) {
                    pre = cur;
                }
                flag = 0;
            }
            cur++;
        }
        if (0 == flag) {
            printWord(pre, cur);
            flag = 1;
        }
        printf("\n请输入一个字符串\n");
    }
}