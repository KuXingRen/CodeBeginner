// 输入一个路径，以深度优先的方式遍历
#include"funclinux.h"

void printDir(const char *path, int width) {
    DIR *dir;
    char buf[1024];
    dir = opendir(path);
    if (NULL == dir) {
        perror("opendir");
    }
    struct dirent *p;
    while (p = readdir(dir)) {
        // 避免死循环
        if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
            continue;
        }
        printf("%*s--%s\n", width, "", p->d_name);
        // 4 表示当前的文件类型时目录
        if (p->d_type == 4) {
            // 清空路径缓存
            memset(buf, 0, sizeof(buf));
            sprintf(buf, "%s/%s", path, p->d_name);
            printDir(buf, width + 4);
        }
    }
    // 关闭文件
    closedir(dir);
}

int main() {
    const char *path = ".";
    printDir(path, 0);
    return 0;
}