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
    printf("Informe a identidade da pessoa %i: \n", index + 1);
    scanf("%d", &pp[index].identidade);
    getchar();
    printf("\n");
    imprima(&pp[index]);
    printf("\n");
    }
} 

void imprima(person *pp) {
    printf("Nome: %sIdade: %i\nIdentidade: %i\n", pp->nome, pp->idade, pp->identidade);
} 

int main() {
    int qnt_pessoa, pessoa;
    printf("Informe a quantidade de pessoas selecionadas: ");
    scanf("%i", &qnt_pessoa);
    getchar();
    
    person *pp = (person *)malloc(qnt_pessoa * sizeof(person));
    recebe(pp, qnt_pessoa);
    free(pp);
    return 0;
}
