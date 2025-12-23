#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome_do_filme[30];
    char ID[11];
    char categoria[20];
    int entrada;
    int assento;
    float valor;    
} Compra;


void LimparSala(int tam, int sala[tam][tam]){ // Fiz uma funcao que limpa os assentos
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            sala[i][j] = 0;
        }
    }
}

void MostrarAssentos(int tam,int sala[tam][tam]){ // Essa funcao imprime os assentos
    printf("\n----------------- TELA DO CINEMA -----------------\n");
    for(int linha = 0; linha < tam; linha++){
        for(int coluna= 0; coluna < tam; coluna++){
            if(sala[linha][coluna] == 0){
                printf("[%d%d] ", linha, coluna);
            }
            else{
                printf("[XX] ");
            }
        }
        printf("\n");
    }
}

void ComprarIngresso(int tam, int sala[tam][tam], Compra* compra){ // Essa funcao realiza a compra do ingresso
    strcpy(compra->nome_do_filme, "Zootopia 2");
    int linha, coluna;
    int sair = 1;
    do{
        printf("\nDigite a linha da cadeira que voce quer: ");
        scanf("%i", &linha);
        printf("\nDigite a coluna da cadeira que voce quer: ");
        scanf("%i", &coluna);

        if(linha < 0 || linha >= tam || coluna < 0 || coluna >= tam){
            printf("Esse assento nao eh valido, tente novamente. \n");
        }
        else if(sala[linha][coluna] == 1){
            printf("Assento ocupado! Tente escolher outro.\n");
        }
        else{
            sair = 0;
        }
    } while (sair);

    sala[linha][coluna] = 1;

    compra->assento = (linha * 10) + coluna;

    int tipo;
    printf("Digite o tipo de ingresso (1-Inteira / 2-Meia)");
    scanf("%i", &tipo);

    if(tipo == 1){
        strcpy(compra->categoria, "Inteira");
        compra->entrada = 1;
        compra-> valor = 50.00;
    }
    else{
        strcpy(compra->categoria, "Meia");
        compra->entrada = 2;
        compra->valor = 25.00;
    }
    system("clear || cls");
    sprintf(compra->ID, "ZOO-%d%d", linha, coluna);
    printf("\n===================================\n");
    printf(" COMPRA CONFIRMADA!\n");
    printf(" Filme: %s\n", compra->nome_do_filme);
    printf(" ID do Bilhete: %s\n", compra->ID);
    printf(" Categoria: %s\n", compra->categoria); 
    printf(" Valor: R$ %.2f\n", compra->valor);
    printf("===================================\n");

}

void ImprimirValorArrecadado(float total){ // funcao que imprime o valor arrecadado 
    printf("\n==============================\n");
    printf(" TOTAL ARRECADADO: R$ %.2f\n", total);
    printf("==============================\n");
}

void ImprimirQuantidadeDeIngressos(int inteira, int meia){ // funcao que imprime a quantidade de ingressos
    printf("\n==============================\n");
    printf(" RELATORIO DE VENDAS\n");
    printf(" Ingressos Inteira: %d\n", inteira);
    printf(" Ingressos Meia:    %d\n", meia);
    printf(" Total de Publico:  %d\n", inteira + meia);
    printf("==============================\n");
}

int EspacoDisponivel(int tam, int sala[tam][tam]){ // Funcao que ve se tem espaço disponivel ou nao
    int disponivel = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(sala[i][j] != 1){
                disponivel++;
            }
        }
    }
    if(disponivel <= 0){
        printf("Não temos assentos disponiveis!");
        return 0;
    }
    else{
        return 1;
    }
}

void main(){
    Compra compra;
    int decisao;
    int desligar = 1;
    int tam = 10;
    int sala[tam][tam];
    
    float total_arrecadado = 0.0;
    int quantidade_inteira = 0;
    int quantidade_meia = 0;
    LimparSala(tam,sala);

    while(desligar == 1){
        printf("\n|===========MENU============|\n");
        printf("|[1] Comprar Ingresso       |\n");
        printf("|[2] Valor Arrecadado       |\n");
        printf("|[3] Quantidade Meia/Inteira|\n");
        printf("|[4] Sair                   |\n");
        printf("|Escolha:");
        scanf("%i", &decisao);
        system("clear || cls");
        switch(decisao){
        case 1:
            if(EspacoDisponivel(tam, sala) == 1){
                MostrarAssentos(tam,sala);
                ComprarIngresso(tam, sala, &compra);
                total_arrecadado += compra.valor;
                if(compra.entrada == 1){
                    quantidade_inteira++;
                }
                else{
                    quantidade_meia++;
                }
                break;
            }
            else{
                break;
            }
        case 2:
            ImprimirValorArrecadado(total_arrecadado);
            break;
        case 3:
            ImprimirQuantidadeDeIngressos(quantidade_inteira, quantidade_meia);
            break;
        case 4:
            desligar = 0;
            break;
        default:
            printf("Funcao invalida, tente novamente");
            break;
        }

    }
}