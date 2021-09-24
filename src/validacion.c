/*
 * validacion.c
 *
 *  Created on: May 15, 2021
 *      Author: andre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


  int esString ( char string[]){

	int retorno = 0;
	if (string != NULL)	{
		for (int i = 0;  i < strlen(string); i++) {
			if (isalpha(string[i])==0){
				retorno = 1;
				break;
			}}

	}
	return retorno;
};
