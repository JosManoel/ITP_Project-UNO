#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_ACTION 10
#define MAX_ID_SIZE 10

// Funcao de debug
void debug(char *message) {
  fprintf(stderr, "%s\n", message);
}

int main() {

  char temp[MAX_LINE];   // string para leitura temporária de dados
  char my_id[MAX_ID_SIZE];  // identificador do seu bot

  setbuf(stdin, NULL);   
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);


  // === INÍCIO DA PARTIDA ===
  scanf("PLAYERS %[^\n]\n", temp);

  debug(temp);

  // Lê o identificador do próprio bot. Isso é importante para testar quando é sua vez.
  scanf("YOU %s\n", my_id);
  // Lê as cartas iniciais que o bot tem na mão. Ex: "[ 4♥ 7♦ 2♣ J♠ A♥ 3♦ 2♣ 9♠ ]".
  scanf("HAND %[^\n]\n", temp);
  // Lê a carta aberta sobre a mesa. Ex: TABLE 8♣
  scanf("TABLE %s\n", temp);


  // === PARTIDA ===

  char id[MAX_ID_SIZE];
  char action[MAX_ACTION];
  char complement[MAX_LINE];

  while(1) {
    // Espera a vez de jogar
    do {
      scanf("%s %s", action, complement);

    } while (strcmp(action, "TURN") || strcmp(complement, my_id));
    
    // agora é a vez do seu bot jogar
    debug("----- MINHA VEZ -----");
    
    char card[] = "A♥ ♥";
    printf("DISCARD %s\n", card);
  }

  return 0;
}