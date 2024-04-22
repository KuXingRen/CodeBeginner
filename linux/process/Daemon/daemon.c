// 创建守护进程并不断写入数据
#include"func.h"
#include"funclinux.h"

int main() {
    pid_t pid;
    pid = fork();
    char buf[] = "wohenshuai\n";
    if (0 == pid) {
        // 脱离会话组
        setsid();
        // 尽可能关闭从父进程继承过来的文件描述符
        for (int i = 3;i < 64;i++) {
            close(i);
        }
        // 执行代码
        int i = 10;
        int times = 3;
        int fd = open("file", O_CREAT | O_WRONLY, 0666);
        ERROR_CHECK(fd, -1, "open");
        char buf[] = "wohenshuai";
        while (i--) {
            sleep(times);
            write(fd, buf, sizeof(buf));
        }
        close(fd);
    }
    else {
        exit(0);
    }
}