#include <iostream>
using namespace std;
#define MaxSize 10

typedef struct LinearTable {
    int* elem;
    int length;
} SqList;

/*
顺序表初始化
*/
bool InitList(SqList& L) {
    //构造一个空的顺序表 L
    L.elem = new int[MaxSize];  //为顺序表分配数组空间 MaxSize
    if (!L.elem)
        return false;  //分配失败退出
    L.length = 0;      //空表长度为 0
    return true;
}
/*
创建
*/
bool CreateList(SqList& L) {
    int x, i = 0;
    // 定义结束条件
    while (x != -1) {
        if (L.length == MaxSize) {
            cout << "顺序表已满";
            return false;
        }
        cin >> x;
        L.elem[i++] = x;  //将数据存放在第 i 个位置
        L.length++;
    }
    return true;
}
/*
取值
*/
bool GetElem(SqList L, int i, int& e) {
    if (i < 1 || i > L.length)  //判断数据是否合法
        return false;
    e = L.elem[i - 1];  //第 i 个元素存放在 i-1 位置
    return true;
}
/*
查找
*/
int LocateElem(SqList L, int e) {
    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
        return -1;
    }
}
/*
插入
*/
bool InsertElem(SqList& L, int i, int e) {
    if (i < 1 || i > L.length)
        return false;
    if (L.length == MaxSize)
        return false;
    for (int j = L.length - 1; j >= i; j--)  //从最后一个元素开始后移
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;  //将新元素 e 放入第 i 个位置
    L.length++;
    return true;
}
/*
删除
*/
bool DelList(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.elem[i - 1];  //将要删除的元素保存在 e 中
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];  //删除后元素前移
    L.length--;
    return true;
}