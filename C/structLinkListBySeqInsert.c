// 用有有序插入的方式建立链表

#include"func.h"

int main() {
    srand(time(NULL));
    printf("请输入链表长度\n");
    int ret = 0, len = 0;
    while ((ret = scanf("%d", &len)) != EOF) {
        if (ret != 1 && len < 0) {
            printf("输入的不是合法整数");
            clearSTDIN();
        }
        pNode L = NULL, p = NULL, * cur = NULL, pre = NULL;
        for (int i = 0;i < len;i++) {
            // 尾插法
            p = (pNode)calloc(1, sizeof(LNode));
            p->data = rand() % 100;
            p->next = NULL;
            cur = &L;
            while (*cur != NULL && (*cur)->data < p->data) {
                cur = &(*cur)->next;
            }
            p->next = *cur;
            *cur = p;
        }
        for (int i = 0;i < len;i++) {
            printf("%d ", L->data);
            L = L->next;
        }
        printf("\n");
    }
}