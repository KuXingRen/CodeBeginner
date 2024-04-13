// 传递任意一个目录路径，能够显示该目录的ls -l的效果
// 需要使用stat结构体，获取inode在内的文件信息
#include"funclinux.h"


// 权限码转换为字符串
// 权限码每一位都有其意义，拿到权限码之后，将权限码与 \
不同的权限掩码进行相与，根据结果的真假来判断需要在字符\
串中填充的字符
char *mode_to_string(mode_t mode, char str[]) {
    memset(str, 0, 11 * sizeof(char));
    // 文件类型
    if (S_ISREG(mode)) str[0] = '-';
    else if (S_ISDIR(mode)) str[0] = 'd';
    else if (S_ISCHR(mode)) str[0] = 'c';
    else if (S_ISBLK(mode)) str[0] = 'b';
    else if (S_ISFIFO(mode)) str[0] = 'p';
    else if (S_ISLNK(mode)) str[0] = 'l';
    else if (S_ISSOCK(mode)) str[0] = 's';
    else str[0] = '?';

    // 用户权限
    str[1] = (mode & S_IRUSR) ? 'r' : '-';
    str[2] = (mode & S_IWUSR) ? 'w' : '-';
    str[3] = (mode & S_IXUSR) ? 'x' : '-';

    // 组权限
    str[4] = (mode & S_IRGRP) ? 'r' : '-';
    str[5] = (mode & S_IWGRP) ? 'w' : '-';
    str[6] = (mode & S_IXGRP) ? 'x' : '-';

    // 其他用户权限
    str[7] = (mode & S_IROTH) ? 'r' : '-';
    str[8] = (mode & S_IWOTH) ? 'w' : '-';
    str[9] = (mode & S_IXOTH) ? 'x' : '-';

    str[10] = '\0'; // 字符串结束符
    return str;
}

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
    char str[11];
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
        printf("%s %2ld %s %s %s %s\n", \
            mode_to_string(buf.st_mode, str), buf.st_nlink,
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