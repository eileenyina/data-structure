#include <iostream>
using namespace std;
const LIST_INIT_SIZE=100;
typedef int ElemType;


struct Sqlist
{
	ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
};

void InitList_sq(Sqlist &L,int maxsize)
{
	L.elem=new ElemType[maxsize];
	L.length=0;
	L.listsize=maxsize;
//	L.incrementsize=incresize;
}
int readd_sq(Sqlist &L)
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
	InitList_Sq(L,LIST_INIT_SIZE);
	n=readd(L);
	diverse_sq(L,n);
	outt(L,n);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	