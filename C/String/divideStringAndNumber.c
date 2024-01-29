// 将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。

#include"func.h"
#define N 100

void devideCharsAndNumbers(char *s) {
    // 从stdin中按行读取，所以字符串结尾一定是\n\0
    char *pre = s, *cur = s;
    while (*cur++ != '\n');
    cur = cur - 2;
    char *tmp = (char *)calloc(cur - pre, 1);
    char *tmpBegin = tmp, *tmpEnd = tmp + (cur - pre);
    while (*pre != '\n') {
        if (*pre < '0' || *pre>'9') {
            *tmpBegin++ = *pre++;
        }
        else {
            *tmpEnd-- = *pre++;
        }
    }
    // tmpBegin此时正好指向数字区的第一个元素的位置，从此处开始反转数字区的元素
    tmpEnd = tmp + (cur - s);
    reverseContent(tmpBegin, tmpEnd, sizeof(char));
    // 将tmp中的值循环赋值给s
    tmpBegin = tmp;
    while (*s != '\n') {
        *s++ = *tmpBegin++;
    }
    *s = '\0';//覆盖掉换行符
    free(tmp);
    tmp = NULL;
}

int main() {
    char s[N] = { 0 };
    printf("请输入一串字符:\n");
    while (fgets(s, N, stdin) != NULL) {
        // 约定字符内容为数字与非数字，故不需要输入合法性检测
        printf("原始的字符串为：\n%s", s);
        devideCharsAndNumbers(s);
        printf("将数字与非数字分开之后的结果:\n%s", s);
        printf("\n请输入一串字符:\n");
    }
    return 0;
}