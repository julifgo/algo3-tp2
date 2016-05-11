/*
 * ElImperioContraataca.cpp
 *
 *  Created on: 24/4/2016
 *      Author: agustin
 */

#include "contraataca.h"
#include <queue>

using namespace std;

vector<int> padre;
vector<int> altura;



// Devuelve la matriz de adyacencia del árbol mínimo.
void elImperioContraataca(int cn, int m, vector< Arista > ady){

    Arista *aristas;
    vector<Arista> solucion;
    int pesoTotal=0;

    aristas = new Arista[m];


    for(int i=0; i<m;i++){
    	aristas[i]=ady[i];
    }

    init(cn);
    MergeSortPeso(aristas,m);
    vector<vector<int> > solucionParaMostrar;
    solucionParaMostrar.resize(cn);

    for(int i=0 ; i<m ; i++){
    	if(find(aristas[i].nodoA) != find(aristas[i].nodoB)){
    		solucion.push_back(aristas[i]);
    		solucionParaMostrar[aristas[i].nodoB].push_back(aristas[i].nodoA);
    		solucionParaMostrar[aristas[i].nodoA].push_back(aristas[i].nodoB);
    		pesoTotal += aristas[i].peso;
    		unir(aristas[i].nodoA,aristas[i].nodoB);
    	}
    }

    vector<bool> visitados(cn,false);
    visitados[0]=true;
    vector<int> arbol;
    arbol.resize(cn,0);

    std::queue<int> bfsq;
    bfsq.push(0);

    while(!bfsq.empty())
    {
      int u=bfsq.front();
      bfsq.pop();
      //Now look at all neighbours of u
      for(int i=0;i<solucionParaMostrar[u].size();i++)
      {
        int v=solucionParaMostrar[u][i];
        //If v has not been processed yet, do that now
        if(!visitados[v])
        {
          visitados[v]=true;
          arbol[v]=u;
          bfsq.push(v);
        }
      }
    }


    cout<<pesoTotal<<endl;
    for(int i=1; i<arbol.size(); i++){
    	cout<<arbol[i]<<endl;
    }

    delete[] aristas;

}

void MergePeso(Arista* A, int size1, Arista* B,  int size2, Arista C[] ){
	int i1, i2, i3;
	    i1 = 0; i2 = 0; i3 = 0;
	    /* while both lists are non-empty */
	    while (i1 < size1 && i2 < size2) {
	        if (A[i1].peso < B[i2].peso) {
	            C[i3++] = A[i1++];
	        }
	        else {
	            C[i3++] = B[i2++];
	        }
	    }
	    while (i1 < size1) {
	        /* copy remainder of list1 */
	        C[i3++] = A[i1++];
	    }
	    while (i2 < size2) {
	        /* copy remainder of list2 */
	        C[i3++] = B[i2++];
	    }
}

void MergeSortPeso(Arista* A, int size){
	Arista temp[size];
	int mid;
	if(size >= 2){
		 mid = size / 2;
		 MergeSortPeso(A, mid);
		 MergeSortPeso(A + mid, size - mid);
		 MergePeso(A, mid, A + mid, size - mid, temp);
		 for (int i = 0; i < size; i++) {
		    A[i] = temp[i];
		 }
	}
}


void init(int n){
	altura.resize(n);
	padre.resize(n);
	for(int i =0; i<n;i++){
		altura[i] = 1;
		padre[i] = i;
	}
}

int find(int x){
	if(padre[x]!=x){
		padre[x] = find(padre[x]);
	}
	return padre[x];
}

void unir(int x, int y){
	x= find(x);
	y= find(y);

	if(altura[x]<altura[y]){
		padre[x] = y;
	}else{
		if(altura[x]==altura[y]){
			altura[x]=altura[x]+1;
		}
		padre[y] = x;
	}
}
