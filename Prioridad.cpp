#include <iostream>
using namespace std;

struct nodo {
    int proceso;
    int prioridad;
    nodo* sig;
};

nodo* cabeza = nullptr;

void inser_proc();
void mostrar_lista();
void procesar();

int main() {
    int menu_prin = 0;
    cabeza = nullptr; // Inicializar cabeza en main()

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

    if (cabeza == nullptr) {
        cabeza = nuevo;
        cabeza->sig = nullptr;
    } else {
        if (nuevo->prioridad < cabeza->prioridad) {
            nuevo->sig = cabeza;
            cabeza = nuevo;
        } else {
            nodo* actual = cabeza;
            nodo* actual_s = cabeza->sig;
            while (actual_s != nullptr && actual_s->prioridad <= nuevo->prioridad) {
                actual = actual->sig;
                actual_s = actual_s->sig;
            }
            actual->sig = nuevo;
            nuevo->sig = actual_s;
        }
    }
    cout << "\n\nNumero ingresado a la lista.\n\n";
}

void procesar() {
    if (cabeza != nullptr) {
        nodo* temp = cabeza;
        nodo* prev = nullptr;
        while (temp->sig != nullptr) {
            prev = temp;
            temp = temp->sig;
        }
        if (prev != nullptr) {
            cout << "\n\nSe ha atendido el proceso " << temp->proceso << " de prioridad " << temp->prioridad << "\n\n";
            prev->sig = nullptr;
            delete temp;
        } else {
            cout << "\n\nSe ha atendido el proceso " << cabeza->proceso << " de prioridad " << cabeza->prioridad << "\n\n";
            delete cabeza;
            cabeza = nullptr;
        }
    } else {
        cout << "\n\nNo hay procesos para atender.\n\n";
    }
}

void mostrar_lista() {
    nodo* actual = cabeza;

    if (cabeza != nullptr) {
        cout << "Proceso | Prioridad" << endl;

        while (actual != nullptr) {
            cout << "   " << actual->proceso << "  |  " << actual->prioridad << endl;
            actual = actual->sig;
        }
    } else {
        cout << "\n\nNo ha insertado ningun numero aun.\n\n";
    }
}




