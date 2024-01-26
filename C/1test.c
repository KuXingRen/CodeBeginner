#include <stdio.h>

void printPath(int path[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void findPaths(int m, int n, int path[], int len) {
    if (m == 0 && n == 0) {
        printPath(path, len);
        return;
    }

    if (m > 0) {
        path[len] = 1; // 1代表向上走
        findPaths(m - 1, n, path, len + 1);
    }

    if (n > 0) {
        path[len] = 2; // 2代表向右走
        findPaths(m, n - 1, path, len + 1);
    }
}

int main() {
    int m = 3, n = 3;
    int path[m + n - 1];
    findPaths(m - 1, n - 1, path, 0);
    return 0;
}
