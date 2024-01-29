// 有102个整数，其中有50个数出现了两次，2个数出现了一次， 找出出现了一次的那2个数。
#include "func.h"
int main() {
    int arr[102];
    int xorResult = 0;
    int singleNumber1 = 0, singleNumber2 = 0;

    // 构造数组
    for (int i = 0; i < 50; i++) {
        arr[i] = i;
        arr[i + 50] = i;
    }
    arr[100] = 45;  // 这是只出现一次的数
    arr[101] = 4567;  // 这是只出现一次的数

    // 找出所有元素的异或结果
    for (int i = 0; i < 102; i++) {
        xorResult ^= arr[i];
    }

    // 找出xorResult中的任意一个非零位
    int bit = xorResult & (-xorResult);
    printf("%d\n", bit);

    // 根据这个位将所有的元素分为两组，并进行异或运算
    for (int i = 0; i < 102; i++) {
        if (arr[i] & bit) {
            singleNumber1 ^= arr[i];
            printf("%d ", arr[i] & bit);
        }
        else {
            singleNumber2 ^= arr[i];
        }
    }

    printf("\n只出现一次的两个数是：%d 和 %d\n", singleNumber1, singleNumber2);

    return 0;
}
