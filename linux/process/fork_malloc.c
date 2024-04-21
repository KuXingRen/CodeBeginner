// fork与malloc的共享
#include"func.h"
#include"funclinux.h"

int main() {
    pid_t pid;
    char *p = malloc(20);
    strcpy(p, "helloworld");
    pid = fork();
    if (0 == pid) {
        //孩子的代码写这里
        printf("I am child,num=%s\n", p);
        return 0;
    }
    else {
        //父亲的代码写这里
        printf("I am parent num=%s\n", p);
        strncpy(p, "HELLO", 5);
        printf("I am parent num=%s\n", p);
        sleep(1);
        return 0;
    }
}