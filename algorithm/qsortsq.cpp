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
void qsort(Sqlist &L,int l,int r,int n)
{
	int i,j,c,m;
	//int c;
	//s=l-r+1;
	m=L.elem[l];
	i=l;
	j=r;
	while(i<=j)
	{
		while (L.elem[i]<m) i++;
		while (L.elem[j]>m) j--;
		if (i<=j)
		{
			c=L.elem[i];
			L.elem[i]=L.elem[j];
			L.elem[j]=c;	
			i=i++;
		    j=j--; 		
		}
		outt(L,n);
    } 
	if (i<r) qsort(L,i,r,n);
	if (j>l) qsort(L,l,j,n);
}

int main()
{
	int n;
	Sqlist L;
	InitList(L,100);
	n=readd(L);
	qsort(L,1,n,n);
	outt(L,n);
	return 0;
}
	
	
	
	
	









