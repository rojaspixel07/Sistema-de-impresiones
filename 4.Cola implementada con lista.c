#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"4.ColaListaDocumentos.h"

main(){
	int i,num;
    printf("Iniciando cola \n");
    Cola queue1 = crearCola();
    printf("Cuantos documentos desea ingresar: ");
    scanf("%i", &num);
    for(i=0;i<num;i++){
    	addFinalLista(&queue1, num);
    }
    Documento z = primerElemento(queue1);
    printf("\nEl primer documento de la cola es: %s\n", z.nombre);
  	printf("\n====IMPRIMIENDO DOCUMENTOS====\n");
 	Sleep(1000);
  	for(i=0;i<num;i++){
  		Documento z = primerElemento(queue1);
    	printf("\nImprimiendo documento: %s\n", z.nombre);
    	Sleep(800);
    	printf("Tiempo de impresion: %i segundos\n", z.numPags * 5);
    	Sleep(1000);
		Documento w = borrarPrimero(&queue1);
  	}

	system("PAUSE");
}
