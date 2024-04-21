// fork与局部变量共享情况(写时复制)
#include"func.h"
#include"funclinux.h"

int main() {
    pid_t pid;
    int num = 10;
    pid = fork();
    if (0 == pid) {
        printf("I am child,num=%d\n", num);
    }
    else {
        printf("I am father,num=%d\n", num);
        num = 5;
        printf("I am father,num=%d\n", num);
        sleep(1);
        return 0;
    }
}