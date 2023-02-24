#include <stdio.h>
#include <stdlib.h>

void imprima(char **matriz, int m, int n) { /*funcao para imprimir a matriz do mapa */
  int i, j;
  for (i = 0; i < m; i++) {
    printf("\n");
    for (j = 0; j < n; j++)
      printf("%c ", matriz[i][j]);
  }
  printf("\n");
}

int verificaTerra(char x){ 
  return (x == '\0' || x == '.') 
    ? 1 
    : 0; /* funcao para verificar e retornar onde tem terra e onde tem agua 1 == água 0 == terra */
} 

int retornaCosta(char **matriz, int m, int n) {
  int costas = 0, i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (verificaTerra(matriz[i][j]) == 1) /* se for água ele não questiona */
        continue;
      if (i == 0 || i == m - 1) { /* para evitar seg fault */
        costas++; /* considera costa */
        continue;
      }
      if (verificaTerra(matriz[i][j + 1]) == 1 ||
          verificaTerra(matriz[i][j - 1]) == 1 ||
          verificaTerra(matriz[i + 1][j]) == 1 ||
          verificaTerra(matriz[i - 1][j]) == 1) {
        costas++; /* se qualquer lado do caractere for água(1) é considerado costa */
      }
    }
  }
  return costas;
}

int main(void) {
  int M, N;
  int i, j;
  printf("Defina as linhas: \n"); /* informando quantidade de linhas da matriz */
  scanf(" %d", &M);
  printf("Defina as colunas: \n"); /* infromando quantidade de colunas da matriz */
  scanf(" %d", &N);
  char **matriz = (char **)malloc(M * sizeof(char *)); /* alocacao dinamica das linhas da matriz */
  if (matriz == NULL) {
    printf("ERRO!");
    exit(1);
  }
  for (i = 0; i < M; i++) {
    matriz[i] = (char *)malloc(N * sizeof(char)); /* alocacao dinamica das colunas da matriz */
  }
  printf("Mapeie com os caracteres: \n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      scanf(" %c", &matriz[i][j]); /*le as caracteres da matriz */
    }
  }
  imprima(matriz, M, N);
  printf("Quantidade de costas: %i\n", retornaCosta(matriz, M, N)); /* informa a quantidade de costas */
  for (i = 0; i < M; i++) { /* liberando a memoria */
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
