// 使用select多路复用实现全双工通信
#include"func.h"
#include"funclinux.h"

int main(int argc, char *argv[]) {
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open1");
    int fdw = open(argv[2], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open2");
    // 用select监控资源
    char buf[128] = { 0 };
    fd_set rdset;
    int ret;
    int ready_fdnum;
    // 聊天循环
    while (1) {
        // 初始化select
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(fdr, &rdset);
        ready_fdnum = select(fdr + 1, &rdset, NULL, NULL, NULL);
        if (FD_ISSET(STDIN_FILENO, &rdset)) {
            memset(buf, 0, sizeof(buf));
            ret = read(STDIN_FILENO, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read");
            // 当收到0时，说明用户发停止输入的信号
            if (0 == ret) {
                printf("I want leave\n");
                break;
            }
            write(fdw, buf, strlen(buf) - 1);
        }
        if (FD_ISSET(fdr, &rdset)) {
            // 对方发来信息
            memset(buf, 0, sizeof(buf));
            ret = read(fdr, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read");
            // 表示对方断开连接
            if (0 == ret) {
                printf("对方断开连接\n");
                break;
            }
            printf("%s\n", buf);
        }
    }
    close(fdr);
    close(fdw);
}