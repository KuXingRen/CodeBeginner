// 红黑树的实现
#include"func.h"
// 宏函数的实现
#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)

#define RED        0    // 红色节点
#define BLACK    1    // 黑色节点

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
void rbtree_insert_fixup(RBRoot *root, Node *node);
// 将节点插入到红黑树中
void rbtree_insert(RBRoot *root, Node *node);
// 创建一个红黑树节点
Node *create_rbtree_node(int key, Node *parent, Node *left, Node *right);
// 新建一个节点并插入到红黑树中,成功返回0，失败返回-1
int insert_rbtree(RBRoot *root, int key);
// 删除操作若破坏红黑树的性质则调用此函数
void rbtree_delete_fixup(RBRoot *root, Node *node, Node *parent);
// 删除一个节点
void rbtree_delete(RBRoot *root, Node *node);
// 删除键值为key的节点
void delete_rbtree(RBRoot *root, int key);
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
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (y->parent == NULL) {
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
    x->parent = y;
    y->right = x;
}
void rbtree_insert_fixup(RBRoot *root, Node *node) {
    Node *parent = NULL, *gparent = NULL;
    // 若父节点存在且为红色
    while ((parent = rb_parent(node)) && rb_is_red(parent)) {
        gparent = rb_parent(parent);
        // 若父节点是一个左孩子
        if (parent == gparent->left) {
            //1.如果叔叔节点是红色
            Node *uncle = gparent->right;
            if (uncle != NULL && rb_is_red(uncle)) {
                rb_set_black(parent);
                rb_set_black(uncle);
                rb_set_red(gparent);
                node = parent;
                continue;
            }
            // 叔叔节点是黑色或者不存在,当前节点是一个右孩子
            // 先左旋，后右旋
            if (parent->right == node) {
                Node *tmp;
                rbtree_left_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            // 叔叔是黑色，且当前节点是一个左孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            rbtree_right_rotate(root, gparent);
        }
        else {
            // 1.叔叔节点是红色
            Node *uncle = gparent->left;
            if (uncle != NULL && rb_is_red(uncle)) {
                rb_set_black(parent);
                rb_set_black(uncle);
                rb_set_red(gparent);
                node = gparent;
                continue;
            }
            // 2. 叔叔为黑色且当前节点为左孩子（叔叔不存在也视作黑色）
            // 右旋一次变为情况3
            if (parent->left == node) {
                Node *tmp;
                rbtree_right_rotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            // 3. 叔叔为黑色（不存在）且当前节点是一个右孩子
            rb_set_black(parent);
            rb_set_red(gparent);
            rbtree_left_rotate(root, gparent);
        }
    }
    // 父节点不存在，说明插入的节点为根节点
    // 父节点为黑色，则插入红节点不破坏红黑树的性质
    // 无论哪种情况，都可以将根节点设为黑色
    rb_set_black(root->node);
}
void rbtree_insert(RBRoot *root, Node *node) {
    Node *y = NULL;
    Node *x = root->node;
    // 将红黑树当作一颗二叉查找树，将节点添加到二叉查找树中
    while (x != NULL) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    rb_parent(node) = y;
    // 修改父节点的指针
    if (y != NULL) {
        if (node->key < y->key) {
            y->left = node;
        }
        else {
            y->right = node;
        }
    }
    else {
        root->node = node;
    }

    // 将新节点的颜色设置为红色
    node->color = RED;
    // 重新平衡红黑树
    rbtree_insert_fixup(root, node);
}
Node *create_rbtree_node(int key, Node *parent, Node *left, Node *right) {
    RBTree node = (RBTree)calloc(1, sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->key = key;
    node->right = right;
    node->parent = parent;
    node->left = left;
    return node;
}
int insert_rbtree(RBRoot *root, int key) {
    Node *node;
    // 不允许插入相同键值的节点
    if (search(root->node, key) != NULL) {
        return -1;
    }
    // 新节点创建失败，则返回
    if ((node = create_rbtree_node(key, NULL, NULL, NULL)) == NULL) {
        return -1;
    }
    rbtree_insert(root, node);
}

void rbtree_delete_fixup(RBRoot *root, Node *node, Node *parent) {
    Node *other; // 兄弟节点指针
    // node为叶子或者黑色节点，且当为黑色时不为根节点，会破坏红黑树的结构性质
    while ((!node || rb_is_black(node)) && node != root->node) {
        //如果node是一个左孩子
        if (parent->left == node) {
            // 初始化兄弟节点指针
            other = parent->right;
            // 如果兄弟节点为红色
            if (rb_is_red(other)) {
                rb_set_black(other);
                rb_set_red(parent);
                rbtree_left_rotate(root, parent);
                other = parent->right;
            }
            // 经过上一步处理，新的other一定是一个黑色节点，因此可以在同一次循环中处理
            if ((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right))) {
                rb_set_red(other);
                node = parent;
                parent = node->parent;
            }
            // 兄弟的左右孩子不全为黑色
            else {
                // 如果兄弟的右孩子为黑色
                if (!other->right || rb_is_black(other->right)) {
                    rb_set_black(other->left);
                    rb_set_red(other);
                    // 对兄弟进行右旋
                    rbtree_right_rotate(root, other);
                    other = parent->right;
                }
                //左孩子颜色任意，右孩子为红色的情况
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                rbtree_left_rotate(root, parent);
                node = root->node;
                break;
            }
        }
        // 如果node是一个右孩子
        else {
            // 初始化兄弟节点指针
            other = parent->left;
            // 如果兄弟节点为红色
            if (rb_is_red(other)) {
                rb_set_black(other);
                rb_set_red(parent);
                rbtree_left_rotate(root, parent);
                other = parent->left;
            }
            // 经过上一步处理，新的other一定是一个黑色节点，因此可以在同一次循环中处理
            if ((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right))) {
                rb_set_red(other);
                node = parent;
                parent = node->parent;
            }
            // 兄弟的左右孩子不全为黑色
            else {
                // 如果兄弟的右孩子为黑色
                if (!other->left || rb_is_black(other->left)) {
                    rb_set_black(other->right);
                    rb_set_red(other);
                    // 对兄弟进行右旋
                    rbtree_right_rotate(root, other);
                    other = parent->left;
                }
                //左孩子颜色任意，右孩子为红色的情况
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                rbtree_left_rotate(root, parent);
                node = root->node;
                break;
            }
        }
        // 将节点设置为黑色
        if (node) {
            rb_set_black(node);
        }
    }
}

void rbtree_delete(RBRoot *root, Node *node) {
    Node *parent, *child;
    int color;

    // node两个孩子非空
    if (node->left != NULL && node->right != NULL) {
        // 寻找node的后继节点作为替代
        // 两个孩子非空则一定会有后继
        Node *replace = node->right;

        // 后继节点为右子树的最左节点
        while (replace->left != NULL) {
            replace = replace->left;
        }

        // 如果node节点不为根结点
        if (rb_parent(node)) {
            if (rb_parent(node)->left == node) {
                rb_parent(node)->left = replace;
            }
            else {
                rb_parent(node)->right = replace;
            }
        }
        else {
            root->node = replace;
        }
        // 当前replace的度一定小于2，且无左孩子
        child = replace->right;
        parent = rb_parent(replace);
        color = rb_color(replace);

        // 如果node是replace的父节点
        if (parent == node) {
            parent = replace;
        }
        else {
            if (child) {
                rb_set_parent(child, parent);
            }
            parent->left = child;
            replace->right = node->right;
            rb_set_parent(node->right, replace);
        }
        // 将replace移动到node的位置
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        if (color == BLACK) {
            rbtree_delete_fixup(root, child, parent);
        }
        free(node);
        node = NULL;
        return;
    }
    // node 有一边为空
    if (node->left != NULL) {
        child = node->left;
    }
    else {
        child = node->right;
    }
    parent = node->parent;
    color = node->color;
    if (child) {
        child->parent = parent;
    }

    // node不是根节点
    if (parent) {
        // 如果node是一个左孩子
        if (node == parent->left) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
    }
    else {
        root->node = child;
    }

    if (color == BLACK) {
        rbtree_delete_fixup(root, child, parent);
    }
    free(node);
    node = NULL;
    return;
}
void delete_rbtree(RBRoot *root, int key) {
    Node *z, *node;
    if ((z = search(root->node, key)) != NULL) {
        rbtree_delete(root, z);
    }
}