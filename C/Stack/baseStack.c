// 栈基础--链式栈(头插法)
#include"func.h"   

// 初始化栈
void initStack(pNode *top) {
    *top = NULL;
}
// 判断栈是否为空
int isEmptyStack(pNode top) {
    return top == NULL;
}
// 入栈操作
int push(pNode *top, TableElem e) {
    pNode ne = (pNode)calloc(1, sizeof(LNode));
    ne->data = e;
    ne->next = *top;
    *top = ne;
    return 1;
}
// 出栈操作
int pop(pNode *top) {
    if (isEmptyStack(*top)) {
        printf("栈为空\n");
        return -1;
    }
    TableElem value = (*top)->data;
    pNode tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return value;
}
// 获取栈的大小
int getStackSize(pNode top) {
    int size = 0;
    while (top != NULL) {
        size++;
        top = top->next;
    }
    return size;
}

// 获取栈顶元素
int getTop(pNode top) {
    return top->data;
}

int main() {
    pNode stack;
    initStack(&stack);

    // 入栈操作
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // 获取栈大小
    printf("栈的大小为：%d\n", getStackSize(stack));

    // 获取栈顶元素
    printf("栈顶元素为：%d\n", getTop(stack));

    // 出栈操作
    printf("出栈元素为：%d\n", pop(&stack));
    printf("出栈元素为：%d\n", pop(&stack));

    // 再次获取栈大小
    printf("栈的大小为：%d\n", getStackSize(stack));
}