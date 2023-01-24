#include "Paquete.h"

Paquete::Paquete()
{
    //ctor
}

void Paquete::setId(const int _Id)
{
    id = _Id;
}

void Paquete::setOrigen(const string _Origen)
{
    origen = _Origen;
}

void Paquete::setDestino(const string _Destino)
{
    destino = _Destino;
}

void Paquete::setPeso(const float _Peso)
{
    peso = _Peso;
}

int Paquete::getId() const
{
    return id;
}

string Paquete::getOrigen() const
{
    return origen;
}

string Paquete::getDestino() const
{
    return destino;
}

float Paquete::getPeso() const
{
    return peso;
}
