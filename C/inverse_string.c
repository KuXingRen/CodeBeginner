// 输入一行字符串，把字符串翻转
#include"func.h"

void reverse(char *start, char *end) {
    while (start < end) {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

void reverseWords(char *s) {
    char *pre = s, *cur = s;
    while (*cur && *cur) {
        cur++;
        if ('\0' == *cur || '\n' == *cur) {
            reverse(pre, cur - 1);
            (*cur == '\n') && (*cur = '\0');
        }
        if (' ' == *cur) {
            reverse(pre, cur - 1);
            pre = cur + 1;
        }
    }
}

int main() {
    char s[100] = { 0 };
    printf("请输入一串字符\n");
    while (fgets(s, 100, stdin) != NULL) {
        char tmpS[100] = { 0 };
        strcpy(tmpS, s);
        char *begin = tmpS, *end = tmpS;
        while (*end++ != '\0');
        reverse(begin, end - 3);// 防止将\n\0反转到字符串首导致打印提前结束
        printf("全部翻转的结果是：%s\n", tmpS);
        reverseWords(s);
        printf("所有单词原地反转的结果是：%s\n", s);
        printf("\n请输入一串字符\n");
    }
    return 0;
}