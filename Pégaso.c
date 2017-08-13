#include<stdio.h>
#include<math.h>

//Método Pégaso para a função (x-3)²-e^-x-55 com erro <=0.00001 no intervalo (0, 20)

float funcao(float x)
{
    return pow((x-3),2) - pow(M_E, -x)-55;
}

void main()
{
    int k=1;
    float xa, xk, xp, fxa, fxk, fxp, erro;
    xa = 0;
    xk = 20;

    printf("k\t XK-1\t\tF(XK-1)\t\t  XK\t\t F(XK)\t\t Xk+1\t\tF(XK+1)\t\terro\n");

    do
    {
        if(k==1)
        {
            fxa = funcao(xa);
            fxk = funcao(xk);
            xp = ((xa*fxk)-(xk*fxa))/(fxk-fxa);
            fxp = funcao(xp);
            printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t", k,xa,fxa, xk, fxk, xp, fxp);
            printf("......\n");
            erro = fabs((xk-xp)/xp);
        }
        else
        {
            if( fxk*fxp < 0 )
            {
                xa = xk;
                xk = xp;
                fxa = funcao(xa);
                fxk = funcao(xk);
                xp = ((xa*fxk)-(xk*fxa))/(fxk-fxa);
                fxp = funcao(xp);
                erro = fabs((xk-xp)/xp);
                printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", k,xa,fxa, xk, fxk, xp, fxp, erro);
            }
            else
            {

                fxa = fxa*(fxk/(fxk+fxp));
                xk = xp;
                fxk = funcao(xk);
                xp = ((xa*fxk)-(xk*fxa))/(fxk-fxa);
                fxp = funcao(xp);
                erro = fabs((xk-xp)/xp);
                printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", k,xa,fxa, xk, fxk, xp, fxp, erro);
            }

        }
        k++;
    }
    while(erro > pow(10,-5));
}
