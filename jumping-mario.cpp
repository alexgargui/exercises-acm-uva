/*
Problem: Jumping mario
Type of Problem: Basics
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2864
Coder: alexgargui
*/
#include <cstdio>

using namespace std;

int fin, finn, a, b, c, d=0;
int cont=1;

void procesa(){
	while(finn--){
		scanf("%d", &a);
		if(d<a){
			b++;
			d=a;
		}
		if(d>a){
			c++;
			d=a;
		}
	}
	printf("Case %d: %d %d\n", cont, b-1, c);
}

int main(){
	scanf("%d\n", &fin);
	while(fin--){
		scanf("%d\n", &finn);
		procesa();
		cont++;
		b=0; c=0; d=0;
	}
}
