// Para evitar a redefinição de variáveis, será utilizado o #ifndef
// Constantes para as Strings a serem lidas

#ifndef DEF
    #define DEF

    #define MAX_LINE 100
    #define MAX_ACTION 10
    #define MAX_ID_SIZE 10

    typedef struct{
        char myId[MAX_ID_SIZE];
        char **hand;
        int handSize;
    } Player;

#endif
