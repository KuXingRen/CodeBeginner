// 从（0,0）到（m,n),每次走一步，只能向上或者向右走，有多少种路径走到(m,n)
#include"func.h"

void printPath(int *path) {
    int *next = path + 2;
    while (*path >= 0) {
        printf("(%d,%d) ", *path, *(path + 1));
        if (*next >= 0) {
            printf("-> ");
        }
        else {
            printf("\n");
        }
        path = path + 2;
        next = path + 2;
    }
}

int findPath(int m, int n, int x, int y, int *path) {
    if (x <= m && y <= n) {
        int nums1 = 2 * (x + y);
        int nums2 = nums1 + 1;
        path[nums1] = x;
        path[nums2] = y;
        if (x == m && y == n) {
            printPath(path);
            return 1;
        }
        return findPath(m, n, x + 1, y, path) + findPath(m, n, x, y + 1, path);
    }
    return 0;
}


int main() {
    int m, n;
    int ret = 0;
    int nums = 0;
    int *path = (int *)calloc(2 * (m + n + 1) + 1, sizeof(int));
    path[2 * (m + n)] = -1;
    while ((ret = scanf("%d%d", &m, &n)) != EOF) {
        if (ret != 2 || (0 > m || 0 > n)) {
            printf("不是合法的输入\n");
            clearSTDIN();
            continue;
        }
        path[2 * (m + n + 1)] = -1;
        nums = findPath(m, n, 0, 0, path);
        printf("%d种\n", nums);
    }
}