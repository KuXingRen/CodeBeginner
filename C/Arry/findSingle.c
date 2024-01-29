//有101个整数，其中有50个数出现了两次，1个数出现了一次， 找出出现了一次的那个数
#include"func.h"
int main() {
    int arr[101];
    int singleNumber = 0;
    int i;
    for (i = 0;i < 50;i++) {
        arr[i] = i;
        arr[i + 50] = i;
    }
    arr[100] = 45;
    for (i = 0;i < 101;i++) {
        singleNumber ^= arr[i];
    }
    printf("只出现一次的数为：%d\n", singleNumber);
}