// https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808

#include <stdio.h>

int num[111] = {0};

void reverse(int a[], int start, int end)
{
    if (start >= end) return;
    for (int i = start; i <= (start + end) / 2; i++)
    {
        int tmp = a[i];
        a[i] = a[start + end - i];
        a[start + end - i] = tmp;
    }
}

int main()
{
    // int N, M;
    // scanf("%d %d", &N, &M);
    // int i;
    // for(i=0;i < N;i++) scanf("%d", &num[i]);

	// M %= N;
    // reverse(num, 0, N-M-1);
    // reverse(num, N-M, N-1);
    // reverse(num, 0, N-1);

    // printf("%d", num[0]);
    // for (i=1;i<N;i++) printf(" %d", num[i]);

    // int a[] = {1, 2, 3, 4, 5, 6};
    // int i, N = 6, M = 5;
    int a[] = {1, 2};
    int i, N = 2, M = 10;
	M %= N;
    reverse(a, 0, N - M - 1);
    reverse(a, N - M, N - 1);
    reverse(a, 0, N - 1);
    printf("%d", a[0]);
    for (i = 1; i < N; i++)
        printf(" %d", a[i]);
    return 0;
}
