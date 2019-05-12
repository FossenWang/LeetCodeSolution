// https://pintia.cn/problem-sets/14/problems/738
// 本题要求实现一个函数，求单链表L结点的阶乘和。这里默认所有结点的值非负，且题目保证结果在int范围内。


#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */

/* 阶乘 */
int Factorial( int n )
{
    if (n < 0) return 0;

    int ans = 1, i = n;

    for (i; i > 0; i--)
    {
        ans *= i;
    }
    return ans;
}

/* 阶乘和 */
int FactorialSum( List L )
{
    int sum = 0;
    PtrToNode nodep = L;
    while (nodep)
    {
        sum += Factorial(nodep->Data);
        nodep = nodep->Next;
    }
    return sum;
}
