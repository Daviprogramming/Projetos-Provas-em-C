// QUESTÃO 1
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main(){
    int tamanho = 50;
    int contador = 0;
    int h = 0;
    char palavratrue[tamanho];
    char palavra[tamanho];
    int j = 0;
    printf("Digite a sua palavra: ");
    scanf("%49[^\n]", palavra);
    getchar();
    
    
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] != ' ' && palavra[i] != ',' && palavra[i] != '-'){
            palavratrue[h] = tolower(palavra[i]);
            h++;
        }
    }    
    palavratrue[h] = '\0';
    j = strlen(palavratrue) - 1;
    for(int i = 0; i < strlen(palavratrue); i++){
        if(palavratrue[i] == palavratrue[j]){
                contador++;
            }
        else{
            printf("Sua palavra nao e um palindromo");
            break;
        }
        j--;
        
        }
        if(contador == strlen(palavratrue)){
            printf("Sua palavra e um palindromo!");

        }
}
*/

//QUESTÃO 2
/*
#include <stdio.h>
#include <string.h>

void main(){
    int tamanho = 60;
    int chave = 5; // ESSA É A CHAVE ONDE VOCÊ PODE DEFINIR QUALQUER NÚMERO PARA FAZER A CRIPTOGRAFIA.
    char palavra[tamanho];
    char palavracriptografada[tamanho];
    char palavradescriptografada[tamanho];
    printf("Digite seu texto/palavra:");
    scanf("%79[^\n]", palavra);
    getchar();
    int j = strlen(palavra) - 1;
    printf("Sua palavra criptografada eh: ");
    for(int i = 0; i <= j; i++){
        palavracriptografada[i] = palavra[i] + chave;
        printf("%c", palavracriptografada[i]);
    }
    printf("\nSua palavra descriptografada eh: ");
    for(int i = 0; i <= j; i++){
        palavradescriptografada[i] = palavracriptografada[i] - chave;
        printf("%c", palavradescriptografada[i]);
    }

}
*/

//QUESTÃO 3
/*
#include <stdio.h>
#include <string.h>

void main(){
    int tamanho = 80;
    char nome_completo[tamanho];
    int contador_primeiro = 0;
    printf("Digite seu nome completo: ");
    fgets(nome_completo, tamanho, stdin);


    int contador_ultimo = strlen(nome_completo);
    for(int i = 0; i < strlen(nome_completo); i++){
        if(nome_completo[i] != ' '){
        contador_primeiro++;
        }
        else{
            break;
        }
    }
        char primeiro[contador_primeiro];

        for(int i = strlen(nome_completo); i > 0; i--){ 
        if(nome_completo[i] != ' '){
        contador_ultimo--;
        }
        else{
            break;
        }
    }
    char ultimo[contador_ultimo];
    for(int i = contador_ultimo + 1; i < strlen(nome_completo) - 1; i++){
        ultimo[i] = nome_completo[i];
        printf("%c", ultimo[i]);
    }
    printf(", ");
    for(int i = 0; i < contador_primeiro; i++){
        primeiro[i] = nome_completo[i];
        printf("%c", primeiro[i]);
    }
}
*/

//QUESTÃO 4
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
    int tamanho = 80;
    char frase[tamanho];
    char frase_criptografada[tamanho];
    printf("Digite a sua frase/palavra: ");
    scanf("%79[^\n]", frase);
    getchar();
    for(int i = 0; i < strlen(frase); i++){
        if(frase[i] != ' ' && frase[i] != '-' && frase[i] != ','){
        frase_criptografada[i] = frase[i] + 3;
        printf("%c", toupper(frase_criptografada[i]));
        }
        else{
            printf("%c", frase[i]);
        }
    }
}
*/

//QUESTÃO 5

/*
#include <stdio.h>
#include <string.h>
void main(){
    int tamanho = 80;
    char frase[tamanho];
    char substring[tamanho];
    char comparacao[tamanho];
    int contador = 0;
    printf("Digite sua frase: ");
    scanf("%79[^\n]", frase);
    getchar();
    printf("Digite sua substring: ");
    scanf("%79[^\n]", substring);
    getchar();

    for(int i = 0; i < strlen(frase); i++){
        for(int j = 0; j < strlen(substring); j++){
            comparacao[j] = frase[j + i];
            if(strcmp(comparacao, substring) == 0){
                contador++;
            } 
        }
    }
    printf("%i", contador);
}
*/

// QUESTÃO 6

/*
#include <stdio.h>
#include <string.h>

void main(){
    int tamanho = 80;
    char string1[tamanho];
    char string2[tamanho];
    int contador1 = 0;
    int contador2 = 0;
    printf("Digite a string 1: ");
    scanf("%79[^\n]", string1);
    getchar();
    printf("Digite a string 2: ");
    scanf("%79[^\n]", string2);
    getchar();
    int tamanho_verdadeiro = strlen(string1) + strlen(string2);
    char string3[tamanho_verdadeiro + 1];
    for(int i = 0; i < tamanho_verdadeiro; i++){
        if(i % 2 == 0){
            if(contador1 < strlen(string1)){
                string3[i] = string1[contador1];
                contador1++;
            }
            else{
                string3[i] = string2[contador2];
                contador2++;
            }
        
        }
        if(i % 2 != 0){
            if(contador2 < strlen(string2)){
                string3[i] = string2[contador2];
                contador2++;
            }
            else{
                string3[i] = string1[contador1];
                contador1++;
            }
        }
    }
    string3[tamanho_verdadeiro] = '\0';
    printf("%s", string3);
    }
*/

//QUESTÃO 7

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int contador = 0;
    int contador2 = 0;
    int tamanho = 80;
    char string1[tamanho];
    char string2[tamanho];    
    printf("Digite sua string 1: ");
    scanf("%79[^\n]", string1);
    getchar();
    printf("Digite sua string 2: ");
    scanf("%79[^\n]", string2);
    getchar();
    char string1_nova[160];
    char string2_nova[160];
    int p = rand() %(strlen(string1)); 
    for(int i = 0; i < strlen(string1) + 1; i++ ){
        if(contador < p){
            string1_nova[i] = string1[contador];
            contador++;
        }
        else{
            string1_nova[i] = string2[contador];
            contador++;
        }
    }        
    string1_nova[strlen(string1)] = '\0';
    for(int j = 0; j < strlen(string2) + 1; j++ ){
        if(contador2 < p){
            string2_nova[j] = string2[contador2];
            contador2++;
        }
        else{
            string2_nova[j] = string1[contador2];
            contador2++;
        }
    }
    string2_nova[strlen(string1)] = '\0';
    printf("A string 1 virou: %s\n", string1_nova);
    printf("A string 2 virou : %s\n", string2_nova);
    printf("E o ponto P foi : %i", p);

}
*/

// Questão 8

/*
#include <stdio.h>
#include <string.h>

void main(){

        int tamanho = 20;
        char string1[tamanho];
        char string2[tamanho];
        char string3[tamanho];
        char caractere = ' ';
        char caractere2 = ' ';
        char caractere3 = ' ';
        int contador2 = 0;
        int contador = 0;
        int contador3 = 0;
        int contador4 = 0;
    char tecla = ' ';
    while(tecla != 'h'){
        printf("--MENU--\n");
        printf("(a) Ler uma string S1 (tamanho maximo 20 caracteres);\n");
        printf("(b) Imprimir o tamanho da string S1;\n");
        printf("(c) Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao;\n");
        printf("(d) Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao;\n");
        printf("(e) Imprimir a string S1 de forma reversa;\n");
        printf("(f) Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser informado pelo usuario;\n");
        printf("(g) Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serão lidos pelo usuario.\n");
        printf("(h) Sair\n: ");
        scanf("%c", &tecla);
        getchar();
        switch (tecla){
        case 'a':
            printf("Digite a sua string: ");            
            scanf("%19[^\n]",string1);
            getchar();
            break;
        case 'b':
            printf("O tamanho da string S1 eh: %i\n", strlen(string1));
            break;
        case 'c':
        printf("Digite uma nova string 2: ");
        scanf("%19[^\n]",string2);
        getchar();
        printf("Resultado da comparacao: %i\n",strcmp(string1, string2));
            break;
        case 'd':
        printf("Digite uma nova string 2: ");
        scanf("%19[^\n]",string2);
        getchar();
        if(strlen(string1) + strlen(string2) < tamanho){
            strcat(string1, string2);
        printf("O resultado da concatenacao eh: %s\n", string1);          
        }
        else{
            printf("Infelizmente o tamanho maximo da concatenacao eh de 20.");
        }
            break;
        case 'e':
        contador2 = 0;
        for(int i = strlen(string1) - 1; i >= 0; i--){
            string3[contador2] = string1[i];
            contador2++;
        }
        string3[strlen(string1)] = '\0';
        printf("A string s1 de forma reversa eh: %s\n", string3);
            break;
        case 'f':
        contador3 = 0;
        printf("Digite o caractere que deseja verificar: ");
        scanf("%c", &caractere);
        getchar();
        for(int i = 0; i < strlen(string1); i++){
            if(string1[i] == caractere){
                contador3++;
            }
        }
        printf("O total de repeticoes foi de : %i\n", contador3);
            break;
        case 'g':
            contador4 = 0;
            printf("Digite o C1: ");
            scanf("%c", &caractere2);
            getchar();
            printf("Digite o C2: ");
            scanf("%c", &caractere3);
            getchar();
            for(int i = 0; i < strlen(string1); i++){
                if(string1[i] == caractere2 && contador4 == 0){
                    string1[i] = caractere3;
                    contador4++;
                }
            }
            printf("Sua nova string1 : %s\n", string1);

            break;
        case 'h':
            printf("Você finalizou o programa!\n ");
            break;
        default:
            printf("opcao invalida, tente novamente !!\n");
            break;
        }
    }
}
*/

//Questão 9
/*Implemente um programa que leia 15 números e verifique se há valores repetidos.
Caso existam, mostre quais se repetem e quantas vezes.*/

#include <stdio.h>
#include <string.h>

void main(){
    int numeros[15];
    int numeros2[15] = {0};
    int contador = 0;
    int repetidos = 0;

    for(int i = 0; i < 15; i++){
        printf("Digite um numero %i vezes", 15 - i);
        scanf("%d", &numeros[i]);
    }



    for(int i = 0; i < 15; i++){
        if (numeros2[i] == 1){
            continue;
        }
        contador = 0;
        for(int j = 0; j < 15; j++){
            if(numeros[i] == numeros[j]){
                contador++;
                numeros2[j] = 1;
            }
        }
        if(contador > 1){
            printf("O numero %d tem uma repeticao de %d vezes.", numeros[i], contador);
            repetidos = 1;
        }
    }
    if(repetidos == 0){
        printf("Nenhum numero repetido foi encontrado, tente novamente!");
    }
printf("O valor eh: %i", contador);
}


//QUESTÃO 10

/*
#include <stdio.h>

void main(){
    int variavel = 0;
    int vetor[10];
    for(int i = 0; i < 10; i++){
    printf("Digite um numero de %i ate 9: ", i);
    scanf("%d", &vetor[i]);
    getchar();
    }
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if(vetor[i] > vetor[j]){

                variavel = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = variavel;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", vetor[i]);
    }

}
*/