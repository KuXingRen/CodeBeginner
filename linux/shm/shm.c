#include"func.h"
#include"funclinux.h"

#define PERM S_IRUSR | S_IWUSR

int main(int argc, char **argv) {
    // 在父子进程之间进行通信，key由系统选择
    int shmid = shmget(IPC_PRIVATE, 1024, PERM);
    ERROR_CHECK(shmid, -1, "shmget");
    pid_t pid = fork();
    if (0 == pid) {
        sleep(5);
        char *c_addr = (char *)shmat(shmid, NULL, 0);
        printf("child pid=%d, shmid=%d, Read buffer=%s\n", \
            getpid(), shmid, c_addr);
        exit(0);
    }
    else {
        // 将共享内存映射到进程地址空间
        char *p_addr = (char *)shmat(shmid, NULL, 0);
        //将共享内存初始化为0
        memset(p_addr, 0, 1024);
        strncpy(p_addr, "Hello!", 1024);
        printf("parent %d Write buffer %s\n", getpid(), p_addr);
        sleep(2);
        // 等待子进程
        wait(NULL);
        // 删除共享内存
        shmctl(shmid, IPC_RMID, 0);
        return 0;
    }
}