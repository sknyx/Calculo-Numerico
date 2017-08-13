
#include <stdio.h>
#include<stdlib.h>

#define linha 4
#define coluna 5
#define max 15 /*m�ximo de itera��es*/

int main()
{
    double valores_iniciais[coluna-1] = {1,2,3,4}; /*usu�rio definir� os valores iniciais das vari�veis para a realiza��o dos c�lculos*/

    double valores[coluna-1], v[coluna-1], x[coluna-1], soma=0;
    int l, c, i=0, j, M;

    double matriz[linha][coluna]=
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
    };

    for(l=0; l<linha; l++)
    {
        for(c=0; c<(coluna-1); c++) /*varrer s� os numeros que possuem vari�veis sem ler os termos independentes*/
        {
            if(l==c)
            {
                //printf("%lf / %lf\n", matriz[l][coluna-1], matriz[l][c]);
                if((matriz[l][c])!=0)
                {
                    v[i] = (matriz[l][coluna-1])/(matriz[l][c]); /*termo independente dividido pelo multiplicador*/
                    i++;
                }
                else
                {
                    v[i] = (matriz[l][coluna-1]); /*termo independente dividido pelo multiplicador*/
                    i++;
                }
            }
        }
    }

    /*for(i=0; i<coluna-1; i++)
    {
        printf("%lf\t", v[i]);
    }
    printf("\n");*/


    for(M=0; M<max; M++) /*controla o n�mero de itera��es que ser�p realizadas*/
    {

        i=0;
        for(l=0; l<linha; l++)
        {
            for(c=0; c<(coluna-1); c++)
            {
                if(l!=c)
                {
                    /*demais termos multiplicados por suas vari�veis*/
                    if(M==0)
                    {
                        if(matriz[i][i]!=0) /*impedir divis�o por zero*/
                        {
                            x[i] = soma + ((((matriz[l][c])*(-1))*(valores_iniciais[c]))/matriz[i][i]);/*valores inciais das vari�veis*/
                            soma = x[i];
                        }
                        else
                        {
                            x[i] = soma + (((matriz[l][c])*(-1))*(valores_iniciais[c]));
                            soma = x[i];
                        }
                    }
                    else
                    {
                        if(matriz[i][i]!=0)
                        {
                            x[i] = soma + (((matriz[l][c])*(-1))*(valores_iniciais[c])/matriz[i][i]);
                            soma = x[i];
                        }
                        else
                        {
                            x[i] = soma + (((matriz[l][c])*(-1))*(valores_iniciais[c]));
                            soma = x[i];
                        }
                    }
                }
            }
            printf("x[%d] =  %lf + %lf\n", i, x[i], v[i]);
            x[i] = x[i] + v[i]; /*valor atual da vari�vel*/
            i++;
            soma=0;
        }

        printf("\n\n");
        for(i=0; i<coluna-1; i++)
        {
            printf("%lf\t", x[i]); /*impress�o das itera��es*/
        }
        printf("\n");
    }

    return 0;
}
