#include"func.h"

int main() {
    pNode L = NULL;
    int i = 0;
    strucLinkListLoop(&L, 3);
    // 循环链表会不断重复打印
    showListNode(L);
    L = findNodeFromEnd(L, 4);
    getLinkListLength(L, &i);
    printf("%d\n", i);
    return 0;
}