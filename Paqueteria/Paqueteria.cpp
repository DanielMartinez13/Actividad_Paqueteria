#include "Paqueteria.h"

Paqueteria::Paqueteria()
{
    Primero = NULL;
    contador = 0;
}

Nodo::Nodo()
{
    //ctor
}

Paquete Nodo::getDato()
{
    return this->dato;
}

void Paqueteria::inserta(const Paquete& value)
{
    Nodo *temp, *aux;
    temp = new Nodo();
    temp->dato = value;
    temp->sig = NULL;

    if(vacia())
        Primero = temp;
    else{
        aux = Primero;
        while (aux->sig !=NULL) {
            aux = aux->sig;
        }
        aux->sig = temp;
        contador++;
    }
}

void Paqueteria::elimina()
{
    Nodo *aux = Primero;
    Primero = aux->sig;
    delete  aux;
    contador--;
}

bool Paqueteria::vacia()
{
    if(Primero==NULL)
        return true;
    else
        return false;
}

void Paqueteria::mostraTodo()
{
    Nodo *aux = Primero;
    int i=0;
    while (aux!=NULL) {
        mostrar(i+1,aux);
        aux = aux->sig;
        i++;
    }
    system("pause");
}
void Paqueteria::mostrar(const int& i, Nodo* aux)
{
    cout << "Paquete no: " << i << endl;
    cout << "ID: " << aux->dato.getId() << endl;
    cout << "Origen: " << aux->dato.getOrigen() << endl;
    cout << "Destino: " << aux->dato.getDestino() << endl;
    cout << "Peso: " << aux->dato.getPeso() << " Kg " << endl << endl;
}

void Paqueteria::guardar()
{
    Nodo *aux = Primero;
    ofstream archivo("BackUp.txt",fstream::out);
    if(!archivo.is_open())
        cout << "Error" << endl;
    archivo << contador+1 << endl;
    while(aux!=NULL)
    {
        archivo << aux->dato.getId() << endl;
        archivo << aux->dato.getOrigen() << endl;
        archivo << aux->dato.getDestino() << endl;
        archivo << aux->dato.getPeso() << endl;
        aux = aux->sig;
    }
    archivo.close();
}

void Paqueteria::cargarDatos()
{
    //ctor
}
