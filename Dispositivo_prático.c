/*

"Dispositivo Prático"

Data: 27/10/2016
Disciplina: Cálculo Numérico
Dupla: Carolina Ataíde  --  161057600051
       Larissa Rayane   --  161057600063

*/

#include<stdio.h>
#include<stdlib.h>

int confere_grau()
{
    int x;
    printf("Informe o grau do polinomio: ");
    scanf("%d", &x);
    return x+1;
}
int main()
{
    int grau, i=0, j=0, l, c, k=1;
    grau = confere_grau();

    double valor_funcao, valor, pontos[grau], valores[grau], pi=1, dk, fx_dk, soma=0;

    FILE *arq;
    arq = fopen("funcao.txt", "r");

    for(l=0; l<2; l++)
    {
        for(c=0; c<grau; c++)
        {
            fscanf(arq, "%lf", &valor);
            if(l==0)
            {
                pontos[i] = valor; //carrega o conteudo da linha 1 no vetor de pontos
                i++;
            }
            else
            {
                valores[j] = valor; //carrega o conteudo da linha 2 no vetor de valores
                j++;
            }
        }
    }
    fclose(arq);

    printf("Informe o valor x de f(x): ");
    scanf("%lf", &valor_funcao);

    for(i=0; i<grau; i++)
    {
        pi *=(valor_funcao - pontos[i]); //(X - Xo)*(X - X1)*(X - X2)*.....*(X - Xn)
    }

    printf("\nK\t    DK\t          FK/DK");
    for(j=0; j<grau; j++)
    {
        for(i=0; i<grau; i++)
        {
            if(i==0)
            {
                dk = valor_funcao - pontos[j]; // X - Xk
            }
            if(i!=j)
            {
                dk *= (pontos[j]- pontos[i]); // Xk - Xi
            }
        }
        fx_dk = valores[j]/dk; //valor da função no ponto Xk dividido pelo multiplicatorio de (Xk - Xi)
        soma += fx_dk; //somatório do fx_dk
        printf("\n\n%d|\t%lf\t%lf\t", k, dk, fx_dk);
        k++;
        dk=0;
    }
    valor = pi*soma; // Pn(a) = PIn(a) * S

    printf("\n\nPI(%.3lf) = %lf\nSoma = %lf", valor_funcao, pi, soma);
    printf("\n\nValor da funcao para f(%lf) = %lf\n", valor_funcao, valor);

    return 0;
}
