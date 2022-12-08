#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add resources
#include "../resources/definitions.h"
#include "../resources/funcs.h"
#include "../controllers/playerController.h"

// Compra n cartas e adiciona a mão
Card *buyCard(Card *cardGroup, int *handSize, int qnt)
{
	char auxCardString[MAX_CARD];

	printf("BUY %d\n", qnt);

	for (int i = 0; i < qnt; i++)
	{
		scanf("%s ", auxCardString);
		cardGroup = addCard(cardGroup, createCard(auxCardString), handSize);
	}

	return cardGroup;
}

// Descarta uma carta e atualiza a mão
Card *discardCard(Card *cardGroup, Card disCard, int *handSize)
{
	char complement[MAX_NAIPE] = "";

	/*
		Caso a carta descartada seja um A ou C, sera enviado como complemento
		o naipe que estiver em mais cartas da mão.
	*/
	if ((disCard.value[0] == 'A') || (disCard.value[0] == 'C'))
	{
		predmtNaipe(complement, cardGroup, *handSize);
	}

	printf("DISCARD %s %s\n", disCard.card, complement);
	cardGroup = removeCard(cardGroup, disCard, handSize);

	return cardGroup;
}

// Determina qual carta será jogada
int determineCard(Card *card, Card tableCard, Card *playerHand, int *handSize)
{
	// Determina o naipe majoritário da mão
	char auxNaipeString[MAX_NAIPE];
	predmtNaipe(auxNaipeString, playerHand, *handSize);


	// Procura por um coringa na mão
	if(searchCard(card, "C", "", playerHand, handSize)){ return true; }
			
	// Procura por um ás na mão
	else if(searchCard(card, "A", "", playerHand, handSize)){ return true; }

	// Procura por um valete do mesmo naipe da mesa
	else if(searchCard(card, "V", tableCard.naipe, playerHand, handSize)){ return true; }

	// Procura por um rei do mesmo naipe da mesa
	else if(searchCard(card, "R", tableCard.naipe, playerHand, handSize)){ return true; }

	// Procura por uma dama do mesmo naipe da mesa
	else if(searchCard(card, "D", tableCard.naipe, playerHand, handSize)){ return true; }
	
	// Procura por uma por uma carta do mesmo valor da carta da mesa mas com o naipe majoritário da mão
	else if(searchCard(card, tableCard.value, auxNaipeString, playerHand, handSize)){ return true; }

	// Procura por uma carta do mesmo naipe da mesa
	else if(searchCard(card, tableCard.naipe, "", playerHand, handSize)){ return true; }

	// Procura por uma carta do mesmo valor da mesa
	else if(searchCard(card, tableCard.value, "", playerHand, handSize)){ return true; }
	
	// Nao encontrou nenhuma carta
	else { return false; }
}