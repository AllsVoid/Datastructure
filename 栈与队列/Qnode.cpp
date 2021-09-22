#include <cstdio>
typedef int ElemType;

typedef struct Qnode {
    ElemType data;
    struct Qnode* next;
} Qnode, *Qptr;

typedef struct {
    Qnode* front;
    Qnode* rear;
} LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = new Qnode;
    Q.front->next = NULL;
}

void EnQueue(LinkQueue& Q, int e) {
    Qptr s;
    s = new Qnode;
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue& Q, int& e) {
    Qptr p;
    if (Q.front == Q.rear)
        return false;
    p=Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return true;
}

int GetHead(LinkQueue Q){
    if(Q.front!=Q.rear)
        return Q.front->next->data;
    return -1;
}