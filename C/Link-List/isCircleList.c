// 判断一个链表中是否有环
#include"func.h"

void isCircle(pNode head) {
    // 使用快慢指针实现
    pNode fast = head->next, slow = head;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == NULL || fast->next == NULL) {
        printf("没有环\n");
    }
    else {
        printf("有环\n");
    }
}

int main() {
    pNode Loophead = NULL, Normhead = NULL;
    strucLinkListLoop(&Loophead, 3);
    structLinkList(&Normhead, 3);
    isCircle(Loophead);
    isCircle(Normhead);
    return 0;
}