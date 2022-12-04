#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../resources/definitions.h"
#include "../resources/funcs.h"

// Retorna o ID do player como um comentário
void returnPlayerId(char* my_id){
    printf("SAY meu ID é: %s\n", my_id);
}

// Recebe uma string com as cartas e retorna um array de cartas do tipo *Card*
Card* createHand(Card *cardGroup, char* handString, int *handSize){
    char auxHandString[MAX_LINE];
    char* auxCardString;

    // Tratamento da handString - retirada dos '[ ]'
    strcpyse(auxHandString, handString, 2, ((int)strlen(handString) - 1));

    // Separando a string em substrings.
    auxCardString = strtok(auxHandString, " ");

    for(int i = 0; auxCardString != NULL; i++){
        // Adicionando uma nova carta
        cardGroup = addCard(cardGroup, createCard(auxCardString), handSize);
        auxCardString = strtok(NULL, " ");
    }

    return cardGroup;
}