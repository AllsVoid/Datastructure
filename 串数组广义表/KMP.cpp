typedef struct {
    char* ch;    //指向字符串的指针
    int length;  //字符串长度
} SString;

int Index_KMO(SString S, SString T, int pos, int next[]) {
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {  //继续比较后面的字符
            i++;
            j++;
        } else
            j = next[j];  //模式串右移
    }
    if (j > T[0])  //继续比较
        return i - T[0];
    else
        return 0;
}

void get_next(SString T, int next[]) {
    int j = 1, k = 0;
    next[1] = 0;
    while (j < T[0]) {  //模式串 T 的长度
        if (k == 0 || T[j] == T[k])
            next[++j] = k++;
        else
            k = next[k];
    }
}

void get_next2(SString T, int next[]) {
    int j = 1, k = 0;
    next[1] = 0;
    while (j <= T[0]) {
        if (k == 0 || T[j] == T[k]) {
            i++;
            j++;
            if (T[j] == T[k])
                next[j] = next[k];
            else
                next[j] = k;
        } else
            k = next[k];
    }
}