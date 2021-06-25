/*
Problem: Parentheses balance
Type of Problem: Stack
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
Coder: alexgargui
*/
#include <cstdio>
#include <stack>

using namespace std;
int fin;
char cadena[130];
int balanceada;

int revisa(char izq, char der){
    char cierra;
    if(izq=='(') cierra=')';
    if(izq=='[') cierra=']';
    if(cierra==der) return 1;
    return 0;
}

int procesa(){
    stack <char> S;

    for(int i=0; cadena[i]!='\0';i++){
        if(cadena[i]=='(' || cadena[i]=='['){
            S.push(cadena[i]);
        }
        else if(cadena[i]==')' || cadena[i]==']'){
            if(S.empty()) return 0;
            if(revisa(S.top(), cadena[i])==0) return 0;
            S.pop();
        }
    }
    if(!S.empty()) return 0;
    return 1;
}
int main()
{
    scanf("%d\n", &fin);
    while(fin--){
        gets(cadena);
        balanceada = procesa();
        if( balanceada == 1 )
            printf("Yes\n");
        if(balanceada == 0)
            printf("No\n");
        balanceada=0;
    }
}
