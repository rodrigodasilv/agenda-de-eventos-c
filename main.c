#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Evento.h"
#include "Lista.h"


int main(int argc, char *argv[]) {
	
	FILE *f = fopen("arquivo_eventos.txt", "r");
	Lista l1;
	if (f==NULL) {
		inicializa_lista( &l1, sizeof(Evento) );
	} else {
		printf("\n Tem arquivo");
	}
	
	// Criando evento
	Evento ev;
	Data data;
	if (setData(&data, 10, 7, 2022) == ERRO_DATA_INVALIDA)
		printf("ERRO_DATA_INVALIDA");
	Hora inicio;
	if (setHora(&inicio, 12, 30) == ERRO_HORA_INVALIDA)
		printf("ERRO_HORA_INVALIDA");
	Hora fim;
	if (setHora(&fim, 13, 30) == ERRO_HORA_INVALIDA)
		printf("ERRO_HORA_INVALIDA");
	setEvento (&ev, data, inicio, fim, "festinha do Musk", "Marte");

	// Inserindo evento no final da lista
	insere_fim(&l1, &ev);
	mostra_lista( l1, mostraEvento);
	
	// Salvar lista num arquivo
	salvar(l1, salva_evento, "teste.txt");
	
	if (setData(&data, 11, 7, 2022) == ERRO_DATA_INVALIDA)
		printf("ERRO_DATA_INVALIDA");
	if (setHora(&inicio, 14, 30) == ERRO_HORA_INVALIDA)
		printf("ERRO_HORA_INVALIDA");
	if (setHora(&fim, 15, 30) == ERRO_HORA_INVALIDA)
		printf("ERRO_HORA_INVALIDA");
	setEvento (&ev, data, inicio, fim, "Outra festinha do Musk", "Lua de Jupiter");
	
	insere_fim(&l1, &ev);
	mostra_lista( l1, mostraEvento);
	salvar(l1, salva_evento, "teste.txt");
	//ler(l1, "teste.txt");
	// Lendo da lista na posição 0
//	Evento ev2;
//	le_valor(l1, &ev2 , 0);
//	mostraEvento(&ev2);

	bool opcao_sair = false;
	int opcao_menu = 0;
	do {
		printf("\nAgenda de Eventos\n");
	    printf("\nInforme a operacao desejada: \n1) Cadastrar \n2) Mostrar todos os eventos da agenda \n");
	    printf("3) Mostrar todos os eventos uma data \n4) Mostrar todos os eventos que tenham de uma serta descri??o \n5) Remover evento \n");
    	printf("6) Sair do programa.\n\nInput: ");
		scanf(" %d",&opcao_menu);
    
	
		switch (opcao_menu){
			case 1: {   
	                 
	        } break;
	        case 2: {
	            
	        } break;    
	        case 3: {
	               
	        } break;
	        case 4: {
	               
	        } break;
	        case 5: {
	              
	        } break;
	        case 6: {
	            opcao_sair = true;
	        }
			default: {
				
	    	} break;
		}
	} while (opcao_sair == false);
	
	return 0;
}
