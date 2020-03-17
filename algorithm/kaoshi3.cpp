#include<iostream>
using namespace std;
#include<string>
//const int Maxsize=100;
/*typedef struct
{
	char data[Maxsize];
	int Length;
}SqString;
*/
void con(char S1[],char S2[],char T[])
{
	int j=0;
	int k=0;
	while (S1[j]!='\0')
	{
		T[k++]=S1[j++];
	}
	j=0;
	while(S2[j]!='\0')
	{
		T[k++]=S2[j++];
	}
	T[k]='\0';
}
int main()
{
	char name[100]={"yinhaotian"};
	char num[100]={"31160512"};
	char all[100];
	con(name,num,all);
	cout<<all<<endl;
}
 

