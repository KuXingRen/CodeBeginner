#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 有序插入节点
void insertNode(Node** head, Node* newNode) {
    Node** current = head;
    while (*current != NULL && (*current)->data < newNode->data) {
        current = &((*current)->next);
    }
    newNode->next = *current;
    *current = newNode;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;  // 初始化空链表

    // 插入节点
    insertNode(&head, createNode(1));
    insertNode(&head, createNode(2));
    insertNode(&head, createNode(3));

    // 打印链表
    printList(head);

    return 0;
}
