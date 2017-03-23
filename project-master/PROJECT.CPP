#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#define NUM 10


void print(int i,int j,int k, int l)       //printing output questions
{
	cout<<"#include<iostream.h>\n";
	cout<<"main()\n{\n\tint i="<<i<<",j="<<j<<",k="<<k<<",l="<<l<<";\n";
	cout<<"\twhile(i<10)\n\t{\n\t\twhile(k<10)\n\t\t{\n\t\t\tcout<<i+k;\n\t\t\tk=k+l;\n\t\t}\n";
	cout<<"\t\ti=i+j;\n\t\tcout<<endl;\n\t}\n}";
}

void input()                            //taking input for output question
{
	fstream inp;
	inp.open("input.txt",ios::out);
	char ch='.';
	while(ch!='#')
	{
		ch=getche();
		if((int)ch==13)
		{
			inp<<'\n';
			cout<<"\n";
		}
		inp<<ch;
	}
	inp.close();
}

int check()                             //checking the users input
{
	fstream inp,opt;
	inp.open("input.txt",ios::in);
	opt.open("print.txt",ios::in);
	char str1[20],str2[20];
	int f=1;
	inp.getline(str1,20,'\n');
	while(strcmp(str1,"#")!=0)
	{
		opt.getline(str2,20,'\n');
		if(strcmp(str1,str2)!=0)
		{
			f=0;
			break;
		}
		inp.getline(str1,20,'\n');
	}
	inp.close();
	opt.close();
	return f;
}

void calcOutput()         //calculating the answer for output question n calling to print question
{
	fstream opt;
	opt.open("print.txt",ios::out);
	int i,j,k,l,x;
	i=random(5);
	j=random(3)+2;
	x=random(5);
	l=random(3)+2;
	print(i,j,x,l);
	while(i<10)
	{
		k=x;
		while(k<10)
		{
			opt<<i+k;
			k+=l;
		}
		i+=j;
		opt<<"\n";
	}
	opt.close();
	input();
	x=check();
	cout<<x;

}


float calc(int n1, int n2, int optn)            //calculating simple operations
{
	fstream qs;
	float x;
	qs.open("ques.txt",ios::app);
	switch(optn)
	{
		case 0: x=n1+n2;
			qs<<n1<<"+"<<n2<<"\n";
			break;
		case 1: x=n1-n2;
			qs<<n1<<"-"<<n2<<"\n";
			break;
		case 2: x=n1*n2;
			qs<<n1<<"*"<<n2<<"\n";
			break;
		case 3: x=n1/n2;
			qs<<n1<<"/"<<n2<<"\n";
			break;
		default: exit(0);
	}
	qs.close();
	return x;
}

void ques()                    //generating random questions for simple operations
{
	int i,n1,n2,optn;
	float ans;
	fstream qs,sol;
	sol.open("ans.txt",ios::out);
	cout<<"Solve the following: ";
	for(i=1;i<=NUM;i++)
	{
		n1=random(100);
		n2=random(100);
		optn=random(4);
		ans=calc(n1,n2,optn);
		sol<<ans<<"\n";
	}
	sol.close();
}
void inputAns()               //taking responses from user
{
	fstream qs,inp;
	int i,val;
	inp.open("inputAnswers.txt",ios::out);
	char str[10];
	qs.open("ques.txt",ios::in);
	for(i=1;i<=NUM;i++)
	{
		qs.getline(str,10,'\n');
		cout<<"\nQues "<<i<<": "<<str;
		cout<<"\tAns= ";
		cin>>val;
		inp<<val<<"\n";
	}
	qs.close();
	inp.close();
}

void compare()                  //checking for correctness
{
	fstream result,sol,inp;
	result.open("result.txt",ios::out);
	sol.open("ans.txt",ios::in);
	inp.open("inputAnswers.txt",ios::in);
	char str[10],str1[10];
	int i;
	for(i=1;i<=NUM;i++)
	{
		sol.getline(str,10,'\n');
		inp.getline(str1,10,'\n');
		if(strcmp(str,str1)==0)
			result<<1<<"\n";
		else
			result<<0<<"\n";

	}
	sol.close();
	inp.close();
	result.close();
}

/*void display()                      //displaying the final result
{
	fstream result;
	result.open("result.txt",ios::in);
	int count=0,i,per;
	char str[5];
	for(i=1;i<=NUM;i++)
	{
		result.getline(str,5,'\n');
		if(*str=='1')
			count++;
	}
	per=count*10;
	cout<<"Percentage scored : "<<per<<"%\n";
	result.close();
} */


void main()
{
	clrscr();
	ques();
	inputAns();
	compare();
	calcOutput();
//	display();
	getch();
}