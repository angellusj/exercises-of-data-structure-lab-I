include<stdio.h>

//respostas

//2.a - O compilador emite uma mensagem de advertência e erro no código.

//2.b - O compilador emite essa mensagem por mais de um motivo, a váriavel do ponteiro p não está recebendo o endereço da váriavel x; quando solicitado a saída do valor da váriavel p não é usado o indicador de valor inteiro que foi atribuído a váriavel; e a solicitação do valor do ponteiro está incorreta e recebe como resposta uma váriavel que não existe no código.

//2.c - A execução não foi bem sucedida.

//2.d - 
int main(void) {
	int x, *p;
	x = 100;
	p = &x;
	printf("Valor de p = %d", *p);
	return 0;
}

//2.e - Primeiramente ocorreu um erro indicando que as aspas usadas dentro da função printf não eram as corretas para essa função, corrigi esse erro e o código foi bem executado.
