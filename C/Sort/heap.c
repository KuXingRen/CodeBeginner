// 实现插入排序
#include"func.h"

void adjustheap(int *arr, int pos, int len) {
    int dad = pos;
    int son = dad * 2 + 1;// 左孩子
    while (son < len) {
        // 找到较大的那个孩子
        if (son + 1 < len && arr[son] < arr[son + 1]) {
            son = son + 1;
        }
        // 将较大的孩子与父亲比较
        if (arr[dad] < arr[son]) {
            SWAP(arr[dad], arr[son])
                dad = son;
            son = dad * 2 + 1;
        }
        else {
            // 如果大孩子比父亲小，说明dad为根的子树已经符合大根堆
            break;
        }
    }
}

void heap(int *arr, int len) {
    int i;
    // 将原始序列调整为大根堆
    for (i = len / 2 - 1;i >= 0;i--) {
        adjustheap(arr, i, len);
    }
    // 交换堆顶元素与堆底元素
    SWAP(arr[0], arr[len - 1])
        for (i = len - 1;i > 1;i--) {
            adjustheap(arr, 0, i);
            SWAP(arr[0], arr[i - 1]);
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

    // 堆排序
    heap(arr, 10);

    // 打印结果
    for (i = 0;i < 10;i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}