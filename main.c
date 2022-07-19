#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Evento.h"
//#include "Lista.h"


int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(Evento) );
	if (carregar_lista(&l1,"arquivo_eventos.txt")!=ERRO_SEM_ARQUIVO) {
		printf("Arquivo carregado! \n");
	}
	
	printf("  ,---.   ,----.   ,------.,--.  ,--.,------.    ,---.   \n");
	printf(" /  O  \\ '  .-./   |  .---'|  ,'.|  ||  .-.  \\ /  O  \\ \n");
	printf("|  .-.  ||  | .---.|  `--, |  |' '  ||  |  \\ : |  .-.  | \n");
	printf("|  | |  |'  '--'  ||  `---.|  | `   ||  '--'  /|  | |  | \n");
	printf("`--' `--' `------' `------'`--'  `--'`-------' `--' `--' \n");
	int opcao_menu = 0;
	do {
	    printf("\nInforme a operacao desejada: \n1) Cadastrar \n2) Mostrar todos os eventos da agenda \n");
	    printf("3) Mostrar todos os eventos uma data \n4) Mostrar todos os eventos conforme descricao \n5) Remover evento \n");
    	printf("6) Sair do programa.\n\nInput: ");
		scanf(" %d",&opcao_menu);
    
	
		switch (opcao_menu){
			case 1: {  
				Evento e;
				criaEvento(&e);
				//verifIntervalo(&e,&l1); Verifica se evento nao sobrepoe outro evento
				int resposta = insere_ordem(&l1, &e,compara_evento, verifica_conflito);
				if(resposta==ERRO_EVENTO_JA_EXISTE){
					printf("Evento ja existe na lista!\n");
				} else if (resposta == ERRO_CONFLITO) {
					printf("Evento em conflito!\n");
				} else {
					printf("Evento inserido com sucesso!\n");
				}
	       		break;            
	        }
	        case 2: {
	            mostra_lista( l1, mostraEvento);
	            break;    
	        }
	        case 3: {
	        	Data d;
	        	criaData(&d);
	        	mostra_lista( busca_todos_mostra(l1,&d,compara_evento_data), mostraEvento);
	        	break;     
	        } 
	        case 4: {
	        	char desc[50];
	        	printf("Informe a descricao: ");
	        	scanf(" %[^\n]",&desc);
	        	printf("%s\n", desc);
	        	mostra_lista( busca_todos_mostra(l1,&desc,compara_evento_desc), mostraEvento);
				break;	               
	        } 
	        case 5: {
	        	int opcao_remocao;
	        	Data dd;
	        	Evento ee;
	        	Lista exc;
	        	do{
	        		printf("\nInforme a operacao desejada: \n1) Dada uma data, remover todos os eventos dessa data \n2) Data uma data e hora inicial, remover o evento \n3) Sair\n");
	        		scanf(" %d",&opcao_remocao);
	        		switch(opcao_remocao){
	        			case 1:{
	        				criaData(&dd);
	        				exc = busca_todos(l1,&dd,compara_evento_data);
							break;
						}
						case 2:{
							criaEventoInicio(&ee);
							exc = busca_todos(l1,&ee,compara_evento_hr_inicio);
							break;
						}
	        			default:{
							break;
						}
					}
					if(opcao_remocao == 1 || opcao_remocao == 2){
						excl_lista(&l1,&exc);
					}
				}while(opcao_remocao !=1 && opcao_remocao!=2 && opcao_remocao!=3);
	       		break;    
	        } 
	        case 6: {
	        	// Salvar lista num arquivo
				salvar_lista(l1, salva_evento, "arquivo_eventos.txt");
	            break;
	        }
			default: {
				break;	
	    	}
		}
	} while (opcao_menu != 6);
	return 0;
}
