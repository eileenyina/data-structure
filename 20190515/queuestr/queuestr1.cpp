#include <iostream>
using namespace std;
typedef int QElemType;

const TRUE=1;
const FALSE=0; 

typedef struct LNode{
	QElemType data;
	struct LNode *next;
}LNode,*LinkList;

typedef LinkList QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void ErrorMessage(char *s)
{
    cout<<s<<endl;
    exit(1);
}

void InitQueue_L(LinkQueue &Q)//����ն���
{
	Q.front=Q.rear=new LNode;
	Q.front->next=NULL;
}

void DestroyQueue_L(LinkQueue &Q)//����
{
	while(Q.front){
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
}

bool Queue_L(LinkQueue &Q)//�ж��Ƿ�Ϊ��
{
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

void QueueLength_L(LinkQueue Q)//�󳤶�
{
	LNode *p;
	int k;
	k=0;
	p=Q.front->next;
	while(p){
		k++;
		p=p->next;
	}
	cout<<k<<endl;
}

void GetHead_L(LinkQueue &Q,QElemType &e)//���ض�ͷ
{
	LNode *p;
	if(Q.front!=Q.rear){
		p=Q.front->next;
		e=p->data;
	}
	else
		ErrorMessage("����Ϊ��");
}


void EnQueue_L(LinkQueue &Q,QElemType e)//������Ԫ��
{
	LNode *p;
	p=new LNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}


bool DeQueue_L(LinkQueue &Q,QElemType &e)//ɾ����ͷԪ��
{
	LNode *p;
	if(Q.front==Q.rear) 
		return FALSE;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) 
		Q.rear=Q.front;
	delete p;
	return TRUE;
}


void QueueTraverse(LinkQueue Q)//����
{
	LNode *p;
	p=Q.front->next;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

void main()
{
	int i;
	LinkQueue Q;
	QElemType e;
	InitQueue_L(Q);
	QElemType A[100]={67,34,56,45};
	for (i=0;i<4;i++)
		EnQueue_L(Q,A[i]);
	//QueueLength_L(Q);
	//GetHead_L(Q,e);
	DeQueue_L(Q,e);
	//cout<<e<<endl;
	QueueTraverse(Q);
}










