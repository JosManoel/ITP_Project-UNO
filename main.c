#include <stdio.h>
#include <string.h>

// Add resources
#include "resources/definitions.h"
#include "resources/funcs.h"

// Add controllers
#include "controllers/movementController.h"
#include "controllers/commentController.h"
#include "controllers/playerController.h"

int main() {
  char my_id[MAX_ID_SIZE];  
  char temp[MAX_LINE];   

  setbuf(stdin, NULL);   
  setbuf(stdout, NULL);  
  setbuf(stderr, NULL);

  // === INÍCIO DA PARTIDA ===

  scanf("PLAYERS %[^\n]\n", temp);
  debug(temp);

  // Lê o identificador do próprio bot
  scanf("YOU %s\n", my_id);
  // Lê mão a ser recebida
  scanf("HAND %[^\n]\n", temp);
  // Lê a carta aberta sobre a mesa. Ex: TABLE 8♣
  scanf("TABLE %s\n", temp);


  // === PARTIDA ===

  char action[MAX_ACTION];
  char complement[MAX_LINE];

  while(1) {
    debug("----- VEZ DO OUTRO JOGADOR -----");
    do {
      scanf("%s %s", action, complement);
 
    } while (strcmp(action, "TURN") || strcmp(complement, my_id));
    
    // agora é a vez do seu bot jogar
    debug("----- MINHA VEZ -----");
    

    char card[] = "A♥ ♥";
    makeComment("Mas que coisa, nao?!");
    returnPlayerId(my_id);
    makeMovement("BUY 1");
    scanf("%s", card);
  }

  return 0;
}