/*
 * RandomInstanceGenerator.cpp
 *
 *  Created on: 9/5/2016
 *      Author: agustin
 */

#include "RandomInstanceGenerator.h"
#include "esperanza.h"

using namespace std;

int myRand(){
	return rand()%1000 + (rand()%1000)*1000 + (rand()%1000)*1000000;
}

bool contiene(const std::vector<pair<int,int> >& v, int x, int y){
	for(int i = 1; i< v.size(); i++){
		if((v[i].first==x &&  v[i].second==y) ||  (v[i].first==y && v[i].second==x)){
			return true;
		}
	}
	return false;
}

ej2 getEj2RandomInstance(int n, int h){
	int m;
	int maxM =((n*(n-1))/2);
	int minM = n-1;
	srand(h);
	//do{
		//m= minM + (rand()%(maxM-minM));
	//}while(m >= minM);
		m=maxM;

	ej2 ejercicio2(n,m);
	std::srand(h);

	vector<pair<int,int> > aristas;

	for(int i=1; i<=n-1; i++){
		int x,y,p;
		x=i;
		y=myRand()%i;
		p=myRand()%1000;
		pair<int,int> par(x,y);
		Arista a(x,y,p);
		aristas.push_back(par);
		ejercicio2.ady[i-1]=a;

	}



	for(int i=n; i<=m;i++){
		int x,y,p;
		do{
			x=myRand()%n;
			y=myRand()%n;
			p=myRand()%1000;
		}while(x!=y && contiene(aristas,x,y));
		cout<<i<<endl;;
		pair<int,int> par(x,y);
		Arista a(x,y,p);
		aristas.push_back(par);
		ejercicio2.ady[i-1]=a;
	}

return ejercicio2;
}

ej1 getEj1RandomInstance(int N, int h){

	ej1 ejercicio1;
	ejercicio1.n=N;
	int M =((N*(N-1))/2);
	aed2::Arreglo<Nodo* > grafo(N*3);
	srand(h);

	int x=0;
	int y=0;
	int cantEspeciales=0;
	for(int i=0;i<M;i++){
		if(y==x){
			y=0;
			x++;
		}
		int especial;
		especial=rand()%10;
		if(especial==9){
			especial=1;
			cantEspeciales++;
		}else{
			especial=0;
		}

		if((i==M-1) && (cantEspeciales==0)){
			especial=1;
		}

		if(!grafo.Definido(x)){
			grafo.Definir(x, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),x));
		}
		grafo[x]->adyacentes.AgregarAtras(y);

		if(!grafo.Definido(y)){
			grafo.Definir(y, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),y));
		}

		grafo[y]->adyacentes.AgregarAtras(x);

		if(!grafo.Definido(x+N)){
			grafo.Definir(x+N, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),x));
		}
		grafo[x+N]->adyacentes.AgregarAtras(y+N);

		if(!grafo.Definido(y+N)){
			grafo.Definir(y+N, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),y));
		}

		grafo[y+N]->adyacentes.AgregarAtras(x+N);

		if(!grafo.Definido(x+N*2)){
			grafo.Definir(x+N*2, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),x));
		}
		grafo[x+N*2]->adyacentes.AgregarAtras(y+N*2);

		if(!grafo.Definido(y+N*2)){
			grafo.Definir(y+N*2, new Nodo(numeric_limits<int>::max(),aed3::Lista<int>(),y));
		}

		grafo[y+N*2]->adyacentes.AgregarAtras(x+N*2);

		if(especial){
			grafo[x]->adyacentes.AgregarAtras(y+N);
			grafo[y+N]->adyacentes.AgregarAtras(x);

			grafo[y]->adyacentes.AgregarAtras(x+N);
			grafo[x+N]->adyacentes.AgregarAtras(y);

			grafo[x+N]->adyacentes.AgregarAtras(y+N*2);
			grafo[y+N*2]->adyacentes.AgregarAtras(x+N);

			grafo[y+N]->adyacentes.AgregarAtras(x+N*2);
			grafo[x+N*2]->adyacentes.AgregarAtras(y+N);

			grafo[y]->adyacentes.AgregarAtras(x+N);
			grafo[x+N]->adyacentes.AgregarAtras(y);

			grafo[x+N]->adyacentes.AgregarAtras(y+N*2);
			grafo[y+N*2]->adyacentes.AgregarAtras(x+N);
		}
		y++;
	}
	ejercicio1.grafo = grafo;
	return ejercicio1;
}


ej3 getEj3RandomInstance(int n, int h){
	srand(h);

	ej3 ejercicio3(n,n);


	for(int i=0; i<ejercicio3.m;i++){
		for(int j=0; j<ejercicio3.n;j++){
			int a = rand()%1000;
			ejercicio3.grafo[i][j] = a;
		}
	}

return ejercicio3;
}
