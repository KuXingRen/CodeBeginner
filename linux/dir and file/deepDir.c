// 输入一个路径，以深度优先的方式遍历
#include"funclinux.h"

int printDir(const char *path, int width) {
    DIR *dir;
    char buf[1024];
    dir = opendir(path);
    if (NULL == dir) {
        perror("opendir");
        return -1;
    }
    struct dirent *p;
    while (p = readdir(dir)) {
        // 避免死循环
        if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
            continue;
        }
        // 实现类似tree的效果

        printf("%*s%s\n", width, "", p->d_name);
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
    return 0;
}

//实现类似tree的效果
int tabPrintDir(const char *path, int width)//这里实现了类似 tree 的效果
{
    DIR *pdir = opendir(path);
    ERROR_CHECK(pdir, NULL, "opendir");
    struct dirent *pdirent;
    char buf[1024];
    while ((pdirent = readdir(pdir))) {
        if (strcmp(pdirent->d_name, ".") == 0 || strcmp(pdirent->d_name, "..") == 0) {
            continue;
        }
        printf("%*s%s\n", width, "", pdirent->d_name);
        sprintf(buf, "%s%s%s", path, "/", pdirent->d_name);
        if (pdirent->d_type == 4) {
            tabPrintDir(buf, width + 4);
        }
    }
    closedir(pdir);
    return 0;
}

int main() {
    const char *path = "..";
    tabPrintDir(path, 0);
    return 0;
}