/*
Problem: 2D Hieroglyphs decoder
Type of problem: Basic decode
Link to problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1792
Coder: alexgargui
*/
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

char Matriz[100][100];
char buffer[100];
char CasosChar[5];
int casos,tamanobuff=0,indice=0,decimal;
char ArregloBinario[20];

void lee(){
    for(int x=0;x<10;x++){
        gets(buffer);
        if(buffer[0]=='\0')
            gets(buffer);
        for(int y=0;buffer[y]!='\0';y++){
            if(x==0)
                tamanobuff++;
            Matriz[x][y] = buffer[y];
        }
    }

    for(int i=1;i<tamanobuff-1;i++){
        for(int j=1;j<9;j++){
            if(Matriz[j][i] == '/'){
                ArregloBinario[indice]='0';
                indice++;
            }
            else if(Matriz[j][i] == '\\'){
                ArregloBinario[indice]='1';
                indice++;
            }
        }

        for(int b=0;b<8;b++){
                if(ArregloBinario[b]=='1' && b == 0){
                    decimal=decimal+1;
                }
                else if(ArregloBinario[b]=='1' && b == 1){
                    decimal=decimal+2;
                }
                else if(ArregloBinario[b]=='1' && b == 2){
                    decimal=decimal+4;
                }
                else if(ArregloBinario[b]=='1' && b == 3){
                    decimal=decimal+8;
                }
                else if(ArregloBinario[b]=='1' && b == 4){
                    decimal=decimal+16;
                }
                else if(ArregloBinario[b]=='1' && b == 5){
                    decimal=decimal+32;
                }
                else if(ArregloBinario[b]=='1' && b == 6){
                    decimal=decimal+64;
                }
                else if(ArregloBinario[b]=='1' && b == 7){
                    decimal=decimal+128;
                }
        }
        printf("%c",decimal);
        decimal=0;
        indice = 0;
    }
    printf("\n");

}

int main()
{
    gets(CasosChar);
    sscanf(CasosChar,"%d",&casos);

    while(casos--){
        lee();

        memset(ArregloBinario,0,20);
        memset(Matriz,0,sizeof(Matriz));
        decimal=0;
        indice=0;
        tamanobuff=0;
    }
}
