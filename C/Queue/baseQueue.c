// 循环队列及其基本操作的顺序实现
#include"func.h"
#define MAXSIZE 128

typedef struct {
    int front, rear;
    int data[MAXSIZE];
} CircularQueue;
//初始化队列
void initialQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = 0;
}
//判断队列为空
int isEmpty(CircularQueue *q) {
    return q->rear == q->front;
}
//判断队列为满
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}
//入队
int enqueue(CircularQueue *q, TableElem e) {
    if (isFull(q)) {
        return -1;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 0;
}
//出队

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    TableElem res = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return res;
}

int main() {
    CircularQueue q;
    initialQueue(&q);

    // 测试入队
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    // 测试出队
    while (!isEmpty(&q)) {
        printf("%d\n", dequeue(&q));
    }
    return 0;

}