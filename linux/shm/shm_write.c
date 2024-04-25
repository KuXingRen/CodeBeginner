// 使用共享内存在非亲缘进程之间通信
#include"func.h"
#include"funclinux.h"

int main(int argc, char **argv) {
    int fd = open("1.out", O_CREAT);
    ERROR_CHECK(fd, -1, "open");
    close(fd);
    // 写入端获得一个key
    key_t key = ftok("1.out", 1);
    ERROR_CHECK(key, -1, "ftok");
    int shmid = shmget(key, 4096, IPC_CREAT);
    ERROR_CHECK(key, -1, "shmget");
    // 将共享内存映射到进程地址空间，名获取首地址
    char *pMap = (char *)shmat(shmid, NULL, 0);
    memset(pMap, 0, 4096);
    strcpy(pMap, "Hello world");
    // 将进程与共享内存分离
    ERROR_CHECK(shmdt(pMap), -1, "shmddt");
    return 0;
}