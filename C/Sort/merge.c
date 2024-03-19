// 实现归并排序
#include"func.h"

void merge_arr(int *a, int l, int mid, int r) {
    int *b = (int *)calloc((r - l + 1), sizeof(int));
    // 将a中的元素赋值给b
    for (int i = 0;i < (r - l + 1);i++) {
        b[i] = a[i + l];
    }
    //将b中的元素按照大小顺序写会a
    int i, j, k;
    for (i = l, j = mid + 1, k = l;i <= mid && j <= r;k++) {
        if (b[i - l] <= b[j - l]) {
            a[k] = b[i - l];
            i++;
        }
        else if (b[i - l] > b[j - l]) {
            a[k] = b[j - l];
            j++;
        }
    }
    // 将剩余元素写回a中
    while (i <= mid) {
        a[k] = b[i - l];
        k++;
        i++;
    }
    while (j <= r) {
        a[k] = b[j - l];
        k++;
        j++;
    }
}

void merge(int *a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge(a, l, mid);
        merge(a, mid + 1, r);
        merge_arr(a, l, mid, r);
    }
}

int main() {
    int arr[10];
    int i = 0, j = 0;
    for (i = 0;i < 10;i++) {
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    // 归并排序
    merge(arr, 0, 9);
    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}