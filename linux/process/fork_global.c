// fork与全局变量
#include"func.h"
#include"funclinux.h"

int num = 10;

int main() {
    pid_t pid;
    pid = fork();
    if (0 == pid) {
        // 全局变量也会写时复制
        printf("I am child,num=%d\n", num);
    }
    else {
        printf("I am father,num=%d\n", num);
        num = 5;
        printf("I am father,now num=%d\n", num);
        sleep(1);
        return 0;
    }
}