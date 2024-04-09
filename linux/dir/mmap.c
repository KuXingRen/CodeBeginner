// 新建一个文件，里边内容为hello，通过mmap映射该文件后，\
修改hello为world，然后解除映射

#include"funclinux.h"

int main() {
    const char *content = "hello";
    const char *file = "res.out";

    // 创建并写入文件
    int fd = open(file, O_RDWR | O_CREAT, S_IRUSR, S_IWUSR);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    write(fd, content, strlen(content));
    close(fd);

    // 重新打开文件并映射
    fd = open(file, O_RDWR);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // 映射文件
    char *map = mmap(0, strlen(content), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        close(fd);
        perror("mmap");
        return -1;
    }

    // 修改文件内容
    strcpy(map, "world");
    // 同步到磁盘
    if (msync(map, strlen("world"), MS_SYNC) == -1) {
        perror("Could not sync the file to disk\n");
    }

    // 解除映射
    if (munmap(map, strlen("world")) == -1) {
        close(fd);
        perror("Error un-mmapping the file\n");
        return -1;
    }

    // 关闭文件

    close(fd);
    return 0;
}
