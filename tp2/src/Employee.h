/*
 * Employee.h
 *
 *  Created on: 28 abr. 2021
 *      Author: gabriel
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employee_initEmployees(Employee* list, int len);
int employee_addEmployee(Employee* list, int len, int id, char name[],char lastName[],char* salary,char* sector);
int employee_getName(Employee* arrayEmpleados, int indice, char* nameEmployee);
int employee_setName(Employee* arrayEmpleados, int indice, char* nameEmployee);
int employee_getLastName(Employee* arrayEmpleados, int indice, char* lastNameEmployee);
int employee_setLastName(Employee* arrayEmpleados, int indice, char* lastNameEmployee);
int employee_getSalary(Employee* arrayEmpleados, int indice, char* salaryEmployee);
int employee_setSalary(Employee* arrayEmpleados, int indice, char* salaryEmployee);
int employee_getSector(Employee* arrayEmpleados, int indice, char* sectorEmployee);
int employee_setSector(Employee* arrayEmpleados, int indice, char* sectorEmployee);
int employee_searchIndexEmpty(Employee* arrayEmpleados, int len);
int employee_findEmployeeById(Employee* list, int len, int id);
int employee_printEmployees(Employee* list, int len);
int employee_printEmployeeByIndex(Employee* list, int index);
int employee_opcionBajaEmpleado(Employee* list, int len);

int employee_categoria(int sector, char* sectorTexto);
int employee_altaEmpleado(Employee* list, int len,int id);
int employee_opcionModificarEmpleado(Employee* list, int len);
int employee_informeListadoAlfabetico(Employee* list, int len);
int employee_informeTotalesYPromediosSalarios(Employee* list, int len);

int employee_existeEmpleado(Employee* list, int len);


#endif /* EMPLOYEE_H_ */
