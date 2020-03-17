#include<iostream>
using namespace std;

const STACK_INIT_SIZE=100;
const STACKINCREMENT=10;
const TRUE=1;
const FALSE=0;

typedef int SElemType;

typedef struct{
	SElemType *elem;
	int top;
	int stacksize;
	int incrementsize;     
}SqStack;

void InitStack_Sq(SqStack &S,int maxsize=STACK_INIT_SIZE,int incresize=STACKINCREMENT)//创建空栈
{
	S.elem=new SElemType[maxsize];
	S.top=-1;
    S.stacksize=maxsize;
	S.incrementsize=incresize;
}

void ErrorMessage(char *s)
{
	cout<<s<<endl;
    exit(1);
}

void incrementStacksize(SqStack &S)//扩容函数
{
	int i;
	SElemType *a;
	a=new SElemType[S.stacksize +S.incrementsize ];
	for(i=0;i<=S.top ;i++)
		a[i]=S.elem [i];
	delete [] S.elem ;
    S.elem =a;
	S.stacksize+=S.incrementsize;
}

SElemType GetTop_Sq(SqStack S,SElemType &e)//获取栈顶元素
{
	if(S.top ==-1)
		ErrorMessage("栈为空！");
	else
		e=S.elem[S.top];
	return e;
}

void Push_Sq(SqStack &S,SElemType e)//将元素压入栈
{
	if(S.top ==S.stacksize -1)
		incrementStacksize(S);
	S.elem [++S.top]=e;
}

void Pop_Sq(SqStack &S,SElemType &e)//删除栈顶元素
{
	if(S.top ==-1)
		ErrorMessage("栈为空！");
	else
	{
		e=S.elem [S.top --];
	}
}

void SqStackTraverse(SqStack S)//遍历栈
{
	int i;
	if(S.top>-1) 
	{
	    for(i=0;i<=S.top ;i++)
		 cout<<S.elem [i]<<'\t';
	}
	else
    ErrorMessage("栈为空");
}

void SqStack_Length(SqStack S)//求栈的长度
{
	cout<<S.top +1<<endl;
}

bool StackEmpty(SqStack S)//判断栈是否为空
{
	if(S.top ==-1)
		return TRUE;
	else
		return FALSE;
}

