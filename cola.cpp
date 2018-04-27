#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

FILE *archivo;
char direccion[] = "C:\\Users\\Adrian Vargas\\Desktop\\colas\\";

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu(Nodo *&, Nodo *&);
void menu_aleatorios(Nodo *&, Nodo *&);
void menu_leer_archivo(Nodo *&, Nodo *&);
void menu_ordenar(Nodo *&, Nodo *&);
void generar_aleatorios(Nodo *&, Nodo *&, int);
void ingresar_datos_cola(Nodo *&, int);
void mostrar_datos_cola(Nodo *);
void vaciar_datos_cola(Nodo *&);
void ingresar_datos_cola(Nodo *&, Nodo *&, int);
void mostrar_datos_cola();
void escribir_cola_archivo(Nodo *);
void cargar_archivo_cola(Nodo *&, Nodo *&, int);
void buscar_dato_cola(Nodo *);
void ordenar_burbuja_cola(Nodo *&);
int calcular_longitud_cola(Nodo *);

int main(){
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	menu(inicio, fin);
	return 0;
}

void menu(Nodo *&inicio, Nodo *&fin){
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
		case 1: menu_aleatorios(inicio, fin);
		break;
		case 2: menu_leer_archivo(inicio, fin);
		break;
		case 3: escribir_cola_archivo(inicio);
		break;
		case 4: menu_ordenar(inicio, fin);
		break;
		case 5: mostrar_datos_cola(inicio);
		break;
		case 6: buscar_dato_cola(inicio);
		break;
		case 7: escribir_cola_archivo(inicio);
		break;
		case 0: exit(0);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_aleatorios(Nodo *&inicio, Nodo *&fin){
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
		case 1: generar_aleatorios(inicio, fin, 1000);
		break;
		case 2: generar_aleatorios(inicio, fin, 2000);
		break;
		case 3: generar_aleatorios(inicio, fin, 5000);
		break;
		case 4: generar_aleatorios(inicio, fin, 10000);
		break;
		case 5: generar_aleatorios(inicio, fin, 20000);
		break;
		case 6: mostrar_datos_cola(inicio);
		break;
		case 0: menu(inicio, fin);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_leer_archivo(Nodo *&inicio, Nodo *&fin){
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
		case 1: cargar_archivo_cola(inicio, fin, 1000);
		break;
		case 2: cargar_archivo_cola(inicio, fin, 2000);
		break;
		case 3: cargar_archivo_cola(inicio, fin, 5000);
		break;
		case 4: cargar_archivo_cola(inicio, fin, 10000);
		break;
		case 5: cargar_archivo_cola(inicio, fin, 20000);
		break;
		case 0: menu(inicio, fin);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void menu_ordenar(Nodo *&inicio, Nodo *&fin){
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
		case 1: ordenar_burbuja_cola(inicio);
		break;
		case 2: ordenar_burbuja_cola(inicio);
		break;
		case 0: menu(inicio, fin);
		break;
		default: printf("opcion no validad\n");
		}
	}while(opcion != 0);
}

void generar_aleatorios(Nodo *&inicio, Nodo *&fin, int longitud){
	vaciar_datos_cola(inicio);
	int i, n;
	srand(time(NULL));
	for(i = 0; i < longitud; i++){
		//n = rand() % 1999999 - 999999;
		n = rand() % 60001 - 30000;
		ingresar_datos_cola(inicio, fin, n);
	}
	printf("\nDatos Generados: %d \n", i);
}

void ingresar_datos_cola(Nodo *&inicio, Nodo *&fin, int n){
	Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(inicio != NULL){
		fin -> siguiente = nuevo_nodo;
	}else{
		inicio = nuevo_nodo;
	}
	fin = nuevo_nodo;
	//printf("Dato insertado %d\n", n);
}

void mostrar_datos_cola(Nodo *inicio){
	int i = 0;
	printf("Datos en la Cola\n");
	Nodo *copia_cola = inicio;
	if(copia_cola == NULL){
		printf("Cola Vacia\n");
	}else{
		while(copia_cola != NULL){
			printf("%d ", copia_cola -> dato);
			copia_cola = copia_cola -> siguiente;
			i += 1;
		}
	}
	printf("\nCantidad de Datos: %d\n", i);
}

void vaciar_datos_cola(Nodo *&inicio){
	while(inicio != NULL){
		inicio = inicio -> siguiente;
	}
}

void escribir_cola_archivo(Nodo *inicio){
	int i = 0, longitud_cola;
	char nombre_archivo[50];
	Nodo *copia_cola = inicio;
	longitud_cola = calcular_longitud_cola(inicio);
	switch(longitud_cola){
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
		while(copia_cola != NULL){
			fprintf(archivo, "%d,", copia_cola -> dato);
			copia_cola = copia_cola -> siguiente;
			i += 1;
		}
	}
	fclose(archivo);
}

void cargar_archivo_cola(Nodo *&inicio, Nodo *&fin, int cantidad){
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
				ingresar_datos_cola(inicio, fin, numero);
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

int calcular_longitud_cola(Nodo *cola){
	int i = 0;
	Nodo *copia_cola = cola;
	while(copia_cola != NULL){
		copia_cola = copia_cola -> siguiente;
		i += 1;
	}
	return i;
}

void buscar_dato_cola(Nodo *inicio){
	int i = 0, datoBuscar;
	Nodo *copia_cola = inicio;
	printf("Ingrese el numero a buscar: ");
	scanf("%d", &datoBuscar);
	printf("\n");
	if(copia_cola == NULL){
		printf("Pila Vacia\n");
		return;
	}else{
		while(copia_cola != NULL){
			if(datoBuscar == copia_cola -> dato){
				printf("Numero %d encontrado en la posicion %d\n", datoBuscar, i);
				return;
			}
			copia_cola = copia_cola -> siguiente;
			i += 1;
		}
	}
	printf("Numero %d NO encontrado, buscado en %d numeros\n", datoBuscar, i);
}

void ordenar_burbuja_cola(Nodo *&inicio){
	Nodo *fila = inicio;
	Nodo *columna;
	int aux;
	if(inicio == NULL){
		printf("Cola Vacia\n");
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
		printf("Cola ordenada con exito\n");
	}
}

