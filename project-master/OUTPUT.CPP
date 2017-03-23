#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void print(int i,int j,int k, int l)
{
	cout<<"#include<iostream.h>\n";
	cout<<"main()\n{\n\tint i="<<i<<",j="<<j<<",k="<<k<<",l="<<l<<";\n";
	cout<<"\twhile(i<10)\n\t{\n\t\twhile(k<10)\n\t\t{\n\t\t\tcout<<i+k;\n\t\t\tk=k+l;\n\t\t}\n";
	cout<<"\t\ti=i+j;\n\t\tcout<<endl;\n\t}\n}";
}

void input()
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

int check()
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

void calcOutput()
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

void main()
{
	clrscr();
	calcOutput();
	getch();
}