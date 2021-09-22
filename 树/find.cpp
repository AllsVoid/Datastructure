#include <iostream>
using namespace std;

typedef struct Bnode {
    int data;
    struct Bnode *lchild, *rchild;
} BNode, *Btree;

void preorder(Btree T) {
    if (T) {
        cout << T->data << "";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void inorder(Btree T) {
    if (T) {
        inorder(T->lchild);
        cout << T->data << "";
        inorder(T->rchild);
    }
}

void posorder(Btree T) {
    if (T) {
        posorder(T->lchild);
        posorder(T->rchild);
        cout << T->data << "";
    }
}

bool LevelTraverse(Btree T) {
    Btree p;
    if (!T)
        return false;
    queue<Btree> Q;
    Q.push(T);
    while (!Q.empty()) {
        p.Q.front();
        Q.pop();
        cout << p->data << "";
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
    return true;
}