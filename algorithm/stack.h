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

void InitStack_Sq(SqStack &S,int maxsize=STACK_INIT_SIZE,int incresize=STACKINCREMENT)//������ջ
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

void incrementStacksize(SqStack &S)//���ݺ���
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

SElemType GetTop_Sq(SqStack S,SElemType &e)//��ȡջ��Ԫ��
{
	if(S.top ==-1)
		ErrorMessage("ջΪ�գ�");
	else
		e=S.elem[S.top];
	return e;
}

void Push_Sq(SqStack &S,SElemType e)//��Ԫ��ѹ��ջ
{
	if(S.top ==S.stacksize -1)
		incrementStacksize(S);
	S.elem [++S.top]=e;
}

void Pop_Sq(SqStack &S,SElemType &e)//ɾ��ջ��Ԫ��
{
	if(S.top ==-1)
		ErrorMessage("ջΪ�գ�");
	else
	{
		e=S.elem [S.top --];
	}
}

void SqStackTraverse(SqStack S)//����ջ
{
	int i;
	if(S.top>-1) 
	{
	    for(i=0;i<=S.top ;i++)
		 cout<<S.elem [i]<<'\t';
	}
	else
    ErrorMessage("ջΪ��");
}

void SqStack_Length(SqStack S)//��ջ�ĳ���
{
	cout<<S.top +1<<endl;
}

bool StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if(S.top ==-1)
		return TRUE;
	else
		return FALSE;
}

