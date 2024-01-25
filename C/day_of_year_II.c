//输入两个日期（年 月 日 年 月 日）， 输出这两个日期之间差多少天。
#include"func.h"

int compareDate(int *y, int *m, int *d) {
    int date1 = y[0] * 10000 + m[0] * 100 + d[0];
    int date2 = y[1] * 10000 + m[1] * 100 + d[1];
    if (date1 < date2) {
        return 1;
    }
    else {
        return -1;
    }
}

int dayOfYear(int y, int m, int d) {
    char daysInNormalYear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    for (int i = 0;i < m - 1;i++) {
        if (y % 4 == 0) {
            if (y % 100 != 0 || y % 400 == 0) {
                sum += 29;
                continue;
            }
        }
        sum += daysInNormalYear[i];
    }
    return sum + d;
}

int daysBetweenYears(int *year, int *month, int *day) {
    int sum = 0, i = 0;
    if (compareDate(year, month, day)) {
        for (i = year[0];i < year[1];i++) {
            if (i % 4 == 0) {
                if (i % 100 != 0 || i % 400 == 0) {
                    sum += 366;
                    continue;
                }
            }
            sum += 365;
        }
        sum = sum - dayOfYear(year[0], month[0], day[0]) + \
            dayOfYear(year[1], month[1], day[1]);
    }
    else {
        for (i = year[1];i < year[0];i++) {
            if (i % 4 == 0) {
                if (i % 100 != 0 || i % 400 == 0) {
                    sum += 366;
                    continue;
                }
            }
            sum += 365;
        }
        sum = sum - dayOfYear(year[1], month[1], day[1]) + \
            dayOfYear(year[0], month[0], day[0]);
    }
    return sum;
}
int isValidDate(int ret, int *year, int *month, int *day, int tag) {
    if (ret != 3) {
        printf("输入的不是一个合法日期\n");
        return -1;
    }
    char daysInNormalYear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (year[tag] % 4 == 0) {
        if (year[tag] % 100 != 0 || year[tag] % 400 == 0) {
            daysInNormalYear[1] = 28;
        }
    }
    if (month[tag] < 0 || month[tag]>12 || day[tag] <= 0 || day[tag] > daysInNormalYear[month[tag] - 1]) {
        printf("输入不合法，正确输入年 月 日信息\n");
        return -1;
    }
    return 1;
}
int main() {
    int year[2] = { 0 }, month[2] = { 0 }, day[2] = { 0 };
    int ret = 0;
    printf("输入第一个日期:\n");
    while ((ret = scanf("%d%d%d", &year[0], &month[0], &day[0])) != EOF) {
        if (!isValidDate) {
            continue;
        }
        printf("输入第二个日期:\n");
        ret = scanf("%d%d%d", &year[1], &month[1], &day[1]);
        if (!isValidDate) {
            continue;
        }
        printf("%d年%d月%d日 和 %d年%d月%d日 之间相差%d天\n", year[0], \
            month[0], day[0], year[1], month[1], day[1], daysBetweenYears(year, month, day));
        printf("输入第一个日期:\n");
    }
}
