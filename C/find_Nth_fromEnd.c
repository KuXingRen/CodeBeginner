// 找到链表倒数第四个结点

#include"func.h"

int main() {
    pNode head = NULL;
    int len = 4;
    // 双指针法
    strucLinkList(&head, len);
    showListNode(head);
    pNode pre = head, cur = head;
    for (int i = 0;i < len - 1;i++) {
        if (cur->next != NULL) {
            cur = cur->next;
        }
        else {
            printf("链表长度不足%d个\n", 4);
            break;
        }
    }
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    printf("倒数第%d个结点的值为%d\n", 4, pre->data);
    return 0;
}