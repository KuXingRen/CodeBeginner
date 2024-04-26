// 共享内存的并发操作，不使用同步机制，会导致结果不等于2*NUM
#include"func.h"
#include"funclinux.h"

#define NUM 100000

int main(int argc, char **argv) {
    // 打开一个共享内存区域
    int shmid = shmget(100, 4096, IPC_CREAT | 0600);
    // 将共享内存映射到进程地址空间
    int *p = (int *)shmat(shmid, NULL, 0);
    memset(p, 0, 4096);
    ERROR_CHECK(shmid, -1, "shmget");
    if (!fork()) {
        for (int i = 0;i < NUM;i++) {
            p[0]++;
        }
        ERROR_CHECK(shmctl(shmid, IPC_RMID, 0), -1, "shmctl");
        exit(0);
    }
    else {
        for (int i = 0;i < NUM;i++) {
            p[0]++;
        }
        // 等待子进程结束
        wait(NULL);
        printf("%d\n", p[0]);
        ERROR_CHECK(shmctl(shmid, IPC_RMID, 0), -1, "shmctl");
    }
}