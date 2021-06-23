/*
Problem: Sudoku
Type of problem: Aritmetica modular
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=930
Coder: alexgargui
*/
#include <cstdio>

using namespace std;

int M[10][10];
int encontrado=0, n2=0, n3=0, dato=0, fi=0, ci=0, casos=0;

void lee(){
	for(int i=0;i<n2;i++){
		for(int j=0;j<n2;j++){
			scanf("%d", &M[i][j]);
		}
	}
}

void bactracking(int n){
	int f=n/n2, c=n%n2;
	if(n==n3){
		encontrado=1;
		return;
	}
	if(M[f][c]>0){
		bactracking(n+1);
		return;
	}
	int N[10]={0};
	for(int i=0;i<n2;i++){
		if(M[f][i]>0){
			N[M[f][i]]=1;
		}
		if(M[i][c]>0){
			N[M[i][c]]=1;
		}
		fi=(f/dato)*dato+(i/dato);
		ci=(c/dato)*dato+(i%dato);
		if(M[fi][ci]>0){
			N[M[fi][ci]]=1;
		}
	}
	for(int i=1;i<=n2;i++){
		if(N[i]==0){
			M[f][c]=i;
			bactracking(n+1);
			if(encontrado==1){
				return;
			}
			M[f][c]=0;
		}
	}
}

void imprime(){
	for(int i=0;i<n2;i++){
		for(int j=0;j<n2;j++){
			printf("%d", M[i][j]);
			if(j<n2-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(){
	while(scanf("%d\n", &dato)==1){
		if(casos>=1){
			printf("\n");
		}
		n2=dato*dato;
		n3=dato*dato*dato*dato;
		lee();
		bactracking(0);
		if(encontrado==1){
			imprime();
		}
		else{
			printf("NO SOLUTION\n");
		}
		casos++;
		encontrado=0, n2=0, n3=0, dato=0, fi=0, ci=0;
	}
}
