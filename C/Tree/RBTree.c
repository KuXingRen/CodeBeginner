// 红黑树的实现
#include"func.h"
// 宏函数的实现
#define rb_parent(r) ((r)->parent);
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_red(r) do{(r)->color = RED;} while(0)
#define rb_set_blak(r) do{(r)->color = BLACK;} while(0)
#define rb_set_parent(r,p) do{(r)->parent = (p);} while(0)
#define rb_set_color(r,c) do{(r)->color = (c);} while(0)


// 红黑树节点定义
typedef struct RBNode {
    unsigned char color;// red 或者 black
    int key;
    struct RBNode *parent;
    struct RBNode *left;
    struct RBNode *right;

}Node, *RBTree;
// 红黑树的根

typedef struct rb_root {
    RBTree node;
}RBRoot;

// 创建红黑树，返回红黑树的根
RBRoot *create_rbtree();
// 销毁红黑树
void destory_rbtree(RBRoot *root);
// 将节点插入到红黑树中，成功返回0，失败返回-1；
int insert_rbtree(RBRoot *root, int key);
// 删除节点为key的值
void delete_rbtree(RBRoot *root, int key);
// 前序遍历红黑树
void preorder_rbtree(RBRoot *root);
// 中序遍历红黑树
void inorder_rbtree(RBRoot *root);
// 后续遍历红黑树
void postorder_rbtree(RBRoot *root);
// (递归实现)查找红黑树中值为key的节点，找到返回0，失败返回-1
int rbtree_search(RBRoot *root, int key);
// (非递归实现)查找红黑树中值为key的节点，找到返回0，失败返回-1
int iterative_rbtree_search(RBRoot *root, int key);
// 返回最小节点的值，将值保存在val中，成功返回0，失败返回-1
int rbtree_minimum(RBRoot *root, int *val);
// 返回最大节点的值，将值保存在val中，成功返回0，失败返回-1
int rbtree_maximum(RBRoot *root, int *val);
// 打印红黑树
void print_rbtree(RBRoot *root);

//查找x的后继节点
Node *rbtree_successor(RBTree x);
// 查找x的前驱节点
Node *rbtree_predecessor(RBTree x);
// 左旋操作
void rbtree_left_rotate(RBRoot *root, Node *x);
// 右旋操作
void rbtree_right_rotate(RBRoot *root, Node *x);
// 插入操作破坏红黑树的性质则调用此函数
// 删除操作若破坏红黑树的性质则调用此函数

// 主函数
int main() {
    return 0;
}
// 创建红黑树
RBRoot *create_rbtree(RBRoot *root) {
    RBRoot *root = (RBRoot *)calloc(1, sizeof(RBRoot));
    root->node = NULL;
    return root;
}
// 前序遍历红黑树
void preorder(RBTree tree) {
    if (tree != NULL) {
        printf("%d", tree->key);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void preorder_rbtree(RBRoot *root) {
    if (root) {
        preorder(root->node);
    }
}

// 中序遍历红黑树
void inorder(RBTree tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d", tree->key);
        inorder(tree->right);
    }
}

void inorder_rbtree(RBRoot *root) {
    if (root) {
        inorder(root->node);
    }
}

// 后续遍历
void postorder(RBTree tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d", tree->key);
    }
}

void postorder_rbtree(RBRoot *root) {
    if (root) {
        postorder(root->node);
    }
}

// 递归实现，查找键值为key的节点
Node *search(RBTree x, int key) {
    if (x == NULL || x->key == key) {
        return x;
    }
    if (key < x->key) {
        return search(x->left, key);
    }
    else {
        return search(x->right, key);
    }
}

int rbtree_search(RBRoot *root, int key) {
    if (root) {
        return search(root->node, key) ? 0 : -1;
    }
}

// 非递归实现，查找键值为key的节点
Node *iterative_search(RBTree x, int key) {
    while ((x != NULL) && x->key != key) {
        if (key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    return x;
}

int iterative_rbtree_search(RBRoot *root, int key) {
    if (root) {
        return iterative_search(root->node, key) ? 0 : -1;
    }
}

// 返回以tree为根的红黑树的最小节点
Node *minimum(RBTree tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

int rbtree_minimum(RBRoot *root, int *val) {
    Node *node = NULL;
    if (root) {
        node = minimum(root->node);
    }
    if (node == NULL) {
        return -1;
    }
    *val = node->key;
    return 0;
}

// 返回以tree为根节点的红黑树的最大节点
Node *maximum(RBTree tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

int rbtree_maximum(RBRoot *root, int *val) {
    Node *node = NULL;
    if (root) {
        node = maximum(root->node);
    }
    if (node == NULL) {
        return -1;
    }
    *val = node->key;
    return 0;
}

Node *rbtree_successor(RBTree x) {
    // 如果x存在右孩子，则x的后继为右子树中最小的节点
    if (x->right != NULL) {
        return minimum(x->right);
    }
    // 如果x没有右孩子，则
    // 1. x是一个左孩子，它的后继为父节点
    // 2. x是一个右孩子，它的后继为具有左孩子的最低父节点
    Node *y = x->parent;
    while ((y != NULL) && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;

}Node *rbtree_predecessor(RBTree x) {
    // 如果x存在左孩子，则前驱为左子树的最大节点
    if (x->left != NULL) {
        return maximum(x->left);
    }
    // 如果x没有左孩子，则
    // 1. x是一个右孩子，x的前驱为父节点
    // 2. x是一个左孩子，x的前驱为具有右孩子的最低父节点
    Node *y = x;
    while ((y != NULL) && x == y->left) {
        x = y;
        y = y->parent;
    }
}

void rbtree_left_rotate(RBRoot *root, Node *x) {
    // 将x的右孩子设置为y
    Node *y = x->right;
    // 将y的左孩子设置为x的右孩子,然后更新双亲指针
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    // 把x的双亲指针赋值给y的双亲指针
    y->parent = x->parent;
    // 如果x的双亲为根节点
    if (x->parent == NULL) {
        root->node = y;
    }
    else {
        if (x->parent->left == x) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
    }
    // 将x设置为y的左孩子
    y->left = x;
    // 更新x的双亲指针
    x->parent = y;
}
void rbtree_right_rotate(RBRoot *root, Node *x) {

}