typedef int ElemType;

typedef struct BTnode{
    ElemType data;
    struct Bnode *lchild, *rchild;
    int ltag,rtag;
}BTnode,*BTree;