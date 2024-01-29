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
        structLinkList(&L, len);
        showListNode(L);
        printf("想要删除第几个节点？\n");
        int index = 0;
        ret = scanf("%d", &index);
        if (ret != 1 || index < 0) {
            if (L == NULL) {
                printf("删除失败,链表为空\n");
            }
            else {
                printf("输入的不是一个合法的整数\n");
            }
            printf("\n请输入链表的长度\n");
            clearSTDIN();
            continue;
        }
        ret = removeNodeByIndex(&L, index - 1);
        if (!ret && L != NULL) {
            printf("超出链表范围，删除失败\n");
            continue;
        }
        showListNode(L);
        freeLinkList(L);
        printf("请输入链表的长度\n");
    }
}