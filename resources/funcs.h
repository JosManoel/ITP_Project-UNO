// Assinatura das funções disponíveis em funcs.c

void debug(char *message);
char* strcpyse(char* destination, const char* source, const int start, const int end);
char* extractNaipe(char* destination, const char* source);
char* extractValue(char* destination, const char* source);
Card* removeCard(Card *cardGroup, Card exclCard, int *qnt);
Card* addCard(Card *cardGroup, Card newCard, int *qnt);
Card createCard(char* cardString);