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
				insere_ordem(&l1, &e,compara_evento);
	       		break;            
	        }
	        case 2: {
	            mostra_lista( l1, mostraEvento);
	            break;    
	        }
	        case 3: {
	        	break;     
	        } 
	        case 4: {
				break;	               
	        } 
	        case 5: {
	       		break;    
	        } 
	        case 6: {
	        	// Salvar lista num arquivo
			salvar_lista(l1, salva_evento, "arquivo_eventos.txt");
			limpa_lista(&l1);
	            break;
	        }
			default: {
				break;	
	    	}
		}
	} while (opcao_menu != 6);
	return 0;
}
