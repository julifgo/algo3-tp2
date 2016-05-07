#include "esperanza.h"
using namespace std;

struct Nodo{

	Nodo(int d, aed3::Lista<pair<int,int> > n, int s):distance(d), adyacentes(n), number(s){}
	int distance; //distance to root
	int number;
	aed3::Lista<pair<int,int> > adyacentes;  //Nodos adyacentes al indice de la posicion del arreglo (el segundo int indica si es especial o no. ver de pasar a bool)

};

int main(){
	
	int N;
	int M;
	cin>>N>>M;
	aed2::Arreglo<Nodo* > grafo(N*3);

	for(int i=0;i<M;i++){
		int x;
		int y;
		int especial;
		cin>>x>>y>>especial;
		if(!grafo.Definido(x)){
			grafo.Definir(x, new Nodo(100000,aed3::Lista<pair<int,int> >(),x)); //VER ESE NUMERO
		}
		grafo[x]->adyacentes.AgregarAtras(pair<int,int>(y,especial));

		if(!grafo.Definido(y)){
			grafo.Definir(y, new Nodo(100000,aed3::Lista<pair<int,int> >(),y));
		}

		grafo[y]->adyacentes.AgregarAtras(pair<int,int>(x,especial));

		if(!grafo.Definido(x+N)){
			grafo.Definir(x+N, new Nodo(100000,aed3::Lista<pair<int,int> >(),x)); //VER ESE NUMERO
		}
		grafo[x+N]->adyacentes.AgregarAtras(pair<int,int>(y+N,especial));

		if(!grafo.Definido(y+N)){
			grafo.Definir(y+N, new Nodo(100000,aed3::Lista<pair<int,int> >(),y));
		}

		grafo[y+N]->adyacentes.AgregarAtras(pair<int,int>(x+N,especial));

		if(!grafo.Definido(x+N*2)){
			grafo.Definir(x+N*2, new Nodo(100000,aed3::Lista<pair<int,int> >(),x)); //VER ESE NUMERO
		}
		grafo[x+N*2]->adyacentes.AgregarAtras(pair<int,int>(y+N*2,especial));

		if(!grafo.Definido(y+N*2)){
			grafo.Definir(y+N*2, new Nodo(100000,aed3::Lista<pair<int,int> >(),y));
		}

		grafo[y+N*2]->adyacentes.AgregarAtras(pair<int,int>(x+N*2,especial));

		if(especial){
			grafo[x]->adyacentes.AgregarAtras(pair<int,int>(y+N,especial));
			grafo[y+N]->adyacentes.AgregarAtras(pair<int,int>(x,especial));

			grafo[y]->adyacentes.AgregarAtras(pair<int,int>(x+N,especial));
			grafo[x+N]->adyacentes.AgregarAtras(pair<int,int>(y,especial));

			grafo[x+N]->adyacentes.AgregarAtras(pair<int,int>(y+N*2,especial));
			grafo[y+N*2]->adyacentes.AgregarAtras(pair<int,int>(x+N,especial));

			grafo[y+N]->adyacentes.AgregarAtras(pair<int,int>(x+N*2,especial));
			grafo[x+N*2]->adyacentes.AgregarAtras(pair<int,int>(y+N,especial));

			grafo[y]->adyacentes.AgregarAtras(pair<int,int>(x+N,especial));
			grafo[x+N]->adyacentes.AgregarAtras(pair<int,int>(y,especial));

			grafo[x+N]->adyacentes.AgregarAtras(pair<int,int>(y+N*2,especial));
			grafo[y+N*2]->adyacentes.AgregarAtras(pair<int,int>(x+N,especial));
		}
	}


	UnaNuevaEsperanza(grafo);
	
//	cout<<"Distance to "<<N-1<<": "<<grafo[N*3-1]->distance<<endl;

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
	
	Nodo* nodoActual = grafo[grafo.Tamanho() - 1];
	Nodo* nodoMinimo = NULL;
	aed3::Lista<int> imprimir;

	while(nodoActual != grafo[0])
	{
		for (int i = 0; i < nodoActual->adyacentes.Longitud(); ++i)
		{
			pair<int,int> adj = nodoActual->adyacentes[i];
			Nodo* neighbour = grafo[adj.first];
			if(nodoMinimo != NULL)
			{
				if(neighbour->distance <= nodoMinimo->distance)
				{
					nodoMinimo = neighbour;
				}
			}
			else
			{
				nodoMinimo = neighbour;
			}
		}
		if(nodoMinimo != NULL)
		{
			imprimir.AgregarAdelante(nodoMinimo->number);
			nodoActual = nodoMinimo;
			nodoMinimo = NULL;
		}
	}
	cout << imprimir.Longitud() << "\n";
	for (int i = 1; i < imprimir.Longitud(); ++i)//i=1 para obviar la cueva de salida
	{
		cout << imprimir[i];
		if(i!=imprimir.Longitud()-1){
			cout << " ";
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
