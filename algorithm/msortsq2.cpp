#include<iostream>
using namespace std;
const Maxsize=20;

typedef int KeyType;
typedef struct{
	KeyType key;
	int other;
}RcdType;

typedef struct{
	RcdType r[Maxsize+1];
	int length;
}SqList;

void InitList_sq(SqList &L)//创建
{
	RcdType r[Maxsize+1]={0};
	L.length=0;
}


void Merge(RcdType SR[],int low,int mid,int high)//归并1
{
	int i=low,j=mid+1,k=0;
	RcdType *TR;
	TR=new RcdType[high-low+1];
	while(i<=mid&&j<=high)
	{
		if (SR[i].key<=SR[j].key)
			TR[k++]=SR[i++];
		else TR[k++]=SR[j++];
	}
	while(i<=mid)
		TR[k++]=SR[i++];
	while(j<=high)
		TR[k++]=SR[j++];
	for(i=low,k=0;i<=high;i++,k++)
		SR[i]=TR[k];
	delete[] TR;
}

void MergeSort(RcdType SR[],int low,int high)//归并2
{
	if(low<high)
	{
		int mid=(low+high)/2;
	    MergeSort(SR,low,mid);
	    MergeSort(SR,mid+1,high);
	    Merge(SR,low,mid,high);
	}
}

void MSort(SqList &L)//归并3
{
	MergeSort(L.r,1,L.length);
}

void main()
{
	SqList L;
	int i;
	InitList_sq(L);
	L.r[1].key=2;
	L.r[2].key=1;
	L.r[3].key=7;
	L.r[4].key=8;
	L.r[5].key=3;
	L.length=5;

    MSort(L);
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<endl;	
}


