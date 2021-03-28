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
		printf("1) Ingresar el 1er operando (A=%.2f).",numberOne);
		printf("\n2) Ingresar el 2do operando (B=%.2f).",numberTwo);
		printf("\n3) Calcular todas las operaciones.");
		printf("\n4) Informar resultados.");
		printf("\n5) Salir.");
		printf("\nIngrese su opcion: ");
		__fpurge(stdin);
		scanf("%d",&optionSelected);
		switch(optionSelected)
		{
			case 1:
				printf("Ingresar el 1er operando: ");
				__fpurge(stdin);
				scanf("%f",&numberOne);
				break;
			case 2:
				printf("Ingresar el 2do operando: ");
				__fpurge(stdin);
				scanf("%f",&numberTwo);
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
				printf("\nEl resultado de %.2f + %.2f es: %.2f",numberOne,numberTwo,sumResult);
				printf("\nEl resultado de %.2f - %.2f es: %.2f",numberOne,numberTwo,subtractionResult);
				if(returnDivision==0)
				{
					printf("\nEl resultado de %.2f / %.2f es: %.2f",numberOne,numberTwo,divisionResult);
				}
				else
				{
					printf("\nNo es posible dividir por cero");
				}
				printf("\nEl resultado de %.2f * %.2f es: %.2f\n",numberOne,numberTwo,multiplicationResult);
				if(returnFactorialOne==0)
				{
					printf("\nEl factorial de %.2f es: %lld"
							,numberOne,factorialOne);
				}
				else if(returnFactorialOne==-1)
				{
					printf("\nEl número %.2f es negativo, no tiene factorial"
							,numberOne);
				}
				else
				{
					printf("El número %.2f es flotante, no tiene factorial"
												,numberOne);
				}
				if(returnFactorialTwo==0)
				{
					printf(" y El factorial de %.2f es: %lld"
							,numberTwo,factorialTwo);
				}
				else if(returnFactorialTwo==-1)
				{
					printf(" y El número %.2f es negativo, no tiene factorial"
							,numberTwo);
				}
				else
				{
					printf(" y El número %.2f es flotante, no tiene factorial"
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
