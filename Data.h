#define ERRO_DATA_INVALIDA -1

typedef struct {
	int dia, mes, ano;
} Data;

int setData(Data *d, int dia, int mes, int ano);
int getDia(Data *d);
int getMes(Data *d);
int getAno(Data *d);
