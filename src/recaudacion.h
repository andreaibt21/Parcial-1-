/*
 * recaudacion.h
 *
 *  Created on: May 13, 2021
 *     Author: andrea brice�o
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
	int	idrecaudacion ;
	int	isEmpty;
} estructuraRecaudacion;





#endif /* RECAUDACION_H_ */
