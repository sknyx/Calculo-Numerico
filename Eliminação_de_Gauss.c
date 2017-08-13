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

    for(repeticao = 1; repeticao<linha; repeticao++) /*Esse for garante o reinicio do segundo for, atualizando a linha que ser� utilizada na nova itera��o*/
    {
        for(lin = repeticao; lin<linha; lin++) /* 'lin' recebe 'repeticao' a fim de come�ar na linha 1 e de acordo com o 'for' da repeti��o, recome�ar na linha seguinte*/
        {
            for(col = (repeticao-1); col<coluna; col++) /* 'col' recebe 'repeticao -1' a fim de come�ar na coluna 0 e de acordo com o 'for' da repeti��o, pular de coluna*/
            {
                if(ctd == 0) /* caso seja uma nova itera��o, um novo multiplicador ser� definido para o c�lculo*/
                {
                    multiplicador = matriz[lin][col]/matriz[lin-op][col]; /*multiplicador recebe = valor atual/valor anterior*/
                    /* [lin-op] garante que divisor seja o valor da posi��o da linha anterior, na mesma coluna*/
                    ctd++; /*incrementa��o para impedir a atualiza��o do 'multiplicador' at� que a itera��o acabe*/
                }
                matriz[lin][col] = (matriz[lin][col]) - ((multiplicador)*(matriz[lin-op][col])); /* A posi��o [lin][col] recebe o valor escalonado */
            }
            ctd = 0; /* A vari�vel 'ctd' retorna ao seu valor valor original para garantir a atualiza��o da vari�vel 'multiplicador' */
            op++;
        }
        op = 1; /* A vari�vel 'op' retorna ao seu valor original para garantir o funcionamento da vari�vel 'multiplicador' */
    }
    /*................ Impress�o da matriz escalonada ................*/
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

    /*................. C�lculo das inc�gnitas ....................... */
    for(i = linha-1; i>=0; i--) /*Inicia na ultima inc�gnita*/
    {
        X[i] = matriz[i][linha]/matriz[i][i]; /*X[i] recebe o valor da igualdade dividido e subtraido/somado das demais inc�gnitas com seus multiplicadores*/
        for(j = (i-1); j>=0; j--) /*substitui o valor de X[i] em seu respectivo lugar nas linhas anteriores afim de encontrar o valor das demais inc�gnitas*/
        {
            matriz[j][linha] = matriz[j][linha]-(matriz[j][i]*X[i]);
        }
    }
    /*............... Impress�o dos resultados das inc�gnitas ........ */
    for(i = 0; i<linha; i++)
    {
        printf("X%d = %lf\n",i+1, X[i]);
    }
}
