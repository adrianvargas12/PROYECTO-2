#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

FILE *archivo;
char direccion[] = "C:\\Users\\Adrian Vargas\\Desktop\\pilas\\";

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu(Nodo *&);
void menu_aleatorios(Nodo *&);
void menu_leer_archivo(Nodo *&);
void menu_ordenar(Nodo *&);
void generar_aleatorios(Nodo *&, int);
void ingresar_datos_pila(Nodo *&, int);
void mostrar_datos_pila(Nodo *);
void vaciar_datos_pila(Nodo *&);
void ingresar_datos_cola(int);
void mostrar_datos_cola();
void escribir_pila_archivo(Nodo *);
void cargar_archivo_pila(Nodo *&, int);
void buscar_dato_pila(Nodo *);
void ordenar_burbuja_pila(Nodo *&);
int calcular_longitud_pila(Nodo *);

int main(){
	Nodo *pila = NULL;
	menu(pila);
	return 0;
}

void menu(Nodo *&pila){
	int opcion;
	do{
		printf("MENU PRINCIPAL\n");
		printf("1. Generar Numeros Aleatorios\n ");
		printf("2. Leer desde Archivo\n ");
		printf("3. Escribir en Archivo\n ");
		printf("4. Ordenar\n ");
		printf("5. Imprimir Resultados\n ");
		printf("6. Busquedad\n ");
		printf("7. Guardar Resultados\n ");
		printf("0. Salir\n ");
		printf("Ingrese su opcion: \n ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: menu_aleatorios(pila);
		break;
		case 2: menu_leer_archivo(pila);
		break;
		case 3: escribir_pila_archivo(pila);
		break;
		case 4: menu_ordenar(pila);
		break;
		case 5: mostrar_datos_pila(pila);
		break;
		case 6: buscar_dato_pila(pila);
		break;
		case 7: escribir_pila_archivo(pila);
		break;
		case 0: exit(0);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_aleatorios(Nodo *&pila){
	int opcion;
	do{
		printf("MENU ALEATORIOS\n");
		printf("1. 1 Mil\n ");
		printf("2. 2 Mil\n ");
		printf("3. 5 Mil\n ");
		printf("4. 10 Mil\n ");
		printf("5. 20 Mil\n ");
		printf("6. Imprimir Datos\n ");
		printf("0. Regresar Menu Principal\n ");
		printf("Ingrese su opcion: \n ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: generar_aleatorios(pila, 1000);
		break;
		case 2: generar_aleatorios(pila, 2000);
		break;
		case 3: generar_aleatorios(pila, 5000);
		break;
		case 4: generar_aleatorios(pila, 10000);
		break;
		case 5: generar_aleatorios(pila, 20000);
		break;
		case 6: mostrar_datos_pila(pila);
		break;
		case 0: menu(pila);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_leer_archivo(Nodo *&pila){
	int opcion;
	do{
		printf("MENU LEER ARCHIVOS\n");
		printf("1. 1 Mil\n ");
		printf("2. 2 Mil\n ");
		printf("3. 5 Mil\n ");
		printf("4. 10 Mil\n ");
		printf("5. 20 Mil\n ");
		printf("0. Regresar Menu Principal\n ");
		printf("Ingrese su opcion: \n ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: cargar_archivo_pila(pila, 1000);
		break;
		case 2: cargar_archivo_pila(pila, 2000);
		break;
		case 3: cargar_archivo_pila(pila, 5000);
		break;
		case 4: cargar_archivo_pila(pila, 10000);
		break;
		case 5: cargar_archivo_pila(pila, 20000);
		break;
		case 0: menu(pila);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_ordenar(Nodo *&pila){
	int opcion;
	do{
		printf("MENU ORDENAR PILA\n");
		printf("1. Burbuja\n ");
		printf("2. Sin Metodo\n ");
		printf("0. Regresar Menu Principal\n ");
		printf("Ingrese su opcion: \n ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: ordenar_burbuja_pila(pila);
		break;
		case 2: ordenar_burbuja_pila(pila);
		break;
		case 0: menu(pila);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void generar_aleatorios(Nodo *&pila, int longitud){
	vaciar_datos_pila(pila);
	int i, n;
	srand(time(NULL));
	for(i = 0; i < longitud; i++){
		//n = rand() % 1999999 - 999999;
		n = rand() % 60001 - 30000;
		ingresar_datos_pila(pila, n);
	}
	printf("\nDatos Generados: %d \n", i);
}

void ingresar_datos_pila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;
}

void mostrar_datos_pila(Nodo *pila){
	int i = 0;
	printf("Datos en la Pila\n");
	Nodo *copia_pila = pila;
	if(copia_pila == NULL){
		printf("Pila Vacia\n");
	}else{
		while(copia_pila != NULL){
			printf("%d ", copia_pila -> dato);
			copia_pila = copia_pila -> siguiente;
			i += 1;
		}
	}
	printf("\nCantidad de Datos: %d\n", i);
}

void vaciar_datos_pila(Nodo *&pila){
	while(pila != NULL){
		pila = pila -> siguiente;
	}
}

void escribir_pila_archivo(Nodo *pila){
	int i = 0, longitud_pila;
	char nombre_archivo[50];
	Nodo *copia_pila = pila;
	longitud_pila = calcular_longitud_pila(pila);
	switch(longitud_pila){
	case 1000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "1mil.txt");
		break;
	case 2000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "2mil.txt");
		break;
	case 5000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "5mil.txt");
		break;
	case 10000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "10mil.txt");
		break;
	case 20000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "20mil.txt");
		break;
	case 0: printf("No hay datos para guardar generar datos primero\n");
	break;
	default: printf("Longitud no valida\n");
	}
	printf("%s\n", nombre_archivo);
	archivo = fopen(nombre_archivo, "wt");
	if(archivo == NULL){
		printf("Error en el archivo\n");
	}else{
		while(copia_pila != NULL){
			fprintf(archivo, "%d,", copia_pila -> dato);
			copia_pila = copia_pila -> siguiente;
			i += 1;
		}
	}
	fclose(archivo);
}

void cargar_archivo_pila(Nodo *&pila, int cantidad){
	int i = 0, numero, j = 0;
	char c, cadena[10];
	char nombre_archivo[50];
	switch(cantidad){
	case 1000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "1mil.txt");
		break;
	case 2000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "2mil.txt");
		break;
	case 5000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "5mil.txt");
		break;
	case 10000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "10mil.txt");
		break;
	case 20000: 
		strcpy(nombre_archivo, direccion);
		strcat(nombre_archivo, "20mil.txt");
		break;
	case 0: printf("No hay datos para guardar generar datos primero\n");
	break;
	default: printf("Longitud no valida\n");
	}
	printf("%s\n", nombre_archivo);
	archivo = fopen(nombre_archivo, "r");
	if(archivo == NULL){
		printf("Error en el archivo\n");
	}else{
		while((c = fgetc(archivo)) != EOF){
			if(c == ','){
				numero = atoi(cadena);
				ingresar_datos_pila(pila, numero);
				i = 0;
				j += 1;
			}else{
				cadena[i] = c;
				i += 1;
			}
		}
	}
	fclose(archivo);
	printf("%d Registros insertados correctamente en la pila\n", j);
}

int calcular_longitud_pila(Nodo *pila){
	int i = 0;
	Nodo *copia_pila = pila;
	while(copia_pila != NULL){
		copia_pila = copia_pila -> siguiente;
		i += 1;
	}
	return i;
}

void buscar_dato_pila(Nodo *pila){
	int i = 0, datoBuscar;
	Nodo *copia_pila = pila;
	printf("Ingrese el numero a buscar: ");
	scanf("%d", &datoBuscar);
	printf("\n");
	if(copia_pila == NULL){
		printf("Pila Vacia\n");
		return;
	}else{
		while(copia_pila != NULL){
			if(datoBuscar == copia_pila -> dato){
				printf("Numero %d encontrado en la posicion %d\n", datoBuscar, i);
				return;
			}
			copia_pila = copia_pila -> siguiente;
			i += 1;
		}
	}
	printf("Numero %d NO encontrado, buscado en %d numeros\n", datoBuscar, i);
}

void ordenar_burbuja_pila(Nodo *&pila){
	Nodo *fila = pila;
	Nodo *columna;
	int aux;
	if(pila == NULL){
		printf("Pila Vacia\n");
		return;
	}else{
		while(fila != NULL){
			columna = fila -> siguiente;
			while(columna != NULL){
				if(fila -> dato > columna -> dato){
					aux = fila -> dato;
					fila -> dato = columna -> dato;
					columna -> dato = aux;
				}
				columna = columna -> siguiente;
			}
			fila = fila -> siguiente;
		}
		printf("Pila ordenada con exito\n");
	}
}
