#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
	int inf, sup, mitad, dato;
	char band = 'F';
	
	do {
		cout << "Por favor, elija un numero entre 1 y 10: ";
		cin >> dato;
		
		if (dato < 1 || dato > 10) {
			cout << "Numero invalido. Por favor, ingrese un numero entre 1 y 10." << endl;
		}
	} while (dato < 1 || dato > 10);
	
	inf = 0;
	sup = 10;
	
	while(inf <= sup){
		mitad = (inf + sup)/2;
		
		if(numeros[mitad] == dato){
			band = 'V';
			break;
		}
		if (numeros[mitad] > dato){
			sup = mitad - 1;
		}
		if (numeros[mitad] < dato){
			inf = mitad + 1; 
		}
	}
	
	if(band == 'V'){
		cout << "El numero " << dato << " ha sido encontrado en la posicion: " << mitad << endl;
	} else {
		cout << "El numero no ha sido encontrado." << endl;
	}

	getch();
	return 0;
}


