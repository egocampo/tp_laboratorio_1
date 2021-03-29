/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "matematicas.h"
#include "utn.h"
#define CLEAR_SCREEN system("clear")

int main(void) {
	int optionSelected;
	float numberOne=0;
	float numberTwo=0;
	float sumResult;
	float subtractionResult;
	float divisionResult;
	float multiplicationResult;
	long long int factorialOne;
	long long int factorialTwo;
	int returnDivision;
	int returnFactorialOne;
	int returnFactorialTwo;
	do
	{
		CLEAR_SCREEN;
		printf("1) Ingresar el 1er operando (A=%.1f).",numberOne);
		printf("\n2) Ingresar el 2do operando (B=%.1f).",numberTwo);
		printf("\n3) Calcular todas las operaciones.");
		printf("\n4) Informar resultados.");
		printf("\n5) Salir.");
		printf("\nIngrese su opcion: ");
		__fpurge(stdin);
		scanf("%d",&optionSelected);
		switch(optionSelected)
		{
			case 1:
				utn_getFloatWithoutMinimumOrMaximum(&numberOne,"Ingresar el 1er operando: ","No es un número válido",3);
				break;
			case 2:
				utn_getFloatWithoutMinimumOrMaximum(&numberTwo,"Ingresar el 2do operando: ","No es un número válido",3);
				break;
			case 3:
				utn_sumNumbers(numberOne,numberTwo,&sumResult);
				utn_subtractionNumbers(numberOne,numberTwo,&subtractionResult);
				utn_multiplicationNumbers(numberOne,numberTwo,&multiplicationResult);
				returnDivision=utn_divisionNumbers(numberOne,numberTwo,&divisionResult);
				returnFactorialOne=utn_factorialNumber(numberOne,&factorialOne);
				returnFactorialTwo=utn_factorialNumber(numberTwo,&factorialTwo);
				break;
			case 4:
				CLEAR_SCREEN;
				printf("\nEl resultado de %.1f + %.1f es: %.1f",numberOne,numberTwo,sumResult);
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
					printf("\nEl factorial de %.1f es: %lld"
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
					printf(" y El factorial de %.1f es: %lld"
							,numberTwo,factorialTwo);
				}
				else if(returnFactorialTwo==-1)
				{
					printf(" y El número %.1f es negativo, no tiene factorial"
							,numberTwo);
				}
				else if(returnFactorialTwo==-3)
				{
					printf(" y El número %.1f es demasiado grande para calcular el factorial aquí"
																	,numberTwo);
				}
				else
				{
					printf(" y El número %.1f es flotante, no tiene factorial"
												,numberTwo);
				}
				printf("\nPresione una tecla para continuar...");
				getchar();
				getchar();
				break;
		}
	}while(optionSelected!=5);
	return EXIT_SUCCESS;
}
