// 将两个有序链表合并成一个有序链表

#include"func.h"

void mergeBySort(pNode *m, pNode L1, pNode L2) {
    pNode *cur = m, p;
    while (L1 != NULL && L2 != NULL) {
        if (L1->data < L2->data) {
            p = (pNode)calloc(1, sizeof(LNode));
            p->data = L1->data;
            p->next = NULL;
            // if (*cur == NULL) {
            //     *cur = p;
            // }
            // else {
            //     (*cur)->next = p;
            //     *cur = p;
            // }
            if ((*cur) == NULL) {
                *cur = p;
            }
            else {
                (*cur)->next = p;
                cur = &(*cur)->next;
            }
            L1 = L1->next;
        }
        else {
            p = (pNode)calloc(1, sizeof(LNode));
            p->data = L2->data;
            p->next = NULL;
            if ((*cur) == NULL) {
                *cur = p;
            }
            else {
                (*cur)->next = p;
                cur = &(*cur)->next;
            }
            L2 = L2->next;
        }
    }
    while (L1) {
        p = (pNode)calloc(1, sizeof(LNode));
        p->data = L1->data;
        p->next = NULL;
        (*cur)->next = p;
        cur = &(*cur)->next;
        L1 = L1->next;
    }
    while (L2) {
        p = (pNode)calloc(1, sizeof(LNode));
        p->data = L2->data;
        p->next = NULL;
        (*cur)->next = p;
        cur = &(*cur)->next;
        L2 = L2->next;
    }
}

int main() {
    srand(time(NULL));
    printf("请输入链表长度\n");
    int ret = 0, len = 0;
    pNode tmp = NULL;
    pNode L1 = NULL, L2 = NULL, mergeL = NULL;
    while ((ret = scanf("%d", &len)) != EOF) {
        if (ret != 1 && len < 0) {
            printf("输入的不是合法整数\n");
            clearSTDIN();
            continue;
        }
        structLinkListBySeqInsert(&L1, len);
        showListNode(L1);
        structLinkListBySeqInsert(&L2, len);
        showListNode(L2);
        mergeBySort(&mergeL, L1, L2);
        showListNode(mergeL);
        freeLinkList(&L1);
        freeLinkList(&L2);
        freeLinkList(&mergeL);
    }
}