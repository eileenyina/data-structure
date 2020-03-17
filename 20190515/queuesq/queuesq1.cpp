#include <iostream>
using namespace std;
typedef int QElemType;
int QUEUE_INIT_SIZE=5;
int QUEUEINCREMENT=2;

int TRUE=1;
int FALSE=0; 

typedef struct{
	QElemType *elem;
	int front;
	int rear;
	int queuesize;
	int incrementsize;
}SqQueue;


/*void ErrorMessage(char *s)
{
    cout<<s<<endl;
    exit(1);
}*/

void InitQueue_Sq(SqQueue &Q,int maxsize=QUEUE_INIT_SIZE,int incresize=QUEUEINCREMENT)//����ն���
{
	Q.elem=new QElemType[maxsize+1];
	Q.queuesize=maxsize;
	Q.incrementsize=incresize;
	Q.front=Q.rear=0;
}

void incrementQueuesize(SqQueue &Q)//����
{
	int k;
	QElemType *a;
	a=new QElemType[Q.queuesize+Q.incrementsize];
	for(k=0;k<Q.queuesize-1;k++)
		a[k]=Q.elem[(Q.front+k)%Q.queuesize];
	delete[] Q.elem;
	Q.elem=a;
	Q.front=0;
	Q.rear=Q.queuesize-1;
	Q.queuesize+=Q.incrementsize;
}


bool Queue_Sq(SqQueue &Q)//�ж��Ƿ�Ϊ��
{
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}


void QueueLength_Sq(SqQueue Q)//�󳤶�
{
	int k;
	k=(Q.rear-Q.front+Q.queuesize)%Q.queuesize;
	cout<<k<<endl;
}

void GetHead_Sq(SqQueue &Q,QElemType &e)//���ض�ͷԪ��
{
	if(Q.front!=Q.rear)
		e=Q.elem[Q.front];
   // else
	//	ErrorMessage("����Ϊ��");
	cout<<e<<endl;
}


void EnQueue_Sq(SqQueue &Q,QElemType e)//����
{
	if((Q.rear+1)%Q.queuesize==Q.front) incrementQueuesize(Q);
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.queuesize;
}



void DeQueue_Sq(SqQueue &Q,QElemType &e)//ɾ��
{
	if(Q.front==Q.rear) 
		ErrorMessage("����Ϊ��");
	else
	{
       e=Q.elem[Q.front];
	   Q.front=(Q.front+1)%Q.queuesize;
	}
}


void QueueTraverse_Sq(SqQueue Q)//����
{
	int k=Q.front;

	while(k!=Q.rear)
	{
		cout<<Q.elem[k]<<endl;
		k=(k+1)%Q.queuesize;
	}
}

void main()
{
	int i;
	SqQueue Q;
	QElemType e;
	InitQueue_Sq(Q);
	QElemType A[100]={67,23,54,45};
	for (i=0;i<4;i++)
		EnQueue_Sq(Q,A[i]);
	//QueueTraverse_Sq(Q);
	//QueueLength_Sq(Q);
	//GetHead_Sq(Q,e);
	DeQueue_Sq(Q,e);
    EnQueue_Sq(Q,56);
    QueueTraverse_Sq(Q);
}
