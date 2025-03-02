#define MAX_TREE_SIZE 100

typedef char ElemType;

//孩子节点
typedef struct CTNode
{
    int child;              //孩子结点的下标
    struct CTNode *next;    //指向下一个孩子结点的指针
}*ChildPtr;

//表头结构
typedef struct
{
    ElemType data;          //存放在树中的节点的数据
    int parent;             //存放双亲的下标
    ChildPtr fitstchild;    //指向第一个孩子的指针
}CTBox;

//树结构
typedef struct Tree
{
    CTBox nodes[MAX_TREE_SIZE]; //节点数组
    int r, n;
};
