#include "Hora.h"

int setHora(Hora *h, int hora, int minuto){
	if(hora<0 || hora>23 || minuto < 0 || minuto>59)
		return ERRO_HORA_INVALIDA;
	h->hora = hora;
	h->minuto = minuto;
}
int gethora(Hora *h){
	return h->hora;
}
int getminuto(Hora *h){
	return h->minuto;
}
