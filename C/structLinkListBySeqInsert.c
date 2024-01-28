// 用有有序插入的方式建立链表

#include"func.h"

int main() {
    srand(time(NULL));
    printf("请输入链表长度\n");
    int ret = 0, len = 0;
    pNode tmp = NULL;
    pNode L = NULL, p = NULL, *cur = NULL, pre = NULL;
    while ((ret = scanf("%d", &len)) != EOF) {
        if (ret != 1 && len < 0) {
            printf("输入的不是合法整数");
            clearSTDIN();
            continue;
        }

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
            tmp = L;
            L = L->next;
            free(tmp);
            tmp = NULL;
        }
        printf("\n");
    }
}