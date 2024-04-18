#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* der;
    nodo* izq;
    
    nodo(int valor): valor(valor), izq(NULL), der(NULL) {}
};

class arbol {
private:
    nodo* raiz;

public:
    arbol(): raiz(NULL) {}

    void insert(int valor) {
        if (raiz == NULL) {
            raiz = new nodo(valor);
        } else {
            resurInsert(raiz, valor, 1);
        }
    }

    nodo* resurInsert(nodo* actual, int valor, int level) {
        if (actual == NULL) {
            return new nodo(valor);
        } else if (valor < actual->valor && level < 3) {
            actual->izq = resurInsert(actual->izq, valor, level+1);
        } else if (valor > actual->valor && level < 3) {
            actual->der = resurInsert(actual->der, valor, level+1);
        } else if (valor == actual->valor) {
            cout << "Este numero ya fue ingresado. No se permiten duplicados";
            return actual;
        } else {
            cout << "\n\nNo se ha ingresado el valor puesto que es menor o mayor a los ya ingresados en la hilera de hijos #2. \n\n"; 
            return actual;
        }
        return actual;
    }

    void buscar(nodo* actual, int valor) {     
        if (actual != NULL) {
            if (valor == actual->valor) {
                cout << "\nEl valor ingresado ha sido encontrado.\n\n";
            } else if (valor < actual->valor) {
                actual = actual->izq;
                buscar(actual, valor);
            } else if (valor > actual->valor) {
                actual = actual->der;
                buscar(actual, valor);
            } else {
                cout << "\nEl valor ingresado no se encontro en el arbol.\n\n";
            }
        } else {
            cout << "\nNo ha ingresado ningun valor a la lista aun.\n\n";
        }   
    }

    void buscar(int valor) {
        buscar(raiz, valor);
    }

    void mostrarPreorden(nodo* actual) {
        if (actual != NULL) {
            cout << actual->valor << " ";
            mostrarPreorden(actual->izq);
            mostrarPreorden(actual->der);
        }
    }

    void mostrarPreorden() {
        mostrarPreorden(raiz);
    }

    void mostrarInorden(nodo* actual) {
        if (actual != NULL) {
            mostrarInorden(actual->izq);
            cout << actual->valor << " ";
            mostrarInorden(actual->der);
        }
    }

    void mostrarInorden() {
        mostrarInorden(raiz);
    }

    void mostrarPostorden(nodo* actual) {
        if (actual != NULL) {
            mostrarPostorden(actual->izq);
            mostrarPostorden(actual->der);
            cout << actual->valor << " ";
        }
    }

    void mostrarPostorden() {
        mostrarPostorden(raiz);
    }

};

int main() {
    int valor = 0 ;
    int menu_prin = 0;
    arbol miarbol;

    while (menu_prin != 5) {
        cout << "\n\nIngrese el numero correspondiente a la accion que desea realizar: \n\n";
        cout << "1). Agregar un nuevo numero al arbol.\n"; 
        cout << "2). Buscar un numero en el árbol.\n";
        cout << "3). Mostrar los valores ingresados al arbol en preorden.\n";
        cout << "4). Mostrar los valores ingresados al arbol en inorden.\n";
        cout << "5). Mostrar los valores ingresados al arbol en postorden.\n";
        cout << "6). Salir del programa.\n\n";
        
        cin >> menu_prin;

        switch (menu_prin) {
            case 1:
                cout << "Digita el numero que quieres insertar al arbol: \n\n";
                cin >> valor;
                miarbol.insert(valor);
                break;
            
            case 2:
                cout << "Digita el numero que quieres buscar en el arbol: \n\n";
                cin >> valor;
                miarbol.buscar(valor);
                break;
            
            case 3:
                cout << "\nRecorrido en preorden:\n";
                miarbol.mostrarPreorden();
                cout << endl;
                break;
            
            case 4:
                cout << "\nRecorrido en inorden:\n";
                miarbol.mostrarInorden();
                cout << endl;
                break;
            
            case 5:
                cout << "\nRecorrido en postorden:\n";
                miarbol.mostrarPostorden();
                cout << endl;
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

