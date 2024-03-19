// 实现快速
#include"func.h"

int part(int *arr, int left, int right) {
    // 将arr[right]作为基准值
    int i, k;
    for (i = k = left;i < right;i++) {
        if (arr[i] < arr[right]) {
            SWAP(arr[i], arr[k])
                k++;
        }
    }
    SWAP(arr[k], arr[right])
        return k;
}

void quickS(int *arr, int left, int right) {
    int pivot;
    // 递归结束条线
    if (left < right) {
        pivot = part(arr, left, right);
        quickS(arr, left, pivot - 1);
        quickS(arr, pivot + 1, right);
    }
}

int main() {
    int arr[10];
    int i = 0;
    for (i = 0;i < 10;i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    // 快速排序
    quickS(arr, 0, 9);
    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}