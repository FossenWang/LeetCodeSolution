// https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808
// 输入样例：
// 00100 6 4
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218
// 输出样例：
// 00000 4 33218
// 33218 3 12309
// 12309 2 00100
// 00100 1 99999
// 99999 5 68237
// 68237 6 -1

#define SWAPNODE(A, B)         \
    {                          \
        struct Node *temp = A; \
        A = B;                 \
        B = temp;              \
    }

#include <stdio.h>

struct Node
{
    int Address;
    int Data;
    int Next;
};

const int len = 100001;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int start = a, N = b, K = c;
    int i, j, address = start;

    struct Node storage[len];
    struct Node *sequence[len];

    // 读取节点数据
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        struct Node node;
        node.Address = a;
        node.Data = b;
        node.Next = c;
        storage[a] = node;
    }
    // 将链表储存到序列中
    for (i = 0; i < N; i++)
    {
        sequence[i] = &storage[address];
        address = storage[address].Next;
        // 遇到 -1 截止链表
        if(address == -1)
            N = i + 1;
    }
    // 反转链表
    int sub_end, sub_start;
    for (sub_end = K - 1; sub_end < N; sub_end += K)
    {
        sub_start = sub_end - (K - 1);
        for (j = sub_start; j <= (sub_start + sub_end) / 2; j++)
        {
            SWAPNODE(sequence[j], sequence[sub_start + sub_end - j]);
        }
    }
    // 输出链表
    for (i = 0; i<N-1; i++)
    {
        printf("%05d %d %05d\n", sequence[i]->Address, sequence[i]->Data, sequence[i+1]->Address);
    }
    i = N-1;
    printf("%05d %d %d\n", sequence[i]->Address, sequence[i]->Data, -1);
    return 0;
}
