#ifndef CONTRAATACA_H_
#define CONTRAATACA_H_

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
};

vector<int> padre;
vector<int> altura;

void elImperioContraataca(int cn, vector< vector<int> > ady);
void init(int n);
int find(int x);
void unir(int x, int y);
void Merge(vector<Arista>& A,vector<Arista>& B, vector<Arista>& C);
void MergeSort(vector<Arista>& A);


#endif /* CONTRAATACA_H_ */
