// 删除字符串中多余的空格
#include"func.h"

#define N 100

void removeDupliSpace(char *s) {
    int tag = 0;// 0表示尚未遇到第一个非空格字符
    char *pre = s;
    char *cur = s;
    while (*s != '\n') {
        s++;
        if (*s != ' ' || (*s == ' ' && *(s - 1) != ' ')) {
            *++pre = *s;
        }
    }
    if (*(pre - 2) == ' ') {
        *(pre - 2) = '\0';
    }
    else {
        *(pre - 1) = '\0';
    }
}
int main() {
    char *s = (char *)calloc(N, sizeof(char));
    printf("请输入一串字符\n");
    while (fgets(s, N, stdin) != NULL) {
        removeDupliSpace(s);
        printf("去除多余空格的字符串%s0\n", s);
        printf("请输入一串字符\n");
    }
}