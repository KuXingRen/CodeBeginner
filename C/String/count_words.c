//输入一行字符串（单词和若干空格）， 输出该行单词个数

#include"func.h"

int main() {
    char a[100] = "  lele__xiongda__python__C++  java ";
    char *cur = a;
    int  flag = 0;
    int count = 0;
    while (*cur != '\0') {
        if (' ' == *cur || '_' == *cur) {
            if (1 == flag) {
                count++;
                flag = 0;
            }
        }
        else {
            flag = 1;
        }
        cur++;
    }
    printf("%d\n", count);
    return 0;
}