#include<stdio.h>
#include<stdlib.h>

#define maxchar 100

int main(void){
    int qnt_entrevistado, index;
    printf("Quantas pessoas foram entrevistadas?\n");
    scanf("%d", &qnt_entrevistado);
    getchar();
    char ** sexo = (char**)malloc(qnt_entrevistado*sizeof(char*));
    char ** opiniao = (char**)malloc(qnt_entrevistado*sizeof(char*));
    for (index = 0; index < qnt_entrevistado; index++){
        opiniao[index] = (char*)malloc(maxchar*sizeof(char));
    }
     for (index = 0; index < qnt_entrevistado; index++){
        sexo[index] = (char*)malloc(maxchar*sizeof(char));
    }
    for (index = 0; index < qnt_entrevistado; index++){
        printf("Qual o sexo do %dº entrevistado?\n", index+1);
        fgets(sexo[index], maxchar, stdin);
        printf("Qual a opinião do %dº entrevistado?\n", index+1);
        fgets(opiniao[index], maxchar, stdin);
    }
    
    return 0;
}
