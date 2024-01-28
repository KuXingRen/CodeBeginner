#include"func.h"

int main() {
    pNode L = NULL;
    strucLinkList(&L, 10);
    while (L != NULL) {
        printf("%d ", L->data);
        L = L->next;
    }
    putchar('\n');
    return 0;
}