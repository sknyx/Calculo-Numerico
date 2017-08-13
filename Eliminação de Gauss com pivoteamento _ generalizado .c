/*
Eliminação de Gauss com pivoteamento

Data: 18/10/2016
Disciplina: Cálculo Numérico
Dupla: Carolina Ataíde  --  161057600051
       Larissa Rayane   --  161057600063

*/

#include<stdio.h>
#include<stdlib.h>

int lin=0;
int col=0;

/*imprimit matriz*/
void i_matriz(float mat[lin][col]);
/*preencher matriz*/
void p_matriz(float mat[lin][col]);
/*multiplicador da matriz*/
float m_matriz(float mat[lin][col], int i, int j);
/*escalonar a matriz*/
void e_matriz(float mat[lin][col],  int linha);
/*substituicao de trás p/ frete da matriz*/
void s_matriz(float mat[lin][col]);
/*contar linhas do txt*/
void contar_linhas();
/*imprime as respostas do sistema*/
void p_resposta(float resp[lin]);

int main()
{

    contar_linhas();
    float matriz[lin][col];
    float mult;
    int i;

    p_matriz(matriz);
    printf("Matriz original: \n");
    i_matriz(matriz);
    for(i=0; i<lin; i++)
    {
        e_matriz(matriz, i);
    }

    printf("\nMatriz Escalonada: \n");
    i_matriz(matriz);
    s_matriz(matriz);
    return 0;
}


//imprime matriz
void i_matriz(float mat[lin][col])
{
    int i, j;
    for(i=0; i<lin; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%.3f\t", mat[i][j]);
        }
        printf("\n");
    }
}

//preenche matriz
void p_matriz(float mat[lin][col])
{

    int i, j;
    FILE *arq;
    arq = fopen("matriz.txt", "r");

    for(i=0; i<lin; i++)
    {
        for(j=0; j<col; j++)
        {
            fscanf(arq, "%f", &mat[i][j]);
        }
    }

    fclose(arq);

    contar_linhas();
    printf("Ordem da matriz: %d\n\n", lin);

}

//multiplicador matriz
//i -> linha
//j -> coluna
float m_matriz(float mat[lin][col], int i, int j)
{

    float m;

    if(i == (lin-1))
    {
        m = i;
    }
    else if(mat[j][i] != 0)
    {

        m = mat[j][i] / mat[i][i];
    }
    else
    {
        m = 0;
    }
    return m;
}


/*escalonamento da matriz*/
void e_matriz(float mat[lin][col],  int linha)
{

    int i, j;
    float vet[col];
    float mult;

    for(i=linha+1; i<lin; i++)
    {
        //armazeno o multiplicador da linha em mult
        mult = m_matriz(mat,linha, i);
        for(j=0; j<col; j++)
        {
            //o vet recebe o (mult*-1) * (a linha do pivo)
            vet[j] = (-1*mult)*mat[linha][j];
            //somo linha de destino com o vet
            mat[i][j] += vet[j];
        }
//		printf("\n");
    }
}

void s_matriz(float mat[lin][col])
{

    float resp[lin];
    int i, j;
    /*inicializo o vetor das respostas com 1 em todas as posicoes*/
    for(i=0; i<lin; i++)
    {
        resp[i] = 1;
    }

    /*vetor para guardar as respostas*/
    float aux=0;

    printf("\n");
    for(i=lin-1; i>=0; i--)
    {
        for(j=col-1; j>=0; j--)
        {
            if(j==(col-1))
            {
                /*j == col-1 significa que estou no
                termo independente*/
                aux += mat[i][j];
            }
            else if(i!=j)
            {
                //somo o inverso de todos os numeros
                //com a excessao do pivo
                aux += (-1*mat[i][j]) * (resp[j]);
            }
        }
        aux /= mat[i][i];
        //armazeno o resultado no vetor de respostas
        resp[i] = aux;
        //zero o acumulador
        aux = 0;
    }

    p_resposta(resp);
}

void p_resposta(float resp[lin])
{

    int i=0;

    printf("Respostas\n");
    for(i=0; i<lin; i++)
    {
        printf("x[%d] = %.4f\n", i+1,resp[i]);
    }
}

void contar_linhas()
{

    FILE *arq;
    arq = fopen("matriz.txt", "r");
    int linhas=0;

    //percorro todo o txt
    while(!feof(arq))
    {
        //feof retorna true quando o arquivo chega ao final
        if(fgetc(arq) == '\n')
        {

            linhas++;
        }
    }

    fclose(arq);

    lin = linhas + 1;
    col = lin + 1;
}
