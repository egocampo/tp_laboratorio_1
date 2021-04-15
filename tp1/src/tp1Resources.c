/*
 * tp1Resources.c
 *
 *  Created on: 9 abr. 2021
 *      Author: gabriel
 */

/*
 * NOTA: A las funciones tp1_showMenu y tp1_imprimirResultados yo las hubiera declarado como void,
 * pero para seguir el estilo las hice como int con return 0
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "matematicas.h"
#include "tp1Resources.h"
#define CLEAR_SCREEN system("clear")

/*
 * \brief Limpia la pantalla y muestra el menú
 * \param float numberOne Muestra el primer numero ingresado
 * \param float numberTwo Muestra el segundo numero ingresado
 * \param int flagNumberOne Avisa si se ingresó el numero uno, o no.
 * \param int flagNumberTwo Avisa si se ingresó el numero dos, o no.
 * */
int tp1_showMenu(float numberOne,float numberTwo,int flagNumberOne,int flagNumberTwo)
{
	CLEAR_SCREEN;
	if(flagNumberOne==0)
	{
		printf("1) Ingresar el 1er operando (A=%.1f).",numberOne);
	}
	else
	{
		printf("1) Ingresar el 1er operando (A= no ingresado).");
	}
	if(flagNumberTwo==0)
	{
		printf("\n2) Ingresar el 2do operando (B=%.1f).",numberTwo);
	}
	else
	{
		printf("\n2) Ingresar el 2do operando (B= no ingresado).");
	}
	printf("\n3) Calcular todas las operaciones.");
	printf("\n4) Informar resultados.");
	printf("\n5) Salir.");
	return 0;
}

/*
 * \brief Realiza los calculos del programa
 * \param int flagNumberOne Indica si se ingresó el número uno o no
 * \param int flagNumberTwo Indica si se ingresó el número dos o no
 * \param float numberOne Numero uno
 * \param float numberTwo Numero dos
 * \param float* sumResult Puntero a la dirección de memoria donde almacenar la suma
 * \param float* subtractionResult Puntero a la dirección de memoria donde almacenar la resta
 * \param float* multiplicationResult Puntero a la dirección de memoria donde almacenar la multiplicacion
 * \param int* returnDivision Puntero a la dirección de memoria donde almacenar si pudo dividirse o no
 * \param float* divisionResult Puntero a la dirección de memoria donde almacenar la división
 * \param int* returnFactorialOne Puntero a la dirección de memoria donde almacenar si pudo calcularse el primer factorial
 * \param long long int* factorialOne Puntero a la dirección de memoria donde almacenar el primer factorial
 * \param int* returnFactorialTwo Puntero a la dirección de memoria donde almacenar si pudo calcularse el segundo factorial
 * \param long long int* factorialTwo Puntero a la dirección de memoria donde almacenar el segundo factorial
 * \param int* flagOption3 Puntero a la dirección de memoria indicando si se pudieron realizar los cálculos.
 * \return 0 ok, -1 error de validacion de datos
 * */
int realizarCalculos(int flagNumberOne,int flagNumberTwo,float numberOne,float numberTwo,float* sumResult,float* subtractionResult,
		float* multiplicationResult,int* returnDivision,float* divisionResult,int* returnFactorialOne,long long int* factorialOne,
		int* returnFactorialTwo,long long int* factorialTwo,int* flagOption3)
{
	int returnFunction = -1;
	if(sumResult != NULL && subtractionResult != NULL && multiplicationResult != NULL && returnDivision != NULL && divisionResult != NULL && returnFactorialOne != NULL && factorialOne != NULL && returnFactorialTwo != NULL && factorialTwo != NULL && flagOption3)
	{
		returnFunction = 0;
		if(flagNumberOne+flagNumberTwo==0)
		{
			utn_sumNumbers(numberOne,numberTwo,sumResult);
			utn_subtractionNumbers(numberOne,numberTwo,subtractionResult);
			utn_multiplicationNumbers(numberOne,numberTwo,multiplicationResult);
			*returnDivision=utn_divisionNumbers(numberOne,numberTwo,divisionResult);
			*returnFactorialOne=utn_factorialNumber(numberOne,factorialOne);
			*returnFactorialTwo=utn_factorialNumber(numberTwo,factorialTwo);
			//*flagOption3 = 0;
			returnFunction = 1;
			printf("Realizados los cálculos.\nPresione una tecla para continuar...");
			getchar();
		}
		else
		{
			printf("Primero debe ingresar los valores de A y B\nPresione una tecla para continuar...");
			getchar();
		}
	}
	return returnFunction;
}

/*
 * \brief Muestra los resultados de los cálculos
 * \param int flagNumberOne Indica si se ingresó el número uno o no
 * \param int flagNumberTwo Indica si se ingresó el número dos o no
 * \param int flagOption3 Indica si se pudieron realizar los cálculos
 * \param float numberOne Numero uno
 * \param float numberTwo Numero dos
 * \param float sumResult Valor de la suma
 * \param float subtractionResult Valor de  la resta
 * \param float multiplicationResult Valor de  la multiplicacion
 * \param int returnDivision Indica si pudo dividirse o no
 * \param float divisionResult Valor de  la división
 * \param int returnFactorialOne Indica si pudo calcularse el primer factorial
 * \param long long int factorialOne Valor del primer factorial
 * \param int returnFactorialTwo Indica si pudo calcularse el segundo factorial
 * \param long long int factorialTwo Valor del segundo factorial
 * */
int imprimirResultados(int flagNumberOne,int flagNumberTwo,int flagOption3,float numberOne,float numberTwo,float sumResult,float subtractionResult,float multiplicationResult,float divisionResult,int returnDivision,int returnFactorialOne,long long int factorialOne,int returnFactorialTwo,long long int factorialTwo)
{
	if(flagNumberOne+flagNumberTwo<0)
	{
		printf("Primero debe ingresar los valores de A y B\nPresione una tecla para continuar...");
		getchar();
	}
	else if(flagOption3 < 1)
	{
		printf("Primero debe ejecutar el paso 3\nPresione una tecla para continuar...");
		getchar();
	}
	else
	{
		CLEAR_SCREEN;
		printf("El resultado de %.1f + %.1f es: %.1f",numberOne,numberTwo,sumResult);
		printf("\nEl resultado de %.1f - %.1f es: %.1f",numberOne,numberTwo,subtractionResult);
		if(returnDivision==0)
		{
			printf("\nEl resultado de %.1f / %.1f es: %.1f",numberOne,numberTwo,divisionResult);
		}
		else
		{
			printf("\nNo es posible dividir por cero");
		}
		printf("\nEl resultado de %.1f * %.1f es: %.1f",numberOne,numberTwo,multiplicationResult);
		if(returnFactorialOne==0)
		{
			printf("\nEl factorial de %.0f es: %lld"
					,numberOne,factorialOne);
		}
		else if(returnFactorialOne==-1)
		{
			printf("\nEl número %.1f es negativo, no tiene factorial"
					,numberOne);
		}
		else if(returnFactorialOne==-3)
		{
			printf("\nEl número %.1f es demasiado grande para calcular el factorial aquí"
															,numberOne);
		}
		else
		{
			printf("\nEl número %.1f es flotante, no tiene factorial"
										,numberOne);
		}
		if(returnFactorialTwo==0)
		{
			printf(" y el factorial de %.0f es: %lld"
					,numberTwo,factorialTwo);
		}
		else if(returnFactorialTwo==-1)
		{
			printf(" y el número %.1f es negativo, no tiene factorial"
					,numberTwo);
		}
		else if(returnFactorialTwo==-3)
		{
			printf(" y el número %.1f es demasiado grande para calcular el factorial aquí"
															,numberTwo);
		}
		else
		{
			printf(" y el número %.1f es flotante, no tiene factorial"
										,numberTwo);
		}
		printf("\nPresione una tecla para continuar...");
		getchar();
	}
	return 0;
}


