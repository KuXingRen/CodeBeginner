// 顺序栈的基本操作
#include"func.h"
#define MAXSIZE 128

typedef struct
{
    int data[MAXSIZE];
    int top;
}baseStackSeq;

// 初始化栈
void initSeqStack(baseStackSeq *S) {
    S->top = -1;
}
// 判断是否栈空
int isEmpty(baseStackSeq *S) {
    return S->top == -1;
}
// 入栈
int push(baseStackSeq *S, TableElem e) {
    if (S->top == MAXSIZE - 1) {
        return 0;
    }
    S->data[++(S->top)] = e;
    return S->top;
}
// 出栈
int pop(baseStackSeq *S) {
    if (isEmpty(S)) {
        return 0;
    }
    int value = S->data[S->top];
    S->top--;
    return value;
}
// 获取栈顶元素
int getTop(baseStackSeq *S) {
    return S->data[S->top];
}
// 获取栈大小
int getStackSize(baseStackSeq *S) {
    return S->top + 1;
}
int main() {
    baseStackSeq stack;
    initSeqStack(&stack);

    // 入栈操作
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // 获取栈大小
    printf("栈的大小为：%d\n", getStackSize(&stack));

    // 获取栈顶元素
    printf("栈顶元素为：%d\n", getTop(&stack));

    // 出栈操作
    printf("出栈元素为：%d\n", pop(&stack));
    printf("出栈元素为：%d\n", pop(&stack));

    // 再次获取栈大小
    printf("栈的大小为：%d\n", getStackSize(&stack));
}