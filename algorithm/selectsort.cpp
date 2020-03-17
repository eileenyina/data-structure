#include <iostream>
using namespace std;
int a[100];
void selectsort(int a);
{
	
}
int main()
{
//	int a[100]={1,2,3,4,5};
    int a[100];
	int n;
	cin>>n;
	int i;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    selectsort(a);
	for( int i=1;i<=n;i++ )
	{
		cout << a[i] <<" " ;
	}
    cout <<endl ;
}
