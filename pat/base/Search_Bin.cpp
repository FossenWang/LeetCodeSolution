// https://pintia.cn/problem-sets/14/problems/44932
// 给一个严格递增数列，函数int Search_Bin(SSTable T, KeyType k)用来二分地查找k在数列中的位置。
// 其中T是有序表，k是查找的值。


#include <iostream>
#include <assert.h>

using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType *R;
    int length;
} SSTable;

void addList(SSTable &T, KeyType * arr, int len)
{
    T.R = new ElemType[MAXSIZE + 1];
    T.length = len;
    int i;
    for (i = 1; i <= T.length; i++)
        T.R[i].key = arr[i-1];
}

int Search_Bin(SSTable T, KeyType k);

int main()
{
    SSTable T;
    KeyType arr[] = {1, 2, 3, 4, 5};
    addList(T, arr, 5);
    assert(Search_Bin(T, 10) == 0);
    assert(Search_Bin(T, 1) == 1);
    assert(Search_Bin(T, 2) == 2);
    return 0;
}

/* 请在这里填写答案 */

int Search_Bin(SSTable T, KeyType k)
{
    int len = T.length, i = len / 2;

    while (i > 0 && i <= len)
    {
        KeyType key = T.R[i].key;
        if (k == key)
        {
            return i;
        }
        else if (k>key)
        {
            i = (i + len) / 2 + 1;
        }
        else
        {
            i = (1 + i) / 2;
        }
    }
    return 0;
}
