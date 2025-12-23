#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void main(){
    srand(time(NULL));

    char westeros[10][10];
    char jon_snow = 'J';
    char continuar;
    int linha_jon = 0;
    int coluna_jon = 0;
    int vez = 0;
    int vez2 = 0;
    char cersei = 'C';
    int cersei_negociacao = 0;
    int tentativa;
    char continuar2;
    int ataque;
    int contador = 0;
    char noite = 'N';
    int vida_jon_snow = 100;
    int vida_cersei = 100;
    int vida_noite = 200;
    char inimigo = 'I';
    int linha_inimigo;
    int coluna_inimigo;
    char obstaculo = 'X';
    int linha_obstaculo;
    int coluna_obstaculo;
    char porcoes = 'P';
    int linha_porcoes;
    int coluna_porcoes;
    char tecla;
    int vitoria = 0;


    for(int linha = 0; linha < 10; linha++){
        for(int coluna = 0; coluna < 10; coluna++){
            westeros[linha][coluna] = '-';
        }
    }
    westeros[linha_jon][coluna_jon] = jon_snow;
    westeros[4][4] = cersei;
    westeros[9][9] = noite;
    
    for(int i = 0; i < 20;){ // inimigos
        linha_inimigo = rand() % 10;
        coluna_inimigo = rand() % 10;
        if(westeros[linha_inimigo][coluna_inimigo] == '-'){
            westeros[linha_inimigo][coluna_inimigo] = inimigo;
            i++;
        } 
    }

    for(int i = 0; i < 10;){ // obstaculos
        linha_obstaculo = rand() % 10;
        coluna_obstaculo = rand() % 10;
        if(westeros[linha_obstaculo][coluna_obstaculo] == '-'){
            westeros[linha_obstaculo][coluna_obstaculo] = obstaculo;
            i++;
        } 
    }

    for(int i = 0; i < 10;){ // pocoes de vida !
        linha_porcoes = rand() % 10;
        coluna_porcoes = rand() % 10;
        if(westeros[linha_porcoes][coluna_porcoes] == '-'){
            westeros[linha_porcoes][coluna_porcoes] = porcoes;
            i++;
        } 
    }
    while(vida_jon_snow > 0 && vitoria == 0){
    system("clear || cls");
    for(int linha = 0; linha < 10; linha++){
        for(int coluna = 0; coluna < 10; coluna++){
            printf("%c ", westeros[linha][coluna]);
        }
        printf("\n");
    }

    printf("Digite uma tecla de movimentacao: ");
    scanf("%c", &tecla);
    getchar();
    switch(tecla){
        case 'w':
        if(linha_jon - 1 >= 0 && westeros[linha_jon - 1][coluna_jon] != 'X' ){
            if(westeros[linha_jon - 1][coluna_jon] == 'I'){
                vida_jon_snow = vida_jon_snow - 1;
            }
            else if(westeros[linha_jon - 1][coluna_jon] == 'P'){
                vida_jon_snow = vida_jon_snow + 5;
            }
            else if(westeros[linha_jon - 1][coluna_jon] == 'C'){
                contador = 0;
                printf("VOCE ENTROU EM NEGOCIACAO COM CERSEI!");
                for(int i = 0; i < 5; i++){
                    printf("\nTentativa [%i]: Aperte alguma tecla para negociar -", i + 1);
                    scanf("%c", &continuar2);
                    getchar();
                    tentativa = rand() % 101;
                    if(tentativa > 60){
                        contador++;
                        printf("Voce venceu a negociacao %i/3", contador);

                    }
                    else{
                    printf("Voce perdeu a negociacao");
                    }
                }
                if(contador >= 3){
                    printf("\nCersei se uniu a você! você recebeu 100 de vida!\n");
                    printf("Aperte qualquer botão para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    vida_jon_snow = vida_jon_snow + 100;
                    cersei_negociacao = 1;
                }
                else{
                    printf("\nVoce iniciou uma guerra contra cersei!\n");
                    while(vida_cersei > 0 && vida_jon_snow > 0){
                        if(vez == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_cersei = vida_cersei - 10;
                            }
                            else{
                                vez = 1;
                            }
                        }
                        if(vez == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 10;
                            }
                            else{
                                vez = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("John morreu durante a guerra contra Cersei");
                    }
                    else{
                        printf("Você derrotou Cersei!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        cersei_negociacao = 1;
                    }
                }
            }
            else if(westeros[linha_jon - 1][coluna_jon] == 'N'){
                if(cersei_negociacao == 0){
                    printf("Voce precisa negociar com cersei primeiro! volte depois da negociacao\n");
                    printf("Digite qualquer caractere para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    break;
                }
                else{
                    while(vida_noite > 0 && vida_jon_snow > 0){
                        if(vez2 == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_noite = vida_noite - 10;
                            }
                            else{
                                vez2 = 1;
                            }
                        }
                        if(vez2 == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 5;
                                vida_noite = vida_noite + 5;
                            }
                            else{
                                vez2 = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("John morreu durante a luta contra o rei da noite!");
                    }
                    else{
                        printf("Você derrotou o Rei da noite!!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        vitoria = 1;
                    }
                }
            }
            westeros[linha_jon][coluna_jon] = '-';
            linha_jon = linha_jon -1;
            westeros[linha_jon][coluna_jon] = 'J';
        }
        break;
        case 'a':
        if(coluna_jon - 1 >= 0 && westeros[linha_jon][coluna_jon - 1] != 'X' ){
            if(westeros[linha_jon][coluna_jon - 1] == 'I'){
                vida_jon_snow = vida_jon_snow - 1;
            }
            else if(westeros[linha_jon][coluna_jon - 1] == 'P'){
                vida_jon_snow = vida_jon_snow + 5;
            }
            else if(westeros[linha_jon][coluna_jon - 1] == 'C'){
                contador = 0;
                printf("VOCE ENTROU EM NEGOCIACAO COM CERSEI!");
                for(int i = 0; i < 5; i++){
                    printf("\nTentativa [%i]: Aperte alguma tecla para negociar -", i + 1);
                    scanf("%c", &continuar2);
                    getchar();
                    tentativa = rand() % 101;
                    if(tentativa > 60){
                        contador++;
                        printf("Voce venceu a negociacao %i/3", contador);

                    }
                    else{
                    printf("Voce perdeu a negociacao");
                    }
                }
                if(contador >= 3){
                    printf("\nCersei se uniu a você! você recebeu 100 de vida!\n");
                    printf("Aperte qualquer botão para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    vida_jon_snow = vida_jon_snow + 100;
                    cersei_negociacao = 1;
                }
                else{
                    printf("\nVoce iniciou uma guerra contra cersei!\n");
                    while(vida_cersei > 0 && vida_jon_snow > 0){
                        if(vez == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_cersei = vida_cersei - 10;
                            }
                            else{
                                vez = 1;
                            }
                        }
                        if(vez == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 10;
                            }
                            else{
                                vez = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("John morreu durante a guerra contra Cersei");
                    }
                    else{
                        printf("Você derrotou Cersei!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        cersei_negociacao = 1;
                    }
                }
            }
            else if(westeros[linha_jon][coluna_jon - 1] == 'N'){
                if(cersei_negociacao == 0){
                    printf("Voce precisa negociar com cersei primeiro! volte depois da negociacao\n");
                    printf("Digite qualquer caractere para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    break;
                }
                else{
                    while(vida_noite > 0 && vida_jon_snow > 0){
                        if(vez2 == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_noite = vida_noite - 10;
                            }
                            else{
                                vez2 = 1;
                            }
                        }
                        if(vez2 == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 5;
                                vida_noite = vida_noite + 5;
                            }
                            else{
                                vez2 = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("Jon morreu durante a luta contra o rei da noite!");
                    }
                    else{
                        printf("Você derrotou o Rei da noite!!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        vitoria = 1;
                    }
                }
            }
            westeros[linha_jon][coluna_jon] = '-';
            coluna_jon = coluna_jon -1;
            westeros[linha_jon][coluna_jon] = 'J';
        }
        break;
        case 's':
        if(linha_jon + 1 < 10 && westeros[linha_jon + 1][coluna_jon] != 'X' ){
            if(westeros[linha_jon + 1][coluna_jon] == 'I'){
                vida_jon_snow = vida_jon_snow - 1;
            }
            else if(westeros[linha_jon + 1][coluna_jon] == 'P'){
                vida_jon_snow = vida_jon_snow + 5;
            }
            else if(westeros[linha_jon + 1][coluna_jon] == 'C'){
                contador = 0;
                printf("VOCE ENTROU EM NEGOCIACAO COM CERSEI!");
                for(int i = 0; i < 5; i++){
                    printf("\nTentativa [%i]: Aperte alguma tecla para negociar -", i + 1);
                    scanf("%c", &continuar2);
                    getchar();
                    tentativa = rand() % 101;
                    if(tentativa > 60){
                        contador++;
                        printf("Voce venceu a negociacao %i/3", contador);

                    }
                    else{
                    printf("Voce perdeu a negociacao");
                    }
                }
                if(contador >= 3){
                    printf("\nCersei se uniu a você! você recebeu 100 de vida!\n");
                    printf("Aperte qualquer botão para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    vida_jon_snow = vida_jon_snow + 100;
                    cersei_negociacao = 1;
                }
                else{
                    printf("\nVoce iniciou uma guerra contra cersei!\n");
                    while(vida_cersei > 0 && vida_jon_snow > 0){
                        if(vez == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_cersei = vida_cersei - 10;
                            }
                            else{
                                vez = 1;
                            }
                        }
                        if(vez == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 10;
                            }
                            else{
                                vez = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("John morreu durante a guerra contra Cersei");
                    }
                    else{
                        printf("Você derrotou Cersei!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        cersei_negociacao = 1;
                    }
                }
            }
            else if(westeros[linha_jon + 1][coluna_jon] == 'N'){
                if(cersei_negociacao == 0){
                    printf("Voce precisa negociar com cersei primeiro! volte depois da negociacao\n");
                    printf("Digite qualquer caractere para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    break;
                }
                else{
                    while(vida_noite > 0 && vida_jon_snow > 0){
                        if(vez2 == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_noite = vida_noite - 10;
                            }
                            else{
                                vez2 = 1;
                            }
                        }
                        if(vez2 == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 5;
                                vida_noite = vida_noite + 5;
                            }
                            else{
                                vez2 = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("Jon morreu durante a luta contra o rei da noite!");
                    }
                    else{
                        printf("Você derrotou o Rei da noite!!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        vitoria = 1;
                    }
                }
            }
            westeros[linha_jon][coluna_jon] = '-';
            linha_jon = linha_jon + 1;
            westeros[linha_jon][coluna_jon] = 'J';
        }
        break;
        case 'd':
        if(coluna_jon + 1 < 10 && westeros[linha_jon][coluna_jon + 1] != 'X' ){
            if(westeros[linha_jon][coluna_jon + 1] == 'I'){
                vida_jon_snow = vida_jon_snow - 1;
            }
            else if(westeros[linha_jon][coluna_jon + 1] == 'P'){
                vida_jon_snow = vida_jon_snow + 5;
            }
            else if(westeros[linha_jon][coluna_jon + 1] == 'C'){
                contador = 0;
                printf("VOCE ENTROU EM NEGOCIACAO COM CERSEI!");
                for(int i = 0; i < 5; i++){
                    printf("\nTentativa [%i]: Aperte alguma tecla para negociar -", i + 1);
                    scanf("%c", &continuar2);
                    getchar();
                    tentativa = rand() % 101;
                    if(tentativa > 60){
                        contador++;
                        printf("Voce venceu a negociacao %i/3", contador);

                    }
                    else{
                    printf("Voce perdeu a negociacao");
                    }
                }
                if(contador >= 3){
                    printf("\nCersei se uniu a você! você recebeu 100 de vida!\n");
                    printf("Aperte qualquer botão para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    vida_jon_snow = vida_jon_snow + 100;
                    cersei_negociacao = 1;
                }
                else{
                    printf("\nVoce iniciou uma guerra contra cersei!\n");
                    while(vida_cersei > 0 && vida_jon_snow > 0){
                        if(vez == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_cersei = vida_cersei - 10;
                            }
                            else{
                                vez = 1;
                            }
                        }
                        if(vez == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 10;
                            }
                            else{
                                vez = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("John morreu durante a guerra contra Cersei");
                    }
                    else{
                        printf("Você derrotou Cersei!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        cersei_negociacao = 1;
                    }
                }
            }
            else if(westeros[linha_jon][coluna_jon + 1] == 'N'){
                if(cersei_negociacao == 0){
                    printf("Voce precisa negociar com cersei primeiro! volte depois da negociacao\n");
                    printf("Digite qualquer caractere para continuar: ");
                    scanf("%c", &continuar);
                    getchar();
                    break;
                }
                else{
                    while(vida_noite > 0 && vida_jon_snow > 0){
                        if(vez2 == 0){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                            vida_noite = vida_noite - 10;
                            }
                            else{
                                vez2 = 1;
                            }
                        }
                        if(vez2 == 1){
                            ataque = rand() % 101;
                            if(ataque >= 50){
                                vida_jon_snow = vida_jon_snow - 5;
                                vida_noite = vida_noite + 5;
                            }
                            else{
                                vez2 = 0;
                            }
                        }
                    }
                    if(vida_jon_snow <= 0){
                        printf("Jon morreu durante a luta contra o rei da noite!");
                    }
                    else{
                        printf("Você derrotou o Rei da noite!!\n ");
                        printf("Aperte qualquer botão para continuar: ");
                        scanf("%c", &continuar);
                        getchar();
                        vitoria = 1;
                    }
                }
            }
            westeros[linha_jon][coluna_jon] = '-';
            coluna_jon = coluna_jon + 1;
            westeros[linha_jon][coluna_jon] = 'J';
        }
        break;
        default:
        printf("Digite uma movimentacao valida!\n");
    }

    }

if(vida_jon_snow <= 0){
    printf("\nVocê perdeu !\n");
}
else{
    printf("\nVocê ganhou o jogo !\n");
}
}
