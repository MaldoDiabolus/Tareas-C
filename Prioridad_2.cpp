#include <iostream>
using namespace std;

struct nodo {
    int proceso;
    int prioridad;
    nodo* sig;
};

nodo* pila = NULL;

void inser_proc();
void mostrar_lista();
void procesar();

int main() {
    int menu_prin = 0;

    while (menu_prin != 4) {

        cout << "\n\nIngrese el numero correspondiente a la accion que desea realizar: \n\n";
        cout << "1). Agregar un nuevo proceso.\n";
        cout << "2). Atender proceso.\n";
        cout << "3). Mostrar los valores ingresados en lista.\n";
        cout << "4). Salir del programa.\n\n";

        cin >> menu_prin;

        switch (menu_prin) {

            case 1:
                inser_proc();
                break;

            case 2:
                procesar();
                break;

            case 3:
                mostrar_lista();
                break;

            case 4:
                cout << "\nPrograma terminado.\n\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
                break;
        }
    }

    return 0;
}

void inser_proc() {
    nodo* nuevo = new nodo();
    cout << "Ingrese el numero correspondiente al proceso: ";
    cin >> nuevo->proceso;

    cout << "Ingrese la prioridad de este proceso: ";
    cin >> nuevo->prioridad;


    if (pila == NULL || nuevo->prioridad > pila->prioridad) {
        nuevo->sig = pila;
        pila = nuevo;
    } else {
        nodo* temp = pila;

        while (temp->sig != NULL && nuevo->prioridad <= temp->sig->prioridad) {
            temp = temp->sig;
        }

        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }

    cout << "\n\nNumero ingresado a la lista.\n\n";
}

void procesar() {
    if (pila != NULL) {
        nodo* temp = pila;
        nodo* prioridad_max = pila;
        
       
        while (temp != NULL) {
            if (temp->prioridad > prioridad_max->prioridad) {
                prioridad_max = temp;
            }
            temp = temp->sig;
        }
        
   
        temp = pila;
        if (prioridad_max == pila) {
            pila = pila->sig;
        } else {
            while (temp->sig != prioridad_max) {
                temp = temp->sig;
            }
            temp->sig = prioridad_max->sig;
        }
        
        cout << "\n\nSe ha atendido el proceso " << prioridad_max->proceso << " de prioridad " << prioridad_max->prioridad << "\n\n";
        delete prioridad_max;
    } else {
        cout << "\n\nNo hay procesos para atender.\n\n";
    }
}

void mostrar_lista() {
    nodo* actual = pila;

    if (actual != NULL) {
        cout << "Proceso | Prioridad" << endl;

        while (actual != NULL) {
            cout << "   " << actual->proceso << "  |  " << actual->prioridad << endl;
            actual = actual->sig;
        }
    } else {
        cout << "\n\nNo ha insertado ningun numero aun.\n\n";
    }
}




