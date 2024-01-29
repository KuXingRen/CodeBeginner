// 链表去重
#include"func.h"

int isExist(pNode head, int data) {
    while (head) {
        if (head->data == data) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void removeDupliElemInLinkList(pNode *head) {
    pNode p = *head, newHead = NULL, *cur = NULL, tmp = NULL;
    cur = &newHead;
    while (p && p->next) {
        if (isExist(newHead, p->data)) {
            tmp = p;
            p = p->next;
            free(tmp);
            tmp = NULL;
        }
        else {
            tmp = p;
            p = p->next;
            tmp->next = NULL;
            *cur = tmp;
            cur = &(*cur)->next;
        }
    }
    head = &newHead;
}

int main() {
    pNode head = NULL;
    srand(time(NULL));
    structLinkListByRange(&head, 10, 5);
    showListNode(head);
    removeDupliElemInLinkList(&head);
    showListNode(head);
    freeLinkList(&head);
    return 0;
}