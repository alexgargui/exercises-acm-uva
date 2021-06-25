/*
Problem: You want what filled
Type of Problem: Queue with bfs
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1887
Coder: alexgargui
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

typedef struct{
	char letra;
	int num;
}datos;

datos d;

typedef struct{
	int fil;
	int col;
}posicion;

queue <posicion> Q;

int f, c, cont=0, resul=0, z=1;
char car;
char matriz[100][100];
vector <datos> var;

void lee(){
	for(int i=1;i<=f;i++){
        gets(&matriz[i][1]);
    }
	for(int i=0;i<=f;i++){
		matriz[i][0]='0';
		matriz[i][c+1]='0';
	}
	for(int j=0;j<=c+1;j++){
		matriz[0][j]='0';
		matriz[f+1][j]='0';
	}
}

int F[4]={-1, 0, 1, 0}; int C[4]={0, 1, 0, -1};
void procesa(){
	posicion p;
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        for(int m=0;m<4;m++){
            if(matriz[p.fil+F[m]] [p.col+C[m]]==car){
                posicion temp={p.fil+F[m], p.col+C[m]};
                Q.push(temp);
                matriz[p.fil+F[m]] [p.col+C[m]]='.';
            }
        }
        cont++;
    }	
}

bool cmp(datos a, datos b){
	if(a.num==b.num){
		return a.letra<b.letra;
	}
	return a.num>b.num;
}

void ordena(){
	sort(var.begin(),var.end(),cmp);
}
void imprime(){
	printf("Problem %d:\n", z);
	z++;
	for(int i=0;i<var.size();i++){
		printf("%c %d\n", var[i].letra, var[i].num);
	}
}

int main(){
	scanf("%d %d\n", &f, &c);
	while(f>0 && c>0){
		lee();
		for(int i=1;i<=f;i++){
			for(int j=1;j<=c;j++){
				if(matriz[i][j]!='.'){
					car=matriz[i][j];
					posicion p={i, j};
					Q.push(p);
					matriz[i] [j] = '.';
					procesa();
					d.letra=car;
					d.num=cont;
					var.push_back(d);
					cont=0;
				}
			}
		}
		ordena();
		imprime();
		var.clear();
		scanf("%d %d\n", &f, &c);
	}
}
