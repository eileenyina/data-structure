#include<iostream>
using namespace std;
#include<string>
const Maxsize=100;
typedef struct
{
	char data[Maxsize];
	int Length;
}SqString;


void StrAssign(SqString &S,char chars[])//≥ı ºªØ
{
	int i=strlen(chars);
	int j=0;
	for(j=0;j<i;++j)
		S.data[j]=chars[j];
	S.data[j]='\0';
	S.Length=i;
}

int StrLength(SqString S)
{
	return S.Length ;
}

void get_next(SqString &T,int *next)
{
	int i=0,j=-1;
	next[0]=-1;
	while(T.data[i]!='\0')
	{
		if((j==-1)||T.data[i]==T.data[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}

int index_krip(SqString &S,SqString &T,int pos)
{
	int next[100];
	int i=pos;
	int j=0;
	get_next(T,next);
	while(i<StrLength(S))
	{
		if(j==-1||S.data[i]==T.data[j])
		{
			i++;
			j++;
		}
		else j=next[j];
		if(j==StrLength(T))
			return i-StrLength(T);
	}
	return -1;
}

void main()
{
	int i;
	char chars1[Maxsize]={"abcbcddacb"};
	char chars2[Maxsize]={"cb"};
	SqString S1;
	SqString S2;
	StrAssign(S1,chars1);
	StrAssign(S2,chars2);
	cout<<index_krip(S1,S2,0)<<endl;	
}