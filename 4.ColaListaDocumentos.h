#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int tamano;
	int numPags;
	char nombre[50];
}Documento;

typedef struct Nodo{
    Documento val;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
	int primero;
	int ultimo;
	Documento nuevo;
}Cola;

Cola crearCola(); 
void addFinalLista(Cola*,int);        //enqueue
Documento borrarPrimero(Cola*);       //dequeue
Documento primerElemento(Cola);       //first

Cola crearCola(){
	Cola cola;
	cola.head = NULL;
	cola.primero = 1;
	cola.ultimo = 0;
	return cola;
}

void addFinalLista(Cola *cola, int num) {       //meter
	int i;
	if(cola->head==NULL){
		
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    	printf("NUEVO DOCUMENTO\n");
    	printf("Ingrese el nombre del documento: ");
    	fflush(stdin);
    	scanf(" %[^\n]", &nodo->val.nombre);
    	printf("Ingrese el numero de paginas: ");
    	scanf("%i", &nodo->val.numPags);
    	nodo->next = NULL;
    	cola->head = nodo;	
	}	
	else
	{
		Nodo *current = cola->head;
		while (current->next != 0) {
       		current = current->next;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	printf("NUEVO DOCUMENTO\n");
    	printf("Ingrese el nombre del documento: ");
    	fflush(stdin);
    	scanf(" %[^\n]",&nuevoNodo->val.nombre);
    	printf("Ingrese el numero de paginas: ");
    	scanf("%i", &nuevoNodo->val.numPags);
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;		
	}	
	cola->ultimo++;	
}

Documento borrarPrimero(Cola *cola) {            //sacar
	Documento valor;
    if (cola->head == NULL) {
        printf("La cola esta vacia");
    }
    else{
    	Nodo *nuevo_head = NULL;
    	Nodo *temp = cola->head;
    	nuevo_head=temp->next;
    	valor = cola->head->val;
    	free(cola->head);
    	cola->head = nuevo_head;
	}
	cola->primero++;
	return valor;
}


Documento primerElemento(Cola cola){            //mostrar primero sin eliminar
	return cola.head->val;
}
