typedef enum { ATOM, LIST } ElemTag;
// Atom=0 原子 LIST=1 子表
typedef struct GLnode {
    ElemTag tag;  //公共部分，区分原子结点和表结点
    union {       //联合部分
        int atom;
        struct {
            struct GLnode *hp, *tp;
        } ptr;
    };
} * Glist;  //广义表类型