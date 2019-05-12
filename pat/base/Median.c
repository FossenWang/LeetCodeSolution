// https://pintia.cn/problem-sets/14/problems/743

#include <stdio.h>
#include <assert.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
    ElementType A[MAXN];
    int N, i;

    ElementType arr1[] = {1, 2, 3, 4, 5};
    assert(Median(arr1, 5) == 3);
    ElementType arr2[] = {3, 2, 1, 5, 4};
    assert(Median(arr2, 5) == 3);
    ElementType arr3[] = {12.3, 34, -5};
    assert(Median(arr3, 3) == 12.3f);
    ElementType arr4[] = {2, 3, 1, 4};
    assert(Median(arr4, 4) == 3);
    return 0;
}

/* 你的代码将被嵌在这里 */

void ShellSort(ElementType A[], int N)
{
    int i, j, increment;
    ElementType temp;
    for (increment = N / 2; increment > 0; increment /= 2)
        for (i = increment; i < N; i++)
        {
            temp = A[i];
            for (j = i; j >= increment; j -= increment)
                if (temp < A[j - increment])
                    A[j] = A[j - increment];
                else
                    break;
            A[j] = temp;
        }
}

ElementType Median(ElementType A[], int N)
{
    ShellSort(A, N);
    return A[N / 2];
}