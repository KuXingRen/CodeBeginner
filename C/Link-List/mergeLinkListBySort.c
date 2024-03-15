// 将两个链表合并为有序链表
#include"func.h"
void mergeSort(pNode *head, pNode *L1, pNode *L2) {
    // 使用链表的有序插入
    pNode *cur = head, tmp = NULL;
    int len1 = 0, len2 = 0;
    while (*L1) {
        // 判断空链表或者循环到尾部
        cur = head;
        while (*cur != NULL && (*cur)->data < (*L1)->data) {
            cur = &(*cur)->next;
        }
        // 将当前*L1所指向的节点移动到*cur上
        tmp = (*L1)->next;
        (*L1)->next = *cur;
        *cur = *L1;
        *L1 = tmp;
    }
    while (*L2) {
        cur = head;
        while (*cur != NULL && (*cur)->data < (*L2)->data) {
            cur = &(*cur)->next;
        }
        tmp = (*L2)->next;
        (*L2)->next = *cur;
        *cur = *L2;
        *L2 = tmp;
    }
}


int main() {
    srand(time(NULL));
    pNode L1 = NULL, L2 = NULL;
    pNode head = NULL;
    structLinkList(&L1, 2);
    structLinkList(&L2, 3);
    showListNode(L1);
    showListNode(L2);
    mergeSort(&head, &L1, &L2);
    showListNode(head);
    return 0;
}