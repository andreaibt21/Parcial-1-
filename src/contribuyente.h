/*
 * contribuyente.h
 *
 *  Created on: May 13, 2021
 *      Author: andre
 */


#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


	typedef struct {
	char  nombre[50];
	char	apellido[50];
	char	cuil[15];
	int	idContribuyente;
	int	isEmpty;

	}estructuraContribuyente;


	int inicializarEstructuraContribuyente(estructuraContribuyente array[], int tamano);

	int buscarLibre(estructuraContribuyente array[], int tamano);

	int mostrarUnContribuyente( estructuraContribuyente unEmpleado);

	int mostrarTodosLosContribuyentes(estructuraContribuyente array[], int tamano);

	int agregarUnContribuyente( estructuraContribuyente   array[], int tamanoDeArray, int *contadorDeLegajo );

	int modificarUnContribuyente( estructuraContribuyente   array[], int tamano);

	int buscarLegajo(estructuraContribuyente array[], int tamanoDeArray);

	int borrarUnContribuyente(estructuraContribuyente array[], int tamano);




#endif /* CONTRIBUYENTE_H_ */
