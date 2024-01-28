// 删除链表中指定的某个节点
#include"func.h"

int main() {
    pNode L = NULL;
    int ret, len;
    printf("请输入链表的长度\n");
    while ((ret = scanf("%d", &len)) != EOF) {
        if (ret != 1 || len < 0) {
            printf("输入的不是一个合法的整数\n");
            clearSTDIN();
            printf("\n请输入链表的长度\n");
            continue;
        }
        strucLinkList(&L);
        showListNode(L);
        printf("想要删除第几个节点？\n");
        int index = 0;
        ret = scanf("%d", &index);
        if (ret != 1 || index < 0) {
            printf("输入的不是一个合法的整数\n");
            printf("\n请输入链表的长度\n");
            clearSTDIN();
            continue;
        }
        removeNodeByIndex(index);
        showListNode(L);
        printf("请输入链表的长度\n");
    }
}