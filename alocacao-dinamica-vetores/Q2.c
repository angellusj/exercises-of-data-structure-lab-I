#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_ALUNOS 10

void coletarRespostas(char *resposta, int qnt_questoes) {
  for (size_t i = 0; i < qnt_questoes; i++) {
    getchar();
    printf("\nQual é a alternativa correta da questão nº%lu? ", i + 1);
    fgets(&resposta[i], 2, stdin);
  }
}

int main(void) {
  int qnt_questoes;
  printf("Quantas questões serão? ");
  scanf(" %i", &qnt_questoes);
  char *gabarito = (char *)malloc(sizeof(char) * qnt_questoes);
  char **respostas = (char **)malloc(sizeof(char *) * QNT_ALUNOS);
  for (size_t i = 0; i < qnt_questoes; i++) {
    getchar();
    printf("\nGabarito da questão %lu: ", i + 1);
    fgets(&gabarito[i], 2, stdin);
  }
  for (size_t i = 0; i < QNT_ALUNOS; i++) {
    respostas[i] =
        (char *)malloc(sizeof(char) * qnt_questoes); 
    printf("\nRespostas do aluno %lu:", i + 1);
    coletarRespostas(respostas[i], qnt_questoes);
  }
  return 0;
}
