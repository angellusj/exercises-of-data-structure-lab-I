#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

typedef struct funcionario {
 float salario;
 char nome[100];
 char cargo[100];
 int identificador;
}funcio;

void recebe(funcio *pp, int qnt_funcionario) {
 int index;
 if (pp == NULL) {
  printf("ERRO");
  exit(1);
 }
 for (index = 0; index < qnt_funcionario; index++) {
  printf("Informe o nome do funcionário %i: \n", index + 1);
  fgets(pp[index].nome, 100, stdin);
  printf("Informe o salário do funcionário %i: \n", index + 1);
  scanf("%f", &pp[index].salario);
  getchar();
  printf("Informe o identificador do funcionário %i: \n", index + 1);
  scanf("%d", &pp[index].identificador);
  getchar();
  printf("Informe o cargo do funcionário %i: \n", index + 1);
  fgets(pp[index].cargo, 100, stdin);
  printf("\n");
  imprima(&pp[index]);
  printf("\n");
 }
}

void imprima(funcio *pp){
    printf("Informações do funcionário:\nNome:%sSalário:%.2f$\nIdentificador:%d\nCargo:%s", pp->nome, pp->salario, pp->identificador, pp->cargo);
}

int main(void) {
    int qnt_funcionario;
    printf("Informe quantos funcionários foram selecionados: ");
    scanf("%d", &qnt_funcionario);
    getchar();
    funcio *pp = (funcio *)malloc(qnt_funcionario * sizeof(funcio));
    recebe(pp, qnt_funcionario);
    free(pp);
    return 0;
}
