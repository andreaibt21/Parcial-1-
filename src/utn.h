/*
 * utn.h
 *
 *  Created on: May 13, 2021
 *      Author: andrea briceño
 */


#ifndef UTN_H_
#define UTN_H_



int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int mostrarMenu(int *respuesta);

int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);

int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);

int utn_getCharAceptar(char *variableChar, char *mensaje, char *mensajeError, int reintentos);

int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos);


//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

#endif /* UTN_H_ */
