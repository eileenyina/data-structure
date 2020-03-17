#include <iostream>
using namespace std;
//const LIST_INIT_SIZE=100;
typedef int ElemType;


struct Sqlist
{
	ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
};

void InitList(Sqlist &L,int maxsize)
{
	L.elem=new ElemType[maxsize];
	L.length=0;
	L.listsize=maxsize;
//	L.incrementsize=incresize;
}
int readd(Sqlist &L)
{
	int n;
	cin>>n;
	int i;
	for (i=1;i<=n;i++)
	{
		cin>>L.elem[i];
	}
	L.length=L.length+n;
	return n;
}
void insert(Sqlist &L,int n,int k)
{
	int i;
	for (i=1;i<=n;i++)
	{
		L.elem[i+1]=L.elem[i];
		L.elem[1]=k;
	}
}
void diverse_sq(Sqlist &L,int n)
{
	int i;
	int c;
	for (i=1;i<=n/2;i++)
	{
		int c=L.elem[i];
		L.elem[i]=L.elem[n+1-i];
		L.elem[n+1-i]=c; 
	}
}
void outt(Sqlist &L,int n)
{
	for( int i=1;i<=n;i++ )
	{
		cout << L.elem[i] <<" " ;
	}
    cout <<endl ;
}
int main()
{
	int n;
	Sqlist L;
	InitList(L,100);
	n=readd(L);
	insert(L,n,100);
	diverse_sq(L,n);
	outt(L,n);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
