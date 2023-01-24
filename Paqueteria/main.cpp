#include <iostream>
#include <string>
#include "Paqueteria.h"
#include "Paquete.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int menu();
//void setearDatos(Paquete pa, Paqueteria p,string id, string origen, string destino, string peso);

int main()
{
    Paquete paquete;
    Paqueteria paqueteria;
    system("cls");
    while(true){
        switch(menu())
        {
            case 1:
                {
                    system("cls");
                    int id;
                    string origen;
                    string destino;
                    float peso;
                    cout << "Agregar paquete\n" << endl;

                    cout << "Ingresa el ID del paquete: ";
                    cin >> id;
                    paquete.setId(id);
                    getchar();

                    cout << "Agrega el origen del paquete: ";
                    getline(cin,origen);
                    paquete.setOrigen(origen);

                    cout << "Agrega el destino del paquete: ";
                    getline(cin,destino);
                    paquete.setDestino(destino);

                    cout << "Agrega el peso del paquete: ";
                    cin >> peso;
                    paquete.setPeso(peso);

                    paqueteria.inserta(paquete);

                    cout <<"\nEl Dato ha sido ingresado exitosamente!!" << endl;
                    system("pause");
                }
            break;
            case 2:
                {
                    if(paqueteria.vacia())
                        cout << "La paqueteria esta vacia :(" << endl;
                    else{
                        paqueteria.elimina();
                        cout << "Primer paquete en la lista eliminado :)" << endl;

                    }
                    getchar();
                }
            break;
            case 3:
                {
                    system("cls");
                    if(!paqueteria.vacia())
                        paqueteria.mostraTodo();
                    else
                        cout << "La paqueteria esta vacia :( " << endl;
                    getchar();
                }
            break;
            case 4:
                {
                    if(paqueteria.vacia())
                        cout << "La lista esta vacia :(" << endl;
                    else
                    {
                        paqueteria.guardar();
                        cout << "Se ha creado un back up de la informacion :)" << endl;
                    }
                    getchar();
                }
            break;
            case 5:
                {
                    system("cls");
                    string origen, destino;
                    int id, cont;
                    char x;
                    float peso;
                    ifstream archivo("BackUp.txt");
                    if(!archivo.is_open())
                        cout << "Error :(" << endl;
                    else{
                        cout << "entro :)" << endl;
                        archivo >> cont;
                        for(int i=0;i<cont;i++)
                        {
                            archivo >> id;
                            archivo.read(&x,1);
                            getline(archivo,origen);
                            getline(archivo,destino);
                            archivo >> peso;
                            paquete.setId(id);
                            paquete.setOrigen(origen);
                            paquete.setDestino(destino);
                            paquete.setPeso(peso);
                            paqueteria.inserta(paquete);

                        }

                        getchar();
                    }
                    archivo.close();
                }
            break;
            case 6:
                {
                    return 0;
                }
            break;
            default:
                cout << "Opcion erronea :(" << endl;
            break;
        }
    }
    return 0;
}

int menu()
{
    system("cls");
    int opcion;
    cout << "(1). Agregar paquete" << endl;
    cout << "(2). Eliminar paquete" << endl;
    cout << "(3). Mostrar" << endl;
    cout << "(4). Guardar" << endl;
    cout << "(5). Recuperar" << endl;
    cout << "(6). Salir" << endl;

    cout << "Elige una opcion: ";
    cin >> opcion;
    getchar();
    return opcion;
}

/*void setearDatos(Paquete pa, Paqueteria p,string id, string origen, string destino, string peso)
{
    int _id;
    float _peso;
    _id = stoi(id);
    _peso = stof(peso);
    pa.setId(_id);
    pa.setOrigen(origen);
    pa.setDestino(destino);
    pa.setPeso(_peso);
    p.inserta(pa);

}*/
