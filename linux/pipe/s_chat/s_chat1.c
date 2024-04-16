// 使用select多路复用实现全双工通信
#include"func.h"
#include"funclinux.h"

int main(int arrgc, char *argv[]) {
    // 同时打开写端和读端方式等待
    ARGS_CHECK(argc, 3);
    int fdr = open("1.out", O_RDONLY);
    ERROR_CHECK(fdr, -1, "open1");
    int fdw = open("1.out", O_WRONLY);
    ERROR_CHECK(fdw, -1, "open2");

}