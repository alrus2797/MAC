#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector< vector<float> > matriz;


void print_matriz(matriz mat){
	for(auto i:mat){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

float determinante_recursivo(matriz mat);

float cofactor(int fil, int col, matriz mat){
	
	
	mat.erase(mat.begin()+fil);
	for(int i = 0; i < mat.size();i++){
		mat.at(i).erase(mat.at(i).begin()+col);
	}
	//cout<<"signo: "<<pow(-1, col + fil)<<endl;
	cout<<"Cofactor: "<<	pow(-1, col + fil) * determinante_recursivo(mat)<<endl;	

	return pow(-1, col + fil) * determinante_recursivo(mat);
	
}


float determinante_recursivo(matriz mat){
	
	float suma = 0;
	if(mat.size()==1){
		return mat[0][0];
	}
	for(int i = 0; i < mat.at(0).size();i++){
		matriz temp = mat;
		suma += cofactor(0, i, temp) * mat.at(0).at(i);
		cout<<"  Suma: "<<suma<<endl;
	}
	cout<<"Resultado: "<<suma<<endl;
	return suma;
}

int main(){
	matriz A = {{1,1,0},{0,0,1},{2,1,0}};
	cout<<"\nMatriz: "<<endl;
	print_matriz(A);
	cout<<endl;
	cout<<"\nHallando la determinante: "<<endl;
	cout<<determinante_recursivo(A)<<endl;

}

