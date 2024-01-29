//  统计一个整数对应的二进制数的1的个数。输入一个整数（可正可负）\
    输出该整数的二进制包含1的个数
#include"func.h"

int count_1_InBinary(char *c) {
    // 进入此函数说明输入合法
    int numberOfOne = 0;
    ('-' == *c && c++ && numberOfOne++) || ('+' == *c && c++);
    // 将剩下的字符串转换为整数
    int decimal = atoi(c);
    while (decimal != 0) {
        if (decimal % 2 == 1) {
            numberOfOne++;
        }
        decimal = decimal / 2;
    }
    return numberOfOne;
}
int isValidNumber(char *c) {
    int i = 0;
    if (!('-' == *c || '+' == *c || (*c >= '0' && *c <= '9'))) {
        return -1;
    }
    ('-' == *c && c++) || ('+' == *c && c++);
    while (*c != '\n' && *c) {
        if (*c < '0' || *c > '9') {
            return -1;
        }
        c++;
        i++;
    }
    return i;
}

int main() {
    printf("输入一个整数:\n");
    char c[256] = { 0 };
    while (fgets(c, sizeof(c), stdin) != NULL) {
        if (!isValidNumber(c)) {
            printf("输入的不是一个合法整数\n");
            return -1;
        }
        else {
            int num = count_1_InBinary(c);
            printf("1 的个数为：%d\n", num);
        }
    }
    return 0;
}