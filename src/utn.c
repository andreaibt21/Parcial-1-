/*
 * utn.c
 *
 *  Created on: May 13, 2021
 *      Author: andrea briceño
 */

#ifndef UTN_C_
#define UTN_C_
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//INICIALIZACION




int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	float auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int mostrarMenu(int *respuesta) {

	int auxRespuesta;
	printf(" \n          MENÚ ABM ");
	printf( "\n   1. Alta de Contribuyente  "
			"\n   2. Modificar el contribuyente "
			"\n   3. Baja de contribuyente "
			"\n   4. Recaudación  "
			"\n   5. Refinanciar Recaudación"
			"\n   6. Saldar Recaudación"
			"\n   7. Imprimir Contribuyentes"
			"\n   8. Imprimir Recaudación"
			"\n   9. SALIR");

	utn_getNumero(&auxRespuesta, "\n\n  Ingrese una opcion    ","\nError, ingrese una opcion del 1 al 8 \n\n", 1, 9,3);
	*respuesta = auxRespuesta;

	return 0;

};

int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[30];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 30)
			{
				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
};

int utn_getCharAceptar(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin); // SIEMPRE VA AL TOMAR CHARs
			scanf("%c", &bufferChar);

			if(bufferChar == 's' || bufferChar == 'n')
			{
				*variableChar = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;

			}
		}while(reintentos>=0);
	}
	return retorno;

}

int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[14];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{      //xx-xxxxxxxx-x
			printf("%s", mensaje);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 14){

				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;

			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
};







/*
void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos){

	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*variableChar = bufferChar;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}

*/

/*
int promediarNotas(float *promedio, int nota1, int nota2){

	int retorno = -1;
	float auxiliarpromedio;

	if (promedio != NULL){
		auxiliarpromedio = ((float)nota1 + nota2)/ 2;
		*promedio= auxiliarpromedio;
		retorno = 0;
	};
	return retorno;
}

 */

/*

int mostrarSiCargoBien(datosPersonales array[], int tamano) {
	int retorno = -1;
	if (array != NULL) {
		printf("\nDatos cargados\n");

		for (int i = 0; i < tamano; i++) {
			printf("Legajo: %d\n", array[i].legajo);
			printf("sexo: %c\n", array[i].sexo);
			printf("edad: %d\n", array[i].edad);
			printf("nota1: %d\n", array[i].nota1);
			printf("nota2: %d\n", array[i].nota2);
			printf("promedio: %.2f\n", array[i].promedio);
			printf("Apellido: %s \n", array[i].apellido);
			printf("isEmpty: %d\n", array[i].isEmpty);
			retorno = 0;
		}
	}
	return retorno;
}*/
#endif /* UTN_C_ */
