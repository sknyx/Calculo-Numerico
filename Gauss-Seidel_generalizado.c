/*
Método de Gauss-Seidel

Data: 18/10/2016
Disciplina: Cálculo Numérico
Dupla: Carolina Ataíde  --  161057600051
       Larissa Rayane   --  161057600063

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*número de linhas e colunas da matriz presente no arquivo fornecido pelo usuário*/
#define linha 6
#define coluna 7

/*máximo de iterações que serão realizadas*/
#define max 9

int main()
{
    double matriz[linha][coluna], novos_valores[coluna-1], v[coluna-1], x[coluna-1], soma=0, v_teste = 1;
    int l, c, i=0, j, iteracoes, k, h;

    /*usuário definirá os valores iniciais das variáveis para a realização dos cálculos*/
    double valores_iniciais[coluna-1];

    for(k=0; k<coluna-1; k++)
    {
        valores_iniciais[k] = 1; /*valores iniciais das variáveis para a realização dos cálculos - nesse caso os valores
                                   estão sendo considerados como '1'*/
    }

    FILE *arq;
    arq = fopen("matriz.txt", "r");

    for(k=0; k<linha; k++)
    {
        for(h=0; h<coluna; h++)
        {
            fscanf(arq, "%lf", &matriz[k][h]); /*carrega o conteudo do arquivo na matriz*/
        }
    }

    fclose(arq);

    /*Critério das linhas*/
    for(k=0; k<linha; k++)
    {
        if(v_teste == 1)
        {
            for(h=0; h<coluna-1; h++)
            {
                if(k==h)
                {
                    v_teste = fabs(matriz[k][h]);
                }
                else
                {
                    soma += fabs(matriz[k][h]);
                }
            }
            if(v_teste>soma)
            {
                v_teste = 1;
            }
        }
        soma=0;
    }

    if(v_teste == 1) /*Verificação do critério das linhas*/
    {
        k=1;
        for(l=0; l<linha; l++)
        {
            for(c=0; c<(coluna-1); c++) /*varrer só os numeros que possuem variáveis sem ler os termos independentes*/
            {
                if(l==c)
                {
                    v[i] = (matriz[l][coluna-1])/(matriz[l][c]); /*termo independente dividido pelo multiplicador*/
                    i++;
                }
            }
        }
        soma=0;
        for(iteracoes=0; iteracoes<max; iteracoes++) /*controla o número de iterações que serão realizadas*/
        {
            i=0;
            for(l=0; l<linha; l++)
            {
                for(c=0; c<(coluna-1); c++)
                {
                    if(l!=c)
                    {
                        if(iteracoes==0) /*cálculo com os valores iniciais das variáveis definidas pelo usuário juntamente
                                            com a atualização dos valores já encontrados*/
                        {
                            x[i] = soma + ((((matriz[l][c])*(-1))*(valores_iniciais[c]))/matriz[i][i]);
                            soma = x[i]; /*somatório de cada valor*/
                        }
                        /* cálculo com os valores da iteração anterior*/
                        else
                        {
                            x[i] = soma + (((matriz[l][c])*(-1))*(novos_valores[c])/matriz[i][i]);
                            soma = x[i];
                        }
                    }
                }
                x[i] += v[i]; /*valor final da variável X[i] na iteração correspondente*/
                valores_iniciais[i] = x[i]; /*valores atualizados  das variáveis referentes a primeira iteração*/
                novos_valores[i] = x[i]; /*valores atualizados  das variáveis das demais iterações*/
                i++;
                soma=0;
            }

            for(i=0; i<coluna-1; i++)
            {
                novos_valores[i] = x[i]; /*atualização dos valores que serão utilizados na próxima iteração*/
            }

            printf("%d|\t", k); /*número da iteração*/
            k++;

            for(i=0; i<coluna-1; i++)
            {
                printf("%lf\t", novos_valores[i]); /*impressão das iterações*/
            }
            printf("\n\n");
        }

        printf("\n");
        for(i=0; i<coluna-1; i++)
        {
            printf("X%d = %lf\n",i+1, novos_valores[i]); /*impressão das raízes do sistema*/
        }
        printf("\n");
    }
    else
    {
        printf("\n\nO sistema fornecido nao foi aprovado no Critério das Linhas!\n\n");
    }
    return 0;
}
