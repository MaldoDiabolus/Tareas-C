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
    
    int i, pos, aux;
    
    for(i = 0; i < cantidad_numeros; i++){
        pos = i;
        aux = numeros[i];
        
        while ((pos > 0) && (numeros[pos-1] > aux)){
            numeros[pos] = numeros[pos-1];
            pos--;
        }
        numeros[pos] = aux;
    }
    
    cout << "Orden: ";
    for (i = 0; i < cantidad_numeros; i++){
        cout << numeros[i] << " ";
    }
    
    getch();
    return 0;
}


