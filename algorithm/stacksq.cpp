const size=100;
const increase=10;
typedef struct
{
	SElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
	
}SqStack;

void initstack(SqStack &s,int maxsize=size,int increasesize=increase)
{
	s.elem=new SElemType[maxsize];
	S.top=-1;
	S.stacksize=maxsize;
	S.incrementsize=incresize;
}
 
