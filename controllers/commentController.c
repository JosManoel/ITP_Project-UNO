#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add resources
#include "../resources/definitions.h"
#include "../resources/funcs.h"

// Recebe uma string e realiza um comentário
void makeComment(const char *comment) { printf("SAY %s\n", comment); }

// Retorna o efeito da carta
char *determineEffect(Card card)
{
    if (strcmp(card.value, "C") == 0)
        return "puxar 4 cartas";
    if (strcmp(card.value, "V") == 0)
        return "puxar 2 cartas";
    if (strcmp(card.value, "D") == 0)
        return "mudar o fluxo do duelo";
    if (strcmp(card.value, "R") == 0)
        return "meu oponente perderá o próximo turno";
    if (strcmp(card.value, "A") == 0)
        return "troco o atributo das cartas";

    return "não encontrado";
}

// Realiza um comentário aleatório sobre a ação de comprar cartas
void randomCommentBuy()
{
    // Frases ditas por Atem, Yugi, Joey e Seto Kaiba e inspiradas no anime Yu-Gi-Oh
    const char *phasesBuyAction[] = {
        "Eu acredito no coração das cartas!",
        "Acha que está ganhando? Na próxima eu ativo o Dark Hole.",
        "Isso é apenas o efeito do meu Two-Pronged Attack!",
        "Jogue seus jogos, enquanto eu me torno o ser mais poderoso do mundo!",
        "Este duelo ainda não acabou!",
        "Fale até cansar...",
        "Isso só aumenta a minha probabilidade de conseguir o Exodia!",
        "Espera só até eu lançar o lendário dragão branco de olhos azuis!",
        "Quando eu conseguir um dos três deuses egípcios, esse duelo acabará!",
    };

    makeComment(phasesBuyAction[rand() % 9]);
}

// Realiza um comentário de acordo com a carta descartada
void randomCommentDiscard(Card disCard)
{
    makeComment("Meu turno!");

    if ((strcmp(disCard.value, "C") == 0) || (strcmp(disCard.value, "V") == 0))
    {
        printf("SAY Você acaba de ativar minha carta %s! Agora você terá que %s!\n", disCard.card, determineEffect(disCard));
    }

    else if ((strcmp(disCard.value, "D") == 0) || (strcmp(disCard.value, "R") == 0))
    {
        printf("SAY Invoco %s e ativo seu efeito especial: %s.\n", disCard.card, determineEffect(disCard));
    }

    else if (strcmp(disCard.value, "A") == 0)
    {
        printf("SAY Ativo %s e %s.\n", disCard.card, determineEffect(disCard));
    }
    else
    {
        printf("SAY Invoco %s.\n", disCard.card);
    }

    makeComment("Encerro o meu turno.");
}
