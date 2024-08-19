/*
  @author Alejandro Rodriguez del Bosque - A01722329
  @brief Implementation and initial run of the mergesort algorithm
*/
// g++ mergesort.cpp -o main.exe
// main.exe
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

#define SIZE 100

vector<int> vec(SIZE);

void random();
void print();
void merge(int start, int half, int end);
void mergeSort(int start, int end);

int main() {
  random();
  print();
  mergeSort(0,SIZE-1);
  print();
}

void random(){
  srand(time(NULL));
  for (int i=0; i<SIZE; i++){
    vec[i] = rand() % 1000;
  }
}

void print(){
  for (int i=0; i<SIZE; i++){
    cout << vec[i] << " ";
  }
  cout << endl << endl;
}

/*
    @brief Helper function for merge sort in charge of sorting the divided array
    Complexity: O(n)
    All loops inside the function operate in linear time, this being the worst complexity and therefore the complexity of the function
*/
void merge(int start, int half, int end){
  int i=start, j=half+1, k=start;
  int aux[SIZE];
 
  while (i <= half && j <= end){ // Traverses the whole array so the complexity is O(n)
    if (vec[i] < vec[j]){
      aux[k] = vec[i];
      i++;
    }else{
      aux[k] = vec[j];
      j++;
    }
    k++;
  }
  while (i <= half){ // Finishes the array in case j has exceeded end
    aux[k] = vec[i];
    k++;
    i++;
  }
  while (j <= end){ // Finishes the array in case i has exceeded half 
    aux[k] = vec[j];
    k++;
    j++;
  }
  for (int i=start; i<=end; i++){ // O(n)
    vec[i] = aux[i];
  }
}

/*
    @brief Merge Sort algorithm
    Complexity O(n log(n))
    El ciclo se va a ejecutar log(n) veces debido a dividir el problema en dos. Sin embargo al hacer esta operacion
    se encuentra con una funcion que se ejecuta en tiempo O(n). Multiplicando ambos da la complejidad de tiempo de 
    O(n log(n)). Se convierte en esto debido a que la misma cantidad de separaciones que haga va a ser la misma cantidad de 
    uniones que esta haciendo.
*/
void mergeSort(int start, int end){
  int half;
  // Si inicio < fin
  if(start == end){
    return;
  }
	//    Calcular la mitad del conjunto
    half = (start + end) / 2;
	//    Llamada recursiva con los parÃ¡metros inicio y mitad
    mergeSort(start, half);
	//    Llamada recursiva con los parÃ¡metros mitad+1 y fin
    mergeSort(half +1, end);
	//    Llamada a la funciÃ³n merge con los parÃ¡metros inicio, mitad y fin
    merge(start, half, end); // Complejidad: O(n)
}