#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct funcionario{
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
  altera(&pp[index]);
  printf("\n");
  getchar();
 }
}

void imprima(funcio *pp){
    printf("Informações do funcionário:\nNome:%sSalário:%.2f$\nIdentificador:%d\nCargo:%s", pp->nome, pp->salario, pp->identificador, pp->cargo);
}

void altera(funcio *pp){
  printf("Salário atual do funcionário:%.2f\n",pp->salario);
  printf("Novo salário: \n");
  scanf("%f", &pp->salario);
  printf("Salário do funcionário atualizado: %.2f", pp->salario);
}

funcio menor_salario(funcio *pp, int qnt_funcionario) {
  funcio menor = pp[0];
  for (size_t i = 0; i < qnt_funcionario; i++)
    menor = (pp[i].salario < menor.salario) ? pp[i] : menor;
  menor.nome[strcspn(menor.nome, "\n")] = '\0';
  return menor;
}

funcio maior_salario(funcio *pp, int qnt_funcionario) {
  funcio maior = pp[0];
  for (size_t i = 0; i < qnt_funcionario; i++)
    maior = (pp[i].salario > maior.salario) ? pp[i] : maior;
  maior.nome[strcspn(maior.nome, "\n")] = '\0';
  return maior;
}

int main(void) {
    int qnt_funcionario;
    printf("Informe quantos funcionários foram selecionados: ");
    scanf("%d", &qnt_funcionario);
    getchar();
    funcio *pp = (funcio *)malloc(qnt_funcionario * sizeof(funcio));
    recebe(pp, qnt_funcionario);
    funcio maior = maior_salario(pp, qnt_funcionario);
  printf("\nMaior salário: %.2f\nfuncionário: %s \ncargo: %s", maior.salario,
         maior.nome, maior.cargo);
  funcio menor = menor_salario(pp, qnt_funcionario);
  printf("\nMenor salário: %.2f\nfuncionario: %s \ncargo: %s", menor.salario,
         menor.nome, menor.cargo);
    free(pp);
    return 0;
}
