#include "esperanza.h"
using namespace std;

struct Nodo{

	Nodo(int d, aed3::Lista<int> n, int s):distancia(d), adyacentes(n), numero(s){}
	int distancia; //distancia a la raiz
	int numero; //numero de nodo (importante ya que vamos a copiar nodos)
	aed3::Lista<int> adyacentes;  //Nodos adyacentes al indice de la posicion del arreglo
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
	}

	UnaNuevaEsperanza(grafo);

	return 0;
}

void UnaNuevaEsperanza (aed2::Arreglo<Nodo* > grafo) {
	queue<Nodo*> q;
	Nodo* nodoAux = grafo[0];
	nodoAux->distancia = 0; //punto de entrada
	q.push(nodoAux);
	while (!q.empty())
  	{
  		Nodo* n = q.front();
  		q.pop(); // VER CORRECGTITUD DE ESTO. HACE REMOVE PERO TIENE EL ACCESS ARRIOBA
  		for (int i = 0; i < n->adyacentes.Longitud(); ++i)
  		{
  			int adj = n->adyacentes[i];
  			Nodo* vecino = grafo[adj];
  			if (vecino->distancia > n->distancia+1)
  			{
  				vecino->distancia = n->distancia+1;
  				q.push(vecino);
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
			int adj = nodoActual->adyacentes[i];
			Nodo* vecino = grafo[adj];
			if(nodoMinimo != NULL)
			{
				if(vecino->distancia <= nodoMinimo->distancia)
				{
					nodoMinimo = vecino;
				}
			}
			else
			{
				nodoMinimo = vecino;
			}
		}
		if(nodoMinimo != NULL)
		{
			imprimir.AgregarAdelante(nodoMinimo->numero);
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
