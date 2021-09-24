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
#include "contribuyente.h"
#include "utn.h"
#include "recaudacion.h"
#include "validacion.h"

#define CANTIDADCONTRIBUYENTES 50
#define CANTIDADRECAUDACION 50

/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL);

	estructuraContribuyente contribuyente[CANTIDADCONTRIBUYENTES];
	estructuraRecaudacion  recaudacion[CANTIDADRECAUDACION];
	inicializarEstructuraContribuyente(contribuyente, CANTIDADCONTRIBUYENTES);
	inicializarEstructuraRecaudacion(recaudacion, CANTIDADRECAUDACION);

	int respuesta = 0;
    int contadorDeIDContribuyente = 1000;
    int contadorDeIDRecaudacion = 100;



		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

			case 1: //AGREGAR UN contribuyente
			agregarUnContribuyente( contribuyente, CANTIDADCONTRIBUYENTES, &contadorDeIDContribuyente );
				break;
			case 2:  // MODIFICAR UN contribuyente
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES) != 0){
					modificarUnContribuyente(contribuyente, CANTIDADCONTRIBUYENTES);
				} else{	printf("\n Error, debe de ingresar al menos un contibuyente");
				}

				break;
			case 3: // ELIMINAR UN contribuyente
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)!= 0){
					borrarUnContribuyenteConRecaudaciones(contribuyente, CANTIDADCONTRIBUYENTES, recaudacion, CANTIDADCONTRIBUYENTES);
				} else{	printf("\n Error, debe de ingresar al menos  un contibuyente");
				}

				break;

			case 4: //Recaudación
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)!= 0){
						agregarRecaudacion(recaudacion, CANTIDADRECAUDACION, contribuyente, CANTIDADCONTRIBUYENTES, &contadorDeIDRecaudacion);
				} else{	printf("\n Error, debe de ingresar al menos  un contribuyente");
				};
				break;

			case 5: //Refinanciar Recaudación
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)!= 0){
				 cambiarElEstadoDeRecaudacion(contribuyente, CANTIDADCONTRIBUYENTES, recaudacion, CANTIDADRECAUDACION,1);
				} else{
					printf("\n Error, debe de ingresar al menos  un contribuyente");
				};
				break;

			case 6: //Saldar Recaudación
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)!= 0){
				cambiarElEstadoDeRecaudacion(contribuyente, CANTIDADCONTRIBUYENTES, recaudacion, CANTIDADRECAUDACION,2);
				} else{	printf("\n Error, debe de ingresar al menos  un contribuyente");							};
				break;


			case 7: // MOSTRAR contribuyentes
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)){
					mostrarRecaudacionesYContibuyentes(contribuyente, CANTIDADCONTRIBUYENTES, recaudacion, CANTIDADRECAUDACION);
				} else{	printf("\n Error, debe de ingresar al menos  un contibuyente");
				}
				break;

			case 8: // Imprimir Recaudaciones
				if (estaVaciaLaEstructuraContribuyentes( contribuyente, CANTIDADCONTRIBUYENTES)){
			mostrarRecaudacionesSaldadas(contribuyente, CANTIDADCONTRIBUYENTES, recaudacion, CANTIDADRECAUDACION);
				} else{	printf("\n Error, debe de ingresar al menos  un contibuyente");
				}
				break;

			case 9:
				printf("\n **********   Usted ha salido    *********");
			break;
		}

	} while (respuesta != 9);

	return EXIT_SUCCESS;
};



