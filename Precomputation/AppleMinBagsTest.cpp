// 有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个袋子，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1
#include<stdio.h>
#include<limits.h>
int f(int rest) {
    if (rest < 0) {
        return INT_MAX;
    }
    if (rest == 0) {
        return 0;
    }
    //使用8规格的袋子，剩余的苹果几个袋子，有可能返回无效解
    int p1 = f(rest - 8);
    //使用6规格的袋子，剩余的苹果几个袋子，有可能返回无效解
    int p2 = f(rest - 6);
    p1 += (p1 != INT_MAX) ? 1 : 0;
    p2 += (p2 != INT_MAX) ? 1 : 0;
    return p1 < p2 ? p1 : p2;
}
//奇数个肯定装不满，考虑偶数个苹果的情况

int bags(int apple) {
    int ans = f(apple);
    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    for (int i = 0; i < 100; i++) {
        int result = bags(i);
        printf("%d:%d\n", i, result);
    }
    return 0;
}
