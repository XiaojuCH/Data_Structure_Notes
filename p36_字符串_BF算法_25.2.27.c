/*

用你熟悉的一门语言写出BF算法的实现形式

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
        printf("错误:字串过大!\n");
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
                    printf("在位置 %d 处查询成功!\n",i);
                    return;
                }
            }
        }
    }

    printf("查询失败,并无此字串!\n");
}