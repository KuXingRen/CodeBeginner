// 找到单链表的中间结点
#include"func.h"

int main() {
    srand(time(NULL));
    int len = rand() % 15, length = 0;
    pNode head = NULL, cur = NULL;
    len = 2;
    strucLinkList(&head, len);
    showListNode(head);
    length = getLinkListLength(head, &length);
    printf("中间结点的序号为%d\n", length / 2);
    length = length / 2;
    cur = head;
    if (length != 0) {
        while (length - 1) {
            cur = cur->next;
            length--;
        }
    }
    printf("元素为%d\n", cur->data);
}