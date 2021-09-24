/*
 * recaudacion.c
 *
 *  Created on: May 13, 2021
 *     Author: andrea briceño
 */

#include "contribuyente.h"
#include "recaudacion.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int agregarRecaudacion( estructuraRecaudacion arrayRecaudacion[], int TAMrecaudacion, estructuraContribuyente arrayContribuyente[], int TAMContribuyente, int *contadorDeIDRecaudacion){
	int retorno = -1;
	int posicionDeContribuyente;
	int mesAuxiliar;
	int tipoAuxiliar;
	float importeAuxiliar;
	mostrarTodosLosContribuyentes(arrayContribuyente, TAMContribuyente);
	int posicionRecaudacion = buscarLibreEnRecaudacion(arrayRecaudacion, TAMrecaudacion);

	if(arrayRecaudacion != NULL && TAMrecaudacion > 0 && contadorDeIDRecaudacion != NULL &&  arrayContribuyente != NULL && TAMContribuyente > 0 ){
		posicionDeContribuyente = buscarLegajo(arrayContribuyente, TAMContribuyente);

		if((estaVaciaLaEstructuraContribuyentes(arrayContribuyente, TAMContribuyente) != 0) && (posicionDeContribuyente != -1) ){ //devuelve la cantidad de contri que hay
			if( posicionRecaudacion != -1 ){

				if(     (utn_getNumero(&mesAuxiliar, "\n Ingrese el mes de la recaudacion, (Valor numerico del mes )", "\n Error, intente nuevamente ", 1, 12, 3) == 0 ) &&
						(utn_getNumero(&tipoAuxiliar, "\n Ingrese el tipo de recaudacion (1-ARBA, 2-IIBB, 3-GANANCIAS)", "\n Error, intente nuevamente ", 1, 3, 3) == 0 ) &&
						(utn_getFloat(&importeAuxiliar, "\n Ingrese el importe a pagar ", "\n Error, intente nuevamente ", 1, 30000, 3) == 0 )
						){

		           estructuraRecaudacion recaudacionAuxiliar;
				   recaudacionAuxiliar.idContribuyente =  arrayContribuyente[posicionDeContribuyente].idContribuyente;
				   recaudacionAuxiliar.mes = mesAuxiliar;
				   recaudacionAuxiliar.importe = importeAuxiliar;
				   recaudacionAuxiliar.tipo = tipoAuxiliar;
				   recaudacionAuxiliar.idRecaudacion=*contadorDeIDRecaudacion;
				   recaudacionAuxiliar.isEmpty = 0;
				   recaudacionAuxiliar.estado = 0 ;
				   arrayRecaudacion[posicionRecaudacion] = recaudacionAuxiliar;
				   (*contadorDeIDRecaudacion)++;
				   printf("\n *** La recaudación se ha guardado *** \n");
				   retorno = 0;

				}

			};
		}else{

			printf("\n Error, intente nuevamente");
		};

	}





	return retorno;
}

int buscarLibreRecaudacion(estructuraRecaudacion array[], int tamanoDeArray) {
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

int inicializarEstructuraRecaudacion(estructuraRecaudacion array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
};

int buscarLibreEnRecaudacion(estructuraRecaudacion array[], int tamanoDeArray) {
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

void obtenerMes(int numeroDeMes, char nombreDeMes[]){


	if(numeroDeMes == 1	){
		strcpy(nombreDeMes,"Enero");
		}
	if(numeroDeMes == 2	){
		strcpy(nombreDeMes,"Febrero");
		}
	if(numeroDeMes == 3	){
		strcpy(nombreDeMes,"Marzo");
		}
	if(numeroDeMes == 4){
		strcpy(nombreDeMes,"Abril");
		}
	if(numeroDeMes == 5	){
		strcpy(nombreDeMes,"Mayo");
		}
	if(numeroDeMes == 6	){
		strcpy(nombreDeMes,"Junio");
		}
	if(numeroDeMes == 7	){
		strcpy(nombreDeMes,"Julio");
		}
	if(numeroDeMes == 8	){
		strcpy(nombreDeMes,"Agosto");
		}
	if(numeroDeMes == 9	){
		strcpy(nombreDeMes,"Septiempre");
		}
	if(numeroDeMes == 10){
		strcpy(nombreDeMes,"Octubre");
		}
	if(numeroDeMes == 11 ){
		strcpy(nombreDeMes,"Noviembre");
		}
	if(numeroDeMes == 12 ){
		strcpy(nombreDeMes,"Diciembre");
		}
};

void obtenertipo(int numeroDeTipo, char nombreDeTipo[]){

	if(numeroDeTipo == 1	){
		strcpy(nombreDeTipo,"ARBA");
		}
	if(numeroDeTipo == 2	){
		strcpy(nombreDeTipo,"IIBB");
		}
	if(numeroDeTipo == 3	){
		strcpy(nombreDeTipo,"GANANCIAS");
		}
}

void obtenerEstado(int numeroDeEstado, char nombreDeEstado[]){

	if(numeroDeEstado == 0	){
		strcpy(nombreDeEstado,"Pendiente");
		}
	if(numeroDeEstado == 1	){
		strcpy(nombreDeEstado,"Refinanciar");
		}
	if(numeroDeEstado == 2	){
		strcpy(nombreDeEstado,"Saldada");
		}
}

void mostrarUnaRecaudacion( estructuraRecaudacion recaudacion){
	char nombreDeMes[15];
	char nombreDeTipo[10];
	char nombreDeEstado[15];

	obtenerMes(recaudacion.mes, nombreDeMes);
	obtenertipo(recaudacion.tipo, nombreDeTipo);
	obtenerEstado(recaudacion.estado, nombreDeEstado);

	printf(" \n     %-8d      %-8s     %-8s     %-8s    %-8.2f     %-8d  ",
			recaudacion.idRecaudacion,
			nombreDeMes,
			nombreDeTipo,
			nombreDeEstado,
			recaudacion.importe,
			recaudacion.idContribuyente);


};

void mostrarTodosLasRecaudaciones(estructuraRecaudacion *array, int tamano){
		if(array != NULL && tamano > 0){
			printf(" \n         ****************  DATOS PERSONALES  ***************** ");
			printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE ");

			for(int i = 0; i < tamano ; i++){

				if(array[i].isEmpty == 0){
					mostrarUnaRecaudacion( array[i]);
				}
			}

		}
};

int buscarUnIDDeRecaudacion(estructuraRecaudacion array[], int tamanoDeArray)
{
	int retorno = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		printf("\n Ingrese un ID de recaudación   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].idRecaudacion==legajoAuxiliar && array[i].isEmpty==0){ // revisa si existe y si está ocupado

				printf("\n El id '%d' ha sido encontrado  \n", legajoAuxiliar);
				retorno = i;
				break;
			};


		}// fin for

	}
	return retorno;
};

int borrarUnContribuyenteConRecaudaciones(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion) {

	int retorno = -1;
	int posicion = -1;
	char respuesta;
	printf("\n          **********   Sector de baja   **********  \n" );

	mostrarTodosLosContribuyentes(arrayContribuyente, tamanoContribuyente);
	posicion = buscarLegajo(arrayContribuyente, tamanoContribuyente);

	if ((arrayContribuyente != NULL) && (tamanoContribuyente > 0 ) && (posicion !=-1) && (arrayRecaudacion != NULL) && (tamanoRecaudacion > 0)) {
		for(int i = 0; i< tamanoContribuyente; i ++ )
		{
			if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[posicion].idContribuyente){
				printf("\nDesea borrar este legajo? \n");
				printf("\n ****************  DATOS PERSONALES   *****************  ");
				printf("\n   NOMBRE      APELLIDO     CUIL          ID ");
				mostrarUnContribuyente( arrayContribuyente[posicion]);
				printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE ");

				mostrarUnaRecaudacion(arrayRecaudacion[i]);
			}

		};


		utn_getSoN(&respuesta, "\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);

		if(respuesta=='s'){

			arrayContribuyente[posicion].isEmpty = 1;

			for(int i = 0; i< tamanoContribuyente; i ++ ){
				if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[posicion].idContribuyente){
			arrayRecaudacion[i].isEmpty = 1;
			}};
			retorno = 0;
			printf("\n     *** Contribuyente dado de baja *** \n");
		}
	}
	return retorno;
};


int cambiarElEstadoDeRecaudacion(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion, int tipo){
	int retorno = -1;
	int posicion = -1;
	char respuesta;
		printf("\n          **********   Sector de Refinanciación   **********  \n" );
		mostrarTodosLasRecaudaciones(arrayRecaudacion, tamanoRecaudacion);
		posicion = buscarUnIDDeRecaudacion(arrayRecaudacion, tamanoRecaudacion);

	if ((arrayContribuyente != NULL) && (tamanoContribuyente > 0 ) && (posicion !=-1) && (arrayRecaudacion != NULL) && (tamanoRecaudacion > 0)) {
		if(posicion != -1){
			for(int i = 0; i < tamanoContribuyente; i++){
				if (arrayRecaudacion[i].idContribuyente == arrayContribuyente[posicion].idContribuyente){
					printf("\n ****************  DATOS PERSONALES   *****************  ");
					printf("\n   NOMBRE      APELLIDO     CUIL          ID ");
					if(arrayContribuyente[posicion].isEmpty == 0){
						mostrarUnContribuyente(arrayContribuyente[i]);
					};
					if(arrayRecaudacion[i].isEmpty == 0){
						printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE ");
						mostrarUnaRecaudacion(arrayRecaudacion[i]);
					};
				};
			}
			utn_getSoN(&respuesta, "\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);
			if(respuesta == 's'){
				if(tipo ==1){
					arrayRecaudacion[posicion].estado = 1;
					printf("\n   **** Recaudación refinanciada   ****" );
				}
				if(tipo == 2){
					arrayRecaudacion[posicion].estado = 2;
					printf("\n   **** Recaudación saldada   ****" );

				}
				retorno = 0;

			}
		}
	}else{
		printf("\n Error, intente nuevamente" );
	};


	return retorno;
};


void mostrarRecaudacionesYContibuyentes(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion){


	for(int i = 0; i < tamanoContribuyente; i++){
		if(arrayContribuyente[i].isEmpty == 0){
			printf("\n ****************  DATOS PERSONALES   *****************  ");
			printf("\n   NOMBRE      APELLIDO     CUIL          ID ");
			mostrarUnContribuyente(arrayContribuyente[i]);

				for(int j= 0; j < tamanoRecaudacion; j++){


					if ((arrayRecaudacion[j].idContribuyente == arrayContribuyente[i].idContribuyente) &&
							(arrayRecaudacion[j].isEmpty == 0)){
								printf("\n    Recaudaciones:  ");
								printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE ");

								mostrarUnaRecaudacion(arrayRecaudacion[j]);

					};

				};
		};
	};


};


void mostrarRecaudacionesSaldadas(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion){

	if((arrayContribuyente != NULL) && (tamanoContribuyente > 0 ) && (arrayRecaudacion != NULL) && (tamanoRecaudacion > 0))
	{

	};
	if(arrayRecaudacion != NULL && tamanoRecaudacion > 0){

			for(int i = 0; i < tamanoRecaudacion ; i++){

				if(arrayRecaudacion[i].isEmpty == 0 && arrayRecaudacion[i].estado == 2){
			printf(" \n         ****************  DATOS PERSONALES  ***************** ");
			printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE    NOMBRE");

					for(int j= 0; j < tamanoRecaudacion; j++){
									if ((arrayRecaudacion[j].idContribuyente == arrayContribuyente[i].idContribuyente) &&
											(arrayRecaudacion[j].isEmpty == 0)){

												mostrarUnaRecaudacion(arrayRecaudacion[j]);
												printf("      %s", arrayContribuyente[i].nombre);

									}else{
										printf("No hay recaudaciones saldadas");
										break;
									}

								};

				}
			}

		}



};












