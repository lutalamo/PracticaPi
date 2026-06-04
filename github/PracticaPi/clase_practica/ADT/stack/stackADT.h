typedef char* elemType;

typedef int (*compare)(elemType, elemType); // 1 si son =.  0 si son distintos

typedef struct stackCDT * stackADT;

stackADT newStack(compare cmp);

void freeStack(stackADT s);

int isEmpty(const stackADT s);

void push(stackADT s, elemType elem);

elemType pop(stackADT s);

int belongs (const stackADT, elemType elem);