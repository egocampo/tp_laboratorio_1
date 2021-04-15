/*
 * utn.
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "matematicas.h"

//-------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////
/////            * ENTEROS *             /////
//////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------
// INGRESO DE DATOS
/*
 * \brief Pide un numero como texto, valida con reintentos
 * \param int* pResult Puntero a la dirección donde almacenar el valor numerico si pasa la validacion
 * \param char* pText Texto de mensaje previo al ingreso
 * \param char* pTextError Texto de error
 * \param int min Minimo valor a recibir
 * \param int max Maximo valor a recibir
 * \param int qtyRetry Cantidad de reintentos ante ingreso erroneo
 * \return -2 error de validacion, -1 error al tomar el dato, 0 sin errores.
 * */
int utn_getNumber(int* pResult, char* pText, char* pTextError, int min, int max, int qtyRetry)
{
	int bufferInt;
	int returnFunction = -2;
	if(pResult != NULL && pText != NULL && pTextError != NULL && min < max && qtyRetry >= 0)
	{
		while(qtyRetry >= 0)
		{
			returnFunction = -1;
			printf("%s",pText);
			if(utn_getInt(&bufferInt)==0)
			{
				if(bufferInt >= min && bufferInt <= max)
				{
					*pResult = bufferInt;
					returnFunction = 0;
					break;
				}
			}
			printf("%s",pTextError);
			qtyRetry--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un numero y lo transforma a int si es un numero.
 * \param int* pResult Puntero a la direccion de memoria donde almacenar el numero entero en caso de ser validado ok.
 * \return 0 si no hubo errores, -1 si hubo error
 * */
int utn_getInt(int* pResult)
{
	int returnFunction = -1;
	char buffer[64];
	if(pResult != NULL)
	{
		returnFunction = -1;
		if(utn_myGets(buffer,sizeof(buffer))==0 && utn_validateNumber(buffer)==1)
		{
			*pResult = atoi(buffer);
			returnFunction = 0;
		}
	}
	return returnFunction;
}

/*
 * \brief Recibe una cadena con fgets, le remueve el enter del final y almacena el resultado
 * \param char* string Puntero a la direccion de memoria del string
 * \param int len Tamaño del array. Limite de caracteres/digitos
 * \return -1 si hubo error de validacion, 0 si no hubo errores.
 * */
int utn_myGets(char* string, int len)
{
	int returnFunction = -1;
	__fpurge(stdin);
	if(string != NULL && len > 0 && fgets(string,len,stdin)==string)
	{
		__fpurge(stdin);
		if(string[strlen(string)-1]== '\n')
		{
			string[strlen(string)-1]='\0';
		}
		returnFunction = 0;
	}
	return returnFunction;
}

/*
 * \brief Valida un numero pasado como parametro desde un array de caracteres
 * \param char* pArray Puntero al array de caracteres
 * \return -1 si hubo error de validacion, 1 si valido datos numericos, 0 si no pudo validar numeros.
 */
int utn_validateNumber(char* string)
{
	int i=0;
	int returnFunction = -1;
	if(string != NULL && strlen(string) > 0)
	{
		returnFunction = 1;
		while(string[i] != 0) // busco el final
		{
			if((string[i]<'0' || string[i]>'9') && string[i]!='-')
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}



//-------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////
/////           * FLOTANTES *            /////
//////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------

/*
 * \brief Pide un numero flotante.
 * \param float* pResult Puntero a la direccion de memoria donde almacenar el numero entero en caso de ser validado ok.
 * \param char* pText Mensaje previo al ingreso
 * \param char* pTextError Mensaje de error ante ingreso erróneo.
 * \param int qtyRetry Cantidad de reintentos.
 * \return 0 si no hubo errores, -1 si hubo error
 * */
int utn_getFloatWithoutMinimumOrMaximum(float* pResult, char* pText, char* pTextError, int qtyRetry)
{
	float bufferFloat;
	int returnFunction = -2;
	if(pResult != NULL && pText != NULL && pTextError != NULL && qtyRetry > 0)
	{
		while(qtyRetry >= 0)
		{
			returnFunction = -1;
			printf("%s",pText);
			if(utn_getFloat(&bufferFloat)==0)
			{
				*pResult = bufferFloat;
				returnFunction = 0;
				break;
			}
			printf("%s",pTextError);
			qtyRetry--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un numero y lo transforma a float si es un numero.
 * \param float* pResult Puntero a la direccion de memoria donde almacenar el numero entero en caso de ser validado ok.
 * \return 0 si no hubo errores, -1 si hubo error
 * */
int utn_getFloat(float* pResult)
{
	int returnFunction = -1;
	char buffer[64];
	if(pResult != NULL)
	{
		returnFunction = -1;
		if(utn_myGets(buffer,sizeof(buffer))==0 && utn_validateFloat(buffer)==1)
		{
			*pResult = atof(buffer);
			returnFunction = 0;
		}
	}
	return returnFunction;
}

/*
 * \brief Valida un numero pasado como parametro desde un array de caracteres
 * \param pArray Puntero al array de caracteres
 * \return -1 si hubo error de validacion, 1 si valido datos numericos, 0 si no pudo validar numeros.
 */
int utn_validateFloat(char* string)
{
	int i=0;
	int returnFunction = -1;
	if(string != NULL && strlen(string) > 0)
	{
		returnFunction = 1;
		while(string[i] != 0) // busco el final
		{
			if((string[i]<'0' || string[i]>'9') && (string[i]!='.' && string[i]!='-'))
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}
