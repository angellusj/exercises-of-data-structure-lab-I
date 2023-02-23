#include<stdio.h>

int main(){
	int x, y, *p;
    y = 0;
	p = &y;
	x = *p;
	x = 4;
	(*p)++;
	--x;
	(*p) += x;
	printf("valor de y=%d \nvalor de x=%d \nvalor de p=%d", y, x, *p);
	return 0;
}
