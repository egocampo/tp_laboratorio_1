/*
 * matematicas.c
 *
 *  Created on: 17 mar. 2021
 *      Author: egabr
 */
int sumNumbers(int numberOne,int numberTwo, int* sumResult)
{
	*sumResult=numberOne+numberTwo;
	return 0;
}

int subtractionNumbers(int numberOne,int numberTwo, int* subtractionResult)
{
	*subtractionResult=numberOne-numberTwo;
	return 0;
}

float divisionNumbers(int numberOne,int numberTwo, float* divisionResult)
{
	if(numberTwo==0)
	{
		return -1;
	}
	*divisionResult=(float)numberOne/numberTwo;
	return 0;
}

int multiplicationNumbers(int numberOne,int numberTwo, int* multiplicationResult)
{
	*multiplicationResult=numberOne*numberTwo;
	return 0;
}

int factorialNumbers(int numberOne, int numberTwo, int* factorialOne, int* factorialTwo)
{
	int i;
	int auxiliarFactorial=1;
	for(i=0;i<numberOne-1;i++)
	{
		auxiliarFactorial=auxiliarFactorial*(numberOne-i);
	}
	*factorialOne=auxiliarFactorial;
	auxiliarFactorial=1;
	for(i=0;i<numberTwo-1;i++)
	{
		auxiliarFactorial=auxiliarFactorial*(numberTwo-i);
	}
	*factorialTwo=auxiliarFactorial;
	return 0;
}
