// 统计一个字符串中字母、数字和其他字符的数量并打印条形统计图
#include"func.h"

int main() {
    char c[256];
    int i = 0;
    while (gets(c) != EOF) {
        int alp = 0, num = 0, oth = 0;
        i = 0;
        while (c[i]) {
            if ((c[i] - '9') <= 0 && (c[i] - '0') >= 0) {
                num++;
            }
            else if (c[i] - 'a' >= 0 && c[i] - 'z' <= 0) {
                alp++;
            }
            else if (c[i] - 'A' >= 0 && c[i] - 'Z' <= 0) {
                alp++;
            }
            else {
                oth++;
            }
            i++;
        }
        int max = (alp > num) ? ((alp > oth) ? alp : oth) : ((num > oth) ? num : oth);
        // 绘制柱状图
        int j = 0, k = 0;
        i = 0;
        for (i = 0; i < max + 2; i++) {
            // 绘制数字
            if (max - alp == i) {
                printf("%*s%d%*s", 2, "", alp, 2, "");
            }
            else if (max + 1 == i) {
                printf("%*s%s%*s", 1, "", "alp", 1, "");
            }
            else if (max - alp<i && max + 1>i) {
                printf("%s", "*****");
            }
            else {
                printf("%5s", "");
            }

            printf("%4s", "");

            if (max - num == i) {
                printf("%*s%d%*s", 2, "", num, 2, "");
            }
            else if (max + 1 == i) {
                printf("%*s%s%*s", 1, "", "num", 1, "");
            }
            else if (max - num<i && max + 1>i) {
                printf("%s", "*****");
            }
            else {
                printf("%5s", "");
            }

            printf("%4s", "");

            if (max - oth == i) {
                printf("%*s%d%*s", 2, "", oth, 2, "");
            }
            else if (max + 1 == i) {
                printf("%*s%s%*s", 1, "", "oth", 1, "");
            }
            else if (max - oth<i && max + 1>i) {
                printf("%s", "*****");
            }
            else {
                printf("%5s", "");
            }
            putchar('\n');
        }
    }
}