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
#include "matematicas.h"
#define CLEAR_SCREEN system("cls")

int main(void) {
	int optionSelected;
	int numberOne=0;
	int numberTwo=0;
	int sumResult;
	int subtractionResult;
	float divisionResult;
	int multiplicationResult;
	do
	{
		CLEAR_SCREEN;
		printf("1) Ingresar el 1er operando (A=%d).",numberOne);
		printf("\n2) Ingresar el 2do operando (B=%d).",numberTwo);
		printf("\n3) Calcular todas las operaciones.");
		printf("\n4) Informar resultados.");
		printf("\n5) Salir.");
		printf("\nIngrese su opcion: ");
		scanf("%d",&optionSelected);
		switch(optionSelected)
		{
			case 1:
				printf("Ingresar el 1er operando: ");
				scanf("%d",&numberOne);
				break;
			case 2:
				printf("Ingresar el 2do operando: ");
				scanf("%d",&numberTwo);
				break;
			case 3:
				sumResult=sumNumbers(numberOne,numberTwo);
				subtractionResult=subtractionNumbers(numberOne,numberTwo);
				multiplicationResult=multiplicationNumbers(numberOne,numberTwo);
				if(numberTwo!=0)
				{
					divisionResult=divisionNumbers(numberOne,numberTwo);
				}
				break;
			case 4:
				CLEAR_SCREEN;
				printf("\na) El resultado de %d + %d es: %d",numberOne,numberTwo,sumResult);
				printf("\nb) El resultado de %d - %d es: %d",numberOne,numberTwo,subtractionResult);
				if(numberTwo!=0)
				{
					printf("\nc) El resultado de %d / %d es: %f",numberOne,numberTwo,divisionResult);
				}
				else
				{
					printf("\nc) No se puede dividir entre 0");
				}
				printf("\nd) El resultado de %d * %d es: %d",numberOne,numberTwo,multiplicationResult);
				printf("\nPresione una tecla para continuar...");
				getchar();
				getchar();
				break;
		}
	}while(optionSelected!=5);
	return EXIT_SUCCESS;
}
