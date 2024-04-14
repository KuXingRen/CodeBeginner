// 实时聊天1,先打开一号管道的读端，再打开二号管道的写端
#include"func.h"
#include"funclinux.h"

int main(int argc, char *argv) {
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open1");
    int fdw = open(argv[2], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open2");
    printf("I am chat1\n");
    // 循环聊天
    char buf[128] = { 0 };
    while (1) {
        // 先写
        memset(buf, 0, sizeof(buf));
        // 通过系统调用读取标准输入
        int ret = read(STDIN_FILENO, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read");
        ret = write(fdw, buf, strlen(buf));
        ERROR_CHECK(ret, -1, "write");
        // printf("ret=%d,reader=%s\n", ret, buf);
        // 再读对方发过来的数据
        memset(buf, 0, sizeof(buf));
        ret = read(fdr, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read");
        printf("ret=%d,reader get =%s\n", ret, buf);
    }

    // 读完再写
    memset(buf, 0, sizeof(buf));
    scnaf("%s", &buf);
    //结束
    clsoe(fdr);
    clsoe(fdw);
    return 0;
}
