// Assinatura das funções disponíveis em movementController.c

Card *buyCard(Card *cardGroup, int *handSize, int qnt);
Card *discardCard(Card *cardGroup, Card disCard, int *handSize);
int determineCard(Card *card, Card tableCard, Card *playerHand, int *handSize);