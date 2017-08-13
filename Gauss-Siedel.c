/*M�todo de Gauss-Sieldel para o sistema de equa��o:
2x+y = 1
x+2y = 3
com erro<=10^-3 e valor inicial [0 , 0]
*/
#include<stdio.h>
#include <math.h>

float eq_x(float y)  /*Fun��o para a equa��o de X que recebe por par�metro Y*/
{
    return (1+y)/2;
}
float eq_y(float x)  /*Fun��o para a equa��o de Y que recebe por par�metro X*/
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
      erro1 = erro tirado da diferen�a entre o 'x' atual e o 'x' anterior.
      erro2 = erro tirado da diferen�a entre o 'y' atual e o 'y' anterior.
      */
    printf("k\t X\t Y\t erro\n"); //Cabe�alho da tabela

    do
    {
        if(k==0)
        {
            printf("%d\t%.3f\t%.3f\t",k, x, y, erro);
            printf(".....\n");
            erro = fabs((x-xa)/x);
        }
        /*
        Na primeira condi��o (if), o programa mostrar� os valores iniciais com o erro ainda n�o definido.
        Aqui a vari�vel 'erro' recebe valor afim do funcionamento do while.
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
            A partir da segunda itera��o (k=1), os valores de x e y passam a se atualizar. Aqui h� o uso das vari�veis auxiliares
            'xa' e 'ya' para receberem os valores anteriores de 'x' e 'y' afim de atualizar os valores de 'x' e 'y'.
            Aqui � onde se encontra a diferen�a entre os m�todos (Jacobi e Gauss), uma vez que 'y' passa a receber o valor atualizado
            de 'x' ao inv�s do 'x' anterior (xa).
            Ap�s isso, os erros relativos entre as vari�veis atuais e as vari�veis anteriores s�o calculados para que seja escolhido
            o maior valor entre eles, assumindo o lugar do erro geral do m�todo.
            */
            if(erro1>erro2)
            {
                erro = erro1;
            }
            else
            {
                erro = erro2;
            }
            printf("%d\t%.3f\t%.3f\t%.3f\n",k, x, y, erro); //Impress�o dos novos valores restritos a 3 casas decimais
        }
        k++; //N�mero da itera��o � atualizado
    }
    while (erro > pow(10, -2)); //Condi��o do funcionamento da repeti��o
}
