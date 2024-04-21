// fork 与 文件描述的共享
#include"func.h"
#include"funclinux.h"

int main() {
    pid_t pid;
    int fd;
    int ret;
    char buf[128] = { 0 };
    fd = open("file", O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    pid = fork();
    if (0 == pid) {
        memset(buf, 0, sizeof(buf));
        ret = read(fd, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read");
        printf("I am child,I gets=%s\n", buf);
    }
    else {
        memset(buf, 0, sizeof(buf));
        ret = read(fd, buf, 5);
        ERROR_CHECK(ret, -1, "read");
        printf("I am father,I gets=%s\n", buf);
    }
    return 0;
}