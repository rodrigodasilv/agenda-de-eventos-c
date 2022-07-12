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

void mostraEvento(void *evento){
	Evento *e = evento;
	printf("Data: %02d/%02d/%04d \n", getDia(&e->data),getMes(&e->data),getAno(&e->data));
	printf("Inicio: %02d:%02d \n", gethora(&e->inicio),getminuto(&e->inicio));
	printf("Fim: %02d:%02d \n", gethora(&e->fim),getminuto(&e->fim));
	printf("Descricao: %s \n", e->descricao);
	printf("Local: %s \n", e->local);
}

void salva_evento(FILE* arquivo, void *evento) {
	Evento *e = evento;
	fprintf(arquivo, "%02d %02d %04d \n", getDia(&e->data),getMes(&e->data),getAno(&e->data)); //Data
	fprintf(arquivo, "%02d %02d \n", gethora(&e->inicio),getminuto(&e->inicio)); //Hora inicio
	fprintf(arquivo, "%02d %02d \n", gethora(&e->fim),getminuto(&e->fim)); //Hora fim
	fprintf(arquivo, "%s \n", e->descricao); //Descricao
	fprintf(arquivo, "%s \n", e->local); //Local
}

int carregar_lista(Lista *l, char* nome_arquivo){
	FILE* arquivo = fopen(nome_arquivo, "r");
	
	if (arquivo==NULL)
		return ERRO_SEM_ARQUIVO;
		
	int qtd;
	if(fscanf(arquivo, "%d", &qtd) != 1)
    	return ERRO_SEM_ARQUIVO;
	
	int i;
	for(i=0; i<qtd; i++){
		int dia,mes,ano;
		Data d;
		fscanf(arquivo, "%d %d %d", &dia,&mes,&ano); //Data
		setData(&d,dia,mes,ano);
		
		Hora inicio;
		int horaInicio, minutoInicio;
		fscanf(arquivo, "%d %d", &horaInicio,&minutoInicio); //Hora inicio
		setHora(&inicio,horaInicio,minutoInicio);
		
		Hora fim;
		int horaFim,minutoFim;
		fscanf(arquivo, "%d %d", &horaFim,&minutoFim); //Hora fim
		setHora(&fim,horaFim,minutoFim);
		
		char descricao[50], local[50];
		fscanf(arquivo, "%s", &descricao); //Descricao
		fscanf(arquivo, "%s", &local); //Local
		Evento e;
		setEvento(&e,d,inicio,fim,descricao,local);
		insere_ordem(l,&e,compara_evento);
	}	
	fclose(arquivo);	
	return 0;
}

int compara_evento( void *x, void *y ){
	Evento *a = x, *b = y;
	
	if( getAno(&a->data) > getAno(&b->data) )
		return 1;
	if( getAno(&a->data) < getAno(&b->data) )
		return -1;
		
	if(getMes(&a->data) > getMes(&b->data))
		return 1;
	if( getMes(&a->data) < getMes(&b->data) )
		return -1;
		
	if(getDia(&a->data) > getDia(&b->data))
		return 1;
	if( getDia(&a->data) < getDia(&b->data) )
		return -1;
	
	if(gethora(&a->inicio) > gethora(&b->inicio))
		return 1;
	if( gethora(&a->inicio) < gethora(&b->inicio) )
		return -1;
	return 0;
}

void criaEvento(Evento *e){
	int dia,mes,ano;
	do{
		printf("Informe o dia do evento: ");
		scanf(" %d",&dia);
	}while(dia<1 || dia > 32);
	do{
		printf("Informe o mes do evento: ");
		scanf(" %d",&mes);
	}while(mes<1 || mes > 12);
	do{
		printf("Informe o ano do evento: ");
		scanf(" %d",&ano);
	}while(ano<0);
	Data d;
	setData(&d,dia,mes,ano);
	Hora inicio;
	int horaInicio, minutoInicio;
	do{
		printf("Informe a hora de inicio do evento: ");
		scanf(" %d",&horaInicio);
	}while(horaInicio<0 || horaInicio>23);
	do{
		printf("Informe o minuto de inicio do evento: ");
		scanf(" %d",&minutoInicio);
	}while(minutoInicio < 0 || minutoInicio>59);
	setHora(&inicio,horaInicio,minutoInicio);
	Hora fim;
	int horaFim,minutoFim;
	do{
		printf("Informe a hora de fim do evento: ");
		scanf(" %d",&horaFim);
	}while(horaFim<0 || horaFim>23);
	do{
		printf("Informe o minuto de inicio do evento: ");
		scanf(" %d",&minutoFim);
	}while(minutoFim < 0 || minutoFim>59);
	setHora(&fim,horaFim,minutoFim);
	
	char descricao[50], local[50];
	printf("Informe a descricao do evento: ");
	scanf(" %s", &descricao); //Descricao
	printf("Informe o local do evento: ");
	scanf(" %s", &local); //Local
	setEvento(e,d,inicio,fim,descricao,local);
}
