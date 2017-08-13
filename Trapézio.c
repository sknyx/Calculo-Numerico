/*
Integra��o Num�rica - Regra do Trap�zio

Data: 17/10/2016
Disciplina: C�lculo Num�rico
Nome: Carolina Ata�de  --  161057600051
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
        soma = h+soma; //vetor com os pontos que ser�o usados para o c�lculo
        intervalos[i] = funcao(soma);
    }

    intervalos[0] = funcao(a); //valor da fun��o no limite inferior
    intervalos[n] = funcao(b); //valor da fun��o no imite superior

    for(i=0; i<n-1; i++)
    {
        integral = ((h/2)*(intervalos[i]+intervalos[i+1])) + integral; /* (altura/2)*(f(x)+f(x+1)) + ... + (altura/2)*(f(n-1)+f(n)) */
    }
    printf("\nIntegral = %lf\n", integral);
    return 0;
}
