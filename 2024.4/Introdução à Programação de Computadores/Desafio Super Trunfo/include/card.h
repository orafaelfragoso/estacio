#ifndef CARD_H
#define CARD_H

#define NOME_MAX 100 ///< Tamanho máximo para o nome da cidade
#define CODIGO_MAX 4 ///< Tamanho máximo para o código da carta (ex.: "A01" + '\0')

/**
 * @brief Estrutura que representa uma carta do jogo Super Trunfo.
 *
 * Cada carta contém informações sobre uma cidade e propriedades calculadas:
 * - estado: caractere indicando o estado (A-H)
 * - codigo: código da carta (ex: "A01")
 * - nome: nome da cidade
 * - populacao: número de habitantes
 * - area: área da cidade em km²
 * - pib: produto interno bruto da cidade
 * - pontosTuristicos: número de pontos turísticos
 * - densidade: densidade populacional (população/área)
 * - pibPerCapita: PIB dividido pela população
 * - superPoder: soma de todas as propriedades (considera-se população, área, PIB, pontos turísticos, densidade e PIB per capita)
 */
typedef struct
{
    char estado;
    char codigo[CODIGO_MAX];
    char nome[NOME_MAX];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Card;

/**
 * @brief Calcula as propriedades derivadas para uma carta.
 *
 * Calcula:
 * - Densidade populacional (população / área)
 * - PIB per Capita (PIB / população)
 * - Super Poder: soma de todas as propriedades numéricas
 *
 * @param card Ponteiro para a carta cuja propriedades serão calculadas.
 */
void computeCalculatedProperties(Card *card);

/**
 * @brief Imprime os dados da carta, incluindo as propriedades calculadas.
 *
 * @param card Ponteiro para a carta.
 */
void printCard(const Card *card);

/**
 * @brief Compara duas cartas e exibe o vencedor para cada propriedade.
 *
 * Para a densidade populacional, vence a carta com menor valor; para as demais,
 * vence a carta com o valor maior. Também compara o “super poder”, que é a soma das propriedades.
 *
 * @param card1 Ponteiro para a primeira carta.
 * @param card2 Ponteiro para a segunda carta.
 */
void compareCards(const Card *card1, const Card *card2);

#endif
