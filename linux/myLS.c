// 传递任意一个目录路径，能够显示该目录的ls -l的效果
// 需要使用stat结构体，获取inode在内的文件信息
#include"funclinux.h"

char *timeTansform(time_t t, char *buffer) {
    struct tm *info;
    info = localtime(&t);
    strftime(buffer, 80, "%b %e %H:%M", info);
    return buffer;
}

int myls(const char *path) {
    DIR *dir;
    dir = opendir(path);
    char buffer[80];
    if (NULL == dir) {
        perror("opendir");
        return -1;
    }
    struct dirent *p;
    struct stat buf;
    while (p = readdir(dir)) {
        if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
            continue;
        }
        stat(p->d_name, &buf);
        memset(buffer, 0, sizeof(buffer));
        printf("%o %2ld %s %s %s %s\n", \
            buf.st_mode, buf.st_nlink,
            getpwuid(buf.st_uid)->pw_name, \
            getgrgid(buf.st_gid)->gr_name, \
            timeTansform(buf.st_mtime, buffer), \
            p->d_name);
    }
    closedir(dir);
}

int main() {
    const char *path = ".";
    myls(path);
    return 0;
}