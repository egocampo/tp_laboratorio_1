/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "menues.h"
#include "gets.h"
#define QTY_EMPLOYEE 100


int main(void)
{
	Employee arrayEmpleados[QTY_EMPLOYEE];
	int opcionElegidaMenuPrincipal;
	char opcionElegidaMenuInformes;
	int contadorEmpleado = 1;
	employee_initEmployees(arrayEmpleados, QTY_EMPLOYEE);

	do
	{
		opcionElegidaMenuPrincipal = 0;
		menu_imprimirMenuPrincipal();
		get_int(&opcionElegidaMenuPrincipal, 2,
				"¿Qué desea realizar? ",
				"Esa no es una opción válida, intentelo nuevamente ",
				1,1,5,3,0);
		switch(opcionElegidaMenuPrincipal)
		{
			case 1:
				employee_altaEmpleado(arrayEmpleados,QTY_EMPLOYEE,contadorEmpleado);
				contadorEmpleado++;
				break;
			case 2:
				employee_opcionModificarEmpleado(arrayEmpleados, QTY_EMPLOYEE);
				break;
			case 3:
				employee_opcionBajaEmpleado(arrayEmpleados, QTY_EMPLOYEE);
				break;
			case 4:
				if(employee_existeEmpleado(arrayEmpleados,QTY_EMPLOYEE) == 0)
				{
					do
					{
						opcionElegidaMenuInformes=' ';
						menu_imprimirSubMenuInformes();
						get_char(&opcionElegidaMenuInformes, "abcABC", 7,"¿Qué desea realizar? ","Esa no es una opción válida, intentelo nuevamente ",3);
						switch(opcionElegidaMenuInformes)
						{
						case 'a':
						case 'A':
							employee_informeListadoAlfabetico(arrayEmpleados, QTY_EMPLOYEE);
							break;
						case 'b':
						case 'B':
							employee_informeTotalesYPromediosSalarios(arrayEmpleados,QTY_EMPLOYEE);
							break;
						}
					}while(opcionElegidaMenuInformes != 'c' && opcionElegidaMenuInformes != 'C');
				}
				else
				{
					system("clear");
					printf("\nNo se encontraron registros. Primero debe ingresar empleados.\n");
					menu_mensajeContinuar();
				}
				break;
		}
	}while(opcionElegidaMenuPrincipal != 5);
	menu_imprimirMensajeDespedida();
	return EXIT_SUCCESS;
}
