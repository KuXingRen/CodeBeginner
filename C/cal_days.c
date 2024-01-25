//输入 一个日期 和一个整数 n，输出从该日期起经过n天以后的日期

#include"func.h"

int clearSTDIN() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 1;
}
int isValidDate(int ret, int year, int month, int day) {
    if (ret != 3) {
        printf("输入的不是一个合法日期\n");
        clearSTDIN();
        return -1;
    }
    int num = year * 10000 + month * 100 + day;
    if (num < 15821015) {
        printf("请输入1582年10月15日之前的日期\n");
        return -1;
    }
    char daysInNormalYear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            daysInNormalYear[1] = 29;
        }
    }
    if (month < 0 || month>12 || day <= 0 || day > daysInNormalYear[month - 1]) {
        printf("输入不合法，正确输入年 月 日信息\n");
        return -1;
    }
    return 1;
}
int getDate(int y, int m, int d, int n) {
    char daysInNormalYear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    // 判断闰年
    int i;
    n = n + d;
    while (n > 0) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            daysInNormalYear[1] = 29;
        }
        else {
            daysInNormalYear[1] = 28;
        }
        if (n > daysInNormalYear[m - 1]) {
            n -= daysInNormalYear[m - 1];
            m++;
        }
        else {
            d = n;
            n = 0;
        }
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    return y * 10000 + m * 100 + d;
}
int main() {
    int y, m, d, n;
    int ret = 0;
    printf("请输入日期:\n");
    while ((ret = scanf("%d%d%d", &y, &m, &d)) != EOF) {
        // 错误检测
        if (isValidDate(ret, y, m, d) < 0) {
            printf("\n请输入日期:\n");
            continue;
        }
        else {
            printf("想要查看多少天以后日期？\n");
            ret = scanf("%d", &n);
            if (ret != 1) {
                printf("输入的不是一个合法数字\n");
                clearSTDIN();
                continue;;
            }
            // 计算天数
            printf("%d年%d月%d日经过%d天之后的日期为", y, m, d, n);
            int date = getDate(y, m, d, n);
            y = date / 10000;
            m = (date % 10000) / 100;
            d = date % 100;
            printf("%d年%d月%d日\n", y, m, d);
        }
        printf("\n请输入日期:\n");
    }
    return 0;
}