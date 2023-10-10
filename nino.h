#pragma once
#include "Usuario.h"
#include "nodoUsuario.h"

class nino: public Usuario{

    public:
     nino(string tipo, string nombre, string contrasena, int edad, string correo, bool log):
        Usuario(tipo,nombre,contrasena,edad,correo,log){
        };
    
    bool instalarSoftware(software agreg, Usuario actual) override {
        if(agreg.getTipo() == "Seguridad" || agreg.getEdad() >= 18){
            return false;
        }
        return true;

    }

    
};