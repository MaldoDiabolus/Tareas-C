#include<iostream>
#include<cstdlib>
#include<climits>
#include<set>

using namespace std;


struct nodo {
    int dato;
    struct nodo *liga_vertice;
    struct nodo *liga_arista;
    int distancia; 
    bool visitado; 
};

typedef struct nodo *registro;
registro sig_ver, ante_ver, cab_ver, sig_ari, ante_ari, dir1, dir2;

registro nuevo_vertice(int dat) {
    registro reg_ver = new(struct nodo);
    reg_ver->dato = dat;
    reg_ver->liga_vertice = NULL;
    reg_ver->liga_arista = NULL;
    return reg_ver;
}

void insertarVertice(int dat) {
    int sw = 0;
    ante_ver = cab_ver;
    sig_ver = cab_ver;

    while (sig_ver != NULL && sw == 0) {
        if (sig_ver->dato == dat) {
            sw = 1;
        } else {
            ante_ver = sig_ver;
            sig_ver = sig_ver->liga_vertice;
        }
    }

    if (sw == 1) {
        cout << "\n Vertice ya existente, no se adiciona!\n";
    } else {
        if (cab_ver == NULL) {
            cab_ver = nuevo_vertice(dat);
        } else {
            ante_ver->liga_vertice = nuevo_vertice(dat);
        }
        cout << "Vertice Agregado \n";
    }
}

registro recorrer_vertice(int dat) {
    registro dir;
    dir = NULL;
    sig_ver = cab_ver;

    while (sig_ver != NULL) {
        if (sig_ver->dato == dat) {
            dir = sig_ver;
        }
        sig_ver = sig_ver->liga_vertice;
    }
    return dir;
}

registro nueva_arista(int pes) {
    registro reg_ari = new(struct nodo);
    reg_ari->dato = pes;
    reg_ari->liga_arista = NULL;
    reg_ari->liga_vertice = dir2;
    return reg_ari;
}

void insertarArista(int dato_destino) {
    int pes, sw2 = 0;
    ante_ari = dir1;
    sig_ari = dir1;

    while (sig_ari != NULL && sw2 == 0) {
        if (sig_ari->dato == dato_destino) {
            sw2 = 1;
        } else {
            ante_ari = sig_ari;
            sig_ari = sig_ari->liga_arista;
        }
    }

    if (sw2 == 1) {
        cout << "Arista ya existente, no se adiciona!\n\n";
    } else {
        cout << "Digite el peso de la arista: ";
        cin >> pes;
        ante_ari->liga_arista = nueva_arista(pes);
    }
}

void verlista() {
    cout << "\n\n Ver lista de vertices y sus aristas";
    sig_ver = cab_ver;

    while (sig_ver != NULL) {
        cout << "\n El nodo ";
        cout << (sig_ver->dato);
        cout << " Tiene Arista a los siguientes vertices ";
        sig_ari = sig_ver->liga_arista;
        while (sig_ari != NULL) {
            cout << " ";
            dir1 = sig_ari->liga_vertice;
            cout << dir1->dato;
            sig_ari = sig_ari->liga_arista;
        }
        sig_ver = sig_ver->liga_vertice;
    }

}

void calcularCaminoMasCorto(int origen, int destino) {

    for (registro ver = cab_ver; ver != NULL; ver = ver->liga_vertice) {
        ver->distancia = (ver->dato == origen) ? 0 : INT_MAX;
        ver->visitado = false;
    }

    while (true) {
        registro actual = NULL;
        for (registro ver = cab_ver; ver != NULL; ver = ver->liga_vertice) {
            if (!ver->visitado && (actual == NULL || ver->distancia < actual->distancia)) {
                actual = ver;
            }
        }

        if (actual == NULL || actual->dato == destino) break;

        actual->visitado = true;

        for (registro ari = actual->liga_arista; ari != NULL; ari = ari->liga_arista) {
            registro vecino = ari->liga_vertice;
            if (vecino->distancia > actual->distancia + ari->dato) {
                vecino->distancia = actual->distancia + ari->dato;
            }
        }
    }


    registro destino_nodo = recorrer_vertice(destino);
    if (destino_nodo->distancia == INT_MAX) {
        cout << "No hay camino desde " << origen << " hasta " << destino << endl;
    } else {
        cout << "La distancia mas corta desde " << origen << " hasta " << destino << " es: " << destino_nodo->distancia << endl;
    }
}

int main() {
    cab_ver = NULL;
    int dato_origen, dato_destino;
    int sw, opcion;

    do {
        cout << "\n\t Menu! \n" << endl;
        cout << "1. Crear vertices" << endl;
        cout << "2. Creacion de aristas" << endl;
        cout << "3. Ver Grafo" << endl;
        cout << "4. Calcular camino mas corto" << endl;
        cout << "5. Salir" << endl;
        cout << "\nDigite su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite un numero para el vertice: ";
                cin >> dato_origen;
                insertarVertice(dato_origen);
                system("pause");
                break;
            case 2:
                cout << "Digite el nodo de origen: ";
                cin >> dato_origen;
                cout << "Digite el nodo de destino: ";
                cin >> dato_destino;
                dir1 = recorrer_vertice(dato_origen);
                dir2 = recorrer_vertice(dato_destino);
                if (dir1 == NULL || dir2 == NULL) {
                    cout << "\n Nodo origen o destino no existen, revise";
                } else {
                    insertarArista(dato_destino);
                }
                system("pause");
                break;
            case 3:
                verlista();
                cout << endl << endl;
                system("pause");
                break;
            case 4:
                if (cab_ver == NULL) {
                cout << "No hay nodos en el grafo. Agrega nodos primero." << endl;
                } else {
                cout << "Digite el nodo de origen: ";
                cin >> dato_origen;
                cout << "Digite el nodo de destino: ";
                cin >> dato_destino;
                calcularCaminoMasCorto(dato_origen, dato_destino);
                }
                system("pause");
                break;
        }
        system("cls");
    } while (opcion != 5);

    return 0;
}

