/*
 * RandomInstanceGenerator.h
 *
 *  Created on: 9/5/2016
 *      Author: agustin
 */

#ifndef RANDOMINSTANCEGENERATOR_H_
#define RANDOMINSTANCEGENERATOR_H_

#include <iostream>
#include<cstdio>
#include <vector>
#include <limits>
#include <math.h>
#include <stdio.h>
#include<cstdlib>
#include "ElImperioContraataca.h"
#include "esperanza.h"
#include "Arreglo.h"

using namespace std;

struct ej2{

	int n;
	int m;
	vector< Arista > ady;

	ej2(int x, int y){
		this->n=x;
		this->m=y;
	    this->ady.resize(y);

	}

};

struct ej1{

	int n;
	int m;
	aed2::Arreglo<Nodo* > grafo;


};

struct ej3{

	int n;
	int m;
	int** grafo;


	ej3(int x, int y){
		this->n=x;
		this->m=y;

		this->grafo = new int*[this->m];


	    for(int i=0; i<this->m;i++){
	    	grafo[i] = new int[this->n];
	    }


	}

	/*~ej3(){
		for(int i=0; i<this->m;i++){
			delete[] grafo[i];
		}
		delete[] grafo;
	}*/


};

ej2 getEj2RandomInstance(int,int);
ej1 getEj1RandomInstance(int,int);
ej3 getEj3RandomInstance(int,int);

#endif /* RANDOMINSTANCEGENERATOR_H_ */
