#pragma once
#include <iostream>
#include <string>
#include "nodoSoftware.h"
#include "ofimatica.h"
using namespace std;
class listaSoftware {
private:
    nodoSoftware* cabeza;
    int cont;
public:
    listaSoftware() : cabeza(nullptr) {}

    void setSoftware(software s) {
        nodoSoftware* nuevoNodo = new nodoSoftware(s);
        nuevoNodo->setSiguiente(cabeza);

        if (cabeza != nullptr) {
            cabeza->setAnterior(nuevoNodo);
        }

        cabeza = nuevoNodo;
        cont++;
    }

    int getCont(){
        return cont;
    }

    nodoSoftware* getCabeza(){
        return cabeza;
    }

    void setCabeza(nodoSoftware* cabeza){
        this->cabeza = cabeza;
    }
    
    nodoSoftware* buscarSoftware(string nombre) {
        nodoSoftware* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getSoftware().getNombre() == nombre) {
                return actual;
            }
            actual = actual->getSiguiente();
        }
        return nullptr; // No se encontró el software
    }

    void MostrarSoftwareTipo(string tipo) {
        nodoSoftware* actual = cabeza;

        while (actual != nullptr) {
            if (actual->getSoftware().getTipo() == tipo) {
                ofimatica* o = new ofimatica(actual->getSoftware().getNombre() , actual->getSoftware().getDeloper(), actual->getSoftware().getEdad() , actual->getSoftware().getEdad());
                 cout<< actual->getSoftware().getNombre()<<" Archivos: "  <<endl;
            }
            actual = actual->getSiguiente();
        }
        
    }

    bool getSoftwareTipoOfimatica(){
        nodoSoftware* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getSoftware().getTipo() == "Ofimatica") {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    };

    
};