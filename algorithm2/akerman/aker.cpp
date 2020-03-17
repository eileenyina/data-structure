#include"stack.h"
#include<iostream>
using namespace std;

int value(int n,int x,int y)
{
	if(n==0)
		return (x+1);
	else switch(n){
		case 1:return x;
                case 2:return 0;
	        case 3:return 1;
		default:return 2;
	}
}

int Ackerman(int n,int x,int y)
{
	int u;
	SElemType e;
	SqStack S;
	InitStack_Sq(S);
	e.nval=n;
    e.xval=x;
    e.yval=y;
	Push_Sq(S,e);
	do{
		GetTop_Sq(S,e);
		while(e.nval!=0&&e.yval!=0){
			e.yval--;
            Push_Sq(S,e);
		}
		Pop_Sq(S,e);
		u=value(e.nval,e.xval,e.yval);
		if(!StackEmpty(S)){
			Pop_Sq(S,e);
			e.nval--;e.yval=e.xval;e.xval=u;
			Push_Sq(S,e);
		}
	}
	while(!StackEmpty(S));
	return u;
}



void main()
{
	int n, x, y;
	cout << "ÊäÈën£º" << endl;
	cin >> n ;
	cout << "ÊäÈëx£º" << endl;
	cin >> x;
	cout << "ÊäÈëy£º" << endl;
	cin >> y;
        Ackerman(n, x, y);
	cout<<Ackerman(n, x, y)<<endl;
}