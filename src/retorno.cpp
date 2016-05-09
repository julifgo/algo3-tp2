#include "retorno.h"
using namespace std;


int main(){

	ElRetornoDelJedi();

	return 0;
}


void ElRetornoDelJedi(vector<vector<int> > grilla, int h, int n, int m) {
	vector<vector<pair<int, Direccion> > > Dic;
	Dic.resize(grilla.size());
	for(int i =0; i<Dic.size();i++){
		Dic[i].resize(grilla[i].size());
	}
	pair<int, Direccion> p;
	p.first = 0;
	p.second = sinDireccion;
	Dic[1][1] = p;

	for(int i=2; i<n;i++){
		pair<int, Direccion> p1;
		p1.second=izquierda;
		p1.first = Dic[1][i-1].first + max(abs(grilla[1][i] - grilla[i-1][1]) - h);
		Dic[i,1]= p1;
	}

	for(int i=2; i<n;i++){
		pair<int, Direccion> p1;
		p1.second=arriba;
		p1.first = Dic[i-1][1].first + max(abs(grilla[i][1] - grilla[1][i-1]) - h);
		Dic[1,i]= p1;
	}

	for(int i=2; i<n;i++){
		for(int j=2; j<n;j++){
			if(min(Dic[j][i-1].first + max(abs(grilla[1][i] -grilla[1][i-1]) - h, 0) + max(abs(grilla[j][i]-grilla[j-1][i]) - h, 0)
					== Dic[j][i-1].first + max(abs(grilla[j][i] - grilla[j][i-1])-h,0))){
				pair<int, Direccion> p1;
				p1.second=arriba;
				p1.first = Dic[j][i-1].first + max(abs(grilla[j][i]-grilla[j][i-1]) - h,0);
				Dic[j][i]=p1;
			}else{
				pair<int, Direccion> p1;
				p1.second=izquierda;
				p1.first = Dic[j-1][i].first + max(abs(grilla[j][i]-grilla[j-1][i]) - h,0);
				Dic[j][i]=p1;

			}
		}
	}
}



int max (int a, int b) {
  return (a<b)?b:a;
}

int min (int a, int b) {
  return (a>b)?b:a;
}
