/*
Problem: Oil deposits
Type of Problem: Stack with DFS
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513
Coder: alexgargui
*/
#include <cstdio>
#include <stack>

using namespace std;
char matriz[110][110];
int f, c, contador=0;
char tmp;

typedef struct{
	int fil;
	int col;
}posicion;

stack <posicion> S;

void lee(){
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            scanf("%c", &tmp);
            if(tmp=='*'){
                matriz[i][j]=0;
            }
            else if(tmp=='@'){
                matriz[i][j]=1;
            }
        }
        scanf("%c", &tmp);
    }
    for(int i=0;i<=f;i++){
        matriz[i][0]=-1;
        matriz[i][c+1]=-1;
    }
    for(int j=0;j<=c;j++){
        matriz[0][j]=-1;
        matriz[f+1][j]=-1;
    }
}

int F[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int C[8]={0, 1, 1, 1, 0, -1, -1, -1};
void procesa(){
    posicion p;
	while(!S.empty()){
		p=S.top();
		S.pop();
		for(int m=0; m<8;m++){
			if(matriz[p.fil+F[m]] [p.col+C[m]]==1){
				matriz[p.fil+F[m]] [p.col+C[m]]=0;
				posicion temp={p.fil+F[m], p.col+C[m]};
				S.push(temp);
			}
		}
	}
}

int main(){
	scanf("%d %d\n", &f, &c);
	while(f>0 && c>0){
		lee();
		for(int j=1; j <= c; j++) {
    	    for(int i=1; i <= f; i++){
   	        	if(matriz[i][j]>0){
       	        	posicion p={i, j};
	        		S.push(p);
                	matriz[i][j] = 0;
                	procesa();
                	contador++;
            	}
        	}
    	}
		printf("%d\n", contador);
		contador=0;
		scanf("%d %d\n", &f, &c);
	}
}
