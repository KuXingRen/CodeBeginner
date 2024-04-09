// 文件描述符的赋值，直接复制文件描述符给另一个变量
#include"funclinux.h"

int main() {
    int fd = open("fdtest.out", O_RDONLY);
    int fd1 = fd;
    char  buf[256] = { 0 };
    // 读取文件的五个字节
    read(fd, buf, 5);
    printf("%s\n", buf);
    // 关闭文件描述符
    close(fd);
    // 缓冲清零
    memset(buf, 0, sizeof(buf));
    // 文件描述符已经被关闭，perror会报告错误
    read(fd1, buf, 6);
    perror("read");
    return 0;
}