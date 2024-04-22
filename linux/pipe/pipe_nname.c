// 创建一个无名管道，让父进程写，子进程度
#include"func.h"
#include"funclinux.h"

int main() {
    int fds[2];
    pipe(fds);
    pid_t pid = fork();
    if (0 == pid) {
        // 孩子关闭写端
        close(fds[1]);
        char buf[128] = { 0 };
        read(fds[0], buf, sizeof(buf));
        printf("I am child,get=%s\n", buf);
    }
    else {
        // 父亲关闭读端
        close(fds[0]);
        sleep(3);
        write(fds[1], "hello", 5);
    }
    return 0;
}