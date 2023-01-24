#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Paquete.h"
using namespace std;

class Nodo
{
private:
    Paquete dato;
    Nodo *sig;
    friend class Paqueteria;

public:
    Nodo();
    Paquete getDato();
};


class Paqueteria
{
    private:
        Nodo *Primero;
        Nodo *aux;
        int contador;
    public:
        Paqueteria();
        void inserta(const Paquete &value);
        void elimina();
        bool vacia();
        void mostrar(const int &i, Nodo* aux);
        void mostraTodo();
        void guardar();
        void cargarDatos();

};

#endif // PAQUETERIA_H
