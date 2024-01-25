#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int tmp;   \
        tmp = a;   \
        a = b;     \
        b = tmp;   \
    }
// 线性表的数据类型
typedef int TableElem;

// 顺序表
typedef struct {
    TableElem *table;
    TableElem length;
} SeqTable, *pSeqTable;
// 链表
typedef struct Node {
    TableElem data;
    struct Node *next;
} LNode, *pNode;

// 构造一个顺序表，指定长度与整数的范围
// 取值范围(0，range)
int getRandSeqTable(pSeqTable *p, TableElem range, TableElem length);
// 快速排序的划分函数
int partition(TableElem *a, TableElem left, TableElem right);
// 快速排序的递归实现
void quickSort(TableElem *a, TableElem left, TableElem right);
// 堆排序的调整算法
void adjustMaxHeap(TableElem *a, TableElem adjustPos, TableElem len);
// 堆排序的循环实现
void heapSort(TableElem *a);
// 打印顺序表
void printSeqTable(pSeqTable table);
// 计数排序算法
int countSort(TableElem *table, TableElem range, TableElem len);
// 一个通用函数，可以将数组内容反转，需要连续存储
void reverseContent(void *begin, void *end, size_t size);