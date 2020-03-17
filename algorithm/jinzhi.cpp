#include<iostream>
using namespace std;
void conversion()
{
	int N,k,i;
	cin>>N;
	cin>>k;
	i=0; 
	int a[100]; 
	while (N)
	{
		i=i+1;
		a[i]=N%k;
		N=N/k;
	}
	while (i)
	{
		cout<<a[i];
		i=i-1;
	}
}
int  main() 
{
	conversion();
	return 0;
}
