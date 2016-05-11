//============================================================================
// Name        : TP2.cpp
// Author      : apenas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdio>
#include <vector>
#include <limits>
#include <fstream>
#include "ElImperioContraataca.h"

using namespace std;

int main() {


	 int x;
	  int m;
	    cin >> x >>m;


		vector<Arista > ady;


	    for(int i=0; i<m;i++){
	    	int x,y,p;
	    	cin >> x >> y >> p;
	    	Arista a(x,y,p);
	    	ady.push_back(a);
	    }


	    elImperioContraataca(x,m,ady);





	return 0;
}


