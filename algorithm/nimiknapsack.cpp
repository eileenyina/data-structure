#include<iostream>
using namespace std;
void knapsack(int w[],int T,int n)
{
	int k=0,i=0;
	int j;
	int S[100];
	do
	{
		while (T>0 &&k<n) 
		{
			if (T-w[k]>=0)
			{
				i++;
				S[i]=k;
				T-=w[k];
			}
			k++;
			if (T==0) 
			{
				for (j=1;j<=i;j++)
				cout<<S[j]<<' ';
				i--;
				T+=w[k];
				k++;
			}
		} 
	} while (k!=0||(k<n));	
} 

