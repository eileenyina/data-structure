#include<iostream>
using namespace std;
#include<string>
const Maxsize=100;

typedef struct
{
	char data[Maxsize];
	int Length;
}SqString;

void ERRORMESSAGE(char*s)
{
	cout<<s<<endl;
	exit(1);
}


int StrLength(SqString S)
{
	return S.Length ;
}


void StrAssign(SqString &S,char chars[])
{
	int i=strlen(chars);
	int j=0;
	for(j=0;j<i;++j)
		S.data[j]=chars[j];
	S.data[j]='\0';
	S.Length=i;
}



void Concat_str(SqString S1, SqString S2, SqString &T)
{
	int j=0, k = 0;
	while (S1.data [j] != '\0')
		T.data [k++] = S1.data [j++];
	    j = 0;
	while (S2.data [j] != '\0')
		T.data [k++] = S2.data [j++];
        T.data [k] = '\0';
	T.Length=S1.Length+S2.Length;
}


int Sub_str(SqString &Sub, SqString &S, int pos, int len)
{
	int slen, j;
	slen = StrLength(S);
	if (pos<0 || pos>slen-1 || len<0 || len>slen-pos )
		return 0;
	for (j = 0;j<len;j++)
		Sub.data[j] = S.data[pos + j - 1];
	Sub.data[len] = '\0';
	Sub.Length =len;
	return 1;
}

void StrInsert(SqString &S,int pos, SqString T)
{
	int slen,tlen,i,k,j;
	slen=StrLength(S);
	tlen=StrLength(T);
	SqString S1;
	S1.data[slen+1];
	if(pos<1||pos>slen+1)
		ERRORMESSAGE("插入位置不合法");
	if(tlen>0){
		i=0;
		while((S1.data[i]=S.data[i])!='\0')i++;
		for(i=0,k=0;i<pos-1;i++)
			S.data[k++]=S1.data[i];
		j=0;
		while(T.data[j]!='\0')S.data[k++]=T.data[j++];
		while(S1.data[i]!='\0')S.data[k++]=S1.data[i++];
		S.data[k]='\0';
	}
	S.Length =S.Length +T.Length ;
}

void outstr(SqString S)
{
	int i;
	for(i=0;i<S.Length;i++)
		cout<<S.data[i];
	cout<<endl;
}


void main()
{
	int i;
	char chars1[Maxsize]={"abbcccgdh"};
	char chars2[Maxsize]={"oji"};
	SqString S1;
	SqString S2;
	SqString S;
	SqString Sub;
	StrAssign(S1,chars1);
	StrAssign(S2,chars2);
	Concat_str(S1,S2,S);
	outstr(S);
	//Sub_str(Sub, S, 2, 2);
	//outstr(Sub);
    StrInsert(S,2,S2);
	outstr(S);
}


