#include"func.h"

int main() {
    pNode L = NULL;
    structLinkListBySeqInsert(&L, 10);
    showListNode(L);
    L = findNodeFromEnd(L, 4);
    printf("%d\n", L->data);

    return 0;
}