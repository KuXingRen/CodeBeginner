// 求n个有序数组的公共元素
// 思路：每次只能比较两个数组，因此需要两个辅助数组储存前面的结果
#include"func.h"
#define N 4
int main() {
    // 构造N个有序数组
    pSeqTable SeqTab[N] = { NULL }, supTab[2] = { NULL };
    int i = 0, j = 0, k = 0;
    srand(time(NULL));
    for (i = 0;i < N;i++) {
        getRandSeqTable(&SeqTab[i], 10, 10);
        quickSort(SeqTab[i]->table, 0, SeqTab[i]->length);
    }
    // 初始化辅助数组
    for (i = 0;i < 2;i++) {
        getRandSeqTable(&supTab[i], 10, 10);
        supTab[i]->length = 0;
    }

    // 第一次循环对比，将结果存到辅助数组1中
    i = 0, j = 0;
    while (i < SeqTab[0]->length && j < SeqTab[1]->length) {
        if (SeqTab[0]->table[i] == SeqTab[1]->table[j]) {
            supTab[0]->table[k] = SeqTab[1]->table[j];
            i++;
            j++;
            k++;
            supTab[0]->length = k;
        }
        else if (SeqTab[0]->table[i] < SeqTab[1]->table[j]) {
            i++;
        }
        else if (SeqTab[0]->table[i] > SeqTab[1]->table[j]) {
            j++;
        }
    }
    // 打印过程
    printf("数组a:");
    for (i = 0;i < SeqTab[0]->length;i++) {
        printf("%3d", SeqTab[0]->table[i]);
    }
    printf("\n数组b:");
    for (i = 0;i < SeqTab[1]->length;i++) {
        printf("%3d", SeqTab[1]->table[i]);
    }
    printf("\n结果:");
    for (i = 0;i < supTab[0]->length;i++) {
        printf("%3d", supTab[0]->table[i]);
    }
    putchar('\n');
    // 剩下的N-2个数组都轮流与辅助数组1(*b1)对比
    // 需要使用指针让两个辅助数组扮演的角色在每次循环结束后互换
    printf("二次循环\n");
    pSeqTable* b1, * b2;
    b1 = &supTab[0], b2 = &supTab[1];
    for (int num = 2;num < N;num++) {
        i = 0, j = 0, k = 0;
        while (i < SeqTab[num]->length && j < (*b1)->length) {
            if (SeqTab[num]->table[i] == (*b1)->table[j]) {
                (*b2)->table[k] = SeqTab[num]->table[i];
                i++;
                j++;
                k++;
                (*b2)->length = k;
            }
            else if (SeqTab[num]->table[i] < (*b1)->table[j]) {
                i++;
            }
            else if (SeqTab[num]->table[i] > (*b1)->table[j]) {
                j++;
            }
        }
        // 打印过程
        printf("数组a:");
        for (i = 0;i < SeqTab[num]->length;i++) {
            printf("%3d", SeqTab[num]->table[i]);
        }
        printf("\n数组b:");
        for (i = 0;i < (*b1)->length;i++) {
            printf("%3d", (*b1)->table[i]);
        }
        printf("\n结果:");
        for (i = 0;i < (*b2)->length;i++) {
            printf("%3d", (*b2)->table[i]);
        }
        putchar('\n');
        // 对比结束，交换b1,b2
        pSeqTable* tmp;
        tmp = b1;
        b1 = b2;
        b2 = tmp;
    }

    // 打印最后的结果
    for (i = 0;i < (*b2)->length;i++) {
        printf("%3d", (*b2)->table[i]);
    }
    putchar('\n');
    return 0;
}