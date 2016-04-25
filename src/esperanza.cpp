#include "esperanza.h"
using namespace std;

struct Nodo{

	Nodo(int d, aed3::Lista<pair<int,int> > n):distance(d), adyacentes(n){}
	int distance; //distance to root
	aed3::Lista<pair<int,int> > adyacentes;  //Nodos adyacentes al indice de la posicion del arreglo (el segundo int indica si es especial o no. ver de pasar a bool)

};

int main(){
	
	int N;
	int M;
	cin>>N>>M;
	aed2::Arreglo<Nodo* > grafo(N);

	for(int i=0;i<M;i++){
		int x;
		int y;
		int especial;
		cin>>x>>y>>especial;
		if(!grafo.Definido(x)){
			grafo.Definir(x, new Nodo(100000,aed3::Lista<pair<int,int> >())); //VER ESE NUMERO
		}
		grafo[x]->adyacentes.AgregarAtras(pair<int,int>(y,especial));

		if(!grafo.Definido(y)){
			grafo.Definir(y, new Nodo(100000,aed3::Lista<pair<int,int> >()));
		}
		grafo[y]->adyacentes.AgregarAtras(pair<int,int>(x,especial));
	}


	UnaNuevaEsperanza(grafo);
	
	cout<<"Distance to "<<N-1<<": "<<grafo[N-1]->distance<<endl;

	return 0;
}


void UnaNuevaEsperanza (aed2::Arreglo<Nodo* > grafo) {
	queue<Nodo*> q;
	Nodo* nodoAux = grafo[0];
	nodoAux->distance = 0; //entry point
	q.push(nodoAux);
	while (!q.empty())
  	{
  		Nodo* n = q.front(); //access next element
  		q.pop(); //remove next element. VER CORRECGTITUD DE ESTO. HACE REMOVE PERO TIENE EL ACCESS ARRIOBA
  		for (int i = 0; i < n->adyacentes.Longitud(); ++i)
  		{
  			pair<int,int> adj = n->adyacentes[i];
  			Nodo* neighbour = grafo[adj.first];
  			if (neighbour->distance > n->distance+1)
  			{
  				neighbour->distance = n->distance+1;
  				q.push(neighbour);
  			}
  		}

  	}
	
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
