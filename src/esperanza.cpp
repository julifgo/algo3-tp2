#include "esperanza.h"
using namespace std;

struct Adyacentes{

	Adyacentes(int d, aed3::Lista<pair<int,int> > n):distance(d), nodos(n){}
	int distance; //distance to root
	aed3::Lista<pair<int,int> > nodos;  //Nodos adyacentes al indice de la posicion del arreglo

};

int main(){
	
	int N;
	int M;
	cin>>N>>M;
	aed2::Arreglo<Adyacentes > grafo(N);

	for(int i=0;i<M;i++){
		int x;
		int y;
		int especial;
		cin>>x>>y>>especial;
		if(!grafo.Definido(x)){
			grafo.Definir(x, Adyacentes(0,aed3::Lista<pair<int,int> >()));
		}
		grafo[x].nodos.AgregarAtras(pair<int,int>(y,especial));

		if(!grafo.Definido(y)){
			grafo.Definir(y, Adyacentes(0,aed3::Lista<pair<int,int> >()));
		}
		grafo[y].nodos.AgregarAtras(pair<int,int>(x,especial));
	}


	UnaNuevaEsperanza(grafo);
	
	return 0;
}


void UnaNuevaEsperanza (aed2::Arreglo<Adyacentes > grafo) {
	
	
}

/*
ENTRADA ESPERADA PARA ARMAR POR EJEMPLO UN K3:
3 -> cant nodos
3 -> cant aristas
0 -> primer componente primer arista
1 -> segundo comoponente primer arista
0 -> arista NO especial
0 -> primer componente segunda arista
2 -> segundo componente segunda arista
1 -> arista especial
1 -> primer componente tercer arista
2 -> segundo componente tercer arista
0 -> arista NO especial
*/
