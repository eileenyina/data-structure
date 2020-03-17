#include<iostream>
using namespace std;
bool matching(char exp[]) 
{
    char a[100];
	int k=0;
	int state=1;
	char ch=*exp++;
	int i=0;
	while (ch !='#'&&state)
	{
		switch (ch)
		{
			case'(':
		    case'[':
				{
					k++;
					a[k]=ch;
					break;
				}
			case')':
				{
					if (k!=0 && a[k]=='(')
					{
						k--;
					}
					else state=0;
					break;
				
				}
			case']':
				{
					if (k!=0 && a[k]=='[')
					{
						k--;
					}
					else state=0;
					break;
				}
        }
        i++;
		ch=exp[i];
	}
	if (state&&k==0) return true;
	else return false;
}




int  main() 
{
	char exp[100];
	cin>>exp;
	bool flag;
	flag=matching(exp);
	cout<<flag;
	return 0;
}
