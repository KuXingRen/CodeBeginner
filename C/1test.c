#include"func.h"

void structLinkListByTail(pNode *head, int len) {
    pNode *cur = head, p = NULL;
    for (int i = 0;i < len;i++) {
        p = (pNode)calloc(1, sizeof(LNode));
        p->data = rand() % 100;
        p->next = NULL;
    }
}
int main() {
    pNode head = NULL;
    structLinkListByTail(&head, 10);
    showListNode(head);
    freeLinkList(&head);
    return 0;
}