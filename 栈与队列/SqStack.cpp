

#define MaxSize 100
typedef int ElemType;
// 动态分配
typedef struct SqStack {
    ElemType* base;  //定义栈底指针
    ElemType* top;   //定义栈顶指针
} SqStack;

/*
初始化
*/
bool InitStack(SqStack& S) {
    S.base = new int[MaxSize];
    if (!S.base)
        return false;
    S.top = S.base;  // top 初始为基底 base，当前为空
    return true;
}

/*
入栈
*/
bool Push(SqStack& S, int e) {
    if (S.top - S.base == MaxSize)  //判断栈是否满
        return false;
    *S.top++ = e;  //新元素压栈，top +1
    return true;
}

/*
出栈
*/
bool Pop(SqStack& S, int& e) {
    if (S.top == S.base)  //判断栈是否空
        return false;
    e = *--S.top;  //栈顶指针减 1，元素赋值给 e
    return true;
}

/*
取栈顶
*/
int GetTop(SqStack S) {
    if (S.top != S.base)
        return *(S.top - 1);  //返回栈顶元素
    else
        return -1;
}