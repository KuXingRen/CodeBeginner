#include"func.h"

int main() {
    srand(time(NULL));
    pNode head = NULL;
    structLinkListByTail(&head, 10);
    showListNode(head);
    freeLinkList(&head);
    return 0;
}