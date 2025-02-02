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
 * @brief Função principal do sistema.
 *
 * Realiza o cadastro de 32 cartas e, em seguida, pergunta se o usuário deseja comparar duas cartas.
 */
int main()
{
  Card cards[TOTAL_CARTAS];
  int i;

  printf("Cadastro de Cartas - Super Trunfo - Países\n");

  // Cadastro de 32 cartas
  for (i = 0; i < TOTAL_CARTAS; i++)
  {
    printf("\n--- Cadastro da Carta %d ---\n", i + 1);
    cards[i] = readCard();
    printf("\nCarta cadastrada com sucesso:\n");
    printCard(&cards[i]);
  }

  // Opção para comparar duas cartas
  int choice;
  printf("\nDeseja comparar duas cartas? (1 para sim, 0 para não): ");
  scanf("%d", &choice);
  getchar(); // Consume o '\n' do buffer
  if (choice == 1)
  {
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
      printf("\nComparando Carta %d e Carta %d:\n", index1, index2);
      compareCards(&cards[index1 - 1], &cards[index2 - 1]);
    }
  }

  return 0;
}
