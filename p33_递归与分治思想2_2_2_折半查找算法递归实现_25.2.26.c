/*

  折半查找算法的递归实现

*/

#include<stdio.h>

int bin_search( int str[], int low, int high, int key)
{
    int mid;
    if(low > high) return -1;

    mid = (low + high ) / 2;
    if(str[mid] == key)
    {
        return mid; //查找成功
    }
    if(str[mid] < key)
    {
        return bin_search(str, mid + 1, high, key);  // 查找右半部分
    }
    if(str[mid] > key)
    {
        return bin_search(str, low, mid - 1, key);  // 查找左半部分
    }

    return -1;
}

int main()
{
    int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int n, addr;

    printf("请输入待查找的关键字:\n");
    scanf("%d",&n);

    addr = bin_search(str, 0, 10, n);
    if( -1 != addr)
    {
        printf("查找成功,可喜可贺,可口可乐! 关键字 %d 所在的位置是: %d\n",n,addr);
    }
    else
    {
        printf("查找失败!\n");
    }

    return 0;
}