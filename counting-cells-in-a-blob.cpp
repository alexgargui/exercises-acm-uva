/*
Problem: Counting cells in a blob
Type of problem: Queue with DFS
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=812
Coder: alexgargui
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct
{
	int F;
	int C;
}pos;

queue<pos>Q;

int FilRef[8]={-1,-1,0,1,1,1,0,-1};
int ColRef[8]={0,1,1,1,0,-1,-1,-1};

int cont[2]={0,0},grid[27][27],N,posicion[2]={0,0};
char buf[26];
int i=0;

void lee()
{
	int a,b;
	a=1;
	while(gets(buf) && buf[0]!='\0')
	{
		b=1;
		while(buf[b-1]!='\0')
		{
			if(buf[b-1]=='0')
				grid[a][b]=0;
			else
			{
				if(buf[b-1]=='1')
					grid[a][b]=1;
			}
			b++;
		}
		a++;
	}
	posicion[0]=a;
	posicion[1]=b;
	//Bordes
	for(int c=0; c<=b; c++)
	{
		grid[0][c]=-1;
		grid[a][c]=-1;
	}
	for(int c=0; c<=a; c++)
	{
		grid[c][0]=-1;
		grid[c][b]=-1;
	}
}

void procesa()
{
	pos P;
	while(!Q.empty())
	{
		P=Q.front();
		Q.pop();
		for(int a=0; a<8; a++)
		{
			if(grid[P.F+FilRef[a]][P.C+ColRef[a]]==1)
			{
				grid[P.F+FilRef[a]][P.C+ColRef[a]]=2;
				cont[0]++;
				pos temp={P.F+FilRef[a],P.C+ColRef[a]};
				Q.push(temp);
			}
		}
	}
}

void muestra()
{
	if(i>=1){
		cout<<endl;
	}
	cout<<cont[1]<< endl;
}

int main()
{
	scanf("%d\n",&N);
	for(int a=1; a<=N; a++)
	{
		lee();
		for(int x=1; x<posicion[0]; x++)
		{
			for(int y=1; y<posicion[1]; y++)
			{
				if(grid[x][y]==1)
				{
					cont[0]++;
					grid[x][y]++;
					pos aux={x,y};
					Q.push(aux);
					procesa();
					if(cont[0]>cont[1])
					{
						cont[1]=cont[0];
					}
					cont[0]=0;
				}
			}
		}
		muestra();
		cont[1]=0;
		i++;
	}
}
