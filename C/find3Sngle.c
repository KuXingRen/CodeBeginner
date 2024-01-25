//有103个整数，其中有50个数出现了两次，3个数出现了一次， 找出出现了一次的那3个数

#include "func.h"

void findSingleInArr(int *arr, int xor, int length) {
    int mask = -xor &xor;
    // 使用mask进行划分
    int res1 = 0, res2 = 0;
    for (int i = 0;i < length;i++) {
        if (arr[i] & mask) {
            res1 ^= arr[i];
        }
        else {
            res2 ^= arr[i];
        }
    }
    printf("%d %d\n", res1, res2);
}

int main() {
    int arr[103];
    for (int i = 0;i < 50;i++) {
        arr[i] = arr[i + 50] = i;
    }
    int heap1[103] = { 0 }, heap2[103] = { 0 };
    while (scanf("%d %d %d", &arr[100], &arr[101], &arr[102]) != EOF) {
        int mask = 1;
        for (int i = 0;i < 32;i++) {
            mask = mask << i;
            int xorHeap1 = 0, xorHeap2 = 0;
            int heapLength1 = 0, heapLength2 = 0;
            // 分堆
            for (int j = 0;j < 103;j++) {
                if (arr[j] & mask) {
                    heap1[heapLength1] = arr[j];
                    heapLength1++;
                    xorHeap1 ^= arr[j];
                }
                else {
                    heap2[heapLength2] = arr[j];
                    heapLength2++;
                    xorHeap2 ^= arr[j];
                }
            }
            // 判断堆是否为偶数且异或值不为0
            // 题设条件下，一定能找到偶数堆且异或值不为0的情况。所以其他情况不考虑
            if (heapLength1 % 2 == 0 && xorHeap1 != 0) {
                // 另一堆的异或值一定为目标之一
                printf("%d ", xorHeap2);
                findSingleInArr(heap1, xorHeap1, heapLength1);
                break;//提前结束，其他maks的情况不考虑
            }
            else if (heapLength2 % 2 == 0 && xorHeap2 != 0) {
                printf("%d ", xorHeap1);
                findSingleInArr(heap2, xorHeap2, heapLength2);
                break;
            }
        }
    }
    return 0;
}