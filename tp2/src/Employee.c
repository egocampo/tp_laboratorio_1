/*
 * Employee.c
 *
 *  Created on: 28 abr. 2021
 *      Author: gabriel
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "Employee.h"
#include "string.h"
#include "gets.h"
#include "validations.h"
#include "menues.h"

int employee_getName(Employee* arrayEmpleados, int indice, char* nameEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && nameEmployee != NULL)
	{
		strncpy(nameEmployee,arrayEmpleados[indice].name,51);
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_setName(Employee* arrayEmpleados, int indice, char* nameEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && val_isValidName(nameEmployee))
	{
		strncpy(arrayEmpleados[indice].name,nameEmployee,51);
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_getLastName(Employee* arrayEmpleados, int indice, char* lastNameEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && lastNameEmployee != NULL)
	{
		strncpy(lastNameEmployee,arrayEmpleados[indice].lastName,51);
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_setLastName(Employee* arrayEmpleados, int indice, char* lastNameEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && val_isValidName(lastNameEmployee))
	{
		strncpy(arrayEmpleados[indice].lastName,lastNameEmployee,51);
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_getSalary(Employee* arrayEmpleados, int indice, char* salaryEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && salaryEmployee != NULL)
	{
		*salaryEmployee = arrayEmpleados[indice].salary;
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_setSalary(Employee* arrayEmpleados, int indice, char* salaryEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && val_isValidFloat(salaryEmployee,0)==1)
	{
		arrayEmpleados[indice].salary = atof(salaryEmployee);
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_getSector(Employee* arrayEmpleados, int indice, char* sectorEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && sectorEmployee != NULL)
	{
		*sectorEmployee = arrayEmpleados[indice].salary;
		returnFunction = 0;
	}
	return returnFunction;
}

int employee_setSector(Employee* arrayEmpleados, int indice, char* sectorEmployee)
{
	int returnFunction = -1;
	if(arrayEmpleados != NULL && indice >= 0 && val_isValidInt(sectorEmployee,0))
	{
		arrayEmpleados[indice].sector = atoi(sectorEmployee);
		returnFunction = 0;
	}
	return returnFunction;
}


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

/** \brief To indicate that all position in the array are empty,
			this function put the flag (isEmpty) in TRUE in all
			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int employee_initEmployees(Employee* list, int len)
{
	int returnFunction = -1;
	int i;
	if(list != NULL && len > 0)
	{
		returnFunction = 0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return returnFunction;
}

/** \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int employee_addEmployee(Employee* list, int len, int id, char name[],char lastName[],char* salary,char* sector)
{
	int returnFunction = -1;
	Employee bufferEmployee[1];
	int indice = employee_searchIndexEmpty(list, len);
	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary != NULL && sector != NULL)
	{
		returnFunction = 0;
		if(employee_setName(bufferEmployee,0,name)==0)
			if(employee_setLastName(bufferEmployee,0,lastName)==0)
				if(employee_setSalary(bufferEmployee,0,salary)==0)
					if(employee_setSector(bufferEmployee,0,sector)==0)
					{
						bufferEmployee[0].id = id;
						bufferEmployee[0].isEmpty = 0;
						list[indice] = bufferEmployee[0];
					}
	}
	return returnFunction;
}

int employee_altaEmpleado(Employee* list, int len,int id)
{
	char name[51];
	char lastName[51];
	char salary[51];
	char sector[5];
	system("clear");
	printf("ALTA DE EMPLEADO\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
	if(get_name(name, 51, "Ingrese el nombre: ","Error. ",3)==1)
	{
		if(get_name(lastName, 51, "Ingrese el apellido: ","Error. ",3)==1)
		{
			if(get_floatAsChar(salary,51,"Ingrese el salario: ","Error. ",1,1,999999,3,0)==1)
			{
				menu_imprimirSectores();;
				if(get_intAsChar(sector,5,"Ingrese el sector: ","Error. ",1,1,5,3, 0)==1)
				{
					employee_addEmployee(list, len, id, name, lastName, salary, sector);
					printf("\nSe ha ingresado correctamente el empleado, con el Id #%d.\n",id);
				}
			}
		}
	}
	menu_mensajeContinuar();
	return 0;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/
int employee_findEmployeeById(Employee* list, int len, int id)
{
	int returnFunction = -1;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				returnFunction = i;
				break;
			}
		}
	}
	return returnFunction;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int employee_removeEmployee(Employee* list, int len, int id)
{
	int returnFunction = -1;
	if(list != NULL && len > 0 && id > 0)
	{
		returnFunction = 0;
		list[employee_findEmployeeById(list, len, id)].isEmpty = 1;
	}
	return returnFunction;
}

int employee_opcionBajaEmpleado(Employee* list, int len)
{
	int returnFunction = -1;
	int idSeleccionado;
	int indiceDelIdSeleccionado;
	char confirmacionBorrado;
	if(list != NULL && len > 0)
	{
		returnFunction = 0;
		system("clear");
		printf("BAJA DE EMPLEADO\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		if(employee_existeEmpleado(list, len) == 0)
		{
			employee_printEmployees(list, len);
			get_int(&idSeleccionado, 5,"\nIngrese el Id del empleado: ","Error. ",1,1,len,3,0);
			indiceDelIdSeleccionado = employee_findEmployeeById(list, len, idSeleccionado);
			if(list[indiceDelIdSeleccionado].isEmpty == 0)
			{
				get_char(&confirmacionBorrado, "sSnN",5, "\n¿Confirma que desea eliminar el Id seleccionado? (S/N): ","Error. ",3);
				if(confirmacionBorrado == 's' || confirmacionBorrado == 'S')
				{
					list[indiceDelIdSeleccionado].isEmpty = 1;
					printf("\nBorrado confirmado.\n");
				}
				else
				{
					printf("\nOperación cancelada.\n");
				}
			}
			else
			{
				printf("\nEl empleado no existe.\n");
			}
		}
		else
		{
			printf("No se encontraron registros. Primero debe ingresar empleados.\n");
		}
	}
	menu_mensajeContinuar();
	return returnFunction;
}

int employee_opcionModificarEmpleado(Employee* list, int len)
{
	int returnFunction = -1;
	int idSeleccionado;
	int indiceDelIdSeleccionado;
	char opcionElegida;
	char auxChar[51];
	if(list != NULL && len > 0)
	{
		returnFunction = 0;
		system("clear");
		printf("MODIFICACION DE EMPLEADOS\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n");
		if(employee_existeEmpleado(list, len) == 0)
		{
			employee_printEmployees(list, len);
			get_int(&idSeleccionado, 5,"\nIngrese el Id del empleado: ","Error. ",1,1,len,3,0);
			indiceDelIdSeleccionado = employee_findEmployeeById(list, len, idSeleccionado);
			if(list[indiceDelIdSeleccionado].isEmpty == 0)
			{
				menu_modificarEmpleado();
				get_char(&opcionElegida, "abcdeABCDE",11, "\n¿Qué desea modificar? ","Error. ",3);
				switch(opcionElegida)
				{
				case 'a':
				case 'A':
					if(get_name(auxChar, 51, "Ingrese el nombre: ","Error. ",3)==1)
					{
						employee_setName(list, indiceDelIdSeleccionado, auxChar);
					}
					break;
				case 'b':
				case 'B':
					if(get_name(auxChar, 51, "Ingrese el Apellido: ","Error. ",3)==1)
					{
						employee_setLastName(list, indiceDelIdSeleccionado, auxChar);
					}
					break;
				case 'c':
				case 'C':
					if(get_floatAsChar(auxChar,51,"Ingrese el salario: ","Error. ",1,1,999999,3,0)==1)
					{
						employee_setSalary(list, indiceDelIdSeleccionado, auxChar);
					}
					break;
				case 'd':
				case 'D':
					menu_imprimirSectores();
					if(get_intAsChar(auxChar,51,"Ingrese el sector: ","Error. ",1,1,999999,3,0)==1)
					{
						employee_setSector(list, indiceDelIdSeleccionado, auxChar);
					}
					break;
				case 'e':
				case 'E':
					printf("\nOperación cancelada.\n");
					break;
				}
			}
			else
			{
				printf("\nEl empleado no existe.\n");
			}
		}
		else
		{
			printf("No se encontraron registros. Primero debe ingresar empleados.\n");
		}
	}
	menu_mensajeContinuar();
	return returnFunction;
}

int employee_existeEmpleado(Employee* list, int len)
{
	int flagExiste = -2;
	int i;
	if(list != NULL && len > 0)
	{
		flagExiste = -1;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				flagExiste = 0;
				break;
			}
		}
	}
	return flagExiste;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int employee_printEmployees(Employee* list, int len)
{
	int returnFunction = -1;
	int i;
	if(list != NULL && len > 0)
	{
		returnFunction = 0;
		printf("Nómina de empleados:\n"
				"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				employee_printEmployeeByIndex(list, i);
			}
		}
	}
	return returnFunction;
}

int employee_printEmployeeByIndex(Employee* list, int index)
{
	int returnFunction = -1;
	char categoriaTexto[50];
	if(list != NULL && index >= 0)
	{
		returnFunction = 0;
		employee_categoria(list[index].sector, categoriaTexto);
		printf("%d) %s, %s ‖ $ %.2f ‖ %s\n",list[index].id,list[index].lastName,list[index].name,list[index].salary,categoriaTexto);
	}
	return returnFunction;
}

int employee_categoria(int sector, char* sectorTexto)
{
	int returnFunction = 0;
	switch(sector)
	{
	 case 1:
		 strncpy(sectorTexto,"Programacion",20);
		 break;
	 case 2:
		 strncpy(sectorTexto,"Diseño",20);
		  break;
	 case 3:
		 strncpy(sectorTexto,"Soporte técnico",20);
		 break;
	 case 4:
		 strncpy(sectorTexto,"RR.HH.",20);
		 break;
	 case 5:
		 strncpy(sectorTexto,"Mantenimiento",20);
		 break;
	}
	return returnFunction;
}

/*
 * \brief Busca dentro de un arrayEstructuraBase el primer indice cuyo campo isEmpty sea verdadero
 * \param estructura* arrayEstructuraBase Array de estructura donde buscar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -2 error de validacion, -1 no hay ningun espacio vacio, 0 o mayor es la posicion libre
 * */
int employee_searchIndexEmpty(Employee* arrayEmpleados, int len)
{
	int returnFunction = -2;
	int i;
	if(arrayEmpleados != NULL && len > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(arrayEmpleados[i].isEmpty == 1)
			{
				returnFunction = i;
				break;
			}
		}
	}
	return returnFunction;
}

int employee_informeListadoAlfabetico(Employee* list, int len)
{
	int retorno = -1;
	Employee listadoOrdenado[len];
	int i, j;
	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			listadoOrdenado[i] = list[i];
		}
		Employee buffer;
		int flagNoEstaOrdenado = 1;
		while(flagNoEstaOrdenado==1)
		{
			flagNoEstaOrdenado = 0;
			for(j=1;j<len;j++)
			{
				if(listadoOrdenado[j].isEmpty == 0 && listadoOrdenado[j-1].isEmpty == 0)
				{
					if(strcmp(listadoOrdenado[j].lastName,listadoOrdenado[j-1].lastName) < 0)
					{
						buffer = listadoOrdenado[j];
						listadoOrdenado[j] = listadoOrdenado[j-1];
						listadoOrdenado[j-1] = buffer;
						flagNoEstaOrdenado = 1;
					}
					if(strcmp(listadoOrdenado[j].lastName,listadoOrdenado[j-1].lastName) == 0 && listadoOrdenado[j].sector < listadoOrdenado[j-1].sector)
					{
						buffer = listadoOrdenado[j];
						listadoOrdenado[j] = listadoOrdenado[j-1];
						listadoOrdenado[j-1] = buffer;
						flagNoEstaOrdenado = 1;
					}
				}
			}
		}
	}
	employee_printEmployees(listadoOrdenado, len);
	menu_mensajeContinuar();
	return retorno;
}

int employee_informeTotalesYPromediosSalarios(Employee* list, int len)
{
	int i;
	float acumuladorSueldos = 0;
	int contadorSueldos = 0;
	float promedioSueldos;
	int contadorSueldosMayoresAlPromedio = 0;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			acumuladorSueldos += list[i].salary;
			contadorSueldos++;
		}
	}
	promedioSueldos = acumuladorSueldos/contadorSueldos;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == 0 && list[i].salary > promedioSueldos)
		{
			contadorSueldosMayoresAlPromedio++;
		}
	}
	printf("\nTotal de sueldos: $ %.2f \n",acumuladorSueldos);
	printf("\nSueldo promedio: $ %.2f \n",promedioSueldos);
	printf("\nCantidad de sueldos por encima del promedio: %d\n",contadorSueldosMayoresAlPromedio);
	menu_mensajeContinuar();
	return 0;
}

