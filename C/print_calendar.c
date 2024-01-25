//输入一个年份,月份，输出该月份的日历
#include"func.h"
#include <stdbool.h>

int clearSTDIN() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 1;
}
int isValidDate(int ret, int y, int m) {
    if (ret != 2) {
        printf("输入的不是一个合法日期\n");
        clearSTDIN();
        return 0;
    }
    if (m < 0 || m>12) {
        printf("输入的不是一个合法日期\n");
        return 0;
    }
    return 1;
}

int isLeapYear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}

int getDayInMonth(int y, int m) {
    if (2 == m) {
        if (isLeapYear(y)) {
            return 29;
        }
        return 28;
    }
    else {
        if (1 == m || 3 == m || 5 == m || 7 == m || 8 == m || 10 == m || 12 == m) {
            return 31;
        }
        return 30;
    }
}
// 格里高利历法
int getDayInWeek(int y, int m, int d) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 + y / 400 - y / 100 + t[m - 1] + d - 1) % 7;
}

int main() {
    int y, m;
    int ret = 0;
    printf("请输入年 月：\n");
    while ((ret = scanf("%d%d", &y, &m)) != EOF) {
        if (!isValidDate(ret, y, m)) {
            printf("\n请输入年 月：\n");
            continue;
        }
        int dayInMonth = getDayInMonth(y, m);
        int dayInWeek = getDayInWeek(y, m, 1);


        printf("一 二 三 四 五 六 日\n");
        int i;
        for (i = 0;i < dayInWeek;i++) {
            printf("   ");
        }
        for (int day = 1; day <= dayInMonth; day++) {
            printf("%2d ", day);
            i++;
            if (i % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }
}