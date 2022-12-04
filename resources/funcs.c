#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

// Funções comuns a todos os arquivos

void debug(char *message) { fprintf(stderr, "%s\n", message);}


// Copia uma string a partir de um determinado ponto até outro ponto
char* strcpyse(char* destination, const char* source, const int start, const int end){
    char auxString[MAX_LINE];

    for(int i = start; i < end; i++) {auxString[i - start] = source[i];}
    auxString[end] = '\0';

    strcpy(destination, auxString);
    
    return destination;
}

//Retorna o naipe da carta
char* extractNaipe(char* destination, const char* source){
    strcpyse(destination, source, (source[1] == '0') ? 2 : 1, (int)strlen(source));
    return destination;
}

//Retorna o valor da carta
char* extractValue(char* destination, const char* source){
    strcpyse(destination, source, 0, (source[1] == '0') ? 2 : 1);    
    return destination;
}

// Adciona uma carta em um grupo de cartas de tamanho dinamico
Card* addCard(Card *cardGroup, Card newCard, int *qnt){
    if(*qnt == 0) cardGroup = malloc(sizeof(Card));
    else cardGroup = realloc(cardGroup, sizeof(Card) * (*qnt + 1));

    // Add a nova carta
    cardGroup[*qnt] = newCard;

    (*qnt)++;
    return cardGroup;
}

// Remove uma carta de um grupo de tamanho dinamico
Card* removeCard(Card *cardGroup, Card exclCard, int *qnt){
    for(int i = 0; i < (*qnt -1); i++){
        if(strcmp(cardGroup[i].card, exclCard.card) == 0){
            debug("Achou a carta");
            // Realoca os elementos do array a partir da card excluida
            for(int j = i; j < (*qnt - 1); j++) cardGroup[j] = cardGroup[j + 1];
            cardGroup = realloc(cardGroup, sizeof(Card) * (*qnt - 1));
            (*qnt)--;
        }
    }

    return cardGroup;
}

// Cria um elemento do tipo Card
Card createCard(char* cardString){
    Card newCard;

    strcpy(newCard.card, cardString);
    extractValue(newCard.value, cardString);
    extractNaipe(newCard.naipe, cardString);

    return newCard;
}