#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1

/************************************
一个数组实现两个堆栈
method：使这两个栈分别从数组的两头开始向中间生长
*************************************/
typedef int Position;
typedef int ElementType;
typedef struct SNode * PtrToSNode;
struct SNode
{
    ElementType * Data;    // 存储元素的数组
    Position Top1;   // 堆栈1的栈顶指针
    Position Top2;   // 堆栈2的栈顶指针
    int MaxSize;    // 堆栈最大容量
};
typedef PtrToSNode Stack;

/* 顺序栈的创建 */
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top1 = -1;
    S->Top2 = MaxSize;
    S->MaxSize = MaxSize;
    return S;
}

/* 入栈：push */
bool Push(Stack S, ElementType X, int Tag)
{
    if(S->Top2 - S->Top1 == 1){
        printf("堆栈满\n");
        return false;
    }
    else{
        if(Tag == 1)    // 对第一个栈操作
            S->Data[++(S->Top1)] = X;
        else    // 对第二个栈操作
            S->Data[--S->Top2] = X;
        return true;
    }
}

/* 出栈：pop */
ElementType Pop(Stack S, int Tag)
{
    if(Tag == 1){   // 对第一个堆栈操作
        if(S->Top1 == -1){
            printf("堆栈空\n");
            return ERROR;
        }
        else
            return S->Data[(S->Top1)--];
    }
    else{   // 对第二个堆栈操作
        if(S->Top2 == S->MaxSize){
            printf("堆栈空\n");
            return ERROR;
        }
        else
            return S->Data[(S->Top2)++];
    }

}

int main()
{
    Stack S;
    int ret;
    S = CreateStack(10);
    //入栈
    for (int i=0; i<5; i++){
        Push(S, i, 1);
    }
    for (int i=5; i<10; i++){
        Push(S, i, 2);
    }
    //出栈
    for (int i=0; i<5; i++){
        ret = Pop(S,1);
        printf("ret:%d\n", ret);
        ret = Pop(S,2);
        printf("ret:%d\n", ret);
    }
	return 0;
}