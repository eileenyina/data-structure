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
void MergeSort(RcdType SR[],int low,int high)//¹é²¢2
{
	if(low<high)
	{
		int mid=(low+high)/2;
	    MergeSort(SR,low,mid);
	    MergeSort(SR,mid+1,high);
	    Merge(SR,low,mid,high);
	}
}

void MSort(SqList &L)//¹é²¢3
{
	MergeSort(L,1,n);
}

int main()
{
	int n;
	Sqlist L;
	InitList(L,100);
	n=readd(L);
	Msort(L);
	outt(L,n);
	return 0;
}
	
	
	
	
	









