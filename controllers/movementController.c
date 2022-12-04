#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add resources
#include "../resources/definitions.h"
#include "../resources/funcs.h"
#include "../controllers/playerController.h"


void makeMovement(char *movement){
    debug("movimento iniciado");
    printf("%s\n", movement);
}


// Compra n cartas e adiciona a mão
Card* buyCard(Card *cardGroup, int *handSize, int qnt){
    char auxCardString[MAX_CARD];

    printf("BUY %d\n", qnt);

    for(int i = 0; i < qnt; i++){
        scanf("%s ", auxCardString);
        debug(auxCardString);
        cardGroup = addCard(cardGroup, createCard(auxCardString), handSize);
    }

    return cardGroup;
}


/* Descarta uma carta e atualiza a mão
   >> Certifique-se que ela esta na mão <<
*/
Card* discardCard(Card *cardGroup, Card disCard, int* handSize){
    char complement[MAX_NAIPE] = "";
    
    /* Caso a carta descartada seja um A ou C, sera enviado como complemento
       o naipe que estiver em mais cartas da mão.*/
    if((disCard.value[0] == 'A') || (disCard.value[0] == 'C')){
        predmtNaipe(complement, cardGroup, *handSize);
    }

    printf("DISCARD %s %s\n", disCard.card, complement);
    cardGroup = removeCard(cardGroup, disCard, handSize);

    return cardGroup;
}