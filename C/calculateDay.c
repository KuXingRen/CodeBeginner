// 输入一个日期，输出该日期是星期几
// 不考虑格里高利历的情况，在代码中显示略过
#include"func.h"
int compareDate(int y, int m, int d) {
    int date1 = 2024 * 10000 + 1 * 100 + 22;
    int date2 = y * 10000 + m * 100 + d;
    if (date1 < date2) {
        return 1;
    }
    else {
        return -1;
    }
}
int isValidDate(int ret, int year, int month, int day) {
    if (ret != 3) {
        printf("输入的不是一个合法日期\n");
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
int dayOfYear(int y, int m, int d) {
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = d;
    for (int i = 0; i < m - 1; i++) {
        sum += daysInMonth[i];
    }
    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) {
        sum += 1;
    }
    return sum;
}

int getDaysDiff(int y, int m, int d) {
    int sum = 0;
    int startYear = compareDate(y, m, d) > 0 ? 2024 : y;
    int endYear = compareDate(y, m, d) > 0 ? y : 2024;
    int startMonth = compareDate(y, m, d) > 0 ? 1 : m;
    int endMonth = compareDate(y, m, d) > 0 ? m : 1;
    int startDay = compareDate(y, m, d) > 0 ? 22 : d;
    int endDay = compareDate(y, m, d) > 0 ? d : 22;
    int increment = compareDate(y, m, d) > 0 ? 1 : -1;

    for (int i = startYear; i != endYear; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            sum += increment * 366;
        }
        else {
            sum += increment * 365;
        }
    }
    sum = sum - dayOfYear(startYear, startMonth, startDay) + dayOfYear(endYear, endMonth, endDay);
    return sum;
}
int getWeekNumber(int y, int m, int d) {
    int days = getDaysDiff(y, m, d);
    int base = 1; // 代表2024年1月22日是周一
    int num = (base + days) % 7;
    return num < 0 ? num + 7 : num;
}
int main() {
    char *week[] = { "星期日","星期一","星期二","星期三","星期四","星期五","星期六" };
    int by = 2024, bm = 1, bd = 22, bweekNum = 1;
    int ret = 0;
    int y, m, d;
    printf("请输入一个日期：\n");
    while ((ret = scanf("%d%d%d", &y, &m, &d)) != EOF) {
        if (!isValidDate(ret, y, m, d)) {
            continue;
        }
        printf("%d年%d月%d日是%s\n", y, m, d, week[getWeekNumber(y, m, d)]);
        // printf("%d", getWeekNumber(y, m, d));
        printf("请输入一个日期：\n");
    }
    return 0;
}