#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef vector<vector<double>> Matriz;
typedef vector<double> Vector;

void imprimirMatriz( Matriz &matriz, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      printf(" %5.2f ", matriz[i][j]);
    cout << endl;
  }
}

//Multiplicar escalar por vector
Vector operator *(double m,Vector &v)
{
  double n= v.size();
  Vector nuevo(n);

  for(int i=0; i<n;i++)
    nuevo[i] = v[i]*m;
  return nuevo;
}

//Sumar dos vectores
Vector operator +(Vector &v1,Vector &v2)
{
  double n= v1.size();
  Vector nuevo(n);
  for(int i=0; i<n;i++)
    nuevo[i] = v1[i] + v2[i];
  return nuevo;
}

// -------------------- DETERMINANTE ------------------------//
double Determinante(Matriz &Ab)
{
  double m,resp;
  Vector temp;

  double n = Ab.size();

  for(int j=0; j<n; j++)
  {
    for(int i=j+1; i<n;i++)
    {
      m = -Ab[i][j]/Ab[j][j];
      temp = m*Ab[j];
      Ab[i] = Ab[i] + temp;
    }
    imprimirMatriz(Ab,n,n);cout<<endl;
  }

  resp = 1;  
  for(int i=0; i<n; i++)
    resp = resp * Ab[i][i];
  cout<<"Resultado: "<<resp<<endl;
  return resp;
}

int main()
{
  //Matriz A = {{5,2,-1},{2,2,5},{1,3,-1}};
  //Matriz A = {{-1,3,1},{2,5,3},{1,-2,1}};
  //Matriz A={{1,1,0},{0,0,1},{2,1,0}};
  Matriz A={{2,2,0},{1,1,2},{4,1,1}};

  double n = A.size();
  cout<<"\nMatriz: "<<endl;
  imprimirMatriz(A, n,n);
  cout<<endl;

  cout<<"\nHallando la determinante: "<<endl;
  cout<<"Respuesta: "<<Determinante(A);
  cout<<endl;

  return 0;
}
