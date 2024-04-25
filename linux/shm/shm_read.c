// 使用共享内存在在非亲缘进程之间进行通信
#include"func.h"
#include"funclinux.h"

int main(int argc, char **argv) {
    int fd = open("1.out", O_CREAT);
    ERROR_CHECK(fd, -1, "open");
    close(fd);
    key_t key = ftok("1.out", 1);
    ERROR_CHECK(key, -1, "ftok");
    // 打开一个共享内存段
    int shmid = shmget(key, 4096, 0600 | IPC_CREAT);
    ERROR_CHECK(shmid, -1, "shmget");
    // 将共享内存段映射到进程地址空间,并获得首地址
    char *pMap = (char *)shmat(shmid, NULL, 0);
    printf("Receive data=%s\n", pMap);
    // 删除共享内存段
    ERROR_CHECK(shmctl(shmid, IPC_RMID, 0), -1, "shmctl");
    return 0;
}