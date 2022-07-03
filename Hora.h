#define ERRO_HORA_INVALIDA -1

typedef struct {
	int hora, minuto;
} Hora;

int setHora(Hora *h, int hora, int minuto);
int gethora(Hora *h);
int getminuto(Hora *h);
