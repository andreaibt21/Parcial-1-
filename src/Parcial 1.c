/*
 ============================================================================
 Name        : Parcial.c
 Author      : ANDREA BRICEÑO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "contribuyente.h"
#include "recaudacion.h"

#define CANTIDADCONTRIBUYENTES 3



//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

	estructuraContribuyente contribuyente[CANTIDADCONTRIBUYENTES];

	inicializarEstructuraContribuyente(contribuyente, 3);


	int respuesta = 0;
    int contadorDeLegajo = 1000;
    int seIngresoUnContribuyente= -1;

		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

			case 1: //AGREGAR UN contribuyente

				agregarUnContribuyente( contribuyente, CANTIDADCONTRIBUYENTES, &contadorDeLegajo );

				break;
			case 2:  // MODIFICAR UN contribuyente

			seIngresoUnContribuyente = buscarLibre(contribuyente, CANTIDADCONTRIBUYENTES);
				if (seIngresoUnContribuyente > 0){
					//modificarAlumno(alumno, CANTIDADALUMNOS );

					printf("\n // MODIFICAR UN ALUMNO");
				} else{

					printf("\n Error, debe de ingresar al menos un empleado");
				}

				break;
			case 3: // ELIMINAR UN contribuyente

				seIngresoUnContribuyente = buscarLibre(contribuyente, CANTIDADCONTRIBUYENTES);
				if (seIngresoUnContribuyente > 0){

				borrarUnContribuyente(contribuyente, CANTIDADCONTRIBUYENTES);

				} else{

					printf("\n Error, debe de ingresar al menos un empleado");
				}

				break;

			case 4: //Recaudación
				break;

			case 5: //Refinanciar Recaudación
						break;

			case 6: //Saldar Recaudación
			  break;



			case 7: // MOSTRAR contribuyentes

				seIngresoUnContribuyente = buscarLibre(contribuyente, CANTIDADCONTRIBUYENTES);
				if (seIngresoUnContribuyente > 0){
				mostrarTodosLosContribuyentes(contribuyente, CANTIDADCONTRIBUYENTES);

				} else{

					printf("\n Error, debe de ingresar al menos un empleado");
				}
				break;

			case 8: // Imprimir Recaudación
				break;

			case 9:

			break;



		}

	} while (respuesta != 5);

	return EXIT_SUCCESS;
};







// INGRESO - ALTA


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



//3-Listar
