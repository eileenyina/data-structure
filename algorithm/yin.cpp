#include <iostream>
using namespace std;
const LIST_INIT_SIZE=100;
typedef int ElemType;


struct Sqlist
{
	int ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
};

void InitList_sq(Sqlist &L,int maxsize,int incresize)
{
	L.elem=new ElemType[maxsize];
	L.length=0;
	L.listsize=maxsize;
	L.incrementsize=incresize;
}
void St



void main()
{
	sqList L;
	InitList_Sq(L,L
