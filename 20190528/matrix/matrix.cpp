#include<iostream>
using namespace std;
const MAXSIZE=1000;
const MAXMN=100;
const MAXNN=100;
typedef int ElemType;

typedef struct{
	int i,j;
	ElemType e;
}Triple;

typedef struct{
	Triple data[MAXSIZE+1];
	int rpos[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

void CreateTSMatrix(TSMatrix &m,int a[6][7])//稀疏矩阵转化为三元组
{
	int i,j,t=0;
	m.mu=6;
	m.nu=7;
	for(i=0;i<m.mu;i++)
	for(j=0;j<m.nu;j++)
	{
		if(a[i][j]!=0)
		{
			m.data[t].i=i;
			m.data[t].j=j;
			m.data[t].e=a[i][j];
			t++;
		}
	}	
	m.tu=t;
}

void Traverse(TSMatrix M)
{
	int i;
	cout<<"i"<<"     "<<"j"<<"     "<<"e"<<endl;
	for(i=0;i<M.tu;i++)
		cout<<M.data[i].i<<"     "<<M.data[i].j<<"     "<<M.data[i].e<<endl;
}


void TransposeTSMatrix(TSMatrix M,TSMatrix &T)
{
	int p,q,col;
	T.nu=M.mu;
	T.mu=M.nu;
	T.tu=M.tu;
	if(T.data)
	{
		q=0;
		for(col=0;col<M.nu;++col)
			for(p=0;p<M.tu;++p)
				if(M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					++q;
				}
	}
}



int num[MAXMN]={0},rpos[MAXMN]={0};	
void CreatRpos(TSMatrix M)
{
	int t,col;
	for(col=0;col<M.nu;++col)
		num[col]=0;
	for(t=0;t<M.tu;++t)
		++num[M.data[t].j];
	rpos[1]=1;
	for(col=1;col<M.nu;++col)
		rpos[col]=rpos[col-1]+num[col-1];
}

void FastTransposeTSMatrix(TSMatrix M,TSMatrix &T)
{
	T.mu=M.nu;
	T.nu=M.mu;
	T.tu=M.tu;
	int p,q,col;
	if(T.tu)
	{
		CreatRpos(M);
		for(p=0;p<M.tu;++p)
		{
	     	col=M.data[p].j;
			q=rpos[col];
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;
			++rpos[col];
		}
	}
}


void main(){
	int A[6][7]={0,12,9,0,0,0,0,0,0,0,0,0,0,0,-3,0,0,0,0,14,0,0,0,24,0,0,0,0,0,18,0,0,0,0,0,15,0,0,-7,0,0,0};
    TSMatrix M,T;
    CreateTSMatrix(M,A);
    Traverse(M);
	TransposeTSMatrix(M,T);
	Traverse(T);
    FastTransposeTSMatrix(M,T);
	Traverse(T);
}