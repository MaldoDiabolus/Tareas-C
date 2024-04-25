#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* izq;
    nodo* der;
    int altura;

    nodo(int valor): valor(valor), izq(NULL), der(NULL), altura(1) {}
};

class arbol {
private:
    nodo* raiz;

public:
    arbol(): raiz(NULL) {}

    
    int altura(nodo* n) {
        if (n == NULL) return 0;
        return n->altura;
    }


    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

 
    nodo* rotarDerecha(nodo* y) {
        nodo* x = y->izq;
        nodo* Temp = x->der;

      
        x->der = y;
        y->izq = Temp;

       
        y->altura = maximo(altura(y->izq), altura(y->der)) + 1;
        x->altura = maximo(altura(x->izq), altura(x->der)) + 1;

        return x;
    }


    nodo* rotarIzquierda(nodo* x) {
        nodo* y = x->der;
        nodo* Temp = y->izq;

      
        y->izq = x;
        x->der = Temp;

    
        x->altura = maximo(altura(x->izq), altura(x->der)) + 1;
        y->altura = maximo(altura(y->izq), altura(y->der)) + 1;

        return y;
    }

    
    int factorEquilibrio(nodo* n) {
        if (n == NULL) return 0;
        return altura(n->izq) - altura(n->der);
    }

   
    nodo* insertar(nodo* nodoActual, int valor) {

        if (nodoActual == NULL) return new nodo(valor);

        if (valor < nodoActual->valor) {
            nodoActual->izq = insertar(nodoActual->izq, valor);
        } else if (valor > nodoActual->valor) {
            nodoActual->der = insertar(nodoActual->der, valor);
        } else {
            cout << "Este numero ya fue ingresado. No se permiten duplicados" << endl;
            return nodoActual;
        }


        nodoActual->altura = 1 + maximo(altura(nodoActual->izq), altura(nodoActual->der));

    
        int equilibrio = factorEquilibrio(nodoActual);

   
        if (equilibrio > 1 && valor < nodoActual->izq->valor)
            return rotarDerecha(nodoActual);


        if (equilibrio < -1 && valor > nodoActual->der->valor)
            return rotarIzquierda(nodoActual);


        if (equilibrio > 1 && valor > nodoActual->izq->valor) {
            nodoActual->izq = rotarIzquierda(nodoActual->izq);
            return rotarDerecha(nodoActual);
        }


        if (equilibrio < -1 && valor < nodoActual->der->valor) {
            nodoActual->der = rotarDerecha(nodoActual->der);
            return rotarIzquierda(nodoActual);
        }

        return nodoActual;
    }

 
    void insertar(int valor) {
        raiz = insertar(raiz, valor);
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
        cout << endl;
    }
};

int main() {
    int valor = 0 ;
    int menu_prin = 0;
    arbol miarbol;

    while (menu_prin != 3) {
        cout << "\n\nIngrese el numero correspondiente a la accion que desea realizar: \n\n";
        cout << "1). Agregar un nuevo numero al arbol.\n"; 
        cout << "2). Mostrar los valores ingresados al arbol.\n";
        cout << "3). Salir del programa.\n\n";
        
        cin >> menu_prin;

        switch (menu_prin) {
            case 1:
                cout << "Digita el numero que quieres insertar al arbol: \n\n";
                cin >> valor;
                miarbol.insertar(valor);
                break;
            
            case 2:
                cout << "\nValores del arbol en orden:\n";
                miarbol.mostrarInorden();
                break;
            
            case 3:
                cout << "\nPrograma terminado.\n\n";
                break;
            
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
                break;
        }   
    }

    return 0; 
}

