/*
 * tp1Resources.h
 *
 *  Created on: 9 abr. 2021
 *      Author: gabriel
 */

#ifndef SRC_TP1RESOURCES_H_
#define SRC_TP1RESOURCES_H_

int tp1_showMenu(float numberOne,float numberTwo,int flagNumberOne,int flagNumberTwo);
int imprimirResultados(int flagNumberOne,int flagNumberTwo,int flagOption3,float numberOne,float numberTwo,float sumResult,float subtractionResult,float multiplicationResult,float divisionResult,int returnDivision,int returnFactorialOne,long long int factorialOne,int returnFactorialTwo,long long int factorialTwo);
int realizarCalculos(int flagNumberOne,int flagNumberTwo,float numberOne,float numberTwo,float* sumResult,float* subtractionResult,float* multiplicationResult,int* returnDivision,float* divisionResult,int* returnFactorialOne,long long int* factorialOne,int* returnFactorialTwo,long long int* factorialTwo,int* flagOption3);

#endif /* SRC_TP1RESOURCES_H_ */
