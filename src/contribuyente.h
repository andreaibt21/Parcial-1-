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
	char  apellido[50];
	char  cuil[15];
	int	idContribuyente;
	int	isEmpty;

	}estructuraContribuyente;

	/**
	 * \brief inicializa la Estructura Contribuyente en 1;
	 * \param array estructura que se va a inicializar
	 * \param tamano longitud del array
	 * \return -1 si hubo un error, 0 si no hubo error
	 */

	int inicializarEstructuraContribuyente(estructuraContribuyente array[], int tamano);

	/**
	 * \brief busca una posicion libre en el array de estructuras
	 * \param array estructura en donde se va a buscar la posicion
	 * \param tamano longitud del array
	 * \return retorna la posicion libre encontrada
	 */
	int buscarLibre(estructuraContribuyente array[], int tamano);
	/**
	 * \brief Muestra uncontribuyente de la Estructura Contribuyente
	 * \param contribuyente estructura que se a usar
	 * \return void

	 */
	void mostrarUnContribuyente(  estructuraContribuyente contribuyente);

	void mostrarTodosLosContribuyentes(estructuraContribuyente array[], int tamano);

	int agregarUnContribuyente( estructuraContribuyente   array[], int tamanoDeArray, int *contadorDeLegajo );

	int buscarLegajo(estructuraContribuyente array[], int tamanoDeArray);

	int borrarUnContribuyente(estructuraContribuyente array[], int tamano);

	int modificarUnContribuyente( estructuraContribuyente   array[], int tamano);

	int estaVaciaLaEstructuraContribuyentes( estructuraContribuyente   array[], int tamanoDeArray);




#endif /* CONTRIBUYENTE_H_ */
