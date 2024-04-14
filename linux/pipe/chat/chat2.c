// 实时聊天2，该进程先打开一号管道的写端，再打开二号管道的读端，防止死锁
#include"func.h"
#include"funclinux.h"

int main(int argc, char *argv[]) {
    ARGS_CHECK(argc, 3);
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open1");
    int fdr = open(argv[2], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open2");
    printf("I am char2\n");
    // 循环聊天
    char buf[128] = { 0 };
    while (1) {
        // chat2先读
        memset(buf, 0, sizeof(buf));
        int ret = read(fdr, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read");
        printf("ret=%d,get=%s", ret, buf);
        // 读完再写
        memset(buf, 0, sizeof(buf));
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "open_stdin");
        write(fdw, buf, strlen(buf));
    }
    close(fdr);
    close(fdw);
    return 0;
}