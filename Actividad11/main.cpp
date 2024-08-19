/*
    @author Alejandro Rodriguez del Bosque - A01722329
    @brief  M1 - Act 1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
    @date   8/12/2024
*/
// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
using namespace std;

// Firmas de las funciones
double iterativa(int n);
double recursiva(int n);
double directa(int n);

// O(n) - las funciones iterativas y directas son las de mas complejidad con O(n) por esa razon es O(n)
int main() {
  
  // Declara una variable n de tipo entero
  int n = 0;
  
  // Pide la n al usuario
  cin >> n;
  
  // Declara e inicializa un vector de enteros o dobles vector<tipo> de tamaÃ±o n
  vector<int> vec(n);
  
  // Mediante un ciclo pide los n valores
  for (int i = 0; i < vec.size(); i++){
    int num = 0;
    cin >> num;
    vec[i] = num;
  }

  for (int i = 0; i < n; i++) {
    cout << "n = " << vec[i] << endl;
    cout << "Iterativo: " << iterativa(vec[i]) << endl;
    cout << "Recursivo: " << recursiva(vec[i]) << endl;
    cout << "Directo  : " << directa(vec[i]) << endl;
  }
}

// O(n)
double iterativa(int n){
  double suma = 0;
  for (int i=1; i<=n; i++){
	  suma += i;
  }
  return suma;
}

// O(n)
double recursiva(int n){
  if (n == 1){
	  return 1;
  }
  return recursiva(n-1) + n;
}

// O(1)
double directa(int n){
  return (n*(n+1))/2;
}