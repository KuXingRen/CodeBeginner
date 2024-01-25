// 输入年月日，输出该日期是当年的第几天。

#include"func.h"
int clearSTDIN() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("输入不合法，正确输入年 月 日信息\n");
    return 1;
}
int main() {
    char daysInNormalYear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int year, month, day;
    int ret = 0;
    while ((ret = scanf("%d%d%d", &year, &month, &day)) != EOF) {
        // 检查输入合法性
        if (ret != 3) {
            clearSTDIN();
        }
        // 如果不是闰年，检查月份和天数是否合法
        if (month < 0 || month>12 || day <= 0 || day > daysInNormalYear[month - 1]) {
            printf("输入不合法，正确输入年 月 日信息\n");
            continue;
        }
        int sum = 0;
        for (int i = 0;i < month - 1;i++) {
            if (1 == i && year % 400 == 0) {
                sum += 29;
                continue;
            }
            sum += daysInNormalYear[i];
        }
        printf("现在是%d年的第%d天\n", year, day + sum);
    }
}