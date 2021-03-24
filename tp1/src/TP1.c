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
	int numberOne=0;
	int numberTwo=0;
	int sumResult;
	int subtractionResult;
	float divisionResult;
	int multiplicationResult;
	int factorialOne;
	int factorialTwo;
	int returnDivision;
	do
	{
		CLEAR_SCREEN;
		printf("1) Ingresar el 1er operando (A=%d).",numberOne);
		printf("\n2) Ingresar el 2do operando (B=%d).",numberTwo);
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
				scanf("%d",&numberOne);
				break;
			case 2:
				printf("Ingresar el 2do operando: ");
				__fpurge(stdin);
				scanf("%d",&numberTwo);
				break;
			case 3:
				sumNumbers(numberOne,numberTwo,&sumResult);
				subtractionNumbers(numberOne,numberTwo,&subtractionResult);
				multiplicationNumbers(numberOne,numberTwo,&multiplicationResult);
				returnDivision=divisionNumbers(numberOne,numberTwo,&divisionResult);
				factorialNumbers(numberOne,numberTwo,&factorialOne,&factorialTwo);
				break;
			case 4:
				CLEAR_SCREEN;
				printf("\nEl resultado de %d+%d es: %d",numberOne,numberTwo,sumResult);
				printf("\nEl resultado de %d-%d es: %d",numberOne,numberTwo,subtractionResult);
				if(returnDivision==0)
				{
					printf("\nEl resultado de %d/%d es: %.2f",numberOne,numberTwo,divisionResult);
				}
				else
				{
					printf("\nNo es posible dividir por cero");
				}
				printf("\nEl resultado de %d*%d es: %d",numberOne,numberTwo,multiplicationResult);
				printf("\nEl factorial de %d es: %d y El factorial de %d es %d"
						,numberOne,factorialOne,numberTwo,factorialTwo);
				printf("\nPresione una tecla para continuar...");
				getchar();
				getchar();
				break;
		}
	}while(optionSelected!=5);
	return EXIT_SUCCESS;
}
