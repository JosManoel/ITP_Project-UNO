// Para evitar a redefinição de variáveis, será utilizado o #ifndef

#ifndef DEF
    #define DEF

    // Constantes definidas para as strings
    #define MAX_LINE 100
    #define MAX_ACTION 10
    #define MAX_ID_SIZE 10
    #define MAX_CARD 6
    #define MAX_NAIPE 4
    #define MAX_VALUE_CARD 3

    typedef struct{
        char card[MAX_CARD];
        char value[MAX_VALUE_CARD];
        char naipe[MAX_NAIPE];
    } Card;

    typedef struct{
        char action[MAX_ACTION];
        char card[MAX_CARD];
        char compt[MAX_ACTION];
    } Movement;


#endif
