// 红黑树的实现
#include"func.h"

// 红黑树节点
typedef struct RBNode {
    unsigned char color;// red 或者 black
    int key;
    struct RBNode *parent;
    struct RBNode *left;
    struct RBNode *right;

}RbNode, *pRbNode;
// 红黑树的根
typedef struct rb_root {
    pRbNode node;
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
// 主函数
int main() {

}