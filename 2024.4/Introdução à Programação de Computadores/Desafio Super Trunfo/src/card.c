#include "card.h"
#include <stdio.h>

/**
 * @brief Calcula as propriedades derivadas da carta.
 */
void computeCalculatedProperties(Card *card)
{
  if (card->area != 0)
    card->densidade = card->populacao / card->area;
  else
    card->densidade = 0;

  if (card->populacao != 0)
    card->pibPerCapita = card->pib / card->populacao;
  else
    card->pibPerCapita = 0;

  /* Calcula o Super Poder como a soma de todas as propriedades:
     população + área + PIB + pontosTurísticos + densidade + PIB per Capita */
  card->superPoder = card->populacao + card->area + card->pib +
                     card->pontosTuristicos + card->densidade + card->pibPerCapita;
}

/**
 * @brief Exibe os dados da carta, incluindo propriedades calculadas.
 */
void printCard(const Card *card)
{
  printf("Estado: %c\n", card->estado);
  printf("Código da Carta: %s\n", card->codigo);
  printf("Nome da Cidade: %s\n", card->nome);
  printf("População: %d\n", card->populacao);
  printf("Área: %.2f km²\n", card->area);
  printf("PIB: %.2f\n", card->pib);
  printf("Número de Pontos Turísticos: %d\n", card->pontosTuristicos);
  printf("Densidade Populacional: %.2f\n", card->densidade);
  printf("PIB per Capita: %.2f\n", card->pibPerCapita);
  printf("Super Poder: %.2f\n", card->superPoder);
}

/**
 * @brief Compara duas cartas e exibe os vencedores para cada propriedade.
 */
void compareCards(const Card *card1, const Card *card2)
{
  printf("\nComparação entre Cartas:\n\n");

  // População (maior vence)
  printf("População: ");
  if (card1->populacao > card2->populacao)
    printf("Carta 1 vence (%d vs %d)\n", card1->populacao, card2->populacao);
  else if (card1->populacao < card2->populacao)
    printf("Carta 2 vence (%d vs %d)\n", card2->populacao, card1->populacao);
  else
    printf("Empate (%d vs %d)\n", card1->populacao, card2->populacao);

  // Área (maior vence)
  printf("Área: ");
  if (card1->area > card2->area)
    printf("Carta 1 vence (%.2f vs %.2f)\n", card1->area, card2->area);
  else if (card1->area < card2->area)
    printf("Carta 2 vence (%.2f vs %.2f)\n", card2->area, card1->area);
  else
    printf("Empate (%.2f vs %.2f)\n", card1->area, card2->area);

  // PIB (maior vence)
  printf("PIB: ");
  if (card1->pib > card2->pib)
    printf("Carta 1 vence (%.2f vs %.2f)\n", card1->pib, card2->pib);
  else if (card1->pib < card2->pib)
    printf("Carta 2 vence (%.2f vs %.2f)\n", card2->pib, card1->pib);
  else
    printf("Empate (%.2f vs %.2f)\n", card1->pib, card2->pib);

  // Pontos Turísticos (maior vence)
  printf("Pontos Turísticos: ");
  if (card1->pontosTuristicos > card2->pontosTuristicos)
    printf("Carta 1 vence (%d vs %d)\n", card1->pontosTuristicos, card2->pontosTuristicos);
  else if (card1->pontosTuristicos < card2->pontosTuristicos)
    printf("Carta 2 vence (%d vs %d)\n", card2->pontosTuristicos, card1->pontosTuristicos);
  else
    printf("Empate (%d vs %d)\n", card1->pontosTuristicos, card2->pontosTuristicos);

  // Densidade Populacional (menor vence)
  printf("Densidade Populacional (menor vence): ");
  if (card1->densidade < card2->densidade)
    printf("Carta 1 vence (%.2f vs %.2f)\n", card1->densidade, card2->densidade);
  else if (card1->densidade > card2->densidade)
    printf("Carta 2 vence (%.2f vs %.2f)\n", card2->densidade, card1->densidade);
  else
    printf("Empate (%.2f vs %.2f)\n", card1->densidade, card2->densidade);

  // PIB per Capita (maior vence)
  printf("PIB per Capita: ");
  if (card1->pibPerCapita > card2->pibPerCapita)
    printf("Carta 1 vence (%.2f vs %.2f)\n", card1->pibPerCapita, card2->pibPerCapita);
  else if (card1->pibPerCapita < card2->pibPerCapita)
    printf("Carta 2 vence (%.2f vs %.2f)\n", card2->pibPerCapita, card1->pibPerCapita);
  else
    printf("Empate (%.2f vs %.2f)\n", card1->pibPerCapita, card2->pibPerCapita);

  // Super Poder (maior vence)
  printf("Super Poder: ");
  if (card1->superPoder > card2->superPoder)
    printf("Carta 1 vence (%.2f vs %.2f)\n", card1->superPoder, card2->superPoder);
  else if (card1->superPoder < card2->superPoder)
    printf("Carta 2 vence (%.2f vs %.2f)\n", card2->superPoder, card1->superPoder);
  else
    printf("Empate (%.2f vs %.2f)\n", card1->superPoder, card2->superPoder);
}
