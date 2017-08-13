#include <stdio.h>
#include <math.h>

//Bisecçâo da função x²-3 com e<=0.01 no intervalo (1 , 2)

float funcao(float x)
{
    return(pow(x,2)-3);
}

int main ()
{
    printf(" k\t  ak\t  F(ak)\t   bk\t F(bk)\t  xk\t  F(xk)\t  Erro\t\n");

    int k;
    float ak, fak, bk, fbk, xk, fxk, erro;

    ak = 1;
    bk = 2;
    k =-1;
    xk =(ak+bk)/2;

    do
    {
        k++;
        if(k!=0)
        {
            if((fxk*fak)>0)
            {
                ak = xk;
                xk = (ak+bk)/2;
                erro = fabs(xk-ak)/fabs(xk);
            }
            else
            {
                bk = xk;
                xk = (ak+bk)/2;
                erro = fabs(xk-bk)/fabs(xk);
            }
        }

        fak = funcao(ak);
        fbk = funcao(bk);
        fxk = funcao(xk);

        printf(" %d\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\t",k, ak, fak, bk, fbk, xk, fxk);

        if(k==0)
        {
            printf(" .....\n");
        }
        else
        {
            printf(" %.3f\n",erro);
        }
    }
    while (erro>=pow(10, -2) && k!=0 || k==0);

}
