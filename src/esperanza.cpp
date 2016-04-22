#include "esperanza.h"
using namespace std;



int main(){
	
	int N;
	int M;
	cin>>N>>M;
	aed2::Arreglo<aed3::Lista<pair<int,int> > > grafo(N);

	for(int i=0;i<M;i++){
		int x;
		int y;
		int especial;
		cin>>x>>y>>especial;
		if(!grafo.Definido(x)){
			grafo.Definir(x, aed3::Lista<pair<int,int> >());
		}
		grafo[x].AgregarAtras(pair<int,int>(y,especial));

		if(!grafo.Definido(y)){
			grafo.Definir(y, aed3::Lista<pair<int,int> >());
		}
		grafo[y].AgregarAtras(pair<int,int>(x,especial));
	}


	UnaNuevaEsperanza(grafo);
	
	return 0;
}


void UnaNuevaEsperanza (aed2::Arreglo<aed3::Lista<pair<int,int> > > grafo) {
	/*cout<<"Nodo 0 tiene "<<grafo[0].Longitud()<<" aristas adyacentes"<<endl;
	cout<<"Nodo 1 tiene "<<grafo[1].Longitud()<<" aristas adyacentes"<<endl;
	cout<<"Nodo 2 tiene "<<grafo[2].Longitud()<<" aristas adyacentes"<<endl;*/
	
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
