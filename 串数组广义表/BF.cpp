#include <iostream>
using namespace std;

typedef struct {
    char* ch;    //指向字符串的指针
    int length;  //字符串长度
} SString;
/*
int Index_BF(SString S, SString T, int pos) {
    int i = pos, j = 1, sum = 0;
    while (i <= S[0] && j <= T[0]) {
        sum++;
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    cout << "共比较" << sum << "次" << j << endl;
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}
*/