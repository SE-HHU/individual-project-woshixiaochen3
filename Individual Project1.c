#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define NUM 500
char op(int a)				/*生成运算符*/ 
{
	switch(a)
	{
		case 1: return '+';break;
		case 2: return '-';break;
	}
}
int answer(int a,char op,int b)		/*算出答案*/ 
{
	int y;
	switch(op)
	{
		case '+': y=a+b;break;
		case '-': y=a-b;break;
	}
	return y;
}
int repeat1(int a,int b,int a1,int arr[][3])	/*验证题目是否重复*/		
{
	int i;
	static int x;
	for(i=0;i<x;i++)
	{
		if((arr[i][2]==a1)&&(a==arr[i][0]||a==arr[i][1])&&(b==arr[i][0]||b==arr[i][1]))
		{
			return 1;
		}
	}
	arr[x][0]=a;
	arr[x][1]=b;
	arr[x][2]=a1;
	++x;
	return 0;
}
int repeat2(int a,int b,int c,int a2,int arr[][4])		/*验证题目是否重复*/
{
	int i;
	static int y;
	for(i=0;i<y;i++)
	{
		if((arr[i][3]==a2)&&(a==arr[i][0]||a==arr[i][1]||a==arr[i][2])&&(b==arr[i][0]||b==arr[i][1]||b==arr[i][2])&&(c==arr[i][0]||c==arr[i][1]||c==arr[i][2])&&(a==arr[i][0]||b==arr[i][0]||c==arr[i][0])&&(a==arr[i][1]||b==arr[i][1]||c==arr[i][1])&&(a==arr[i][2]||b==arr[i][2]||c==arr[i][2]))
		{
			return 1;
		}
	}
	arr[y][0]=a;
	arr[y][1]=b;
	arr[y][2]=c;
	arr[y][3]=a2;
	++y;
	return 0;
}
int main()
{
	int a,b,c,i=1,m,n,k,number,a1,a2,arr1[NUM][3]={100},arr2[NUM][4]={100};
	char op1,op2;
	printf("请输入要生成的题目数量（最多500道）：");
	scanf("%d",&number);
	if(number>NUM)
	{
		printf("\n你要求的题目太多了，题海战术不适用于小学生哟！\n");
	}
	else if(number<=0)
	{
		printf("\n你输入的数字不符合规范。\n");
	}
	else
	{
		FILE *fp1,*fp2;
		if((fp1=fopen("D:\\Exercises.txt","w+"))==NULL)
		{
			printf("Cannot open this file.\n");
			exit(0);
		}
		if((fp2=fopen("D:\\Answers.txt","w+"))==NULL)
		{
			printf("Cannot open this file.\n");
			exit(0);
		}
		srand(time(0));
		while(i<=number)
		{
			m=rand()%2+1;				/*随机运算符*/ 
			op1=op(m);					/*生成运算符*/ 
	    	a=rand()%99+1;
		    b=rand()%99+1;
	    	a1=answer(a,op1,b);
		    if(a1<0||a1>=100)continue;		/*验证答案为100以内*/ 
		    k=rand()%2+1;					/*随机题目中运算符个数*/ 
		    if(k==1)
		    {
		    	if(repeat1(a,b,a1,arr1)==1)continue;		/*验证题目是否重复*/
				printf("%2d. %d%c%d=%10d\n",i,a,op1,b,a1);
				fprintf(fp1,"%3d. %d%c%d=\n",i,a,op1,b);
				fprintf(fp2,"%3d. %d%c%d=%d\n",i,a,op1,b,a1);
				i++;
			}
			else
			{
			    n=rand()%2+1;						/*随机第二个运算符*/
			    op2=op(n);							/*生成第二个运算符*/
				c=rand()%99+1;
				a2=answer(a1,op2,c);
				if(a2<0||a2>=100)continue;						/*验证答案为100以内*/
				if(repeat2(a,b,c,a2,arr2)==1)continue;			/*验证题目是否重复*/
				printf("%2d. %d%c%d%c%d=%10d\n",i,a,op1,b,op2,c,a2);
				fprintf(fp1,"%3d. %d%c%d%c%d=\n",i,a,op1,b,op2,c);
				fprintf(fp2,"%3d. %d%c%d%c%d=%d\n",i,a,op1,b,op2,c,a2);
				i++;
			}
		}
		if(fclose(fp1))
		{
			printf("Cannot close this file!\n");
			exit(0);
		}
		if(fclose(fp2))
		{
			printf("Cannot close this file!\n");
			exit(0);
		}
	}
	return 0;
}


