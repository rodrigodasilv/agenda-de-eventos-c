#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "Evento.h"

int setEvento(Evento *e,Data data, Hora inicio, Hora fim, char descricao[50],char local[50]){
	e->data = data;
	e->inicio = inicio;
	e->fim = fim;
	strcpy(e->descricao, descricao);
	strcpy(e->local, local);
}
Data getData(Evento *e){
	return e->data;
}
Hora getHoraInicio(Evento *e){
	return e->inicio;
}
Hora getHoraFim(Evento *e){
	return e->fim;
}

void mostraEvento(Evento *e){
	printf("Data: %02d/%02d/%04d \n", getDia(&e->data),getMes(&e->data),getAno(&e->data));
	printf("Inicio: %02d:%02d \n", gethora(&e->inicio),getminuto(&e->inicio));
	printf("Fim: %02d:%02d \n", gethora(&e->fim),getminuto(&e->fim));
	printf("Descricao: %s \n", e->descricao);
	printf("Local: %s \n", e->local);
}

void salva_evento(FILE* arquivo, Evento *e) {
	fprintf(arquivo, "Data: %02d/%02d/%04d \n", getDia(&e->data),getMes(&e->data),getAno(&e->data));
	fprintf(arquivo, "Inicio: %02d:%02d \n", gethora(&e->inicio),getminuto(&e->inicio));
	fprintf(arquivo, "Fim: %02d:%02d \n", gethora(&e->fim),getminuto(&e->fim));
	fprintf(arquivo, "Descricao: %s \n", e->descricao);
	fprintf(arquivo, "Local: %s \n", e->local);
}

