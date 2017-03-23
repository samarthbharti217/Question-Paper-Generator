
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#define NUM 10
char* DecimalToBinary(int a);
char* DecimalToHexadecimal(int a);
#include<malloc.h>
void convert(int n, int op)
{
	fstream ques,solu;
	int j,m;
	int i=0;
	int d=0;
	int f=10;
	char* s=(char*)malloc(sizeof(char)*f);
	char* c=(char*)malloc(sizeof(char)*f);

	ques.open("qs.txt",ios::app);
	solu.open("answ.txt",ios::app);
	switch(op)
	{
		case 0: c=DecimalToBinary(n);		//case 0=Convert decimal into binary
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }


			for(j=0;j<i;j++){
					solu<<*(c+j);		//to write binary no. in solution text file
					}
			ques<<n<<"n";				//to write decimal no. in question text file
			cout<<"\nConvert into Binary: ";
			cout<<n;
			break;
		case 1: c=DecimalToBinary(n);		//case1=convert binary into decimal
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }
			for(j=0;j<i;j++){
					ques<<*(c+j);		//to write binary no. in question text file
				      cout<<*(c+j);	}

			solu<<"\n"<<n;				//to write n in solution text file

			break;

		case 2:  c=DecimalToBinary(n);		//case2=convert hexadecimal into binary
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }

			for(j=0;j<i;j++){
					solu<<*(c+j);		//to write binary no. in solution text file
					}
			s=DecimalToHexadecimal(n);
			while(*(s+d)!='\n'){
						d++;		//to know the size of s
					   }
			for(m=0;m<d;m++){
					ques<<*(s+m);		//to write hexadecimal no. in question text file
				       cout<<*(s+m);
					}
			cout<<"\nConvert into Binary:";
			break;

		case 3:   c=DecimalToBinary(n);		//case3=convert binary into hexadecimal
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }

			for(j=0;j<i;j++){
					ques<<*(c+j);		//to write binary no. in question text file
				       cout<<*(c+j);	}
			s=DecimalToHexadecimal(n);
			while(*(s+d)!='\n'){
						d++;		//to know the size of s
					   }
			for(m=0;m<d;m++){
					solu<<*(s+m);		//to write Hexadecimal no. in solution text file
					}
			cout<<"\nConvert into Hexadecimal:";
			break;

		case 4:   c=DecimalToHexadecimal(n);	//case4=Convert hexadecimal into decimal
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }

			for(j=0;j<i;j++){
					ques<<*(c+j);		//to write hexadecimal no. in question text file
				      cout<<*(c+j);	}
			solu<<"\n"<<n;				//to write n in solution text file
			cout<<"\nConvert into Decimal:";
			break;

		case 5:  c=DecimalToHexadecimal(n);		//case5=Convert decimal into hexadecimal
			while(*(c+i)!='\n'){
						i++;		//to know the size of c
					   }

			for(j=0;j<i;j++){
					solu<<*(c+j);		//to write hexadecimal no. in solution text file
					}
			ques<<n;
			cout<<n;					//to write n in question text file
			cout<<"\nConvert into Hexadecimal:";
			break;

		default: exit(0);
	}
	ques.close();
	solu.close();
}

void ques()
{
	int i,n,op;
	float ans;
	cout<<"Convert the following: ";
	for(i=1;i<=NUM;i++)
	{
		n=random(100);
		op=random(5);
		convert(n,op);

	}
}
char* DecimalToBinary(int a)  //function to convert Binary from Decimal
{
	int i=0;
	int t=a;
	while(t>0)
	{
		t=t/2;
		i++;
	}
	char* c=(char*)malloc(sizeof(int)*(i+1));		//taking char ptr and doing dynamic memory allocation
	for(int j=i-1;j>=0;j--)
	{
		c[j]=a%2;
		a=a/2;
	}
		c[i]='\n';
	return c;
}

char* DecimalToHexadecimal(int a) //function to convert decimal into HexaDecimal
{
	int i=0;
	int t=a;
	while(t>0)
	{
		t=t/16;
		i++;
	}
       char* c=(char*)malloc(sizeof(char)*(i+1));		//taking char ptr and doing dynamic memory allocation
	for(int j=i-1;j>=0;j--)
	{
		t=t%16;
		if(t==10)
		{
		       c[j]='A';
		}
		else if(t==11)
		{
		      c[j]='B';
		}
		else if(t==12)
		{
		       c[j]='C';
		}
		else if(t==13)
		{
		       c[j]='D';
		}
		else if(t==14)
		{
		       c[j]='E';
		}
		else if(t==15)
		{
		       c[j]='F';
		}
		else
		{
		       c[j]=t;
		}
		t=t/16;
	}
       c[i]='\n';

}
void inputAns()
{
	fstream ques,inpt;
	int i,val;
	inpt.open("inputAnswer.txt",ios::out);
	char str[10];
	ques.open("qs.txt",ios::in);
	for(i=1;i<=NUM;i++)
	{
		ques.getline(str,10,'\n');
		cout<<"\nQues "<<i<<": "<<str;
		cout<<"\tAns= ";
		cin>>val;
		inpt<<val<<"\n";
	}
	ques.close();
	inpt.close();
}

void compare()
{
	fstream res,solu,inpt;
	res.open("res.txt",ios::out);
	solu.open("answ.txt",ios::in);
	inpt.open("inputAnswer.txt",ios::in);
	char str[10],str1[10];
	int i;
	for(i=1;i<=NUM;i++)
	{
		solu.getline(str,10,'\n');
		inpt.getline(str1,10,'\n');
		if(strcmp(str,str1)==0)
			res<<1<<"\n";
		else
			res<<0<<"\n";

	}
	solu.close();
	inpt.close();
	res.close();
}

void display()
{
	fstream res;
	res.open("res.txt",ios::in);
	int count=0,i,per;
	char str[5];
	for(i=1;i<=NUM;i++)
	{
		res.getline(str,5,'\n');
		if(*str=='1')
			count++;
	}
	per=count*10;
	cout<<"Percentage scored : "<<per<<"%\n";
	res.close();  }
void main()
{
	clrscr();
	ques();
	inputAns();
	compare();
	display();
	getch();
}