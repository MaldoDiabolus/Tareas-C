#include <iostream>
using namespace std;

struct nodo {
    int num_list;
    nodo* ant;
    nodo* sig;
} *cabeza, *cola;

void insertar_nodo();
void borrar_nodo();
void borrar_por_posicion();
void mostrar_lista(int cont);
void sumar_todo(int cont);
void max_min(int cont);

int main() {
    int cont = 0;
    int menu_prin = 0;

    while (menu_prin != 6) {
        cout << "Ingrese el numero correspondiente a la accion que desea realizar: \n\n";
        cout << "1). Ingresar un nuevo numero a la lista.\n";
        cout << "2). Ver los numeros enlistados.\n";
        cout << "3). Borrar algun numero registrado.\n";
        cout << "4). Mostrar la suma de todos los numeros ingresados.\n";
        cout << "5). Mostrar numeros mayores y menores en la lista.\n";
        cout << "6). Salir del programa.\n\n";

        cin >> menu_prin;

        switch (menu_prin) {

        case 1:
            insertar_nodo();
            cont = cont + 1;
            break;

        case 2:
            mostrar_lista(cont);
            break;

        case 3:
            borrar_nodo();
            break;

        case 4:
            sumar_todo(cont);
            break;

        case 5:
            max_min(cont);
            break;

        case 6:
            cout << "\nPrograma terminado.\n\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n\n";
            break;
        }
    }

    return 0;
}

void insertar_nodo() {
    nodo* nuevo = new nodo();
    cout << "Ingrese el siguiente numero que quiere ingresar a la lista: ";
    cin >> nuevo->num_list;

    if (cabeza == NULL) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->sig = nuevo;
        nuevo->ant = cola;
        cola = nuevo;
    }
    cout << "\n\nNumero ingresado a la lista.";
}

void mostrar_lista(int cont) {
    nodo* actual = cabeza;
    if (cabeza != NULL) {
        while (cont != 0) {
            cout << "  " << actual->num_list << endl;
            actual = actual->sig;
            cont = cont - 1;
        }
    } else {
        cout << "\n\nNo ha insertado ningun numero aun.\n\n";
    }
}

void max_min(int cont) {
    nodo* actual = cabeza;
    int max;
    int min;
    int num_actu;

    if (cabeza != NULL) {
        max = actual->num_list;
        min = actual->num_list;

        while (cont != 0) {
            num_actu = actual->num_list;

            if (max < num_actu) {
                max = num_actu;
            }

            if (min > num_actu) {
                min = num_actu;
            }

            actual = actual->sig;
            cont = cont - 1;
        }

        cout << "\n\nEl numero con valor maximo ingresado a la lista es: " << max << "\n\nY el menor es: " << min << "\n\n";
    } else {
        cout << "\n\nNo ha insertado ningun numero aun.\n\n";
    }
}

void borrar_nodo() {
    nodo* actual = cabeza;
    bool encontrado = false;

    cout << "\n\nPrimero tengamos en cuenta los numeros ingresados en la lista:\n";

    while (actual != NULL) {
        cout << "  " << actual->num_list << endl;
        actual = actual->sig;
    }

    if (cabeza != NULL) {
        borrar_por_posicion();
    } else {
        cout << "\n\nComo no ha insertado ningun numero aun, no hay ningun numero para eliminar.\n\n";
    }
}

void borrar_por_posicion() {
    nodo* actual = cabeza;
    int x = 0;
    cout << "\nTeniendo en cuenta la recapitulacion de los numeros ingresados, ingrese el numero de la posicion en la lista del nodo que desea eliminar: \n\n";
    cin >> x;

    int xbackup = x;

    if (x > 0) {
        if (x == 1) {
            if (cabeza != NULL) {
                cout << "\n\nEl nodo en la posicion #" << xbackup << " con valor " << cabeza->num_list << " ha sido eliminado.\n\n" << endl;
                cabeza = cabeza->sig;
                delete actual;
            } else {
                cout << "\n\nLa lista ya está vacía.\n\n" << endl;
            }
        } else {

            for (int i = 1; actual != NULL && i < x; ++i) {
                actual = actual->sig;
            }
            if (actual != NULL) {
                actual->ant->sig = actual->sig;
                if (actual->sig != NULL) {
                    actual->sig->ant = actual->ant;
                }
                cout << "\n\nEl nodo en la posicion #" << xbackup << " con valor " << actual->num_list << " ha sido eliminado.\n\n" << endl;
                delete actual;
            } else {
                cout << "\n\nLa posicion ingresada es mayor que el tamano de la lista.\n\n" << endl;
            }
        }
    } else {
        cout << "\n\nEl numero de la posicion en la lista del nodo no puede ser 0 o negativo, intente nuevamente.\n\n";
    }
}

void sumar_todo(int cont) {
    int sumados = 0;
    nodo* actual = cabeza;

    for (cont; cont != 0; cont = cont - 1) {
        sumados = sumados + actual->num_list;
	}

}

