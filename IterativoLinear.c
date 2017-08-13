#include<stdio.h>
#include<math.h>

//Método Iterativo Linear para a função x^2-senx com erro <= 0.001 e Xo = 0.9

float FunOrig(float x)
{
    return pow(x, 2)-sin(x);
}
float funcao(float x)
{
    return sqrt(sin(x));
}

void main()
{
    int k=1;
    float x, Fx, fx, erro;

    x = 0.9;

    printf("k\t   X\t\t  Fx\t\t  fx\t\t erro\n");

    do
    {
        Fx = funcao(x);
        fx = FunOrig(x);
        erro = fabs((Fx-x)/Fx);
        printf("%d\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", k,x,Fx, fx, erro);
        x = Fx;
        k++;
    }
    while (erro > pow(10, -3));
}
