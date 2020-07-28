#include "milionario.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

void milionario(){

	List domande = leggi_domande();
   	
	if(domande == NULL){
		// unexpected error. Contact the administrator
		return;
	}
	
	printf("####### Chi vuol esser milionario #######");
	
	while(1){
		printf("\n\n");
		printf("1. Nuova partita\n");
		printf("2. Credits\n");
		printf("3. Esci\n");
		printf(":");
		int scelta;
		scanf("%d", &scelta);
	
		if(scelta == 1){
			inizio_partita(domande);
		} else if( scelta == 2 ){
			credits();
		}else if(scelta == 3){
			break;
		}else{
			printf("Scelta non valida!\n");
		}
	}
}

void inizio_partita(List domande){
	
	const char *montepremi[] = {"0 Euro", "500 Euro", "1000 Euro", "5000 Euro", "1 Milione"};
	int premio_corrente = 0;
	
	
	
	
	
}

void credits(){

	printf("by Sax corporation \n");
	
}


List leggi_domande(){


	List lista = createList();

    char riga[SIZE];
    FILE* finput;

    finput = fopen("domande.txt", "r");
    char *res = fgets(riga, SIZE, finput);

	if( finput != NULL ) {
		while( res != NULL ) {
			int len = strlen(riga);

			//printf("lunghezza riga letta (incluso carattere fine riga): %d\n", len);
			
			char delim[] = ":";
			
			char *d = strtok(riga, delim);
			char *r1 = strtok(NULL, delim);
			char *r2 = strtok(NULL, delim);
			char *r3 = strtok(NULL, delim);
			char *r4 = strtok(NULL, delim);
			int risposta_esatta = atoi(strtok(NULL, delim));
			
			/*printf("Domanda: %s", d);
			printf("R1: %s", r1);
			printf("R2: %s", r2);
			printf("R3: %s", r3);
			printf("R4: %s", r4);
			printf("Risposta esatta: %d \n\n", risposta_esatta);*/
			
			domanda domanda;
			strcpy(domanda.domanda, d);
			strcpy(domanda.r1,r1);
			strcpy(domanda.r2,r2);
			strcpy(domanda.r3,r3);
			strcpy(domanda.r4,r4);
			domanda.risposta_corretta = risposta_esatta;
			
			insertFirst(lista, domanda);

			res = fgets(riga, SIZE, finput);
		}

		fclose(finput);
		
		return lista;
	}
	else {
		printf("Impossibile aprire il file.");
		return NULL;
	}

}