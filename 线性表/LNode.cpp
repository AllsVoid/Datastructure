#include <cstdio>  //NULL 未定义
#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;  //指向下一节点的指针
} LNode, *LinkList;      //指针 Linklist

/*
初始化
*/
bool InitList_L(LinkList& L) {
    L = new LNode;  //生成新节点作为头节点，用头指针 L 指向头节点
    if (!L)
        return false;
    L->next = NULL;  //头节点指针域置空
    return true;
}

/*
头插法
*/
void CreateList_H(LinkList& L) {
    int n;
    LinkList s;  //定义指针变量
    L = new LNode;
    L->next = NULL;  //建立一个带头节点链表
    cout << "请输入元素个数：" << endl;
    cin >> n;
    cout << "请依次输入 n 个元素：" << endl;
    cout << "头插法创建单链表" << endl;
    while (n--) {
        s = new LNode;   //生成新节点 s
        cin >> s->data;  //输入元素值复制给新节点的数据域
        s->next = L->next;
        L->next = s;
    }
}

/*
尾插法
*/
void CreateList_R(LinkList& L) {
    int n;
    LinkList s, r;  //定义指针变量
    L = new LNode;
    L->next = NULL;  //建立一个带头节点链表
    r = L;           //尾指针 r 指向头节点
    cout << "请输入元素个数：" << endl;
    cin >> n;
    cout << "请依次输入 n 个元素：" << endl;
    cout << "尾插法创建单链表" << endl;
    while (n--) {
        s = new LNode;   //生成新节点
        cin >> s->data;  //输入元素值复制给新节点的数据域
        s->next = L->next;
        r->next = s;  //将新节点 s 插入尾节点 r 之后
        r = s;        // r 指向新的尾节点 s
    }
}
/*
取值
*/
bool GetElem_L(LinkList L, int i, int& e) {
    int j;
    LinkList p;
    p = L->next;  // p 指向第一个数据节点
    j = 1;        //计数器
    while (j < i && p) {  //顺着链表向后扫描，直至 p 指向第 i 个元素或 p 为空
        p = p->next;  // p 指向下个节点
        j++;
    }
    if (!p || j > i)
        return false;
    e = p->data;  //取第 i 个节点的数据域
    return true;
}

/*
查找
*/
bool LocateElem(LinkList L, int e) {
    LinkList p;
    p = L->next;
    // 沿链表向后扫描，直至 p 为空或 p=e
    while (p && p->data != e)
        p = p->next;
    if (!p)
        return false;
    return true;
}

/*
插入
*/
bool ListInsert_L(LinkList& L, int i, int e) {
    // 在头节点的单链表 L 中第 i 个位置之前插入值为 e 的新节点
    int j;
    LinkList p, s;
    p = L;
    j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)  // i>n+1 或 i<1
        return false;
    s = new LNode;
    s->data = e;
    s->next = p->next;  //新节点的指针域指向第 i 个节点
    p->next = s;        //节点 p 的指针域指向节点 s
    return true;
}

/*
删除
*/
bool ListDelete_L(LinkList& L, int i) {
    LinkList p, q;
    int j;
    p = L;
    j = 0;
    // 查找第 i-1 个节点，p 指向该节点
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if (!(p->next) || (j > i - 1))
        return false;
    q = p->next;  //临时保存被删节点以备释放空间
    p->next = q->next;  //将 q 节点的下一节点地址赋值给 p 节点的指针域
    delete q;           //释放空间
    return true;
}