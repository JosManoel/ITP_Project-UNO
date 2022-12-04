// Assinatura das funções disponíveis em funcs.c

void debug(char *message);
char* extractNaipe(char* destination, const char* source);
char* extractValue(char* destination, const char* source);
Card* removeCard(Card *cardGroup, Card exclCard, int *qntCard);
Card* addCard(Card *cardGroup, Card newCard, int *qntCard);
Card createCard(char* cardString);