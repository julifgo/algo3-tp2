#include "retorno.h"

using namespace std;


/*int main(){

	ElRetornoDelJedi();

	return 0;
}*/


void ElRetornoDelJedi(int** grilla, int h, int n, int m){
	pair<int, Direccion>** Dic;
	Dic = new pair<int, Direccion>*[m];
	for(int i =0; i<m;i++){
		Dic[i] = new pair<int,Direccion>[n];
	}
	/*for(int i=0; i<n; i++){
		for(int j=0; j<m;j++){
			cout<<grilla[j][i]<<" ";
		}
		cout<<endl;
	}

	/*Dic.resize(n);
	for(int i =0; i<Dic.size();i++){
		Dic[i].resize(m);
	}*/
	pair<int, Direccion> p;
	p.first = 0;
	p.second = sinDireccion;
	Dic[0][0] = p;

	for(int i=1; i<m;i++){
		pair<int, Direccion> p1;
		p1.second=arriba;
		p1.first = Dic[i-1][0].first + max(std::abs(grilla[i][0] - grilla[i-1][0]) - h,0);
		Dic[i][0]= p1;
	}

	for(int i=1; i<n;i++){
		pair<int, Direccion> p1;
		p1.second=izquierda;
		p1.first = Dic[0][i-1].first + max(abs(grilla[0][i] - grilla[0][i-1]) - h,0);
		Dic[0][i]= p1;
	}

	for(int i=1; i<n;i++){
		for(int j=1; j<m;j++){
			if(min(Dic[j][i-1].first + max(abs(grilla[j][i] -grilla[j][i-1]) - h, 0), Dic[j-1][i].first + max(abs(grilla[j][i]-grilla[j-1][i]) - h, 0))
					== Dic[j][i-1].first + max(abs(grilla[j][i] - grilla[j][i-1])-h,0)){
				pair<int, Direccion> p1;
				p1.second=izquierda;
				p1.first = Dic[j][i-1].first + max(abs(grilla[j][i]-grilla[j][i-1]) - h,0);
				Dic[j][i]=p1;
			}else{
				pair<int, Direccion> p1;
				p1.second=arriba;
				p1.first = Dic[j-1][i].first + max(abs(grilla[j][i]-grilla[j-1][i]) - h,0);
				Dic[j][i]=p1;

			}
		}
	}
	/*for(int i=0; i<n; i++){
		for(int j=0; j<m;j++){
			cout<<Dic[j][i].first<<" ";
		}
		cout<<endl;
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n;j++){
			cout<<Dic[j][i].second<<" ";
		}
		cout<<endl;
	}*/


	int i,j,C;
	std::vector<std::string> camino;
	C=0;
	i=m-1;
	j=n-1;

	while(i!=0 || j!=0){
			if(Dic[i][j].second == arriba){
				camino.push_back("Y");
				//C+=Dic[i][j].first;
				i--;
				//C+=Dic[i][j].first;
			}else{
				camino.push_back("X");
				//C+=Dic[i][j].first;
				j--;
			}
	}


	cout<<Dic[m-1][n-1].first<<endl;
	while(camino.size()>0) {
		cout<< camino.back() <<endl;
		camino.pop_back();
	}

	delete[] Dic;
}



int max (int a, int b) {
  return (a<b)?b:a;
}

int min (int a, int b) {
  return (a>b)?b:a;
}
