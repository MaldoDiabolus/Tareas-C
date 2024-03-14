#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	
	char band = 'F';
	
    int cantidad_numeros;
    cout << "Ingrese la cantidad de numeros que desea ordenar: ";
    cin >> cantidad_numeros;

    int numeros[cantidad_numeros];
    int numeros_inser [cantidad_numeros];
    cout << "Ingrese los numeros:" << endl;
    
    for (int i = 0; i < cantidad_numeros; ++i) {
        cin >> numeros[i];        
    }
    
    for (int i = 0; i < cantidad_numeros; ++i) {
        numeros_inser[i] = numeros[i];        
    }
    
    int i, pos, aux;
    
    for(i = 0; i < cantidad_numeros; i++) {
        pos = i;
        aux = numeros_inser[i];
        
        while ((pos > 0) && (numeros_inser[pos - 1] > aux)) {
            numeros_inser[pos] = numeros_inser[pos - 1];
            pos--;
        }
        numeros_inser[pos] = aux;
    }
    
    int j;
    
    for(i = 0; i < cantidad_numeros - 1; i++){
        for(j = 0; j < cantidad_numeros - i - 1; j++){
            if(numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
    
    cout << "Orden burbuja: ";
    for(i = 0; i < cantidad_numeros; i++){
        cout << numeros[i] << " ";
    }
    
    cout << "\n\nOrden insercion: ";
    for(i = 0; i < cantidad_numeros; i++){
        cout << numeros_inser[i] << " ";
    }
    
    
    int opc = 1;
    int dato = 0;
    
    while ( opc != 0 ) {
	
    cout << "\n\nElija un numero entre todos los ingresados (Ingrese 0 para terminar el programa): \n";
	cin >> dato;
	opc = dato;
	
	int inf = 0;
	int sup = cantidad_numeros;
	int mitad = (inf + sup)/2;

	
    while (inf <= sup) {
    mitad = inf + (sup - inf) / 2;

    if (numeros[mitad] == dato) {
        band = 'V';
        break;
    }
    if (numeros[mitad] > dato) {
        sup = mitad - 1;
    }
    if (numeros[mitad] < dato) {
        inf = mitad + 1; 
    }
    }
	
	if(band == 'V'){
		cout << "El numero " << dato << " ha sido encontrado en la posicion: " << mitad << endl;
	} else {
		cout << "El numero no ha sido encontrado." << endl;
	}
     
	}
    
    getch();
    return 0;
}

