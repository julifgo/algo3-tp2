#include "contraataca.h"

using namespace std;

/*// Declaraciones en el archivo .h
int cn; //cantidad de nodos
vector< vector<int> > ady; //matriz de adyacencia*/

// Devuelve la matriz de adyacencia del árbol mínimo.
void elImperioContraataca(int cn, vector< vector<int> > ady){
    vector< vector<int> > adyacencia = ady;
    vector<Arista> aristas;
    vector<Arista> solucion;
    int pesoTotal=0;

    for(int i = 0; i < cn; i++){
    	for(int j = i+1; j < cn; j++){
    		if(i!=j){
    			Arista a(i,j,adyacencia[i][j]);
    			aristas.push_back(a);
    		}
    	}
    }

    init(cn);
    MergeSort(aristas);
    vector<int> solucionParaMostrar(cn,0);

    for(int i=0 ; i<aristas.size() ; i++){
    	if(find(aristas[i].nodoA != aristas[i].nodoB)){
    		solucion.push_back(aristas[i]);
    		solucionParaMostrar[aristas[i].nodoB]=aristas[i].nodoA;
    		pesoTotal += aristas[i].peso;
    		unir(aristas[i].nodoA,aristas[i].nodoB);
    	}
    }


    cout<<pesoTotal<<endl;



}

void Merge(vector<Arista>& A,vector<Arista>& B, vector<Arista>& C){
	int ia, ib, ic;
	ia=0;
	ib=0;
	ic=0;

	for(ia; ia<A.size(); ia++){
		if(ib<B.size() && ( ic>=C.size() || B[ib].peso<C[ic].peso)){
			A[ia]=B[ib];
			ib++;
		}else{
			A[ia]=C[ic];
			ic++;
		}
	}
}

void MergeSort(vector<Arista>& A){
	if(A.size()>1){
		int n = A.size()/2;
		vector<Arista> B;
		vector<Arista> C;
		for(int i=0; i<A.size(); i++){
			if(i<n){
				B.push_back(A[i]);
			}else{
				C.push_back(A[i]);
			}
		}
		MergeSort(B);
		MergeSort(C);
		Merge(A,B,C);
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
