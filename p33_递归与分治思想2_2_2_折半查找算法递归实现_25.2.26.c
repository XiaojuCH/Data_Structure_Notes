/*

  �۰�����㷨�ĵݹ�ʵ��

*/

#include<stdio.h>

int bin_search( int str[], int low, int high, int key)
{
    int mid;
    if(low > high) return -1;

    mid = (low + high ) / 2;
    if(str[mid] == key)
    {
        return mid; //���ҳɹ�
    }
    if(str[mid] < key)
    {
        return bin_search(str, mid + 1, high, key);  // �����Ұ벿��
    }
    if(str[mid] > key)
    {
        return bin_search(str, low, mid - 1, key);  // ������벿��
    }

    return -1;
}

int main()
{
    int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int n, addr;

    printf("����������ҵĹؼ���:\n");
    scanf("%d",&n);

    addr = bin_search(str, 0, 10, n);
    if( -1 != addr)
    {
        printf("���ҳɹ�,��ϲ�ɺ�,�ɿڿ���! �ؼ��� %d ���ڵ�λ����: %d\n",n,addr);
    }
    else
    {
        printf("����ʧ��!\n");
    }

    return 0;
}