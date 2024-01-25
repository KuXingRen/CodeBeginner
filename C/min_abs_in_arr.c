//  给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小
#include"func.h"
#define range 1000
#define N 10
int main() {
    pSeqTable table = NULL;
    srand(time(NULL));
    getRandSeqTable(&table, range, N);
    printSeqTable(table);
    TableElem arr[range] = { 0 };
    int i = 0, k = 0;
    // 计数排序
    for (i = 0; i < N; i++) {
        arr[table->table[i]]++;
    }
    for (i = 0; i < range; i++) {
        if (0 < arr[i] && 0 != arr[i]) {
            for (int j = 0; j < arr[i]; j++) {
                table->table[k] = i;
                printf("%4d", table->table[k]);
                k++;
            }
        }
    }
    putchar('\n');
    // 因为已经排序，只需要统计相邻元素的插值即可找到答案
    int x = 0, y = 1, min_diff = abs(table->table[0] - table->table[1]);
    int diff = min_diff;
    for (int i = 1;i < N - 1;i++) {
        diff = abs(table->table[i] - table->table[i + 1]);
        if (diff < min_diff) {
            x = table->table[i];
            y = table->table[i + 1];
            min_diff = diff;
        }
    }
    printf("x=%d,y=%d,abs=%d\n", x, y, min_diff);
    return 0;
}