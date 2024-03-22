// 实现elf哈希函数
#include"func.h"
unsigned long elf_hash(const char *str) {
    unsigned long h = 0, g;
    while (*str) {
        // 将h左移四位再加上当前字符的ascll值
        h = (h << 4) + *str;
        // 检查h的高四位是否为0；
        if (g = (h & 0xF0000000L) != 0) {
            // 如果高四位不为0，则对h的5-8位进行异或操作
            h ^= (g >> 24);
            h &= ~g; // 清除h的高四位
        }
        str++;
    }
    return (h & 0x7FFFFFFF); // 返回h的低31位
}

int main() {
    int N = 3;
    char *name[] = { "java","python","C++" };
    for (int i = 0;i < N;i++) {
        printf("%-7s:%lu\n", name[i], elf_hash(name[i]));
    }

    return 0;
}