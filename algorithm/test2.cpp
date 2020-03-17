#include <iostream>
using namespace std;

int divi(int a, int b)
{ 
int c;
    if (a<b)
    {
    	c=a;
    	a=b;
    	b=c;
    }
	if ((a % b)==0)
	{
		cout << b << endl;
	}
	else divi(b,(a % b));
	return 0;
}

int main()
{
int d;
	int a,b;
	cin >> a;
	cin >> b;
	d=divi(a,b);
//	cout << c << endl;

    return 0;
}
