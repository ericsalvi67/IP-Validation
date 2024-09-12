/* Faça um programa em linguagem C que leia uma string e verifique se essa corresponde a um endereço de IP (Internet Protocol) válido. 
Um IP corresponde a uma sequencia de 4 valores numéricos compreendidos  no intervalo [0-255] e separados entre si por um carácter “.” .*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50


int verifyIP(char str[N])
{
    int i;
    int c=0; //contador
    int p=0; //soma ponto
    int s=0; //soma total

    for(i=0;str[i]!='\0';i++) //verifica quantidade de numeros
    {
        if(!(str[i]>='.' && str[i]<='9' && str[i]!='/')) return 0; //se respeita numerais
        if(str[i]=='.' && str[i+1]=='.') return 0; //se nao repete . (..)

        if(str[i]=='.') p++; //soma ponto
        c++; //contador

        if(p>3 || c>15) return 0; //se respeita a estrutura de IP
    }

    if(str[0]=='.' || str[c-1]=='.') return 0; //se nao inicia ou termina com .

    for(i=0;i<=c;i++) //teste de estrutura de IP
    {
        if(str[i]!='.') //somatoria ate o .
        {
            s*=10;
            s+=str[i];
            s-=48;
            if(s>255) return 0; //testa o conjunto de numeros
        }
        else s=0; //reset de soma
    }

    return 1;

}

void classtest(const char str[N]) //recurso extra!!
{
    int i;
    int s=0;

    for(i=0;str[i]!='.';i++) //soma do primeiro conjunto
    {
        s*=10;
        s+=str[i];
        s-=48;
    }

    if(s<127) printf("\tClasse A"); // define a classe
    else if (s<192) printf("\tClasse B");
    else if (s<224) printf("\tClasse C");
    else if (s<240) printf("\tClasse D");
    else if (s<=255) printf("\tClasse E");
}

int main()
{
    char str[N];
    
    printf("DIGITE O IP: ");
    gets(str);

    if(verifyIP(str))
    {
        printf("\nIP Valido");
        printf("\t=>");
        classtest(str);
    } 
    else printf("\nIP Invalido");
}
