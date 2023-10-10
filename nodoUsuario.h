#pragma once
#include <iostream>
#include <string>
using namespace std;

class nodoUsuario {
    private:
    Usuario usuario;

    public:
    nodoUsuario* siguiente; //es mas rapido que crear una funcion que lo retorne
    nodoUsuario(const Usuario& u) : usuario(u), siguiente(nullptr) {}

    Usuario getUsuario(){
        return usuario;
    }
    string getTipoUsuario() {
        return usuario.getTipo();
    }
    nodoUsuario* getSiguiente(){
        return siguiente;
    }
};