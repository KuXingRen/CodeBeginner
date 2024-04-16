// select基于管道实现实时聊天
#include"func.h"
#include"funclinux.h"

int main(int argc, char *argv[]) {
    ARGS_CHECK(argc, 3);
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open1");
    int fdr = open(argv[2], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open2");
    char buf[128] = { 0 };
    fd_set rdset;
    int ret;
    int ready_fdnum;
    while (1) {
        // 初始化select 
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(fdr, &rdset);
        ready_fdnum = select(fdr + 1, &rdset, NULL, NULL, NULL);
        if (FD_ISSET(STDIN_FILENO, &rdset)) {
            memset(buf, 0, sizeof(buf));
            ret = read(STDIN_FILENO, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read1");
            if (0 == ret) {
                printf("I want to leave\n");
                break;
            }
            write(fdw, buf, strlen(buf) - 1);
        }
        if (FD_ISSET(fdr, &rdset)) {
            // 对方发来消息
            memset(buf, 0, sizeof(buf));
            ret = read(fdr, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read2");
            if (0 == ret) {
                printf("对方断开连接\n");
                break;
            }
            printf("%s\n", buf);
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}