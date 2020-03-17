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
void outt(Sqlist &L,int n)
{
	for( int i=1;i<=n;i++ )
	{
		cout << L.elem[i] <<" " ;
	}
    cout <<endl ;
}
void insertsort(Sqlist &L,int n)
{
	int i,j,k,c,r,u;
	for (i=2;i<=n;i++)
	{
		j=1;
		c=L.elem[i];
		while(L.elem[i]>L.elem[j])
		{
			j++;
		}
		u=L.elem[j];
		for (k=j;k<=i-1;k++)
		{
			r=L.elem[k+1];
			L.elem[k+1]=u;
			u=r;
//			outt(L,n);
		}
//		cout << i <<" ";
//		cout << j <<" ";
//		cout<<endl;
		L.elem[j]=c;
		

	}
}

int main()
{
	int n;
	Sqlist L;
	InitList(L,100);
	n=readd(L);
	insertsort(L,n);
	outt(L,n);
	return 0;
}
	
	
	
	
	









