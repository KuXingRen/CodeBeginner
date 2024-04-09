// 文件描述符复制，会新创建一个文件描述符指向文件对象
// 使用dup复制文件描述符
#include"funclinux.h"

int main() {
    int fd = open("fdtest.out", O_RDONLY);
    // 使用dup复制文件描述符
    int fd1 = dup(fd);
    char buf[256] = { 0 };
    read(fd, buf, 6);
    printf("%s\n", buf);
    close(fd);
    // 清空buf
    memset(buf, 0, sizeof(buf));
    read(fd1, buf, 6);
    // 多个文件描述符指向同一个文件对象时，会共享\
    文件对象的成员变量，如文件指针，第二次读取会从\
    上次读取结束的位置开始
    printf("%s\n", buf);
    close(fd1);
    return 0;
}