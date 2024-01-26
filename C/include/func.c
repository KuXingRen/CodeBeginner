#include "func.h"

int clearSTDIN() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 1;
}

int getRandSeqTable(pSeqTable *Seq, int range, int length) {
    // 检查range
    if (range < 0) {
        printf("范围不合法\b");
        return -1;
    }
    // 检查SeqTable是否为空
    if (*Seq != NULL) {
        printf("getRandSeqTable需要一个pSeqTable类型的空指针\n");
        return -1;
    }
    // 初始化SeqTable
    *Seq = (pSeqTable)calloc(1, sizeof(SeqTable));
    (*Seq)->length = length;
    (*Seq)->table = (int *)malloc(sizeof(TableElem) * length);
    int i;
    for (i = 0; i < length; i++) {
        (*Seq)->table[i] = rand() % range;
    }
    // 成功赋值的个数
    return i;
}

int partition(TableElem *a, TableElem left, TableElem right) {
    int i, k; // 把right作为分隔值
    for (i = k = left; i < right; i++) {
        if (a[i] < a[right]) {
            SWAP(a[i], a[k])
                k++;
        }

    }
    SWAP(a[k], a[right])
        return k;
}

void quickSort(TableElem *a, TableElem left, TableElem right) {
    int pivot;          // 分隔值的下标
    if (left < right) { // 递归结束条件
        pivot = partition(a, left, right);
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

void printSeqTable(pSeqTable table) {
    for (int i = 0; i < table->length; i++) {
        printf("%4d", table->table[i]);
    }
    putchar('\n');
}

int countSort(TableElem *table, TableElem range, TableElem length) {
    if (range > 1000000) {
        printf("范围过大，不适合使用计数排序，考虑其他排序算法\n");
        return -1;
    }
    if (table) {
        TableElem *arr = (TableElem *)calloc(range, sizeof(TableElem));
        int i;
        for (i = 0; i < length; i++) {
            arr[table[i]]++;
        }
        int j = 0, k = 0;
        for (i = 0; i < range; i++) {
            if (0 < arr[i]) {
                for (j = 0; j < arr[i]; j++) {
                    table[k] = i;
                    k++;
                }
            }
        }
        return k;
    }
    printf("传入了一个空指针\n");
    return -1;
}

void reverseContent(void *begin, void *end, size_t size) {
    // 因为不知道具体类型，所以需要类型size信息，然后使mem系列函数实现
    begin = (char *)begin;
    end = (char *)end;

    char *tmp = (char *)malloc(size);
    if (tmp == NULL) {
        return;
    }

    while (begin < end) {
        memcpy(tmp, end, size);
        memcpy(end, begin, size);
        memcpy(begin, tmp, size);

        begin += size;
        end -= size;
    }
    free(tmp);
    tmp = NULL;
}