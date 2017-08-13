#include <stdio.h>
#include <math.h>

//Método de Newton

float funcao(float x)
{
    return (-pow(x,3)-pow(x,2)+(3*(x))-1);
}
float dx1(float x)
{
    return (-3*pow(x,2)-(2*(x))+3);
}
float dx2(float x)
{
    return (-6*x)-2;
}
int main()
{
    printf(" k\t     xk\t            F(xk)\t    F'(xk)\t    Erro\t\n");

    int k;
    float xo, xk, fxk, flxk, fllxk, erro, xa;

    xo = funcao(-3)*dx2(-3);

    if(xo>0)
    {
        xk=-3;
    }
    else
    {
        xk=-2;
    }
    k=-1;
    fxk= funcao(xk);
    flxk= dx1(xk);

    do
    {
        k++;
        if(k!=0)
        {
            xa = xk;
            xk = xa-(fxk/flxk);
            erro = fabs(xk-xa)/fabs(xk);
        }
        fxk = funcao(xk);
        flxk = dx1(xk);
        printf(" %d\t%.8f\t%.8f\t%.8f\t",k, xk, fxk, flxk);
        if(k==0)
            printf("..........\n");
        else
            printf("%.8f\n",erro);
    }
    while ((erro>=pow(10, -3) && k!=0) || k==0);
}
