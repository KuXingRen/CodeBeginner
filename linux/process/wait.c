// 使用wait检查子进程的执行状态
#include"func.h"
#include"funclinux.h"
int main() {
    pid_t pid;
    pid = fork();
    if (0 == pid) {
        //孩子的代码写这里
        printf("I am child,pid=%d,ppid=%d\n", getpid(), getppid());
        exit(3);
    }
    else {
        //父亲的代码写这里
        printf("I am parent,mychild=%d,pid=%d,ppid=%d\n", pid, getpid(), getppid());
        int status;
        pid = wait(&status);//孩子结束以后，会给父亲发送SIGCHLD,可以回收资源
        if (WIFEXITED(status)) {
            printf("child exit code=%d\n", WEXITSTATUS(status));
        }
        else {
            printf("child crash\n");
        }
        printf("wait pid=%d\n", pid);
        return 0;
    }
}