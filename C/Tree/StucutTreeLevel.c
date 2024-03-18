// 实现二叉树的层次建树
#include"func.h"
typedef struct binTree {
    TableElem data;
    struct binTree *left;
    struct binTree *right;
}binTree, *pBintree;
// 队列的节点
typedef struct queNode {
    pBintree cur;
    struct queNode *next;
}TNode, *ptNode;
// 队列，存储树的节点
typedef struct teeQue {
    ptNode front;
    ptNode rear;
}treeQue, *pTque;

// 构造树节点
pBintree structTreeNode(TableElem e) {
    pBintree p = (pBintree)calloc(1, sizeof(binTree));
    p->data = e;
    p->left = p->right = NULL;
    return p;
}
// 构造队列节点
ptNode structQueNode(TableElem e) {

    ptNode new = (ptNode)calloc(1, sizeof(TNode));
    new->cur = structTreeNode(e);
    new->next = NULL;
    return new;
}
// 初始化队列
void initialQue(pTque *p) {
    *p = (pTque)calloc(1, sizeof(treeQue));
    (*p)->rear = (*p)->front = NULL;
}

// 队列判空
int isEmpty(pTque p) {
    return p->front == NULL;
}
// 入队
int enQueue(pTque *p, TableElem e) {
    ptNode new = structQueNode(e);
    if (isEmpty(*p)) {
        (*p)->front = (*p)->rear = new;
    }
    else {
        (*p)->rear->next = new;
        (*p)->rear = (*p)->rear->next;
    }
}
// 出队
int deQueue(pTque *p) {
    if (isEmpty(*p)) {
        printf("队列空\n");
        return -1;
    }
    pBintree tmp = (*p)->front->cur;
    if ((*p)->rear == (*p)->front) {
        (*p)->rear = (*p)->front = NULL;
    }
    else {
        (*p)->front = (*p)->front->next;
    }
    return tmp->data;
}
int main() {
    pTque p;
    pBintree tree;
    initialQue(&p);
    for (int i = 0;i < 10;i++) {
        // 如果树节点的队列为空,则该节点为根节点
        if (isEmpty(p)) {
            enQueue(&p, i);
            tree = p->front->cur;
        }
        else {
            // 如果左孩子为空
            enQueue(&p, i);
            if (p->front->cur->left == NULL) {
                p->front->cur->left = p->rear->cur;
                printf("节点%d获得左孩子%d\n", p->front->cur->data, i);
                continue;
            }
            if (p->front->cur->right == NULL) {
                p->front->cur->right = p->rear->cur;
                printf("节点%d获得右孩子%d\n", p->front->cur->data, i);
                continue;
            }
            // 左右孩子都有
            printf("节点%d左右已满\n", deQueue(&p));
            // 将新节点挂在新队头的左孩子上
            p->front->cur->left = p->rear->cur;
            printf("节点%d获得左孩子%d\n", p->front->cur->data, i);
        }
    }
    return 0;
}