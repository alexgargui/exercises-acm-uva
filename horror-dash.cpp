/*
Problem: Horror dash
Type of Problem: Basics
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2899
Coder: alexgargui
*/
#include <cstdio>

using namespace std;

int a, d=0;
int b=0;
int c=0;
int cont=1;

void procesa(){
	scanf("%d", &a);
	while(a--){
		scanf("%d", &d);
		if(d>b){
			b=d;
			d=0;
		}
	}
	printf("Case %d: %d\n", cont, b);
	cont++;
	b=0;
}
int main(){
	scanf("%d\n", &c);
	while(c--){
		procesa();
	}
}
