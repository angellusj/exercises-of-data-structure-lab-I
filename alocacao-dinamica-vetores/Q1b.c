#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxchar 100


// mulheres que gostaram
float obterPorcentagemA(int qnt_entrevistado, char **sexo, char **opiniao) {
  float porcentagem=0;
  /*
          \n ao final, pois foi obtido através do fgets
          o operador ternário iria se questionar se o sexo é feminino
          caso seja, ele irá também se questionar se a opinião é "gostou"
          e então ou irá aumentar o contador ou irá se manter o mesmo.
  */
  for (size_t i = 0; i < qnt_entrevistado; i++) {
    porcentagem = (strcmp(sexo[i], "feminino\n") == 0 &&
                   strcmp(opiniao[i], "gostou\n") == 0)
                      ? porcentagem + 1 
                      : porcentagem;
  }
  return (float)(porcentagem * 100 /
                 qnt_entrevistado); // calcula a porcentagem na saída/retorno.
}


int main(void) {
  int qnt_entrevistado, index;
  printf("Quantas pessoas foram entrevistadas?\n");
  scanf(" %d", &qnt_entrevistado);
  getchar();
  char **sexo = (char **)malloc(qnt_entrevistado * sizeof(char *));
  char **opiniao = (char **)malloc(qnt_entrevistado * sizeof(char *));
  for (index = 0; index < qnt_entrevistado; index++) {
    opiniao[index] = (char *)malloc(maxchar * sizeof(char));
    sexo[index] = (char *)malloc(maxchar * sizeof(char));
  }
  for (index = 0; index < qnt_entrevistado; index++) {
    printf("Qual o sexo do %dº entrevistado?\n", index + 1);
    fgets(sexo[index], maxchar, stdin);
    printf("Qual a opinião do %dº entrevistado?\n", index + 1);
    fgets(opiniao[index], maxchar, stdin);
  }
  // debug
  printf("A porcentagem de mulheres que gostaram foi: %.2f\n",
         obterPorcentagemA(qnt_entrevistado, sexo, opiniao));
  return 0;
}
