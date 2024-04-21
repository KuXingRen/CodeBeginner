// 使用fork创建子进程，并打印两个进程的信息
#include"func.h"
#include"funclinux.h"
int main() {
    pid_t pid;
    pid = fork();
    if (0 == pid) {
        // 子进程的代码
        printf("I am child,pid=%d,ppid=%d\n", getpid(), getppid());
    }
    else {
        // 父进程的代码
        printf("I am father,pid=%d,ppid=%d\n", getpid(), getppid());
    }
    return 0;
}