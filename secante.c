#include<stdio.h>
#include<math.h>

//Método da Secante para a função (e^x)-(senx)-2 com E<0.00001 no intervalo (1,1.2)

float funcao(float x) //função
{
    return (pow(x,3)-(2*x)-1);
}

float dx1(float x) //primeira derivada
{
    return (3*pow(x,2)-2);
}

float dx2(float x) //segunda derivada
{
    return (6*x);
}

int main()
{

    printf(" k\t   XK-1\t           F(XK-1)\t     XK\t            F(XK)\t  Erro\t\n");

    int k=-1;
    float xo, xk, fxk, erro, xa, fxa, aux;

    xo = funcao(-0.25)*dx2(-0.25);

    if(xo>0)
    {
        xk=-0.25;
        xa=-0.75;
    }
    else
    {
        xk=-0.75;
        xa=-0.25;
    }

    do
    {
        k++;
        if(k!=0)
        {
            aux = xk;
            xk = (xa*fxk - xk*fxa) / (fxk - fxa);
            xa= aux;
            erro = fabs(xk-xa)/fabs(xk);
        }
        fxk = funcao(xk);
        fxa = funcao(xa);
        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t", k, xa, fxa, xk, fxk);
        if(k==0)
        {
            printf("........\n");
        }
        else
        {
            printf("%.6f\n", erro);
        }
    }
    while( (erro>pow(10,-5) && k!=0 )|| k==0);
}

