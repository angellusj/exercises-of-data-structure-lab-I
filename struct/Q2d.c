#include<stdio.h>
#include<stdlib.h> 

typedef struct pessoa{
    char nome[100];
    int idade;
    int identidade;
}person; 

void recebe(person *pp, int qnt_pessoa) {
int index;
if (pp == NULL) {
    printf("ERRO");
    exit(1);
    
}
for (index = 0; index < qnt_pessoa; index++) {
    printf("Informe o nome da pessoa %i: \n", index + 1);
    fgets(pp[index].nome, 100, stdin);
    printf("Informe o idade da pessoa %i: \n", index + 1);
    scanf("%i", &pp[index].idade);
    getchar();
    printf("Informe o identidade da pessoa %i: \n", index + 1);
    scanf("%d", &pp[index].identidade);
    getchar();
    imprima(&pp[index]);
    printf("\n");
    }
} 

void imprima(person *pp) {
  printf("Nome: %sIdade: %i\nIdentidade: %i\n", pp->nome, pp->idade, pp->identidade);
} 

person menor_idade(person *pp, int qnt_pessoa) {
person menor = pp[0];
  for (size_t i = 0; i < qnt_pessoa; i++)
  menor = (pp[i].idade < menor.idade) ? pp[i] : menor;
return menor;
}

person maior_idade(person *pp, int qnt_pessoa) {
  person maior = pp[0];
  for (size_t i = 0; i < qnt_pessoa; i++)
  maior = (pp[i].idade > maior.idade) ? pp[i] : maior;
  return maior;
} 

int main() {
    int qnt_pessoa, pessoa;
    printf("Informe a quantidade de pessoas selecionadas: ");
    scanf("%i", &qnt_pessoa);
    getchar();
 
    person *pp = (person *)malloc(qnt_pessoa * sizeof(person));
    recebe(pp, qnt_pessoa);
    person maior = maior_idade(pp, qnt_pessoa);
  printf("\nMaior idade: %i\nPessoa: %s", maior.idade, maior.nome);
  person menor = menor_idade(pp, qnt_pessoa);
  printf("\nMenor idade: %i\nPessoa: %s", menor.idade, menor.nome);
    free(pp);
    return 0;
}
