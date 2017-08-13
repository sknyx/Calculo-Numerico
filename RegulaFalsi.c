#include<stdio.h>
#include<math.h>

//Método Regula Falsi para a função (x+1)²(e)^(x²-2)-1 com erro <=0.01 no intervalo (-2, -1)

float funcao(float x)
{
    return pow((x+1),2)*pow(M_E, (pow(x,2)-2))-1;
}

void main()
{
    int k=0;
    float xa, xk, xp, fxa, fxk, fxp, erro;
    xa = -2;
    xk = -1;

    printf("k\t XK-1\t\tF(XK-1)\t\t  XK\t\t F(XK)\t\t Xk+1\t\tF(XK+1)\t\terro\n");

    do
    {
        if(k==0)
        {
            fxa = funcao(xa);
            fxk = funcao(xk);
            xp = ((xa*fxk)-(xk*fxa))/(fxk-fxa);
            fxp = funcao(xp);
            printf("%d\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t", k,xa,fxa, xk, fxk, xp, fxp);
            printf(".....\n");
            erro = fabs((xk-xp)/xp);
        }
        else
        {
            if( fxk*fxp > 0 )
            {
                xk = xp;
                fxa = funcao(xa);
                fxk = funcao(xk);
                fxp = funcao(xp);
                xp = ((xa*fxk)-(xk*fxa))/(fxk-fxa);
                erro = fabs((xk-xp)/xp);
                printf("%d\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", k,xa,fxa, xk, fxk, xp, fxp, erro);
            }
        }
        k++;
    }
    while(erro > pow(10,-2));
}
