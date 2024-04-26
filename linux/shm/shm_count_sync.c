// 共享内存的并发操作，使用同步机制
#include"func.h"
#include"funclinux.h"

#define NUMS 100000
int main(int argc, char **argv) {
    // 打开一个共享内存段
    int shmid = shmget(100, 4096, 0600 | IPC_CREAT);
    ERROR_CHECK(shmid, -1, "shmget");
    int *p = (int *)shmat(shmid, NULL, 0);
    memset(p, 0, 4096);
    // 初始化信号量
    sem_t *sem = sem_open("pSem", O_CREAT, 0600, 1);
    ERROR_CHECK(sem, SEM_FAILED, "sem_open");
    if (!fork()) {
        for (int i = 0;i < NUMS;i++) {
            sem_wait(sem);
            p[0]++;
            sem_post(sem);
        }
        exit(0);
    }
    else {
        for (int i = 0;i < NUMS;i++) {
            sem_wait(sem);
            p[0]++;
            sem_post(sem);
        }
        wait(NULL);
        printf("%d\n", p[0]);
        // 关闭信号量
        sem_close(sem);
    }
    // 删除共享内存段
    ERROR_CHECK(shmctl(shmid, IPC_RMID, 0), -1, "shmctl");
    // 删除信号量
    sem_unlink("pSem");
    return 0;
}