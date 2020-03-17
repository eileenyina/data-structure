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

void SelectSort(SqList &L)//选择
{
	int i,j,k;
	RcdType W;
	for(i=1;i<L.length;++i){
		j=i;
		for(k=i+1;k<=L.length;k++)
			if(L.r[k].key<L.r[j].key) j=k;
			if(i!=j)
			{W=L.r[j];L.r[j]=L.r[i];L.r[i]=W;}
	}
}

void InsertSort(SqList &L)//插入
{
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key){
			L.r[0]=L.r[i];
			for(j=i-1;L.r[0].key<L.r[j].key;--j)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
}

void BubbleSort(SqList &L)//起泡
{
	int i,j,lastExchangeIndex;
	RcdType W;
	i=L.length;
	while(i>1){
		lastExchangeIndex=1;
		for(j=1;j<i;j++){
			if(L.r[j+1].key<L.r[j].key){
				W=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=W;
				lastExchangeIndex=j;
			}
		}
		i=lastExchangeIndex;
	}
}

int Partition(RcdType R[],int low,int high)//快速1
{
	int pivotkey;
	R[0]=R[low];
	pivotkey=R[low].key;
	while(low<high){
		while(low<high&&R[high].key>=pivotkey)
			--high;
		if(low<high)
			R[low++]=R[high];
		while(low<high&&R[low].key<=pivotkey)
			++low;
		if(low<high)
			R[high--]=R[low];
	}
	R[low]=R[0];
	return low;
}

void Qsort(RcdType R[],int s,int t)//快速2
{
	int pivotloc;
	if(s<t){
		pivotloc=Partition(R,s,t);
		Qsort(R,s,pivotloc-1);
		Qsort(R,pivotloc+1,t);
	}
}

void QuickSort(SqList &L)//快速3
{
	Qsort(L.r,1,L.length);
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
	L.r[1].key=28;
	L.r[2].key=10;
	L.r[3].key=7;
	L.r[4].key=17;
	L.r[5].key=12;
	L.length=5;
	//SelectSort(L);//选择排序
	//InsertSort(L);//插入排序
	//BubbleSort(L);//起泡排序
    //QuickSort(L);//快速排序
    //MSort(L);//归并排序
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<endl;	
}


