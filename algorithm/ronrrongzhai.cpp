#include<iostream>
using namespace std;

const STACK_INIT_SIZE=100;
const STACKINCREMENT=10;

typedef int SElemType;

typedef struct
{
	SElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
}SqStack;

 void InitStack_Sq(SqStack &S);   
 void GetTop_Sq(SqStack &S,SElemType &e);
 void Push_Sq(SqStack &S,SElemType e);
 bool Pop_Sq(SqStack &S,SElemType &e);

    

void InitStack_Sq(SqStack &S,int maxsize=STACK_INIT_SIZE,int incresize=STACKINCREMENT)
//void InitStack_Sq(SqStack &S)
{
	S.elem=new SElemType[maxsize];
	S.top=-1;
	S.stacksize=maxsize;
	S.incrementsize=incresize;
}

bool sGetTop_Sq(SqStack &S,SElemType e)
{
	if(S.top ==-1)	return false;
	e=S.elem [S.top];
	return true;
}

void sPush_Sq(SqStack &S,SElemType e)
{
//	if(S.top ==S.stacksize -1) incrementStacksize(S);
	S.elem [++S.top ]=e;
}

bool sPop_Sq(SqStack &S,SElemType e)
{
	if(S.top ==-1) return false;
	e=S.elem[S.top --];
	return true;
}
//void out(SqStack &S)
void main()
{
	SElemType e;
	SqStack S;
	e=1;
	bool judge;
/*    InitStack_Sq(&S,100,10);
    GetTop_Sq(&S,SElemType &e)
    Push_Sq(SqStack &S,SElemType e)
    Pop_Sq(SqStack &S,SElemType &e)*/

    printf ("构造一个栈并录入数据:\n");
    InitStack_Sq(S,100,10);
    judge=sGetTop_Sq(S,e);
    sPush_Sq(S,e);
    sPop_Sq(S,e);
    printf("\n");
    //GetTop_Sq(S,e);
}