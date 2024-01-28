#include"func.h"

int main() {
    srand(time(NULL));
    pNode L = NULL;
    strucLinkList(&L, 10);
    showListNode(L);
    removeNodeByIndex(&L, 3 - 1);
    showListNode(L);
    return 0;
}