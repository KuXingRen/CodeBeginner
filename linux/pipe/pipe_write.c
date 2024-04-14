// 该进程先写再读
#include"funclinux.h"
#include"func.h"
int main(int argc, char *argv[]) {
    ARGS_CHECK(argc, 2);
    // 以只写的方式打开文件
    int fd = open(argv[1], O_WRONLY);
    ERROR_CHECK(fd, -1, "open");
    printf("I am writer\n");
    close(fd);
    return 0;
}