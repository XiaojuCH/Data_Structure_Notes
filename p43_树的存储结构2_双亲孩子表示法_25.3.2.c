#define MAX_TREE_SIZE 100

typedef char ElemType;

//���ӽڵ�
typedef struct CTNode
{
    int child;              //���ӽ����±�
    struct CTNode *next;    //ָ����һ�����ӽ���ָ��
}*ChildPtr;

//��ͷ�ṹ
typedef struct
{
    ElemType data;          //��������еĽڵ������
    int parent;             //���˫�׵��±�
    ChildPtr fitstchild;    //ָ���һ�����ӵ�ָ��
}CTBox;

//���ṹ
typedef struct Tree
{
    CTBox nodes[MAX_TREE_SIZE]; //�ڵ�����
    int r, n;
};
