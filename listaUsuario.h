#pragma once
#include <iostream>
#include <string>
#include "nodoUsuario.h"
using namespace std;
class listaUsuario {
private:
    nodoUsuario* cabeza;
public:
    listaUsuario() : cabeza(nullptr) {}

    void agregarUsuario(Usuario& u) {
        nodoUsuario* nuevoNodo = new nodoUsuario(u);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // Puedes agregar más funciones según lo que necesites (eliminar, buscar, etc.)
    nodoUsuario*  getCabeza(){
        return cabeza;
    }
     nodoUsuario* buscarUsuario(const string& nombre) {
        nodoUsuario* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getUsuario().getNombre() == nombre) {
                return actual;
            }
            actual = actual->getSiguiente();
        }
        return nullptr; // Si no se encuentra el usuario
    }

    nodoUsuario* buscarUsuarioConSoftware(string nombreSoftware) {
        nodoUsuario* actual = getCabeza();

        while (actual != nullptr) {
          // Verificar si el usuario actual tiene instalado el software
           if (actual->getUsuario().tieneSoftwareInstalado(nombreSoftware)) {
               return actual;
           }
           actual = actual->getSiguiente();
        }

     return nullptr; // Si no se encontró ningún usuario con el software
    }

    void eliminarSoftware(string nombre, listaUsuario* lista,nodoUsuario * actual1) {
        nodoSoftware* actual = actual1->getUsuario().getLista()->getCabeza();

            while (actual != nullptr) {
                if (actual->getSoftware().getNombre() == nombre) {
                    nodoUsuario* usuarioDueño = lista->buscarUsuarioConSoftware(nombre);

                if (usuarioDueño != nullptr) {
                    string usuario;
                    string contrasenia;

                    cout << "Debes tener la autorizacion de " << usuarioDueño->getUsuario().getNombre() << " para desinstalar. Ingresa sus credenciales:" << endl;
                    cout << "Usuario: ";
                    cin >> usuario;
                    cout << "Contrasenia: ";
                    cin >> contrasenia;

                if (usuarioDueño->getUsuario().getNombre() == usuario && usuarioDueño->getUsuario().getContrasena() == contrasenia) {
                    // Eliminar el software
                    if (actual->getAnterior() != nullptr) {
                        actual->getAnterior()->setSiguiente(actual->getSiguiente());
                    }
                    if (actual->getSiguiente() != nullptr) {
                        actual->getSiguiente()->setAnterior(actual->getAnterior());
                    }

                    if (actual == actual1->getUsuario().getLista()->getCabeza()) {
                       actual1->getUsuario().getLista()->setCabeza(actual->getSiguiente());
                    }

                    delete actual;
                    //cont--;
                    return;
                } else {
                    cout << "Credenciales incorrectas. No tienes permiso para desinstalar el software." << endl;
                    return;
                }
            } else {
                cout << "No se encontró ningún usuario que tenga instalado este software." << endl;
                return;
            }
        }
        actual = actual->getSiguiente();
    }

    cout << "No se encontró ningún software con el nombre proporcionado." << endl;
}

    
};