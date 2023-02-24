#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3
// 3 alunos no maximo
#define MAX_TURMAS 3
// 3 turmas no maximo

typedef struct aluno { /* struct do aluno */
  int mat;
  char nome[81];  /* tamanho maximo do nome do aluno */
  float notas[3]; /* quantidade de notas */
  float media;
} Aluno;

typedef struct turma {
  char *id;  /* caractere que identifica a turma, por exemplo, A ou B */
  int vagas; /* numero de vagas disponiveis para fechar a turma */
  Aluno *alunos[MAX_VAGAS];
} Turma;

Turma *turmas[MAX_TURMAS];

void obterNumero(long int *holder, size_t size) {
  size =
      (!size)
          ? 100
          : size; /* se usuario nao passar no argumento entao o padrao e 100 */
  char *b1 = (char *)malloc(sizeof(char) * size);
  char *ePTR;
  scanf(" %s", b1);
  *holder = strtol(b1, &ePTR, 10); /* Para evitar bugs quando passado letras */
} /* scanf vai ler uma letra e o strtol ira converte-la em numero, caso nao tenha um numero ele retorna 0 */

int turmaVazia() {
  return (turmas[0]->id != NULL)
             ? 0
             : 1; /* verifica se a turma geral está totalmente vazia */
}
// 0 = preenchida
// 1 = vazia

Turma *procura_turma(char *id) {
  for (size_t i = 0; i < MAX_TURMAS; i++) {
    if (turmas[i]->id == NULL)
      break;  /* evita acesso a turmas vazias */
    if (strcmp(turmas[i]->id, id) == 0) { /* significa que sao iguais */
      return turmas[i];
    }
  }
  printf("Turma inexistente.\n");
  return NULL;
}

void cria_turma() {  /* função sem tipo de retorno */
  char *id = (char *)malloc(sizeof(char)); /* vetor para id */
  printf("Criando nova turma... \n");
  printf("Digite um ID: ");
  scanf(" %s", id);
  for (size_t i = 0; i < MAX_TURMAS; i++) { /* procura turma livre */
    if (turmas[i]->id == NULL) {            /* turma encontrada */
      turmas[i]->id = (char *)malloc(sizeof(char));
      turmas[i]->id = id;           /* assimila id a turma vazia */
      turmas[i]->vagas = MAX_VAGAS; /* da valores padroes */
      for (size_t j = 0; j < MAX_VAGAS; j++)
        turmas[i]->alunos[j] = NULL; /* NULL para todas as vagas */
      printf("Turma %s criada com sucesso!\n", id);
      return;
    } else if (strcmp(turmas[i]->id, id) == 0) {
      printf("Esta turma ja foi registrada.\n");
      return;
    }
  }
  printf("Nao ha mais espaço para novas turmas.\n");
}

void matricula_aluno() {
  char *id = (char *)malloc(sizeof(char));
  printf("Para realizar a matricula do aluno informe:\nID da turma: ");
  scanf(" %s", id);
  Turma *alvo = procura_turma(id); /* ponteiro que temporariamente armazena a turma que esta sendo trabalhada */
  if (alvo == NULL)
    return;
  if (alvo->vagas <= 0) { /* verifica se todas as vagas foram preenchidas */
    printf("Vagas totalmente preenchidas.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++) { /* procurar a primeira vaga */
    if (alvo->alunos[i] == NULL) {         /* vaga encontrada */
      alvo->alunos[i] =
          malloc(sizeof(Aluno)); /* acolhe vaga, para preenche-la em seguinte */
      while (alvo->alunos[i]->mat <= 0) {
        printf("Numero da matricula: ");
        obterNumero((long int *)&alvo->alunos[i]->mat, 10);
      }
      getchar(); /* por culpa do \n deixado pelo scanf, serve para pega-lo */
      printf("Nome do aluno: ");
      fgets(alvo->alunos[i]->nome, 81, stdin);
      --alvo->vagas;
      break;
    }
  }
  printf("Aluno matriculado com sucesso!\n");
  return;
}

void lanca_notas() {
  char *id = (char *)malloc(sizeof(char));
  printf("Lancando notas, aguarde...\n");
  printf("Informe o ID da turma: ");
  scanf(" %s", id);
  Turma *alvo = procura_turma(id);
  if (alvo == NULL)
    return;
  if (alvo->vagas == MAX_VAGAS) { /* verifica se há vagas disponiveis */
    printf("Nenhum aluno matriculado nesta turma.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++) {
    if (alvo->alunos[i] == NULL)
      return;
    printf("\nMatricula: %d \tAluno: %s\n", alvo->alunos[i]->mat, alvo->alunos[i]->nome); /* imprime a matricula e o nome de determinado aluno */
    for (size_t j = 0; j < 3; j++) {
      printf("Digite a nota %lu: ", j + 1);
      scanf(" %f", &alvo->alunos[i]->notas[j]); /* le e armazena a nota do aluno */
          alvo->alunos[i]->media += alvo->alunos[i]->notas[j]; /* soma a nota do aluno com a media e atribui o valor na media */
    }
    alvo->alunos[i]->media /= 3; /* realiza o calculo da media */
  }
}

void imprime_alunos() {
  char *id = (char *)malloc(sizeof(char));
  printf("Listando alunos, aguarde...\n");
  printf("Informe o ID da turma: ");
  scanf(" %s", id);
  Turma *alvo = procura_turma(id);
  if (alvo == NULL)
    return;
  if (alvo->vagas == MAX_VAGAS) { /* verifica se há vagas na turma */
    printf("Nenhum aluno matriculado nesta turma.\n");
    return;
  }
  for (size_t i = 0; i < MAX_VAGAS; i++) {
    if (alvo->alunos[i] == NULL)
      break; /* verifica se o aluno existe */
    printf("\nMatricula: %i \tNome: %s", alvo->alunos[i]->mat, alvo->alunos[i]->nome);   /* informaçoes do aluno */
    printf("Media: %.2f\n", alvo->alunos[i]->media); /* media do aluno */
  }
}

void imprime_turmas() {
  printf("Listando turmas, aguarde...\n");
  for (size_t i = 0; i < MAX_TURMAS; i++) {
    if (turmas[i]->id == NULL)
      return; /* parar de listar na primeira turma vazia. */
    printf("Turma %s - %i vagas disponiveis\n", turmas[i]->id,
           turmas[i]->vagas);
  }
}
int main(int argc, char *argv[]) {
  for (size_t i = 0; i < MAX_TURMAS; i++) {
    turmas[i] = (Turma *)malloc(sizeof(Turma)); /* vetor para armazenar as
turmas */
    if (turmas[i] == NULL) {
      printf("Erro, sem memoria suficiente.\n");
      exit(1);
    }
  }
  size_t opt = 0; /* variavel de controle das opçoes do menu */
  while (opt != 6) {
    printf("\nMENU:\n"
           "1 - Criar turma\n"
           "2 - Listar turmas\n"
           "3 - Matricular aluno\n"
           "4 - Lancar notas\n"
           "5 - Listar alunos\n"
           "6 - Sair\n\n");
    printf("Selecione uma opcao: ");
    obterNumero((long int *)&opt, 3);
    printf("\n");
    if (opt > 0 &&
        opt < 7) { /* enquanto as opçoes estiverem entre 1 e 6 ira realizar as funçoes que forem selecionadas no menu */
      switch (opt) {
      case 1:
        cria_turma();
        break;
      case 2:
        (turmaVazia() == 0)
            ? imprime_turmas()
            : printf("Turmas vazias.\n"); /* se a turma estiver disponivel realiza a funçao imprime_turmas, se nao avisa que a turma esta vazia */
        break;
      case 3:
        (turmaVazia() == 0)
            ? matricula_aluno()
            : printf(
                  "Turmas vazias.\n"); /* se a turma estiver disponivel realiza a funçao matricula_aluno, se nao avisa que a turma esta vazia */
        break;
      case 4:
        (turmaVazia() == 0)
            ? lanca_notas()
            : printf("Turmas vazias.\n"); /* se a turma estiver disponivel realiza a funçao lanca_notas, se nao avisa que a turma esta vazia */
        break;
      case 5:
        (turmaVazia() == 0)
            ? imprime_alunos()
            : printf("Turmas vazias.\n"); /* se a turma estiver disponivel realiza a funçao imprime_alunos, se nao avisa que a turma esta vazia */
        break;
      case 6: /* sai do menu */
        break;
      }
    } else {
      printf("Dite uma opcao dentro das listadas.\n"); /* aviso para caso tente escolher uma opçao que nao esteja no menu */
    }
  }
  printf("Saindo...\n");
  for (size_t i = 0; i < MAX_TURMAS; i++)
    turmas[0] = NULL;
  return 0;
}
