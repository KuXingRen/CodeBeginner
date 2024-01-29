// 将一个链表逆置
#include"func.h"

int main() {
    pNode head = NULL;
    int len = 10;
    structLinkListBySeqInsert(&head, len);
    showListNode(head);
    reverseLinkList(&head);
    showListNode(head);
    freeLinkList(&head);
    return 0;
}