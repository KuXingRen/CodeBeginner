//mystrcpy(), mystrcmp(), mystrcat(), mystrlen() ;备注：\
mystrcat()mystrcpy()返回值为void

#include"func.h"


int my_strcmp(const char *str1, const char *str2) {
    while (*str1++ != *str2++ && *str1 != '\0' && *str2 != '\0') {
        return *str1 - *str2;
    }
    return *str1 - *str2;
}

int my_strlen(const char *str) {
    int len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

char *my_strcat(char *dst, const char *src) {
    char *p = dst + strlen(src) * sizeof(char) + 1;
    while (*src != '\0') {
        *p++ = *src++;
    }
    *p = '\0';
    return *dst;
}

char *my_strcpy(char *dst, char *src, int datasize) {
    if (my_strlen(src) + 1 > datasize) {
        return "目标缓冲区大小不足以容纳字符串\n";
    }
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return 0;
}
int main() {
    char a[100] = "abc";
    char c[100] = "abc";
    char *b = "ac";
    printf("%d\n", my_strlen(a));
    printf("%d\n", my_strcmp(a, b));
    my_strcpy(c, b, 100);
    printf("%s\n", c);
    my_strcat(a, b);
    printf("%s\n", a);
}