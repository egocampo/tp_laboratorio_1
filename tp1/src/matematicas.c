/*
 * matematicas.c
 *
 *  Created on: 17 mar. 2021
 *      Author: egabr
 */

/*
 * utn_sumNumbers : suma dos numeros dados
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* sumResult: direccion de memoria para guardar el resultado de la suma
 * */
int utn_sumNumbers(int numberOne,int numberTwo, int* sumResult)
{
	*sumResult = numberOne + numberTwo;
	return 0;
}
/*
 * utn_subtractionNumbers : resta dos numeros dados
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* subtractionResult: direccion de memoria para guardar el resultado de la resta
 * */
int utn_subtractionNumbers(int numberOne,int numberTwo, int* subtractionResult)
{
	*subtractionResult = numberOne - numberTwo;
	return 0;
}
/*
 * utn_divisionNumbers : divide un numero dado por otro numero dado
 * int numberOne: dividendo
 * int numberTwo: divisor
 * int* sumResult: direccion de memoria para guardar el resultado de la division
 * returnFunction: devuelve 0 si no hubo error, devuelve -1 si el divisor es cero (no puede dividirse entre cero)
 * */
float utn_divisionNumbers(int numberOne,int numberTwo, float* divisionResult)
{
	int returnFunction = 0;
	if(numberTwo == 0)
	{
		returnFunction = -1;
	}
	*divisionResult = (float)numberOne / numberTwo;
	return returnFunction;
}
/*
 * utn_multiplicationNumbers : multiplica un numero dado por otro numero dado
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* sumResult: direccion de memoria para guardar el resultado de la multiplicacion
 * */
int utn_multiplicationNumbers(int numberOne,int numberTwo, int* multiplicationResult)
{
	*multiplicationResult = numberOne * numberTwo;
	return 0;
}
/*
 * utn_factorialNumber : calcula el factorial de un numero dado
 * int number: numero dado
 * int* factorial: direccion de memoria para guardar el factorial
 * retunrFunction: devuelve 0 si no hubo error, devuelve -1 si el numero dado es negativo (no existe factorial de negativos)
 * */
int utn_factorialNumber(int number, int* factorial)
{
	int i;
	int auxiliarFactorial = 1;
	int returnFunction = 0;
	if(number > 0)
	{
		for(i = 0;i < number - 1;i++)
		{
			auxiliarFactorial = auxiliarFactorial * (number - i);
		}
		*factorial = auxiliarFactorial;
	}
	else if(number == 0)
	{
		*factorial = 1;
	}
	else
	{
		returnFunction = -1;
	}
	return returnFunction;
}
