/*
 * ElImperioContraataca.h
 *
 *  Created on: 24/4/2016
 *      Author: agustin
 */

#ifndef ELIMPERIOCONTRAATACA_H_
#define ELIMPERIOCONTRAATACA_H_

#include <iostream>
#include<cstdio>
#include <vector>
#include <limits>

using namespace std;



struct Arista{
	int nodoA;
	int nodoB;
	int peso;

	Arista(int a, int b, int peso){
		this->nodoA=a;
		this->nodoB=b;
		this->peso=peso;
	}

	Arista(){
		this->nodoA=0;
		this->nodoB=0;
		this->peso=0;
	}
};



void elImperioContraataca(int cn, int m, vector< Arista > ady);
void init(int n);
int find(int x);
void unir(int x, int y);
void MergePeso(Arista* A, int low, int pivot,  int high);
void MergeSortPeso(Arista* A, int size);





#endif /* ELIMPERIOCONTRAATACA_H_ */
