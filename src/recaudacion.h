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
	int	isEmpty;
} estructuraRecaudacion;

int agregarRecaudacion(estructuraRecaudacion arrayReca[], int cantidadReca, estructuraContribuyente arrayContri[], int cantidadContri, int* contadorIdRecaudaciones);



#endif /* RECAUDACION_H_ */
