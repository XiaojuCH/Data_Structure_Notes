#include<stdio.h>


typedef struct List
{
    int num;
    struct List *next;
} List;

List *head = NULL;
List *tail = NULL;

int main()
{
    
    printf("1.初始化链表\n");
    printf("2.插入♂节点\n");
    printf("3.删除节点\n");
    printf("4.返回节点位置\n");
    printf("5.遍历链表\n");
    printf("0.退出\n");

    while(1)
    {
        printf("请选择你的操作: ");
        int choice;
        scanf("%d",&choice);
        fflush(stdin);

        if(choice == 0) break;

        switch(choice)
        {
            case 1:
            {
                printf("输入节点的值,输入0完成初始化\n");
                while(1)
                {
                    List *new = (List*)malloc(sizeof(List));
                    if(new == NULL)
                    {
                        printf("内存分配失败!");
                        return;
                    }

                    int number;
                    scanf("%d",&number);
                    if(number == 0) 
                    {
                        free(new);
                        break;
                    }

                    new->num = number;

                    if(head == NULL)
                    {
                        head = new;
                        tail = new;
                    }
                    else
                    {
                        tail->next = new;
                        tail = tail->next;
                    }
                    tail->next = NULL;
                }
                printf("初始化成功!\n");
                break;
            }

            case 2:
            {
                if(!head)
                {
                    printf("请先初始化链表!\n");
                    break;
                }

                List *New = (List*)malloc(sizeof(List)); 
                int numm;
                printf("请输入你需要插♂的内容:\n");
                scanf("%d",&numm);

                New->num = numm;

                printf("请问你要插入♂到第几个位置:\n");
                int location , loc = 1;
                scanf("%d",&location);

                for(List *q = head ; q != NULL ; q = q->next)
                {
                    ++loc;
                    if(loc == location)
                    {
                        New->next = q->next;
                        q->next = New;
                    }
                }
                printf("插入♂成功!\n");
                break;
            }

            case 3:
            {
                printf("请输入需要删除的节点的位置:");
                int loc , location = 1;
                scanf("%d",&loc);
                
                List *prev = NULL;
                List *curr = head;
                while (curr != NULL && location < loc) {
                    prev = curr;
                    curr = curr->next;
                    location++;
                }
            
                if (curr == NULL) {
                    printf("位置超出链表长度，删除失败！\n");
                } else {
                    prev->next = curr->next;  // 连接前后节点
                    free(curr);  // 删除当前节点
                    printf("删除成功!\n");
                }
                break;
            }

            case 4:
            {
                printf("请输入你想要返回位置的内容:");
                int n , location = 1;
                scanf("%d",&n);

                for(List *q = head; q != NULL; q = q->next)
                {
                    if(q->num == n)
                    {
                        printf("%d 在第 %d 个位置上\n",n,location);
                        break;
                    }
                    else
                    {
                        location++;
                    }
                }
                break;
            }

            case 5:
            {
                if(!head)
                {
                    printf("请先初始化链表!\n");
                    break;
                }
                printf("*****************链表中的元素*****************\n");
                for(List *p = head ; p != NULL ; p = p->next)
                {

                    printf("%d  ",p->num);
                }
                printf("\n");
                break;
            }

            default: 
            {
                printf("请输入正确的选项!\n");
                continue;
            }
        }

    }

    return 0;
}
