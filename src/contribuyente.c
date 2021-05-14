/*
 * contribuyente.c
 *
 *  Created on: May 13, 2021
 *      Author: andre
 */
#include "contribuyente.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarEstructuraContribuyente(estructuraContribuyente array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que está libre.
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
				break; //si encontré una posicion libre rompo el for
			};
		};
	};
	return retorno;
};



int mostrarUnContribuyente( estructuraContribuyente contribuyente){
	printf(" \n     %s      %s     %s     %d         ", contribuyente.nombre, contribuyente.apellido, contribuyente.cuil , contribuyente.idContribuyente);

	return 0;

}

int mostrarTodosLosContribuyentes(estructuraContribuyente array[], int tamano){
	int retorno = -1;

		if(array != NULL && array > 0){
			printf(" \n ****************  DATOS PERSONALES  ***************** ");
			printf("\n   NOMBRE      APELLIDO     CUIL          ID ");

			for(int i = 0; i < tamano ; i++){
				if(array[i].isEmpty == 0){

					mostrarUnContribuyente( array[i]);
				}
			}
			retorno = 0;
		}

	return retorno;

}



int agregarUnContribuyente( estructuraContribuyente   array[], int tamanoDeArray, int *contadorDeLegajo ){
	int retorno = -1;
	int posicion;
	estructuraContribuyente contriAuxiliar;

	if(array != NULL && tamanoDeArray > 0 && contadorDeLegajo != NULL)
	{
		posicion = buscarLibre(array, tamanoDeArray);
		if(posicion == -1)
		{
			printf("\n No hay espacio disponible para cargar alumnos");
		}else{

			if (
				  (utn_getString(contriAuxiliar.nombre,"\n Ingrese el nombre ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getString(contriAuxiliar.apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3) == 0) &&
			     (utn_getCuil(contriAuxiliar.cuil, "\n Ingrese su cuil con el siguiente formato xx-xxxxxxxx-x    ", "\n Error, ingrese la nota2. Entre 1 y 10", 3) == 0)
			 // (utn_getNumero(&contriAuxiliar.cuil,"\n Ingrese su cuil con el siguiente formato xx-xxxxxxxx-x", "\n Error, ingrese la nota2. Entre 1 y 10", 0, 10,3) == 0)
			)
					{
					contriAuxiliar.isEmpty = 0;
					contriAuxiliar.idContribuyente= *contadorDeLegajo;
					array[posicion] = contriAuxiliar;
					(*contadorDeLegajo)++; //Aumenta el lejago en 1, inicializado en 1000

					printf("\n *** Contribuyente guardado *** \n");
					retorno = 0;
				}
		}

	}
	return retorno;
}


int buscarLegajo(estructuraContribuyente array[], int tamanoDeArray)

{
	int retorno = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		mostrarTodosLosContribuyentes(array, tamanoDeArray);
		printf("\n Ingrese un legajo   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].idContribuyente== legajoAuxiliar ) //revisa si existe
			{
				if(array[i].isEmpty==0){ // y si está ocupado

					printf("\n El legajo '%d' ha sido encontrado  \n", legajoAuxiliar);
					retorno = i;

					break;
				}
			}
			else
			{
				retorno = -1;
				printf("El legajo  '%d' no existe \n", legajoAuxiliar);
				break;
			}
		}// fin for

	}
	return retorno;
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
		printf("\n ingrese 's' para dar de baja.");
		fflush(stdin);
		scanf("%c", &respuesta);
		if(respuesta=='s'){
			array[posicion].isEmpty = 1; // Pone el campo isEmpty array en 1, es decir que está libre.
			retorno = 0;
			printf("\n *** Contribuyente dado de baja *** \n");
		}
	}
	return retorno;
};


int modificarUnContribuyente( estructuraContribuyente   array[], int tamano){

	int retorno = -1;
	int posicion = -1;
	//char respuesta;
	int datoACambiar = 0;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL && tamano > 0 && posicion !=-1) {
	printf("\n\n ");
	fflush(stdin);

	printf("\nDesea cambiar este legajo? \n");
	printf(" ****************  DATOS PERSONALES a cambiar ***************** \n ");
	printf("        NOMBRE      APELLIDO     CUIL      ID \n");

	mostrarUnContribuyente(array[posicion]); // muestra el estudiante que quieres cambiar
	utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar apellido \n3- modificar cuil ", "\n Error, ingrese nuevamente", 1, 3, 3);


	switch (datoACambiar) {

	/* (utn_getString(contriAuxiliar.nombre,"\n Ingrese el nombre ", "\n Error intente nuevamente", 3) == 0) &&
	   (utn_getString(contriAuxiliar.apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3) == 0) &&
	   (utn_getCuil(contriAuxiliar.cuil, "\n Ingrese su cuil con el siguiente formato xx-xxxxxxxx-x    ", "\n Error, ingrese la nota2. Entre 1 y 10", 3) == 0)

	 * */
	case 1:
			utn_getString(array[posicion].nombre ,"\n Ingrese el nombre ", "\n Error intente nuevamente", 3);
			printf("\n *** Empleado cambiado *** ");
			printf("\n Estos son los datos nuevos: ");
			printf("        NOMBRE      APELLIDO     CUIL      ID \n");
			mostrarUnContribuyente(array[posicion]); // muestra el estudiante con campos nuevos;
			retorno = 0;
			break;
		case 2:
			utn_getString(array[posicion].apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3);
			printf("\n *** Empleado cambiado *** ");
			printf("\n Estos son los datos nuevos: ");
			printf("        NOMBRE      APELLIDO     CUIL      ID \n");
			mostrarUnContribuyente(array[posicion]); // muestra el estudiante con campos nuevos;
			retorno = 0;
			break;
		case 3:

			printf("\n *** Empleado cambiado *** ");
			printf("\n Estos son los datos nuevos: ");
			printf("        NOMBRE      APELLIDO     CUIL      ID \n");
			mostrarUnContribuyente(array[posicion]); // muestra el estudiante con campos nuevos;
			retorno = 0;
			break;
		default:
			break;
	}
	}


	return retorno;



}

















