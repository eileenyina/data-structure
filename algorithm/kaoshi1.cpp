#include <iostream>
using namespace std;
//typedef int ElemType;
int n;
typedef struct LNode
{
	//ElemType data;
	int data;
	struct LNode *next;
	
} LNode,*LinkList;
LNode *p,*q;
LinkList H;

void initlist(LinkList &L,int n)
{

	LNode *p,*q; 
	int i;
	p=L;
	n=n+1;
/*	p->data=3;
	q=new LNode;
	p->next=q;	
	p=q;
*/
	for (i=1;i<n;i++) 
	{
		cin>>p->data;
		q=new LNode;
		p->next=q;	
		cout << p->data <<' ';
		p=q;	
	
	}

	cout <<endl ;
	p->next=NULL;
//	 cout <<endl ;
	//return L;
} 
void insert(LinkList &L,LNode *p)
{
	p->next=L->next;
	L->next=p;
	 
}
void delect(LinkList &L)
{
	LNode *p;
	//p=new LNode;
	p=L;
	int i;
	while(p->next)
	{
		if (p->next->data==2)
		{
			p->next=p->next->next;
		}
		p=p->next;
	}
	//L=p;
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
	initlist(L,10);
//	LNode *p=new LNode;
//	p->data=6;
//	insert(L,p);
//    initlist;
//    outt(L);
    delect(L);
    outt(L);
	
	return 0;
}
