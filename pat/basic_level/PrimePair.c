// https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744

#include <stdio.h>

int prime_array[100001] = {NULL};

int isPrime(int a) {
    if (prime_array[a]) return 1;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0) return 0;
    prime_array[a] = 1;
    return 1;
}

int main() {
    int N, count = 0;
    scanf("%d", &N);
    for (int i = 5; i <= N; i++)
        if (isPrime(i-2) && isPrime(i)) count++;
    printf("%d", count);
    return 0;
}
