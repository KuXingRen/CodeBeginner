// 实现插入排序
#include"func.h"

int main() {
    int arr[10];
    int i = 0, j = 0;
    for (i = 0;i < 10;i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    // 选择排序
    for (i = 1;i < 10;i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}