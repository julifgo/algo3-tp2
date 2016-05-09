
#ifndef RETORNO_H_
#define RETORNO_H_

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

enum Direccion {arriba, abajo, izquierda, derecha, sinDireccion};


void ElRetornoDelJedi(vector<vector<int> > grilla, int h, int n, int m);
int max (int a, int b);
int min (int a, int b);

#endif /* RETORNO_H_ */
