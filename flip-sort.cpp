/*
Problem: Flip sort
Type of Problem: Sorts
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1268
Coder: alexgargui
*/
#include <cstdio>

using namespace std;

int lista[1001];
int numero;
int numeros;
int contador =0;

int main()
{

	while(scanf("%d\n", &numeros)==1){
		for(int x=0;x<numeros;x++){
			scanf("%d",&lista[x]);
		}
		for(int i=0;i<numeros;i++){
			for(int j=0;j<numeros-1;j++){
				if(lista[j]>lista[j+1]){
					numero = lista[j];
					lista[j] = lista[j+1];
					lista[j+1] = numero;
					contador++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",contador);
		contador=0;
	}
}
