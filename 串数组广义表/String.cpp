typedef struct {
    char* ch;    //指向字符串的指针
    int length;  //字符串长度
} SString;

#define CHUNKSIZE 80
typedef struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk* next;
} Chunk;
typedef struct {
    Chunk *head, *tail;
    int length;
} LString;