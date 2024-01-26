// 删除字符串中指定的字符

#include"func.h"
#define N 100

void deleteChar(char *s, char content) {
    char *cur = s;
    while (*s != '\n') {
        if (content == *s) {
            s++;
        }
        else {
            *cur++ = *s++;
        }
    }
    *cur = '\0';// 添加新的结束符
}

int main() {
    char *s = (char *)calloc(N, sizeof(char));
    char content = 0;
    printf("请输入一串字符\n");
    while (fgets(s, N, stdin) != NULL) {
        printf("请输入要删除的字符\n");
        while ((content = getchar()) == '\n');
        clearSTDIN();
        deleteChar(s, content);
        printf("删除%c后的字符串为%s\n", content, s);
        printf("\n请输入一串字符\n");
    }
    free(s);
}