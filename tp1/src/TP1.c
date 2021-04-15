/*
 ============================================================================
ALUMNO: GABRIEL OCAMPO
DIVISION: 1°H
MATERIA: PROG / LABO 1
TP_1 CALCULADORA
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "matematicas.h"
#include "tp1Resources.h"
#define CLEAR_SCREEN system("clear")

int main(void) {
	int optionSelected;
	float numberOne;
	float numberTwo;
	int flagNumberOne=-1;
	int flagNumberTwo=-1;
	int flagOption3=-2;
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
		optionSelected=0;
		tp1_showMenu(numberOne, numberTwo,flagNumberOne,flagNumberTwo);
		utn_getNumber(&optionSelected,"\nIngrese su opcion: ","",1,5,0);
		switch(optionSelected)
		{
			case 1:
				flagNumberOne = utn_getFloatWithoutMinimumOrMaximum(&numberOne,"Ingresar el 1er operando: ","",1);
				break;
			case 2:
				flagNumberTwo = utn_getFloatWithoutMinimumOrMaximum(&numberTwo,"Ingresar el 2do operando: ","",1);
				break;
			case 3:
				flagOption3 = realizarCalculos(flagNumberOne,flagNumberTwo,numberOne,numberTwo,&sumResult,&subtractionResult,&multiplicationResult,&returnDivision,&divisionResult,&returnFactorialOne,&factorialOne,&returnFactorialTwo,&factorialTwo,&flagOption3);
				break;
			case 4:
				imprimirResultados(flagNumberOne,flagNumberTwo,flagOption3,numberOne,numberTwo,sumResult,subtractionResult,multiplicationResult,divisionResult,returnDivision,returnFactorialOne,factorialOne,returnFactorialTwo,factorialTwo);
				break;
		}
	}while(optionSelected!=5);
	printf("Gracias por su uso. Hasta la próxima.\n");
	return EXIT_SUCCESS;
}
