#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    Card *table;             // Array de cartas da mesa.
    int qntCard = 0;         // Quantidade de cartas descartadas.
    int splPlayer = false;   // Verifica se o C ou V na mesa é para o player
    char initCard[MAX_CARD]; // Carta inicial

    char tempHand[MAX_LINE]; // Recebe a mao inicial.
    char my_id[MAX_ID_SIZE]; // Recebe o ID do bot.
    Card *playerHand;        // Array de cartas na mão.
    Card disCard;            // Carta que será descartada.
    int qntHand = 0;         // Quantidade de cartas na mão.

    int duelTime = true; // É HORA DO DUELO!


    // Limpa os buffers
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);


    // Leitura de inicio da partida
    scanf("PLAYERS %[^\n]\n", temp);
    scanf("YOU %s\n", my_id);
    scanf("HAND %[^\n]\n", tempHand);
    scanf("TABLE %s\n", initCard);


    // Adicionando carta inicial da mesa
    table = addCard(table, createCard(initCard), &qntCard);

    // Adicionando cartas a mão
    playerHand = createHand(playerHand, tempHand, &qntHand);


    while (1)
    {
        do
        {
            scanf("%s %s", action, complement);

            // Valida se o Coringa ou Valete que está na mesa é para o player
            if ((strcmp(action, "BUY") == 0) && splPlayer)
            {
                splPlayer = false;
            }

            if (strcmp(action, "DISCARD") == 0)
            {
                // Add carta ao monte da mesa (table)
                table = addCard(table, createCard(complement), &qntCard);

                // Identifica um Valete ou um Coringa na mesa
                if ((strcmp(table[qntCard - 1].value, "C") == 0) || (strcmp(table[qntCard - 1].value, "V") == 0))
                {
                    splPlayer = true;
                }

                // Identifica a troca de naipe e recebe o proximo naipe
                if ((strcmp(table[qntCard - 1].value, "C") == 0) || (strcmp(table[qntCard - 1].value, "A") == 0))
                {
                    scanf("%s", compt2ry);
                    strcpy(table[qntCard - 1].naipe, compt2ry);
                }
            }

        } while (strcmp(action, "TURN") || strcmp(complement, my_id));

        if (duelTime)
        {
            makeComment("É HORA DO DUELO!");
            duelTime = false;
        }

        if ((strcmp(table[qntCard - 1].value, "C") == 0) && splPlayer)
        {
            /*
                Compra 4 cartas se tiver um coringa na mesa
                O comentario para essa acao tambem é feito aqui.
            */

            randomCommentBuy();
            playerHand = buyCard(playerHand, &qntHand, 4);
        }
        else if ((strcmp(table[qntCard - 1].value, "V") == 0) && splPlayer)
        {
            /*
                Compra 2 cartas se tiver um valete na mesa
                O comentario para essa acao tambem é feito aqui.
            */

            randomCommentBuy();
            playerHand = buyCard(playerHand, &qntHand, 2);
        }
        else
        {
            if (determineCard(&disCard, table[qntCard - 1], playerHand, &qntHand))
            {
                /*
                    Caso determineCard encotrar uma carta, aqui ela será descartada.
                    O comentário para essa ação também é feito aqui.
                */

                randomCommentDiscard(disCard);
                table = addCard(table, disCard, &qntCard);

                if ((strcmp(disCard.value, "C") == 0) || (strcmp(disCard.value, "A") == 0))
                {
                    char auxNaipe[MAX_NAIPE]; // Naipe auxiliar

                    // Troca o naipe pelo naipe escolhido ao descartar um Coringa ou um Valete
                    predmtNaipe(auxNaipe, playerHand, qntHand);
                    strcpy(table[qntCard - 1].naipe, auxNaipe);
                }

                playerHand = discardCard(playerHand, disCard, &qntHand);
            }
            else
            {
                /*
                    Caso determineCard não encontre nenhuma carta, será comprado uma carta.
                    O comentário para essa ação também é feito aqui.
                */

                randomCommentBuy();
                playerHand = buyCard(playerHand, &qntHand, 1);
            }
        }
    }

    return 0;
}