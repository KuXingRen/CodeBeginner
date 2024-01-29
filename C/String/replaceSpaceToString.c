// 将字符串中的所有空格替换为%020

#include"func.h"
#define N 100 // 假设N足够大，所以不进行越界检查
// 该函数可以将a替换成b
void replaceSpace(char **s, char *a, char *b) {
    char *tmp = (char *)calloc(N, sizeof(char));
    char *cur = tmp, *curS = *s;
    while (*curS != '\n') {// *s从stdin读取
        if (*a != *curS) {
            *cur++ = *curS++;
        }
        else {
            while ('\0' != *b) {
                *cur++ = *b++;
            }
            curS++;
            b = b - 4;
        }
    }
    free(*s); // 因为s申请的堆空间，所以需要先释放然后再重新赋值
    *s = tmp;
}

int main() {
    char *s = (char *)calloc(N, sizeof(char));
    printf("请输入一串字符\n");
    while (fgets(s, N, stdin) != NULL) {
        replaceSpace(&s, " ", "%020\0");
        printf("%s\n", s);
        printf("\n请输入一串字符\n");
    }
    return 0;
}