#include "Data.h"

int setData(Data *d, int dia, int mes, int ano){
	if(dia < 1 || dia>31 || mes<1 || mes>12 || ano<0)
		return ERRO_DATA_INVALIDA;
	d->ano = ano;
	d->dia = dia;
	d->mes = mes;
}
int getDia(Data *d){
	return d->dia;
}
int getMes(Data *d){
	return d->mes;
}
int getAno(Data *d){
	return d->ano;
}

void criaData(Data *d){
	int dia, mes, ano;
	do{
		printf("Informe o dia: ");
		scanf(" %d",&dia);
		printf("Informe o mes: ");
		scanf(" %d",&mes);
		printf("Informe o ano: ");
		scanf(" %d",&ano);
	}while(dia < 1 || dia>31 || mes<1 || mes>12 || ano<0);
	setData(d,dia,mes,ano);
}
