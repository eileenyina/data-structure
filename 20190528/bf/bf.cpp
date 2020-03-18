#include<iostream>
using namespace std;
#include<string>
const int Maxsize=100;
typedef struct
{
	char data[Maxsize];
	int Length;
}SqString;

void StrAssign(SqString &S,char chars[])
{
	int i=strlen(chars);
	int j=0;
	for(j=0;j<i;++j)
		S.data[j]=chars[j];
	S.data[j]='\0';
	S.Length=i;
}


int Index_BF(SqString S,SqString T,int pos)
{
	int i,j;
	i=pos;
	j=0;
	while(S.data[i+j]!='\0'&&T.data[j]!='\0')
		if(S.data[i+j]==T.data[j])
			j++;
		else{i++;j=0;}
	if(T.data[j]=='\0') return i;
	else return -1;
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
	cout<<Index_BF(S1,S2,0)<<endl;
}