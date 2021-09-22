#define MaxSize 100
typedef int ElemType;

typedef struct SqQueue {
    ElemType* base;   //空间基地址
    int front, rear;  //对头和队尾
} SqQueue;

bool InitQueue(SqQueue& Q) {
    Q.base == new int[MaxSize];  //分配大小空间
    if (!Q.base)
        return false;
    Q.front = Q.rear = 0;
    return true;
}

bool EnQueue(SqQueue& Q, int& e) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.base[Q.rear] = e;               //新元素插入队尾
    Q.rear = (Q.rear + 1) % MaxSize;  //队尾后移
    return true;
}

bool DeQueue(SqQueue& Q, int& e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];
    return -1;
}

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}