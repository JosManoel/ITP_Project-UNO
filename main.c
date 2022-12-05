#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resources/definitions.h"
#include "resources/funcs.h"
#include "controllers/movementController.h"
#include "controllers/commentController.h"
#include "controllers/playerController.h"

int main()
{
    char action[MAX_ACTION];   // Armazena a acao executada.
    char complement[MAX_LINE]; // Armazena o complemento.
    char compt2ry[MAX_NAIPE];  // Armazena o complemento secundario.
    char temp[MAX_LINE];       // String temporaria.

    Card *table;       // Array de cartas da mesa.
    int qntCard = 0;   // Quantidade de cartas descartadas.
    int splPlayer = 0; // Verifica se o C ou V na mesa é para o player

    char tempHand[MAX_LINE]; // Recebe a mao inicial.
    char my_id[MAX_ID_SIZE]; // Recebe o ID do bot.
    Card *playerHand;        // Array de cartas na mão.
    Card disCard;            // Carta que será descartada.
    int qntHand = 0;         // Quantidade de cartas na mão.


    // Limpa os buffers
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    // Leitura de inicio da partida
    scanf("PLAYERS %[^\n]\n", temp);
    scanf("YOU %s\n", my_id);
    scanf("HAND %[^\n]\n", tempHand);
    scanf("TABLE %s\n", temp);


    // Adicionando cartas a mão
    playerHand = createHand(playerHand, tempHand, &qntHand);


    while (1)
    {
        do
        {
            scanf("%s %s", action, complement);

            if ((strcmp(action, "DISCARD") == 0))
            {
                // Add carta ao monte da mesa (table)
                table = addCard(table, createCard(complement), &qntCard);

                // Identifica a troca de naipe e recebe o proximo naipe
                if ((strcmp(table[qntCard - 1].value, "C") == 0) || (strcmp(table[qntCard - 1].value, "A") == 0))
                {
                    scanf("%s", compt2ry);
                    strcpy(table[qntCard - 1].naipe, compt2ry);
                }
            }

        } while (strcmp(action, "TURN") || strcmp(complement, my_id));


        if (strcmp(table[qntCard - 1].value, "C") == 0)
        {
            /*
                Compra 4 cartas se tiver um coringa na mesa
                O comentario para essa acao tambem deve ser feito aqui.
            */

            makeComment("Eu acredito no coração das cartas");
            playerHand = buyCard(playerHand, &qntHand, 4);
        }
        else if (strcmp(table[qntCard - 1].value, "V") == 0)
        {
            /*
                Compra 2 cartas se tiver um valete na mesa
                O comentario para essa acao tambem deve ser feito aqui.
            */

            makeComment("Assim você está me ajudando. Na proxima vem um combo");
            playerHand = buyCard(playerHand, &qntHand, 2);
        }
        else
        {
            if (determineCard(&disCard, table[qntCard - 1], playerHand, &qntHand))
            {
                /*
                    Caso determineCard encotrar uma carta, aqui ela será descartada.
                    O comentário para essa ação também deve ser feito aqui.
                */

                makeComment("Vou descartar!");
                playerHand = discardCard(playerHand, disCard, &qntHand);
            }
            else
            {
                /*
                    Caso determineCard não encontre nenhuma carta, será comprado uma carta.
                    O comentário para essa ação também deve ser feito aqui.
                */

                makeComment("Mas que coisa, nao?!");
                playerHand = buyCard(playerHand, &qntHand, 1);
            }
        }
    }

    return 0;
}