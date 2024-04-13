// 使用dup重定向标准输出
#include"funclinux.h"

int main() {
    char buf[128] = { 0 };
    char *arr = "hello world\n";
    // 打开文件并获取文件门描述符
    int fd = open("res.out", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
    }
    // 保存标准输出的副本
    int stdout_copy = dup(STDOUT_FILENO);
    if (stdout_copy < 0) {
        perror("dup");
        close(fd);
        return -1;
    }
    // 重定向标准输出
    printf("标准输出文件描述符%d\n", STDOUT_FILENO);
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        close(stdout_copy);
    }
    // 所有标准输出都会定向到文件中
    printf("%s", arr);
    lseek(fd, 0, SEEK_SET);
    size_t read_size;
    if (read_size = read(fd, buf, 5) < 1) {
        perror("read");
        close(fd);
        close(stdout_copy);
        return -1;
    }
    lseek(fd, 0, SEEK_END);
    // 读取文件内容,以下内容不会出现在终端中，而是在重定向之后的文件中
    printf("从文件中读取的内容%s,size_t =%ld\n", buf, read_size);
    // 关闭文件描述符
    close(fd);
    // 恢复标准输出重定向
    if (dup2(stdout_copy, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(stdout_copy);
        return -1;
    }
    // 关闭副本的文件描述符
    close(stdout_copy);
    printf("标准输出已恢复\n");
    return 0;
}