// Assinatura das funções disponíveis em playerController.c

void returnPlayerId(char *my_id);
char *predmtNaipe(char *destination, Card *cardGroup, const int handSize);
Card *createHand(Card *cardGroup, char *handString, int *handSize);
int searchCard(Card *card, char *searchString, char* complement, Card *playerHand, int *handSize);
