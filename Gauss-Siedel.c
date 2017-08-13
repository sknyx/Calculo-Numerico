/*Método de Gauss-Sieldel para o sistema de equaçâo:
2x+y = 1
x+2y = 3
com erro<=10^-3 e valor inicial [0 , 0]
*/
#include<stdio.h>
#include <math.h>

float eq_x(float y)  /*Função para a equação de X que recebe por parâmetro Y*/
{
    return (1+y)/2;
}
float eq_y(float x)  /*Função para a equação de Y que recebe por parâmetro X*/
{
    return (3-x)/2;
}

float main()
{
    int k=0;
    float x=0, y=0, xa, ya, erro1, erro2, erro;
    /*x e y recebem os valores iniciais 0.
      xa = 'x' anterior.
      ya = 'y' anterior.
      erro1 = erro tirado da diferença entre o 'x' atual e o 'x' anterior.
      erro2 = erro tirado da diferença entre o 'y' atual e o 'y' anterior.
      */
    printf("k\t X\t Y\t erro\n"); //Cabeçalho da tabela

    do
    {
        if(k==0)
        {
            printf("%d\t%.3f\t%.3f\t",k, x, y, erro);
            printf(".....\n");
            erro = fabs((x-xa)/x);
        }
        /*
        Na primeira condição (if), o programa mostrará os valores iniciais com o erro ainda não definido.
        Aqui a variável 'erro' recebe valor afim do funcionamento do while.
        */
        else
        {
            xa = x;
            ya = y;
            x = eq_x(ya);
            y = eq_y(x);

            erro1 = fabs((x-xa)/x);
            erro2 = fabs((y-ya)/y);
            /*
            A partir da segunda iteração (k=1), os valores de x e y passam a se atualizar. Aqui há o uso das variáveis auxiliares
            'xa' e 'ya' para receberem os valores anteriores de 'x' e 'y' afim de atualizar os valores de 'x' e 'y'.
            Aqui é onde se encontra a diferença entre os métodos (Jacobi e Gauss), uma vez que 'y' passa a receber o valor atualizado
            de 'x' ao invés do 'x' anterior (xa).
            Após isso, os erros relativos entre as variáveis atuais e as variáveis anteriores são calculados para que seja escolhido
            o maior valor entre eles, assumindo o lugar do erro geral do método.
            */
            if(erro1>erro2)
            {
                erro = erro1;
            }
            else
            {
                erro = erro2;
            }
            printf("%d\t%.3f\t%.3f\t%.3f\n",k, x, y, erro); //Impressão dos novos valores restritos a 3 casas decimais
        }
        k++; //Número da iteração é atualizado
    }
    while (erro > pow(10, -2)); //Condição do funcionamento da repetição
}
