/*
 * recaudacion.h
 *
 *  Created on: May 13, 2021
 *     Author: andrea briceño
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	int	idContribuyente;
	int	mes;
	int	tipo ;
	float importe;
	int	idRecaudacion ;
	int estado;
	int	isEmpty;
} estructuraRecaudacion;

/**
 * \brief Agrega una recaudacion al array de estructura arrayRecaudacion
 * \param arrayRecaudacion estructura en donde se va a buscar la posicion
 * \param TAMrecaudacion longitud del array de recaudacion
 * \param arrayContribuyente
 * \param TAMContribuyente longitud del arrayd de contribuyente
 * \param contadorDeIDRecaudacion contador de id de recaudaciones
 * \return -1 si hubo un error, 0 si no hubo error
 */
int agregarRecaudacion( estructuraRecaudacion arrayRecaudacion[], int TAMrecaudacion, estructuraContribuyente arrayContribuyente[], int TAMContribuyente, int *contadorDeIDRecaudacion);

/**
 * \brief busca una posicion libre en el array de estructuras
 * \param array estructura en donde se va a buscar la posicion
 * \param tamano longitud del array
 * \return retorna la posicion libre encontrada
 */
int buscarLibreEnRecaudacion( estructuraRecaudacion array[], int tamano);

/**
 * \brief inicializa la Estructura recaudacion en 1;
 * \param array estructura que se va a inicializar
 * \param tamano longitud del array
 * \return -1 si hubo un error, 0 si no hubo error
 */
int inicializarEstructuraRecaudacion( estructuraRecaudacion array[], int tamano);

/**
 * \brief Muestra uncontribuyente de la Estructura Contribuyente
 * \param contribuyente estructura que se a usar
 * \return void

 */
void mostrarUnaRecaudacion( estructuraRecaudacion recaudacion);


/**
 * \brief Muestra los uncontribuyentes de la Estructura Contribuyente
 * \param contribuyente estructura que se a usar
 * \return void
 */
void mostrarTodosLasRecaudaciones( estructuraRecaudacion array[], int tamano);

/**
 * \brief Obtienes el mes pasado por parametro
 * \param numeroDeMes se ingresa el numero del mes
 * \param nombreDeMes puntero del mes
 * \return void
 */
void obtenerMes(int numeroDeMes, char nombreDeMes[]);

/**
 * \brief Obtienes el tipo de recaudacion
 * \param numeroDeTipo se ingresa el numero del tipo
 * \param  nombreDeTipo puntero del tipo
 * \return void
 */
void obtenertipo(int numeroDeTipo, char nombreDeTipo[]);

/**
 * \brief Obtienes el estado de recaudacion
 * \param numeroDeEstado se ingresa el numero del estado
 * \param  nombreDeTipo puntero del Estado
 * \return void
 */
void obtenerEstado(int numeroDeEstado, char nombreDeEstado[]);

/**
 * \brief Busca el id de la recaudacion ingresada
 * \param array estructura en donde se va a buscar el id
 * \param tamanoDeArray longitud del array
 * \return -1 si hubo un error, 0 si no hubo error
 */
int buscarUnIDDeRecaudacion( estructuraRecaudacion array[], int tamanoDeArray);


/**
 * \brief Libera el espacio de una contribucion con sus respectivas recaudaciones del array, pone isEmpty en 1
 * \param arrayContribuyente estructura del contribuyente a dar de baja
 * \param tamanoContribuyente longitud del array de contri
 * \param arraytamanoRecaudacion estructura de la recaudacion a dar de baja
 * \param tamanoRecaudacion longitud del array de recaudaciones
 * \return -1 si hubo un error, 0 si no hubo error
 */
int borrarUnContribuyenteConRecaudaciones(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion);



/**
 * \brief Cambia el estado de una recaudacion a saldada o refinada
 * \param arrayContribuyente estructura del contribuyente a cambiar
 * \param tamanoContribuyente longitud del array de contribuyente a cambiar
 * \param arraytamanoRecaudacion estructura de la recaudacion a cambiar
 * \param tamanoRecaudacion longitud del array de recaudacionesa cambiar
 * \param tipo Tipo de estado a cambiar
 * \return -1 si hubo un error, 0 si no hubo error
 */
int cambiarElEstadoDeRecaudacion(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion, int tipo);
/**
 * \brief Muestra los contribuyentes y sus recaudaciones
 * \param arrayContribuyente estructura del contribuyente
 * \param tamanoContribuyente longitud del array de contribuyente
 * \param arraytamanoRecaudacion estructura de la recaudacion
 * \param tamanoRecaudacion longitud del array de recaudacionesa
 * \return void
 */
void mostrarRecaudacionesYContibuyentes(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion);
/**
 * \brief Muestra las recaudaciones saldadas con el nombre del contribuidor
 * \param arrayContribuyente estructura del contribuyente
 * \param tamanoContribuyente longitud del array de contribuyente
 * \param arraytamanoRecaudacion estructura de la recaudacion
 * \param tamanoRecaudacion longitud del array de recaudacionesa
 * \return void
 */
void mostrarRecaudacionesSaldadas(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion);

#endif /* RECAUDACION_H_ */
