// 求两个有序数组的公共元素
#include "func.h"

int main() {
    pSeqTable pSeq1 = NULL;
    pSeqTable pSeq2 = NULL;
    srand(time(NULL)); // 产生种子
    getRandSeqTable(&pSeq1, 15, 20);
    getRandSeqTable(&pSeq2, 15, 10);

    // 变成有序数组
    quickSort(pSeq1->table, 0, pSeq1->length);
    quickSort(pSeq2->table, 0, pSeq2->length);
    int i = 0, j = 0;
    for (i = 0;i < pSeq1->length;i++) {
        printf("%-3d", pSeq1->table[i]);
    }
    putchar('\n');
    for (i = 0;i < pSeq2->length;i++) {
        printf("%-3d", pSeq2->table[i]);
    }
    putchar('\n');
    i = 0, j = 0;
    int p1 = 0, p2 = 0;
    while (i < pSeq1->length && j < pSeq2->length) {
        p1 = pSeq1->table[i];
        p2 = pSeq2->table[j];
        if (pSeq1->table[i] == pSeq2->table[j]) {
            printf("%d ", pSeq1->table[i]);
            i++;
            j++;
        }
        else if (pSeq1->table[i] < pSeq2->table[j]) {
            i++;

        }
        else if (pSeq1->table[i] > pSeq2->table[j]) {
            j++;
        }
    }
    putchar('\n');
    return 0;
}