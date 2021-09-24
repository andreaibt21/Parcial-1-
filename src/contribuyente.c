/*
 * contribuyente.c
 *
 *  Created on: May 13, 2021
 *      Author: andre
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
#include "UTN.h"

int inicializarEstructuraContribuyente(estructuraContribuyente array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
};

int buscarLibre(estructuraContribuyente array[], int tamanoDeArray) {
	int retorno = -1;

	if (array != NULL) {
		for (int i = 0; i < tamanoDeArray; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break;
			};
		};
	};
	return retorno;
};

void mostrarUnContribuyente( estructuraContribuyente contribuyente){

	printf(" \n     %-8s      %-8s     %-8s     %-8d  ", contribuyente.nombre, contribuyente.apellido, contribuyente.cuil , contribuyente.idContribuyente);


}

void mostrarTodosLosContribuyentes(estructuraContribuyente *array, int tamano){


		if(array != NULL && tamano > 0){
			printf(" \n ****************  DATOS PERSONALES  ***************** ");
			printf("\n   NOMBRE      APELLIDO     CUIL          ID ");

			for(int i = 0; i < tamano ; i++){

				if(array[i].isEmpty == 0){
					mostrarUnContribuyente( array[i]);



				}
			}

		}



}

int agregarUnContribuyente( estructuraContribuyente   array[], int tamanoDeArray, int *contadorDeIDRecaudacion ){
	int retorno = -1;
	int posicion;
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	char cuilAuxiliar[14];


	if(array != NULL && tamanoDeArray > 0 && contadorDeIDRecaudacion != NULL)
	{
		posicion = buscarLibre(array, tamanoDeArray);
		if(posicion == -1)
		{
			printf("\n No hay espacio disponible para cargar contribuyentes");
		}else{

			if (
				  (utn_getString(nombreAuxiliar,"\n Ingrese el nombre   ", "\n Error intente nuevamente   ", 3) == 0) &&
				  (utn_getString(apellidoAuxiliar,"\n Ingrese el apellido   ", "\n Error intente nuevamente   ", 3) == 0) &&
			      (utn_getCuil(cuilAuxiliar, "\n Ingrese su cuil con el siguiente formato xx-xxxxxxxx-x   ", "\n Error intente nuevamente", 3) == 0)

			)
					{
				    estructuraContribuyente contriAuxiliar;
				    strcpy(contriAuxiliar.nombre, nombreAuxiliar);
				    strcpy(contriAuxiliar.apellido, apellidoAuxiliar);
				    strcpy(contriAuxiliar.cuil, cuilAuxiliar);

					contriAuxiliar.isEmpty = 0;
					contriAuxiliar.idContribuyente= *contadorDeIDRecaudacion;
					array[posicion] = contriAuxiliar;
					(*contadorDeIDRecaudacion)++;
					printf("\n *** Contribuyente guardado *** \n");
					retorno = 0;
				} else{
					printf("\n *** El Contribuyente no pudo ser guardado *** \n");
				};

		};

	};
	return retorno;
};

int buscarLegajo(estructuraContribuyente array[], int tamanoDeArray)

{
	int legajoAbuscar = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		printf("\n Ingrese un ID de Contribuyente   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++)
		{
			if(array[i].idContribuyente==legajoAuxiliar && array[i].isEmpty==0){

				legajoAbuscar = i;
				break;
			};
		}// fin for
			if( legajoAbuscar == -1)
			{
				printf("\n Error,  El ID '%d' no existe  \n", legajoAuxiliar);

			};


	}
	return legajoAbuscar;
}

int borrarUnContribuyente(estructuraContribuyente array[], int tamano) {

	int retorno = -1;
	int posicion = -1;
	char respuesta;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL && tamano > 0 && posicion !=-1) {

		printf("\nDesea borrar este legajo? \n");
		printf("\n ****************  DATOS PERSONALES   *****************  ");
		printf("\n   NOMBRE      APELLIDO     CUIL          ID ");
		mostrarUnContribuyente( array[posicion]);

		utn_getSoN(&respuesta, "\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);

		if(respuesta=='s'){
			array[posicion].isEmpty = 1;
			retorno = 0;
			printf("\n     *** Contribuyente dado de baja *** \n");
		}
	}
	return retorno;
};

int modificarUnContribuyente( estructuraContribuyente   array[], int tamano){

	int retorno = -1;
	int posicion ;
	char respuesta;
	int datoACambiar = 0;

	if (array != NULL && tamano > 0 ) {
	printf("\n      ********  Modificar contribuyentes  ******** \n");
	mostrarTodosLosContribuyentes(array, tamano);
	posicion = buscarLegajo(array, tamano);
	printf("\n\n ");
	fflush(stdin);
	if(posicion != -1){
		printf("\nDesea cambiar este legajo? \n");
		printf(" ****************  DATOS PERSONALES a cambiar ***************** \n ");
		printf("        NOMBRE      APELLIDO     CUIL      ID ");

		mostrarUnContribuyente(array[posicion]);
		utn_getSoN(&respuesta, "\n\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);
		if (respuesta == 's'){

			utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar apellido \n3- modificar cuil ", "\n Error, ingrese nuevamente", 1, 3, 3);
			switch (datoACambiar) {

			case 1:
					utn_getString(array[posicion].nombre ,"\n Ingrese el nombre ", "\n Error intente nuevamente", 3);
					printf("\n *** Empleado cambiado *** ");
					printf("\n Estos son los datos nuevos: ");
					printf(" \n        NOMBRE      APELLIDO     CUIL      ID");
					mostrarUnContribuyente( array[posicion]);
					retorno = 0;
					break;
				case 2:
					utn_getString(array[posicion].apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3);
					printf("\n *** Empleado cambiado *** ");
					printf("\n Estos son los datos nuevos: ");
					printf(" \n        NOMBRE      APELLIDO     CUIL      ID ");
					mostrarUnContribuyente( array[posicion]);
					retorno = 0;
					break;
				case 3:

					printf("\n *** Empleado cambiado *** ");
					printf("\n Estos son los datos nuevos: ");
					printf(" \n       NOMBRE      APELLIDO     CUIL      ID ");
					utn_getCuil(array[posicion].cuil, "\n Ingrese su cuil con el siguiente formato xx-xxxxxxxx-x    ", "\n Error intente nuevamente", 3);
					mostrarUnContribuyente( array[posicion]);
					retorno = 0;
					break;
				default:
					break;
				}//fin switch
			}//fin if
		}

	}
	return retorno;



}

int estaVaciaLaEstructuraContribuyentes( estructuraContribuyente   array[], int tamanoDeArray){

	int contador = 0;
	if(array!=NULL && tamanoDeArray>0)
	{
		for(int i=0; i<tamanoDeArray; i++)
		{
				if(array[i].isEmpty==0){

					contador++;
			}
		}// fin for
	}
	return contador;
};















