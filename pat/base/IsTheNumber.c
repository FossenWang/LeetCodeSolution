// https://pintia.cn/problem-sets/14/problems/739
// 本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。
// 其中N是用户传入的参数。如果N满足条件，则该函数必须返回1，否则返回0。


#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */


int IsTheNumber(const int N)
{
    double sn = sqrt(N);
    double int_part = round(sn);
    if ((sn - int_part) != 0.0)
    {
        return 0;
    }

    // 保存数字的位数, int 长度最多只有十位
    int num[10] = {0};
    // i 为数字 N 当前位数对应的数组索引，起于个位，即数组索引为 0
    int n = N, i = 0, j;
    while (n)
    {
        // 求当前数位的值并保存
        num[i] = n % 10;
        // 从数组末尾 i 前一位开始，向前遍历数组
        for (j = i - 1; j >= 0; j--)
        {
            if (num[j] == num[i])
            {
                return 1;
            }
        }
        // 每次遍历都向左移一位小数点
        n /= 10;
        i++;
    }
    return 0;
}