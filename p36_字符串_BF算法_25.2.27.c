/*

������Ϥ��һ������д��BF�㷨��ʵ����ʽ

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void BF(char *p, char *q);


int main()
{
    char p[15] = "XXXiaojuCHNB";
    char q[8] = "Xiaoju";

    BF(p, q);

    return 0;
}

void BF(char *p, char *q)
{
    int a = strlen(p);
    int b = strlen(q);
    if(b > a)
    {
        printf("����:�ִ�����!\n");
        exit(0);
    }
    else
    {
        for(int i = 0 ; i < a - b; i++)
        {
            int count = 0;
            int k = i;
            for(int j = 0 ; j < b; j++)
            {
                if(q[j] == p[k++])
                {
                    count++;
                }
                if(count == b)
                {
                    printf("��λ�� %d ����ѯ�ɹ�!\n",i);
                    return;
                }
            }
        }
    }

    printf("��ѯʧ��,���޴��ִ�!\n");
}