// 删除数组中的重复元素

#include"func.h"
#define N 100

void removeDuplicatesFromString(char *s) {
    char *cur = s, *pre = s;
    while (*s != '\n') {
        s++;
        if (*s != *pre) {
            *(++cur) = *s;
        }
        pre = s;
    }
    *(cur + 1) = '\0';
}

int main() {
    char *s = (char *)calloc(N, sizeof(char));
    printf("请输入一串字符\n");
    while (fgets(s, N, stdin) != NULL) {
        removeDuplicatesFromString(s);
        printf("去重后的字符串为:%s", s);
        printf("\n请输入一串字符\n");
    }
    free(s);
}