#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resources/definitions.h"
#include "resources/funcs.h"
#include "controllers/movementController.h"
#include "controllers/commentController.h"
#include "controllers/playerController.h"


int main() {
  char temp[MAX_LINE];
  
  // Variaveis responsaveis pela mesa 
  Card *table;
  int qntCard = 0;

  // Variaveis responsaveis pela mao
  char tempHand[MAX_LINE];
  char my_id[MAX_ID_SIZE];  
  Card *playerHand;
  int qntCardHand = 0;

  setbuf(stdin, NULL);   
  setbuf(stdout, NULL);  
  setbuf(stderr, NULL);

  // Leitura de inicio da partida
  scanf("PLAYERS %[^\n]\n", temp);
  scanf("YOU %s\n", my_id);
  scanf("HAND %[^\n]\n", tempHand);
  scanf("TABLE %s\n", temp);

  // Adicionando cartas a mão
  playerHand = createHand(playerHand, tempHand, &qntCardHand);

  // === PARTIDA ===

  char action[MAX_ACTION];
  char complement[MAX_LINE];

  while(1) {
    do {
      debug("----- VEZ DO OUTRO JOGADOR -----");

      scanf("%s %s", action, complement);

      if((strcmp(action,"DISCARD") == 0)){
        // Add carta ao monte da mesa (table)
        debug("nova carta na mesa");
        table = addCard(table, createCard(complement), &qntCard);

        // Identifica a troca de naipe e recebe o proximo naipe
        if((strcmp(table[qntCard - 1].value, "C") == 0) || (strcmp(table[qntCard - 1].value, "A") == 0) ){
          debug("trocou de naipe");
          scanf("%s", temp);
        }
      }

    } while (strcmp(action, "TURN") || strcmp(complement, my_id));
    
    // agora é a vez do seu bot jogar
    debug("----- MINHA VEZ -----");

    if(strcmp(table[qntCard - 1].value, "C") == 0){
      //Compra 4 cartas e adciona a mao
      playerHand = buyCard(playerHand, &qntCardHand, 4);
    }

    if(strcmp(table[qntCard - 1].value, "V") == 0){
      //Compra 2 cartas e adciona a mao
      playerHand = buyCard(playerHand, &qntCardHand, 2);
    }

    makeComment("Mas que coisa, nao?!");

    //Compra 1 cartas e adciona a mao
    // playerHand = buyCard(playerHand, &qntCardHand, 1);

    // Descarta uma carta da mão
    Card disCard;
    disCard = createCard("A♦");
    playerHand = discardCard(playerHand, disCard, &qntCardHand);
  }

  return 0;
}