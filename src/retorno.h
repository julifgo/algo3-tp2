
#ifndef RETORNO_H_
#define RETORNO_H_

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



void ElRetornoDelJedi(int** grilla, int h, int n, int m);
int max(int a, int b);
int min(int a, int b);


enum Direccion {arriba, abajo, izquierda, derecha, sinDireccion};
#endif /* RETORNO_H_ */
