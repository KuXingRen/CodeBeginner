// 去除单链表的重复元素
#include"func.h"

void removeDupElemByLoop(pNode *head) {
    // 两层循环
    pNode cur = NULL, pre = NULL, dup = NULL;
    cur = *head;
    while (cur != NULL && cur->next != NULL) {
        pre = cur;
        //内层循环（如果能进入第一层循环，pre一定不为null）
        while (pre->next != NULL) {
            if (pre->next->data == cur->data) {
                dup = pre->next;
                pre->next = pre->next->next;
                free(dup);
            }
            else {
                pre = pre->next;
            }
        }
        cur = cur->next;
    }
}

// elf哈希函数
unsigned long elfHash(const char *str) {
    unsigned long hash = 0;
    unsigned long x = 0;

    while (*str) {
        hash = (hash << 4) + (*str++); // hash左移4位，加上当前字符
        if ((x = hash & 0xF0000000L) != 0) { // 如果高四位不为0
            hash ^= (x >> 24); // 将高四位与hash的低四位进行异或
            hash &= ~x; // 清空高四位
        }
    }
    return (hash & 0x7FFFFFFF);
}

void removeDupElemByHash(pNode *head) {
    int TABLE_SIZE = 256;
    int *hashtable = (int *)calloc(TABLE_SIZE, sizeof(int));
    pNode cur = *head, pre = NULL;
    // 将字符转换为字符串
    char buffer[20];
    while (cur != NULL) {
        sprintf(buffer, "%d", cur->data);
        unsigned long hashvalue = elfHash(buffer) % TABLE_SIZE;

        if (hashtable[hashvalue] == 0) {
            hashtable[hashvalue] = 1;
            pre = cur;
            cur = cur->next;
        }
        else {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
    }
}

int main() {
    pNode head = NULL;
    structLinkListByRange(&head, 10, 5);
    showListNode(head);
    removeDupElemByLoop(&head);
    //removeDupElemByHash(&head);
    showListNode(head);

}