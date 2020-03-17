#include <iostream>
using namespace std;
struct student 
{
	int num;
	char name[10];
	int score;
};
int main()
{
	student temp,k;
	int num=5;
	student stu[5]={1,"xx",90,2,"yy",92,3,"zz",99,4,"xxx",88,5,"yyy",85};
	for (int i=0;i<=5;i++)
	{
		for (int j=i; j<=5;j++)
		{
			if (stu[i].score>stu[j].score)
			{
				k=stu[i];
				stu[j]=stu[i];
				stu[j]=k; 
			}
		}
	}
	for (int j=j;j<=5;j++)
	cout<<stu[j].num<<stu[j].name<<stu[j].score<<endl;
	return 0;
}
