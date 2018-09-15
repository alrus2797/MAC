#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef vector<vector<double>> Matriz;
typedef vector<double> Vector;

void imprimirVector( Vector b ,int n)
{
  for (auto i = b.begin(); i != b.end(); ++i)
    printf(" %5.3f ", *i ); //cout << *i << "   ";
}

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

int PosMax(Matriz &A,int i , int j)
{
  double n = A.size();
  double max=0;
  int pos_max= 0;
  Vector X;

  // Copiar columna
  for(int k = i; k <n; k++)
  {
    if (fabs(A[k][j]) > max )
    {
      max = fabs(A[k][j]);
      pos_max = k;
    }
  }
  return pos_max;
}

//Cambia filas en AB ( n = n+1)
Matriz CambiarFilas(Matriz &A, int i, int k)
{
  double n = A.size();
  Vector X;

  // Copiar fila
  for(int j=0 ; j <=n; j++)
    X.push_back( A[i][j]);
  for(int j=0 ; j <=n; j++)
  {
    A[i][j]= A[k][j];
    A[k][j]= X[j];
  }
  return A;
}


void OperacionesElementales(Matriz &Ab)
{
  double m, ind=0;
  Vector temp ,nuevoV , res, v;

  double n = Ab.size();

  for(int j=0; j<n; j++)
  {
    //ind = PosMax(Ab,j,j);
    Ab = CambiarFilas(Ab,j,ind);

    imprimirMatriz(Ab,n,n);cout<<endl;

    for(int i=j+1; i<n;i++)
    {
      m = -Ab[i][j]/Ab[j][j];
      temp = m*Ab[j];
      Ab[i] = Ab[i] + temp;
    }
    imprimirMatriz(Ab,n,n);cout<<endl;
  }

  cout<<"Nueva mat: \n";
  imprimirMatriz(Ab,n,n);
  //nuevoV = nuevoVect(Ab,n);

  //res = SustRegre( nuevaM , nuevoV );
  //return res;
}

int main()
{
  cout <<" Operaciones elementales: \n";
  Matriz A = {{-1,3,2},{2,-5,1},{3,1,-6}};
  double n = A.size();
  OperacionesElementales(A);
  return 0;
}
