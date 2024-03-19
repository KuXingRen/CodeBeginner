// 实现选择排序
#include"func.h"

int main() {
    int arr[10];
    int i = 0;
    for (i = 0;i < 10;i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    // 选择排序
    int j = 0;
    for (i = 0;i < 9;i++) {
        int index = i;
        for (j = i + 1;j < 10;j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        // 交换元素
        int  tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }

    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}