#include <iostream>
using namespace std;
//const maxsize=100; 
typedef int ElemType;
int n;
typedef struct LNode
{
	int data;
	struct LNode *prior;
	struct LNode *next;
}LNode, *LinkList;
LNode *p,*q;
LinkList H;

void initlist(LinkList &L,int n)
//void initlist()
{
	//int n=5;
	//int n=5;
	LNode *p,*q; 
	int i;
	p=L;
	n=n+1;
	for (i=1;i<n;i++) 
	{
		p->data=i;
		if (i==1) L=p;
		q=new LNode;
		p->next=q;	
		q->prior=p;
		cout << p->data <<' ';
		p=q;	
	
	}
	L->prior=p;
	cout <<endl ;
	p->next=NULL;
//	 cout <<endl ;
	//return L;
} 
void insert(LinkList &L,LNode *p)
{
	p->next=L->next;  p->prior=L;
	L->next=p;        p->next->prior=p;
	 
}
void delect(LinkList &L)
{
	LNode *p;
	p=new LNode;
	p=L->next;
	L=p;
	L->prior=NULL;
}
void outt(LinkList &L)
{
	LNode *p;
	p=L;
	while (p->next)
	{
		cout << p->data <<' ';
		p=p->next;
	}
	cout <<endl ;
}
int main()
{
	LNode *L=new LNode;
//	L=NULL;
	int n;
	initlist(L,5);
	LNode *p=new LNode;
	p->data=6;
	insert(L,p);
//    initlist;
    outt(L);
    delect(L);
    outt(L);
	
	return 0;
}
