#include<stdio.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
	*area=(3*pow(l,2)*sqrt(3))/2;
	*perimetro=6*l;
}

int main(){
	float lado, a, p;
	printf("Informe o tamanho do lado do hexagono.");
	scanf("%f", &lado);
	calcula_hexagono(lado, &a,&p);
	printf("Area do hexagono: %.2f\nPerimetro do hexagono: %.2f", a, p);
	return 0;
	}
