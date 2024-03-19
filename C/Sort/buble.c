// 冒泡排序
#include"func.h"

int main() {
    int arr[10];
    int i = 0;
    for (i = 0;i < 10;i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');
    // 冒泡排序
    int j = 0;
    for (i = 0;i < 9;i++) {
        for (j = i;j < 10;j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}