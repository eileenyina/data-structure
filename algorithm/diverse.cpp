#include <iostream>
using namespace std;
int main()
{
	int a[100]={1,2,3,4,5};
	int n;
	cin>>n;
	int i;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    for (i=1;i<=n/2;i++)
	{
		int c=a[i];
		a[i]=a[n+1-i];
		a[n+1-i]=c; 
	}
	for( int i=1;i<=n;i++ )
	{
		cout << a[i] <<" " ;
	}
    cout <<endl ;
}
