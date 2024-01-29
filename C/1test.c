#include"func.h"

int main() {
    pNode L = NULL;
    int i = 0;
    structLinkListByRange(&L, 10, 5);
    showListNode(L);
    return 0;
}