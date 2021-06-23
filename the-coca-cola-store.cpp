/*
Problem: The coca cola store
Type of problem: Basic
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2999
Coder: alexgargui
*/
#include <cstdio>

using namespace std;

int vacias, llenas, var, ver;

int main(){
	scanf("%d\n", &vacias);
	while(vacias!=0){
		llenas=0; var=0; ver=0;
		while(vacias>=3){
			var=vacias/3;
			ver=vacias%3;
			vacias=var+ver;
			llenas=llenas+var;
		}
		if(vacias==2){
			llenas++;
		}
		printf("%d\n", llenas);
		scanf("%d\n", &vacias);
	}
}
