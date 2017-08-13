/*
Integração Numérica - Regra do Trapézio

Data: 17/10/2016
Disciplina: Cálculo Numérico
Nome: Carolina Ataíde  --  161057600051
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define a 0
#define b 1.2

double funcao(double x)
{
    return (pow((M_E),x)) * cos(x); // cos(x)e^x
}

int main()
{
    int n, i;

    printf("Informe a quantidade de TRAPEZIOS: ");
    scanf("%d", &n);
    n = n+1;

    double trapezios[n], intervalos[n], h, soma=0, integral=0;

    h = (double)(b-a)/(n-1);

    for(i=1; i<n; i++)
    {
        soma = h+soma; //vetor com os pontos que serão usados para o cálculo
        intervalos[i] = funcao(soma);
    }

    intervalos[0] = funcao(a); //valor da função no limite inferior
    intervalos[n] = funcao(b); //valor da função no imite superior

    for(i=0; i<n-1; i++)
    {
        integral = ((h/2)*(intervalos[i]+intervalos[i+1])) + integral; /* (altura/2)*(f(x)+f(x+1)) + ... + (altura/2)*(f(n-1)+f(n)) */
    }
    printf("\nIntegral = %lf\n", integral);
    return 0;
}
