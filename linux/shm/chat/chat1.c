// 共享内存实现对话
#include"func.h"
#include"funclinux.h"

typedef struct text {
    int useful;
    char buf[1024];
}Text;
// 接收程序
int main(int argc, char **argv) {
    int shmid = shmget(5080, sizeof(Text), 0600 | IPC_CREAT);
    printf("%d\n", shmid);
    ERROR_CHECK(shmid, -1, "shmget");
    // 将共享内存段映射到进程地址空间，并规定共享内存中数据的类型，然后返回首地址
    Text *pText = (Text *)shmat(shmid, NULL, 0);
    pText->useful = 0;
    while (1) {
        if (0 == pText->useful) {
            int ret = read(STDIN_FILENO, pText->buf, 1024);
            pText->useful = 1;
            // 对方发来结束
            if (strncmp("end", pText->buf, 3) == 0) {
                break;
            }
        }
        sleep(1);
    }
    shmdt((void *)pText);
    return 0;
}