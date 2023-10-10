#pragma once
#include "Usuario.h"
#include "nodoUsuario.h"

class usuarioNormal: public Usuario{

    public:
     usuarioNormal(string tipo, string nombre, string contrasena, int edad, string correo, bool log):
        Usuario(tipo,nombre,contrasena,edad,correo,log){
        };
    
    bool instalarSoftware(software agreg, Usuario actual) override {
        if(agreg.getTipo() != "Seguridad"){
            return false;
        }
        return true;

    }

    
};