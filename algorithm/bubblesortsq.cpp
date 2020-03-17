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
void bubblesort(Sqlist &L,int n)
{
	int i,j,c;
	//int c;
	for (i=1;i<=n-1;i++)
	{
		for (j=1;j<=n-i;j++)
		{
			if (L.elem[j]>L.elem[j+1])
			{
				c=L.elem[j];
				L.elem[j]=L.elem[j+1];
				L.elem[j+1]=c;
			}
			
		}

	}
}

int main()
{
	int n;
	Sqlist L;
	InitList(L,100);
	n=readd(L);
	bubblesort(L,n);
	outt(L,n);
	return 0;
}
	
	
	
	
	









