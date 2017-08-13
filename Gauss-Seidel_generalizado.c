/*
M�todo de Gauss-Seidel

Data: 18/10/2016
Disciplina: C�lculo Num�rico
Dupla: Carolina Ata�de  --  161057600051
       Larissa Rayane   --  161057600063

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*n�mero de linhas e colunas da matriz presente no arquivo fornecido pelo usu�rio*/
#define linha 6
#define coluna 7

/*m�ximo de itera��es que ser�o realizadas*/
#define max 9

int main()
{
    double matriz[linha][coluna], novos_valores[coluna-1], v[coluna-1], x[coluna-1], soma=0, v_teste = 1;
    int l, c, i=0, j, iteracoes, k, h;

    /*usu�rio definir� os valores iniciais das vari�veis para a realiza��o dos c�lculos*/
    double valores_iniciais[coluna-1];

    for(k=0; k<coluna-1; k++)
    {
        valores_iniciais[k] = 1; /*valores iniciais das vari�veis para a realiza��o dos c�lculos - nesse caso os valores
                                   est�o sendo considerados como '1'*/
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

    /*Crit�rio das linhas*/
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

    if(v_teste == 1) /*Verifica��o do crit�rio das linhas*/
    {
        k=1;
        for(l=0; l<linha; l++)
        {
            for(c=0; c<(coluna-1); c++) /*varrer s� os numeros que possuem vari�veis sem ler os termos independentes*/
            {
                if(l==c)
                {
                    v[i] = (matriz[l][coluna-1])/(matriz[l][c]); /*termo independente dividido pelo multiplicador*/
                    i++;
                }
            }
        }
        soma=0;
        for(iteracoes=0; iteracoes<max; iteracoes++) /*controla o n�mero de itera��es que ser�o realizadas*/
        {
            i=0;
            for(l=0; l<linha; l++)
            {
                for(c=0; c<(coluna-1); c++)
                {
                    if(l!=c)
                    {
                        if(iteracoes==0) /*c�lculo com os valores iniciais das vari�veis definidas pelo usu�rio juntamente
                                            com a atualiza��o dos valores j� encontrados*/
                        {
                            x[i] = soma + ((((matriz[l][c])*(-1))*(valores_iniciais[c]))/matriz[i][i]);
                            soma = x[i]; /*somat�rio de cada valor*/
                        }
                        /* c�lculo com os valores da itera��o anterior*/
                        else
                        {
                            x[i] = soma + (((matriz[l][c])*(-1))*(novos_valores[c])/matriz[i][i]);
                            soma = x[i];
                        }
                    }
                }
                x[i] += v[i]; /*valor final da vari�vel X[i] na itera��o correspondente*/
                valores_iniciais[i] = x[i]; /*valores atualizados  das vari�veis referentes a primeira itera��o*/
                novos_valores[i] = x[i]; /*valores atualizados  das vari�veis das demais itera��es*/
                i++;
                soma=0;
            }

            for(i=0; i<coluna-1; i++)
            {
                novos_valores[i] = x[i]; /*atualiza��o dos valores que ser�o utilizados na pr�xima itera��o*/
            }

            printf("%d|\t", k); /*n�mero da itera��o*/
            k++;

            for(i=0; i<coluna-1; i++)
            {
                printf("%lf\t", novos_valores[i]); /*impress�o das itera��es*/
            }
            printf("\n\n");
        }

        printf("\n");
        for(i=0; i<coluna-1; i++)
        {
            printf("X%d = %lf\n",i+1, novos_valores[i]); /*impress�o das ra�zes do sistema*/
        }
        printf("\n");
    }
    else
    {
        printf("\n\nO sistema fornecido nao foi aprovado no Crit�rio das Linhas!\n\n");
    }
    return 0;
}
