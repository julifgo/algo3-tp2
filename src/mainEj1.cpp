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
#include "retorno.h"

using namespace std;

int main() {

int N;
	  int M;
	  int H;
	    cin >> N >>M>>H;


	    int** grilla;

	    grilla = new int*[N];


	    for(int i=0; i<N;i++){
	    	grilla[i] = new int[M];
	    }

	    for(int i=0; i<N;i++){
	    	for(int j =0; j<M;j++){
	    		int x;
	    		cin>>x;
	    		grilla[i][j] = x;
	    	}
	    }

	    ElRetornoDelJedi(grilla,H,N,M);





	return 0;
}


