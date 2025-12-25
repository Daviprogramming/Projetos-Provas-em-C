//Questão 1
/*
#include <stdio.h>
void main(){
    int matriz[3][3];
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("Digite os elementos da sua matriz[%i][%i] : ", linha,coluna);
            scanf("%i", &matriz[linha][coluna]);
        }
    }
    for(int linha = 0; linha< 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("%i", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
*/

//Questão 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int matriz[4][4];
    int soma = 0;
    for(int linha = 0; linha < 4; linha++){
        for(int coluna = 0; coluna < 4; coluna++){
            matriz[linha][coluna] = rand() % 10;
        }
    }
    for(int linha = 0; linha < 4; linha++){
        for(int coluna = 0; coluna < 4; coluna++){
            soma = soma + matriz[linha][coluna];
        }
    }
    printf("A soma de todos seus elementos eh: %i", soma);
}
*/

//Questão 3

/*
#include <stdio.h>

void main(){
    int matriz[3][3];
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("Digite o valor do elemento [%i][%i] da matriz: ", linha, coluna);
            scanf("%i", &matriz[linha][coluna]);
        }
    }
    printf("Os elementos da diagonal principal sao: ");
    for(int linha=0; linha< 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            if(linha == coluna){
                printf("%i/",matriz[linha][coluna]);
            }
        }
    }
}
*/

//Questão 4

/*
#include <stdio.h>

void main(){
    int l = 0;
    int c = 2;
    int matriz2[3][3];
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("Digite o elemento da linha[%i] e coluna[%i] da matriz: ", linha, coluna);
            scanf("%i", &matriz2[linha][coluna]);
        }
    }
    printf("Os elementos da diagonal secundaria sao : ");
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            if(linha == l && coluna == c ){
                printf("%i", matriz2[linha][coluna]);
                l++;
                c--;
            }
        }
    }
}
*/

//Questão 5
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int matriz[3][3];
    int soma = 0;
    for(int linha = 0; linha < 3; linha ++){
        for(int coluna = 0; coluna < 3; coluna++){
            matriz[linha][coluna] = rand() % 10;
        }
    }

    printf("A sua matriz eh:\n");
    
    for(int linha = 0; linha < 3; linha ++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("%i|",matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("A soma dos elementos de cada linha eh:\n");

    for(int linha = 0; linha < 3; linha++){
        soma = 0;
        for(int coluna = 0; coluna < 3; coluna++){
            soma = soma + matriz[linha][coluna];
        }
        printf("Linha %i: %i\n", linha + 1, soma);
    }
    printf("A soma dos elementos de cada coluna eh:\n");

    for(int linha = 0; linha < 3; linha++){
        soma = 0;
        for(int coluna = 0; coluna < 3; coluna++){
            soma = soma + matriz[coluna][linha];
        }
        printf("Coluna %i: %i\n", linha + 1, soma);
    }

}
*/

//Questão 6
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int matriz[4][4];
    int maior = 0;
    int linha_maior = 0;
    int coluna_maior = 0;
    int menor = 201;
    int linha_menor = 0;
    int coluna_menor = 0;

    for(int linha = 0; linha < 4; linha++){
        for(int coluna = 0; coluna < 4; coluna++){
            matriz[linha][coluna] = rand() % 200;
            if(matriz[linha][coluna] > maior){
                maior = matriz[linha][coluna];
                linha_maior = linha;
                coluna_maior = coluna;

            }
            if(matriz[linha][coluna] < menor){
                menor = matriz[linha][coluna];
                linha_menor = linha;
                coluna_menor = coluna;
            }
        }
    }
    printf("O MAIOR numero da matriz eh:%i, onde suas linhas e colunas sao respectivamente: %i e %i\n\n", maior, linha_maior + 1, coluna_maior + 1);
    printf("O MENOR numero da matriz eh:%i, onde suas linhas e colunas sao respectivamente: %i e %i ", menor, linha_menor + 1, coluna_menor + 1);

}
*/

//Questão 7
/*
#include <stdio.h>

void main(){
    int matriz[3][3];
    int par = 0;
    int impar = 0;
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("Digite o elemento da matriz[%i][%i]: ", linha, coluna);
            scanf("%i", &matriz[linha][coluna]);
            if(matriz[linha][coluna] % 2 == 0){
                par++;
            }
            else{
                impar++;
            }
        }
    }
    printf("Tem %i pares e %i impares nessa matriz!", par, impar);
}
*/

//Questão 8

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main(){
    srand(time(NULL));
    int matriz[3][2];
    int matriztransposta[2][3];
    printf("Matriz padrao:\n");
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 2; coluna++){
            matriz[linha][coluna] = rand() % 10;
            matriztransposta[coluna][linha] = matriz[linha][coluna];
            printf("%i/", matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("\nMatriz transposta: \n");
    for(int linha = 0; linha < 2; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            printf("%i/", matriztransposta[linha][coluna]);
        }
        printf("\n");
    }

}
*/

//Questão 9

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int A[2][2];
    int B[2][2];
    int C[2][2];
    printf("A matriz 'A' eh:\n");
    for(int linha = 0; linha < 2; linha++){
        for(int coluna = 0; coluna < 2; coluna++){
            A[linha][coluna] = rand() % 10;
            B[linha][coluna] = rand() % 10;
            C[linha][coluna] = A[linha][coluna] + B[linha][coluna];
            printf("%i/", A[linha][coluna]);
        }
        printf("\n");
    }
    printf("A matriz 'B' eh:\n");
    for(int linha = 0; linha < 2; linha++){
        for(int coluna = 0; coluna < 2; coluna++){
            printf("%i/", B[linha][coluna]);
        }
        printf("\n");
    }    
    printf("A matriz 'C' eh:\n");
    for(int linha = 0; linha < 2; linha++){
        for(int coluna = 0; coluna < 2; coluna++){
            printf("%i/", C[linha][coluna]);
        }
        printf("\n");
    }    

}
*/

//Questão 10
/*Leia uma matriz quadrada (com valores fornecidos pelo usuário) e verifique se ela é
simétrica, ou seja, se A[i][j] == A[j][i] para todos os elementos.*/
#include <stdio.h>

void main(){
    int linhas = 3;
    int colunas = 3;
    int matriz[linhas][colunas];
    int contador = 0;
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
             printf("Digite o elemento[%i][%i] da sua matriz: ", linha, coluna);
             scanf("%i", &matriz[linha][coluna]);
        }
    }
    for(int linha= 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            if(matriz[linha][coluna] == matriz[coluna][linha]){
                contador++;
            }
        }
    }
    if(contador == linhas * colunas){
        printf("A sua matriz eh simetrica!!");
    }
    else{
        printf("A sua matriz nao eh simtreica!!");
    }
}
