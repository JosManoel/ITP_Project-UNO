#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../resources/definitions.h"
#include "../resources/funcs.h"

// Retorna o ID do player como um comentário
void returnPlayerId(char *my_id) { printf("SAY meu ID é: %s\n", my_id); }

// Retorna o naipe predominante da mão
char *predmtNaipe(char *destination, Card *cardGroup, const int handSize)
{
    NaipeCount suits[5];

    // Inicializando suits
    strcpy(suits[hearts].naipe, "♥");
    strcpy(suits[diamonds].naipe, "♦");
    strcpy(suits[clubs].naipe, "♣");
    strcpy(suits[spades].naipe, "♠");
    strcpy(suits[countSuit].naipe, " ");

    for (int k = 0; k < 5; k++)
        suits[k].count = 0;

    // Contando os elementos a partir do naipe
    for (int i = 0; i < handSize; i++)
    {
        if (strcmp(cardGroup[i].naipe, "♥") == 0)
            suits[hearts].count++;
        else if (strcmp(cardGroup[i].naipe, "♦") == 0)
            suits[diamonds].count++;
        else if (strcmp(cardGroup[i].naipe, "♣") == 0)
            suits[clubs].count++;
        else if (strcmp(cardGroup[i].naipe, "♠") == 0)
            suits[spades].count++;
    }

    for (int j = 0; j < 4; j++)
        if (suits[countSuit].count < suits[j].count)
            suits[countSuit] = suits[j];

    strcpy(destination, suits[countSuit].naipe);

    return destination;
}

// Recebe uma string com as cartas e retorna um array de cartas do tipo *Card*
Card *createHand(Card *cardGroup, char *handString, int *handSize)
{
    char auxHandString[MAX_LINE];
    char *auxCardString;

    // Tratamento da handString - retirada dos '[ ]'
    strcpyse(auxHandString, handString, 2, ((int)strlen(handString) - 1));

    // Separando a string em substrings.
    auxCardString = strtok(auxHandString, " ");

    for (int i = 0; auxCardString != NULL; i++)
    {
        // Adicionando uma nova carta
        cardGroup = addCard(cardGroup, createCard(auxCardString), handSize);
        auxCardString = strtok(NULL, " ");
    }

    return cardGroup;
}