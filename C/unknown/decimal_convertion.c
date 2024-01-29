// 二进制、十进制、十六进制互相转换
#include"func.h"
int decimalToBinary(char *c) {
    int i = 0;
    // 检查输入合法性
    while (c[i]) {
        if (c[i] < '0' || c[i]>'9') {
            printf("期望得到一个十进制数，但是收到了: %s\n", c);
            return -1;
        }
        i++;
    }
    i = 0;
    int num = 0;
    while (c[i]) {
        num = num * 10 + (c[i] - '0');
        i++;
    }
    if (0 == num) {
        puts("0");
        return 1;
    }
    i = 0;
    while (num > 0) {
        c[i] = '0' + num % 2;
        num = num / 2;
        i++;
    }
    i--;
    for (i; i >= 0; i--) {
        putchar(c[i]);
    }
    putchar('\n');
}

int binartToDecimal(char *c) {
    // 检查输入合法性
    int i = 0;
    while (c[i]) {
        if ('1' != c[i] && '0' != c[i]) {
            printf("期望得到二进制数，但是收到了：%s\n", c);
            return -1;
        }
        i++;
    }
    i = 0;
    int num = 0;
    while (c[i]) {
        num = num * 2 + c[i] - '0';
        i++;
    }
    printf("%d\n", num);
}

int decimalToHexadecimal(char *c) {
    // 检查输入合法性
    int decimal = atoi(c);
    while (*c) {
        if (*c < '0' || *c > '9') {
            printf("输入的不是一个有效十进制数\n");
            return -1;
        }
        c++;
    }
    char hex[100] = { 0 }, i = 0, tmp = 0;
    while (decimal != 0) {
        tmp = decimal % 16;
        if (tmp < 10) {
            hex[i] = tmp + '0';
        }
        else {
            hex[i] = tmp + 'A' - 10;
        }
        i++;
        decimal = decimal / 16;
    }
    // 逆序打印
    for (int j = i - 1;j >= 0;j--) {
        printf("%c", hex[j]);
    }
    putchar('\n');
}

int hexadecimalToDecimal(char *c) {
    // 边读取边检查
    int num = 0;
    while (*c) {
        if (!((*c >= '0' && *c <= '9') || (*c >= 'a' && *c <= 'z') || \
            (*c >= 'A' && *c <= 'Z')
            )) {
            printf("输入的不是一个合法的十六进制数\n");
            return -1;
        }
        else {
            if (*c >= '0' && *c <= '9') {
                num = num * 16 + *c - '0';
            }
            else if (*c >= 'a' && *c <= 'z') {
                num = num * 16 + *c - 'a' + 10;
            }
            else if (*c >= 'A' && *c <= 'Z') {
                num = num * 16 + *c - 'A' + 10;
            }
        }
        c++;
    }
    printf("%d\n", num);
}

int main() {
    char c[256];
    while (fgets(c, 256, stdin) != NULL) {
        int i = 0;
        hexadecimalToDecimal(c);
    }
    return 0;
}