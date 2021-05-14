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

#define CANTIDADCONTRIBUYENTES 50
#define CANTIDADRECAUDACION 50



/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

	estructuraContribuyente contribuyente[CANTIDADCONTRIBUYENTES];
	//estructuraRecaudacion  recaudacion[CANTIDADRECAUDACION];
	inicializarEstructuraContribuyente(contribuyente, 3);


	int respuesta = 0;
    int contadorDeLegajo = 1000;
    int seIngresoUnContribuyente= -1;
    int contadorIdRecaudaciones = 100;

		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

			case 1: //AGREGAR UN contribuyente


				agregarUnContribuyente( contribuyente, CANTIDADCONTRIBUYENTES, &contadorDeLegajo );

				break;
			case 2:  // MODIFICAR UN contribuyente

			    seIngresoUnContribuyente = buscarLibre(contribuyente, CANTIDADCONTRIBUYENTES);
				if (seIngresoUnContribuyente > 0){

					printf("\n ********  Modificar el contribuyente  ******** \n");
					modificarUnContribuyente(contribuyente, CANTIDADCONTRIBUYENTES);

				} else{

					printf("\n Error, debe de ingresar al menos un contibuyente");
				}

				break;
			case 3: // ELIMINAR UN contribuyente

				seIngresoUnContribuyente = buscarLibre(contribuyente, CANTIDADCONTRIBUYENTES);
				if (seIngresoUnContribuyente > 0){

				borrarUnContribuyente(recaudacion, CANTIDADCONTRIBUYENTES);

				} else{

					printf("\n Error, debe de ingresar al menos  un contibuyente");
				}

				break;

			case 4: //Recaudación
				//agregarRecaudacion(recaudacion, CANTIDADRECAUDACION, recaudacion, int CANTIDADCONTRIBUYENTES, contadorIdRecaudaciones)

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

					printf("\n Error, debe de ingresar al menos  un contibuyente");
				}
				break;

			case 8: // Imprimir Recaudación

				break;

			case 9:
				printf("\n **********   Usted ha salido    *********");
			break;



		}

	} while (respuesta != 5);

	return EXIT_SUCCESS;
};



