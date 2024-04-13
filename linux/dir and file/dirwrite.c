//定义一个学生结构体类型struct student，\
里边含有学号，姓名，分数，定义结构体数组struct student s[3],\
给数组赋初值后，写入文件，然后通过lseek偏移到开头，\
然后再读取进行打印输出（注意，是直接把结构体数组写入文件，\
双击打开文件看不到学号，分数这些的，也不需要双击打开看）

#include"funclinux.h"

struct student {
    int id;
    char name[20];
    int score;
};

int main() {
    // 初始化结构体数组
    struct student stu[3] = {
        {1,"sam",95},
        {2,"Tony",97},
        {3,"jack",91}
    };
    // 打开文件
    int fd = open("student.out", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // 将结构体写入到我呢见
    write(fd, stu, sizeof(stu));

    // 将lseek移动到文件开头
    lseek(fd, 0, SEEK_SET);

    // 关闭文件
    close(fd);

    // 重新打开文件进行读取
    fd = open("student.out", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // 读取内容到结构体数组
    struct student stu_read[3];
    read(fd, stu_read, sizeof(stu_read));

    // 打印读取的内容
    for (int i = 0;i < 3;i++) {
        printf("%d %s %d\n", stu_read[i].id, stu_read[i].name, \
            stu_read[i].score);
    }
    // 关闭文件
    close(fd);

    return 0;
}