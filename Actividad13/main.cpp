// g++ main.cpp -o main.exe
// main.exe < in0.txt
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// variables globales
int n, m;
vector< vector<int> > laberinto; // [[]]
vector< vector<int> > solucion; // [[]]

// firmas de las funciones
bool backtracking(int fil, int col);
void imprime();

/*
    Complejidad O(n*m + 2^n + 2^m)
*/
int main() {
  cin >> n;
  cin >> m;
  // Por cada i desde 0 hasta n-1
  //   Agrega un renglon vacio al laberinto (push_back)
  //   Agrega un renglon vacio a la solucion (push_back)
  //   Por cada j desde 0 hasta m-1
  //      Lee un valor y guardalo en el laberinto en la posicion i,j
  
  vector<int> renglon(m); // [0,0,0,0,0,0,0,0,0]

  /*
    Complejidad: O(n*m)
    Se da debido a que vamos a recorrer todas las casillas para ir agregando cada numero uno por uno
  */
  for(int i = 0; i < n; i++){
    vector<int> rowLaberinto;
    
    // O(m)
    for(int j = 0; j < m; j++){
        int z;
        cin >> z;
        rowLaberinto.push_back(z);
    }
    solucion.push_back(renglon);
    laberinto.push_back(rowLaberinto);
  }
  /*
    Complejidad O(2^n + 2^m) 
  */
  backtracking(0,0);
  
  /*
    Complejidad O(n*m)
  */
  imprime();
}

/*
    Complejidad O(1)
*/
bool isSafe(int fil, int col){
  return fil >= 0 && fil < n && col >= 0 && col < m && laberinto[fil][col] == 1 && solucion[fil][col] == 0;
}

/*
    Complejidad: O(2^n + 2^m)
    Tenemos dos llamadas recursivas a n y dos llamadas recursivas a m. Utilizando las formula de c^n para multiples llamadas recursivas nos
    da la formula O(2^n + 2^m)
*/
bool backtracking(int fil, int col){
  if(fil == n-1 && col == m-1){
    solucion[fil][col] = 1;
    return true;
  }
  if(isSafe(fil, col)){
    solucion[fil][col] = 1;
    // Si la recursion hacia abajo da verdadero, entonces regresar verdadero
    // O (n)
    if(backtracking(fil + 1, col)){
        return true;
    }
    // Si la recursion hacia la derecha da verdadero, entonces regresar verdadero
    // O(m)
    if(backtracking(fil, col + 1)){
        return true;
    }
    // Si la recursion hacia la izquierda da verdadero, entonces regresar verdadero
    // O(m)
    if(backtracking(fil, col - 1)){
        return true;
    }
    // Si la recursion hacia arriba da verdadero, entonces regresar verdadero
    // O(n)
    if(backtracking(fil - 1, col)){
        return true;
    }
    solucion[fil][col] = 0;
  }
  return false;
}

/*
    Complejidad O(n*m)
*/
void imprime(){
  cout << "Laberinto:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << laberinto[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << "solucion:" << endl;
  for (int i = 0; i < solucion.size(); i++) {
    for (int j = 0; j < solucion[0].size(); j++) {
      cout << solucion[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}