#include <cstdio>
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DuLnode {
    ElemType data;
    //前驱指针 *prior
    //后继指针 *next
    struct DuLnode *prior, *next;
} DuLnode, *DuLinkList;

bool InitList_L(DuLinkList& L) {
    L = new DuLnode;
    if (!L)
        return false;
    L->prior = L->next = NULL;
    return true;
}

/*
头插创建
*/
void CreateDuList_H(DuLinkList& L) {
    int n;
    DuLinkList s;  //指针变量
    L = new DuLnode;
    L->prior = L->next = NULL;  //建立带头结点的空链表
    cout << "请输入元素个数 n：" << endl;
    cin >> n;
    cout << "请依次输入 n 个元素：" << endl;
    cout << "头插法创建单链表" << endl;
    while (n--) {
        s = new DuLnode;
        cin >> s->data;  //输入元素值复制给新节点的数据域
        if (L->next)  //如果 L 后又结点，修改后面结点的 prior 指针
            L->next->prior = s;
        s->next = L->next;
        s->prior = L;
        L->next = s;  //新结点 s 插入头结点之后
    }
}

/*
插入
*/
bool ListInsert_L(DuLinkList& L, int i, int& e) {
    int j;
    DuLinkList p, s;
    p = L;
    j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return false;
    s = new DuLnode;
    s->data = e;
    p->prior->next = s;
    s->prior = p->prior;
    s->next = p;
    p->prior = s;
    return true;
}

/*
删除
*/
bool ListDelete_L(DuLinkList& L, int i) {
    DuLinkList p;
    p = L;
    int j;
    j = 0;
    while (p && (j < i)) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return false;
    if (p->next)
        p->next->prior = p->prior;
    p->prior->next = p->next;
    delete p;
    return true;
}
