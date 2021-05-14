/*
 * recaudacion.c
 *
 *  Created on: May 13, 2021
 *     Author: andrea briceño
 */

#include "contribuyente.h"
#include "recaudacion.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct {
	int	idContribuyente;
	int	mes;
	int	tipo ;
	float importe;
	int	idRecaudacion ;
	int	isEmpty;

} estructuraRecaudacion;
*/



int agregarRecaudacion(estructuraRecaudacion arrayReca[], int cantidadReca, estructuraContribuyente arrayContri[], int cantidadContri, int* contadorIdRecaudaciones)
{
	int retorno = -1;
	estructuraRecaudacion recaudacionAuxiliar;
	int posicion;
	int auxI;
	char descripcion[20];

	if(arrayReca!=NULL && cantidadReca>0 && arrayContri!=NULL && cantidadContri>0)
	{
		posicion=buscaLibreRecaudacion(arrayReca, cantidadReca);

		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaContribuyenteById(arrayContri, cantidadContri, &auxI)!=-1)
			{
				if(

				(utn_getNumero(&recaudacionAuxiliar.tipo, "Ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS", "Error, ingrese nuevamente",1,3,2)==0)&&
				(utn_getNumero(&recaudacionAuxiliar.mes, "Ingrese MES", "Error, ingrese nuevamente",1,12,2)==0)&&
				(utn_getFloat(&recaudacionAuxiliar.importe, "Ingrese el importe","Error, ingrese nuevamente", 100, 1000, 2)==0)

				)
				{
					recaudacionAuxiliar.idContribuyente=auxI;
					recaudacionAuxiliar.idRecaudacion=0;
					printf("Estos son los datos, desea continuar:");
							imprimir1Recaudacion(recaudacionAuxiliar, descripcion);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorIdRecaudaciones)++;
					   recaudacionAuxiliar.idRecaudacion=*contadorIdRecaudaciones;
					   recaudacionAuxiliar.isEmpty=0;
					   arrayReca[posicion]=recaudacionAuxiliar;
					   imprimir1Recaudacion(recaudacionAuxiliar, descripcion);
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}
