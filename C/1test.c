#include"func.h"

int main() {
    pNode L = NULL;
    int i = 0;
    structLinkListBySeqInsert(&L, 10);
    showListNode(L);
    L = findNodeFromEnd(L, 4);
    getLinkListLength(L, &i);
    printf("%d\n", i);
    return 0;
}