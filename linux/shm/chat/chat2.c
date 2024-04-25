// 共享内存实现对话
#include"func.h"
#include"funclinux.h"

typedef struct text {
    int useful;
    char buf[1024];
}Text;
// 发送程序
int main(int argc, char **argv) {
    // 打开共享内存段
    int shmid = shmget(5080, sizeof(Text), 0600 | IPC_CREAT);
    ERROR_CHECK(shmid, -1, "shmget");
    Text *PText = (Text *)shmat(shmid, NULL, 0);
    PText->useful = 0;
    while (1) {
        if (1 == PText->useful) {
            write(STDOUT_FILENO, PText->buf, strlen(PText->buf));
            PText->useful = 0;
            if (strncmp("end", PText->buf, 3) == 0) {
                break;
            }
        }
        sleep(1);
    }
    shmdt((void *)PText);
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}