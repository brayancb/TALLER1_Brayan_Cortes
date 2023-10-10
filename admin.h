#pragma once
#include "Usuario.h"
#include "nodoUsuario.h"

class admin: public Usuario{

    public:
     admin(string tipo, string nombre, string contrasena, int edad, string correo, bool log):
        Usuario(tipo,nombre,contrasena,edad,correo,log){
        };
    
    bool instalarSoftware(software agreg, Usuario actual) override{
        return true;
    }

    
};