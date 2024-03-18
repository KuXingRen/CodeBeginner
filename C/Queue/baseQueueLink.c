// 循环队列的链式实现
#include"func.h"

typedef struct {
    pNode front;
    pNode rear;
} CircularQueue;

//初始化队列
void initialQueue(CircularQueue **q) {
    *q = (CircularQueue *)calloc(1, sizeof(CircularQueue));
    (*q)->rear = (*q)->front = NULL;
}
//创建队列节点
pNode createQueueNode(TableElem data) {
    pNode newnode = (pNode)calloc(1, sizeof(LNode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
//队空
int isEmpty(CircularQueue *q) {
    return q->front == NULL;
}
//入队
int enQueue(CircularQueue **q, TableElem e) {
    pNode newnode = createQueueNode(e);
    if (isEmpty(*q)) {
        (*q)->front = (*q)->rear = newnode;
        return -1;
    }
    else {
        (*q)->rear->next = newnode;
        (*q)->rear = newnode;
    }
    // 将队尾节点连接到队头
    (*q)->rear->next = (*q)->front;
}
//出队
int deQueue(CircularQueue **q) {
    if (isEmpty(*q)) {
        printf("队列为空\n");
    }
    int data = (*q)->front->data;
    pNode tmp = (*q)->front;

    // 队列中只有一个节点
    if ((*q)->front == (*q)->rear) {
        (*q)->front = (*q)->rear = NULL;
    }
    else {
        (*q)->front = (*q)->front->next;
        (*q)->rear->next = (*q)->front;
    }
    free(tmp);
    tmp = NULL;
    return data;
}
int main() {
    CircularQueue *q;
    initialQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    printf("出队元素：%d\n", deQueue(&q));
    printf("出队元素：%d\n", deQueue(&q));
    enQueue(&q, 40);
    printf("出队元素：%d\n", deQueue(&q));

    // 清理队列
    while (!isEmpty(q)) {
        deQueue(&q);
    }
    free(q);

    return 0;
}