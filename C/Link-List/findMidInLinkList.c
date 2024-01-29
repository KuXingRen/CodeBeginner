// 找到单链表的中间结点
#include"func.h"

int main() {
    srand(time(NULL));
    int range = rand() % 15, len = 0;
    pNode head = NULL, cur = NULL, pre = NULL;
    range = 4;
    structLinkList(&head, range);
    if (head) {
        showListNode(head);
        len = getLinkListLength(head, &len);
        len = len / 2;
        cur = head;
        for (int i = 0;i < len;i++) {
            cur = cur->next;
        }
        printf("%d\n", cur->data);
    }
    else {
        printf("链表为空\n");
    }
    return 0;
}