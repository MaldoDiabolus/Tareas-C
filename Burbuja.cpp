#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int cantidad_numeros;
    cout << "Ingrese la cantidad de numeros que desea ordenar: ";
    cin >> cantidad_numeros;

    int numeros[cantidad_numeros];
    cout << "Ingrese los numeros:" << endl;
    for (int i = 0; i < cantidad_numeros; ++i) {
        cin >> numeros[i];
    }
    
    int i, j, aux;
    
    for(i = 0; i < cantidad_numeros - 1; i++){
        for(j = 0; j < cantidad_numeros - i - 1; j++){
            if(numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
    
    cout << "Orden: ";
    for(i = 0; i < cantidad_numeros; i++){
        cout << numeros[i] << " ";
    }
    
    getch();
    return 0;
}

