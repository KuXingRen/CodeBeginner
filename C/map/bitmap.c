// 位图的实现
#include"func.h"

int main() {
    // 假设操作系统位数为8
    int os_bitsize = 8;
    unsigned char *bitmap = (unsigned char *)calloc(256, sizeof(char));
    int arr[] = { 1,2,3,4,3,4,5,6,4,5,6,7 };
    for (int i = 0;i < 12;i++) {
        if (bitmap[arr[i] / os_bitsize] & (1U << (arr[i] % os_bitsize))) {
            // 如果为真，说明该元素已经存在
            printf("%d已经存在\n", arr[i]);
        }
        else {
            //不存在，则添加到位图中
            bitmap[arr[i] / os_bitsize] |= (1 << (arr[i] % os_bitsize));
            printf("%d不存在，添加到位图中\n", arr[i]);
        }
    }
    free(bitmap);
    return 0;
}