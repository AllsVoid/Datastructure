#define MaxSize 100
#include <iostream>
using namespace std;

typedef int TElemType;
// 顺序存储二叉树
typedef TElemType SqBTree[MaxSize];
SqBTree bt;

typedef struct Bnode{
    TElemType data;
    struct Bnode *lchild, *rchild;
}BNode, *Btree;

void createtree(Btree &T){
    char check;
    T=new Bnode;
    cout <<"请输入结点信息："<< endl;
    cin>>T->data;
    cout <<"是否添加"<<T->data<<"的左孩子？"<<endl;
    cin>>check;
    if (check=='Y')
        createtree(T)->lchild;
    else
        T->lchild=NULL;
    cout <<"是否添加"<<T->data"的右孩子？"<<endl;
    if (check=='Y')
        createtree(T)->rchild;
    else
        T->rchild=NULL;
}