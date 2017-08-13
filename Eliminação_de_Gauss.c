#include <stdio.h>

#define linha 5
#define coluna 6

void main()
{
    double matriz[linha][coluna]=
    {
        {1,0,2,3,2,27},
        {1,1,1,2,1,23},
        {1,2,1,1,2,31},
        {0,1,2,2,3,31},
        {2,1,0,1,1,22},
    };

    int lin, col, ctd = 0, op = 1, repeticao, i, j;
    double multiplicador, X[coluna-1];

    for(repeticao = 1; repeticao<linha; repeticao++) /*Esse for garante o reinicio do segundo for, atualizando a linha que será utilizada na nova iteração*/
    {
        for(lin = repeticao; lin<linha; lin++) /* 'lin' recebe 'repeticao' a fim de começar na linha 1 e de acordo com o 'for' da repetição, recomeçar na linha seguinte*/
        {
            for(col = (repeticao-1); col<coluna; col++) /* 'col' recebe 'repeticao -1' a fim de começar na coluna 0 e de acordo com o 'for' da repetição, pular de coluna*/
            {
                if(ctd == 0) /* caso seja uma nova iteração, um novo multiplicador será definido para o cálculo*/
                {
                    multiplicador = matriz[lin][col]/matriz[lin-op][col]; /*multiplicador recebe = valor atual/valor anterior*/
                    /* [lin-op] garante que divisor seja o valor da posição da linha anterior, na mesma coluna*/
                    ctd++; /*incrementação para impedir a atualização do 'multiplicador' até que a iteração acabe*/
                }
                matriz[lin][col] = (matriz[lin][col]) - ((multiplicador)*(matriz[lin-op][col])); /* A posição [lin][col] recebe o valor escalonado */
            }
            ctd = 0; /* A variável 'ctd' retorna ao seu valor valor original para garantir a atualização da variável 'multiplicador' */
            op++;
        }
        op = 1; /* A variável 'op' retorna ao seu valor original para garantir o funcionamento da variável 'multiplicador' */
    }
    /*................ Impressão da matriz escalonada ................*/
    printf("\nMatriz escalonada:\n\n");

    for(lin = 0; lin<linha; lin++)
    {
        for(col = 0; col<coluna; col++)
        {
            printf("%lf\t", matriz[lin][col]);
        }
        printf("\n");
    }
    printf("\n\n");

    /*................. Cálculo das incógnitas ....................... */
    for(i = linha-1; i>=0; i--) /*Inicia na ultima incógnita*/
    {
        X[i] = matriz[i][linha]/matriz[i][i]; /*X[i] recebe o valor da igualdade dividido e subtraido/somado das demais incógnitas com seus multiplicadores*/
        for(j = (i-1); j>=0; j--) /*substitui o valor de X[i] em seu respectivo lugar nas linhas anteriores afim de encontrar o valor das demais incógnitas*/
        {
            matriz[j][linha] = matriz[j][linha]-(matriz[j][i]*X[i]);
        }
    }
    /*............... Impressão dos resultados das incógnitas ........ */
    for(i = 0; i<linha; i++)
    {
        printf("X%d = %lf\n",i+1, X[i]);
    }
}
