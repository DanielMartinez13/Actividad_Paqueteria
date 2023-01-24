#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>
using namespace std;

class Paquete
{
    private:
        int id;
        string origen;
        string destino;
        float peso;
    public:
        Paquete();
        void setId(const int _Id);
        void setOrigen(const string _Origen);
        void setDestino(const string _Destino);
        void setPeso(const float _Peso);
        int getId()const;
        string getOrigen() const;
        string getDestino() const;
        float getPeso() const;
};

#endif // PAQUETE_H
