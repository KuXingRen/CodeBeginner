// 找到字符串数组中的最大值与次大值
#include"func.h"
#define N 100

void find_2_max(char **s, int n, char **max, char **sec_max) {
    *max = *sec_max = s[0];
    for (int i = 0;i < n;i++) {
        if (strcmp(s[i], *max) > 0) {
            *sec_max = *max;
            *max = s[i];
        }
        else if (strcmp(s[i], *sec_max) > 0 && strcmp(s[i], *max) != 0) {
            *sec_max = s[i];
        }
    }
}

int main() {
    char **s = (char **)calloc(5, sizeof(char *));
    char *max, *sec_max;
    for (int i = 0;i < 5;i++) {
        printf("请输入第%i个字符串\n", i);
        s[i] = (char *)calloc(N, sizeof(char));
        fgets(s[i], N, stdin);
    }
    find_2_max(s, 5, &max, &sec_max);
    printf("最大值%s次大值为%s", max, sec_max);
    // 释放内存
    for (int i = 0;i < 5;i++) {
        free(s[i]);
    }
    free(s);
}