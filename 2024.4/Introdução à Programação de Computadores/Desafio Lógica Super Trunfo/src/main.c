#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

#define TOTAL_CARTAS 32 ///< Total de cartas a serem cadastradas

/**
 * @brief Remove o caractere de nova linha ('\n') de uma string.
 *
 * @param str A string a ser processada.
 */
void removeNewLine(char *str)
{
  str[strcspn(str, "\n")] = '\0';
}

/**
 * @brief Lê os dados de uma carta via terminal.
 *
 * Solicita ao usuário que insira os dados e computa as propriedades calculadas.
 *
 * @return Card com os dados informados.
 */
Card readCard()
{
  Card c;
  char buffer[200];

  // Leitura do estado
  printf("Digite o estado (A-H): ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    c.estado = buffer[0];
  }

  // Leitura do código da carta
  printf("Digite o código da carta (ex: A01): ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    removeNewLine(buffer);
    strncpy(c.codigo, buffer, CODIGO_MAX - 1);
    c.codigo[CODIGO_MAX - 1] = '\0';
  }

  // Leitura do nome da cidade
  printf("Digite o nome da cidade: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    removeNewLine(buffer);
    strncpy(c.nome, buffer, NOME_MAX - 1);
    c.nome[NOME_MAX - 1] = '\0';
  }

  // Leitura da população
  printf("Digite a população: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    c.populacao = atoi(buffer);
  }

  // Leitura da área
  printf("Digite a área em km²: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    c.area = atof(buffer);
  }

  // Leitura do PIB
  printf("Digite o PIB: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    c.pib = atof(buffer);
  }

  // Leitura do número de pontos turísticos
  printf("Digite o número de pontos turísticos: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    c.pontosTuristicos = atoi(buffer);
  }

  // Calcula as propriedades derivadas (densidade, PIB per capita, super poder)
  computeCalculatedProperties(&c);

  return c;
}

/**
 * @brief Retorna o valor do atributo escolhido de uma carta.
 *
 * Os atributos disponíveis são:
 *   1 - População
 *   2 - Área
 *   3 - PIB
 *   4 - Pontos Turísticos
 *   5 - Densidade Populacional
 *
 * @param card Ponteiro para a carta.
 * @param attr Número representando o atributo.
 * @return float Valor do atributo.
 */
float getAttributeValue(const Card *card, int attr)
{
  switch (attr)
  {
  case 1:
    return (float)card->populacao;
  case 2:
    return card->area;
  case 3:
    return card->pib;
  case 4:
    return (float)card->pontosTuristicos;
  case 5:
    return card->densidade;
  default:
    return 0.0f;
  }
}

/**
 * @brief Executa a comparação avançada entre duas cartas com base em dois atributos.
 *
 * Para atributos distintos de “densidade populacional” (opção 5), o maior valor é melhor.
 * Para “densidade populacional”, o menor valor é melhor; essa regra é aplicada invertendo
 * o sinal (usando operador ternário) para a soma. Assim, em ambos os casos, a carta com o
 * maior total ajustado vence.
 *
 * @param card1 Ponteiro para a primeira carta.
 * @param card2 Ponteiro para a segunda carta.
 */
void advancedComparison(const Card *card1, const Card *card2)
{
  int attr1, attr2;
  char buffer[50];

  printf("\nMenu de Seleção de Atributos para Comparação Avançada:\n");
  printf("1 - População\n");
  printf("2 - Área\n");
  printf("3 - PIB\n");
  printf("4 - Pontos Turísticos\n");
  printf("5 - Densidade Populacional\n");

  // Escolha do primeiro atributo
  printf("Escolha o primeiro atributo: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    attr1 = atoi(buffer);
  }
  else
  {
    printf("Erro na leitura.\n");
    return;
  }

  // Escolha do segundo atributo
  printf("Escolha o segundo atributo: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    attr2 = atoi(buffer);
  }
  else
  {
    printf("Erro na leitura.\n");
    return;
  }

  // Validação dos atributos
  if (attr1 < 1 || attr1 > 5 || attr2 < 1 || attr2 > 5)
  {
    printf("Atributo inválido. Tente novamente.\n");
    return;
  }

  // Para cada carta, se o atributo for densidade (5), usamos o valor negativo (ternário)
  float value1_card1 = (attr1 == 5) ? -getAttributeValue(card1, attr1) : getAttributeValue(card1, attr1);
  float value2_card1 = (attr2 == 5) ? -getAttributeValue(card1, attr2) : getAttributeValue(card1, attr2);
  float total_card1 = value1_card1 + value2_card1;

  float value1_card2 = (attr1 == 5) ? -getAttributeValue(card2, attr1) : getAttributeValue(card2, attr1);
  float value2_card2 = (attr2 == 5) ? -getAttributeValue(card2, attr2) : getAttributeValue(card2, attr2);
  float total_card2 = value1_card2 + value2_card2;

  printf("\nResultado da Comparação Avançada:\n");
  printf("Carta 1 -> Total ajustado: %.2f\n", total_card1);
  printf("Carta 2 -> Total ajustado: %.2f\n", total_card2);

  // Utilizando operador ternário para definir o vencedor
  (total_card1 > total_card2) ? printf("Carta 1 vence na comparação avançada!\n") : (total_card1 < total_card2 ? printf("Carta 2 vence na comparação avançada!\n") : printf("Empate na comparação avançada!\n"));
}

/**
 * @brief Função principal do sistema.
 *
 * Realiza o cadastro de 32 cartas, oferece um menu para comparação convencional
 * ou avançada e executa a opção escolhida.
 */
int main()
{
  Card cards[TOTAL_CARTAS];
  int i;
  char buffer[50];
  int menuChoice;

  printf("Cadastro de Cartas - Super Trunfo - Países\n");

  // Cadastro de 32 cartas
  for (i = 0; i < TOTAL_CARTAS; i++)
  {
    printf("\n--- Cadastro da Carta %d ---\n", i + 1);
    cards[i] = readCard();
    printf("\nCarta cadastrada com sucesso:\n");
    printCard(&cards[i]);
  }

  // Menu principal com opção de comparação
  printf("\nMenu Principal:\n");
  printf("1 - Comparação Tradicional (todos os atributos)\n");
  printf("2 - Comparação Avançada (selecione 2 atributos específicos)\n");
  printf("0 - Sair\n");
  printf("Escolha uma opção: ");
  if (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    menuChoice = atoi(buffer);
  }
  else
  {
    printf("Entrada inválida.\n");
    return 1;
  }

  switch (menuChoice)
  {
  case 1:
  {
    // Comparação tradicional: o usuário escolhe duas cartas e a comparação de todos os atributos já é feita
    int index1, index2;
    printf("Digite o número da primeira carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &index1);
    getchar(); // Consumir o '\n'
    printf("Digite o número da segunda carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &index2);
    getchar();

    if (index1 < 1 || index1 > TOTAL_CARTAS || index2 < 1 || index2 > TOTAL_CARTAS)
    {
      printf("Índices inválidos. Encerrando comparação.\n");
    }
    else
    {
      printf("\nComparando Carta %d e Carta %d:\n", index1, index2);
      compareCards(&cards[index1 - 1], &cards[index2 - 1]);
    }
    break;
  }
  case 2:
  {
    // Comparação avançada: o usuário escolhe duas cartas e depois dois atributos para comparação
    int index1, index2;
    printf("Digite o número da primeira carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &index1);
    getchar();
    printf("Digite o número da segunda carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &index2);
    getchar();
    if (index1 < 1 || index1 > TOTAL_CARTAS || index2 < 1 || index2 > TOTAL_CARTAS)
    {
      printf("Índices inválidos. Encerrando comparação.\n");
    }
    else
    {
      advancedComparison(&cards[index1 - 1], &cards[index2 - 1]);
    }
    break;
  }
  case 0:
    printf("Encerrando o programa.\n");
    break;
  default:
    printf("Opção inválida. Encerrando.\n");
    break;
  }

  return 0;
}
