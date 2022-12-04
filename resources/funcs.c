#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

// Funções comuns a todos os arquivos

void debug(char *message) { fprintf(stderr, "%s\n", message);}

//Retorna o naipe da carta
char* extractNaipe(char* destination, const char* source){
    char auxNaipe[MAX_NAIPE];
    int start = (source[1] == '0') ? 2 : 1; 

    for(int i = start; i < (int)strlen(source); i++) {auxNaipe[i - start] = source[i];}
    strcpy(destination, auxNaipe);
    
    return destination;
}

//Retorna o valor da carta
char* extractValue(char* destination, const char* source){
    char auxValue[MAX_VALUE_CARD];
    int size = (source[1] == '0') ? 2 : 1; 

    for(int i = 0; i < size; i++) {auxValue[i] = source[i];}
    auxValue[size] = '\0';
    
    strcpy(destination, auxValue);
    
    return destination;
}

// Adciona uma carta em um grupo de cartas de tamanho dinamico
Card* addCard(Card *cardGroup, Card newCard, int *qntCard){
    if(*qntCard == 0) cardGroup = malloc(sizeof(Card));
    else cardGroup = realloc(cardGroup, sizeof(Card) * (*qntCard + 1));

    // Add a nova carta
    cardGroup[*qntCard] = newCard;

    (*qntCard)++;
    return cardGroup;
}

// Remove uma carta de um grupo de tamanho dinamico
Card* removeCard(Card *cardGroup, Card exclCard, int *qntCard){
    for(int i = 0; i < (*qntCard -1); i++){
        if(strcmp(cardGroup[i].card, exclCard.card) == 0){

            // Realoca os elementos do array a partir da card excluida
            for(int j = i; j < (*qntCard - 1); j++) cardGroup[j] = cardGroup[j + 1];
            cardGroup = realloc(cardGroup, sizeof(Card) * (*qntCard - 1));
            (*qntCard)--;
        }
    }

    return cardGroup;
}

// Cria um elemento do tipo CArt
Card createCard(char* cardString){
    Card card;

    strcpy(card.card, cardString);
    extractValue(card.value, cardString);
    extractNaipe(card.naipe, cardString);

    return card;
}