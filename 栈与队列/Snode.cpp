#include <cstdio>

typedef int ElemType;

typedef struct Snode {
    ElemType data;
    struct Snode* next;
} Snode, *LinkStack;

/*
初始化
*/
bool InitStack(LinkStack& S) {
    S = NULL;
    return true;
}

/*
入栈
*/
bool Push(LinkStack& S, int e) {
    LinkStack p;
    p = new Snode;
    p->data = e;  // e 存入新结点数据域
    p->next = S;  //修改新结点的 next 指针指向 S
    S = p;        //修改新栈顶指针为 p
    return true;
}

/*
出栈
*/
bool Pop(LinkStack& S, int& e) {
    LinkStack p;
    if (S == NULL)
        return false;
    e = S->data;  //暂存栈顶元素
    p = S;        //暂存栈顶地址
    S = S->next;
    delete p;
    return true;
}

/*
取栈顶
*/
int GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
    else
        return -1;
}