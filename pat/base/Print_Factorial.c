// https://pintia.cn/problem-sets/14/problems/742
// 本题要求实现一个打印非负整数阶乘的函数。
// 其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。

#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */

void Print_Factorial(const int N)
{
    if (N >= 0 && N <= 12)
    {
        int ans = 1, i = N;
        for (i; i > 0; i--)
        {
            ans *= i;
        }
        printf("%d", ans);
    }
    else if (N > 12 && N <= 1000)
    {
        // 阶乘结果保存在数组中，每个数组元素都是一位数
        int num[3000] = {0};
        num[0] = 1;
        // f: 阶乘元素, j: 当前位数对应的数组索引，k: 结果总位数，carry 进位，temp: 临时变量
        int f, j, k = 1, carry = 0, temp;

        // 将当前的阶乘元素 f 依次与总结果 num 的每一位相乘
        for (f = 2; f <= N; f++)
        {
            for (j = 0; j < k; j++)
            {
                temp = num[j] * f + carry;
                // 留下当前位的数值
                num[j] = temp % 10;
                // 去掉个位后就是下一位的进位值
                carry = temp / 10;
            }
            // 此时的 carry 保存了第 k 位数的进位值
            while (carry != 0)
            {
                num[k] = carry % 10;
                k++;
                carry = carry / 10;
            }
        }

        // 打印结果，数组索引比位数 k 小一
        int i;
        for (i = k - 1; i >= 0; i--)
        {
            printf("%d", num[i]);
        }
    }
    else
    {
        printf("Invalid input");
    }
}
