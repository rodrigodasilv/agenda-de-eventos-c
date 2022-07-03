#include <stdio.h>
#include <stdlib.h>
#include "Evento.h"

int main(int argc, char *argv[]) {
	Data a;
	Hora b;
	Evento c;
	if(setData(&a,1,12, 2002)==ERRO_DATA_INVALIDA)
		printf("ERRO_DATA_INVALIDA");
	if(setHora(&b,10,30)==ERRO_HORA_INVALIDA)
		printf("ERRO_HORA_INVALIDA");
	setEvento(&c,a,b,b,"teste","sua casa rs");
	mostraEvento(&c);
	return 0;
}
