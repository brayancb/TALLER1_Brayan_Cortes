#pragma once
#include <string>
#include "listaSoftware.h"

using namespace std;

class Usuario {
private:
    string tipo;
    string nombre;
    string contrasena;
    int edad;
    string correo;
    bool log = false;
    listaSoftware* softwares = new listaSoftware();

public:
    Usuario(string tipo, string nombre, string contrasena, int edad, string correo, bool log);
    ~Usuario();

    string getTipo();

    string getNombre();
    void setNombre(string nombre);

    string getContrasena();
    void setContrasena(string contrasena);

    int getEdad();
    void setEdad(int edad);

    string getCorreo();
    void setCorreo(string correo);

    bool getLog();
    void setLog(bool log);

    void setSoftware1(software s);

    void getSoftwares();
    
    listaSoftware* getLista();

    bool tieneSoftwareInstalado(string nombreSoftware);

    virtual bool instalarSoftware(software agreg, Usuario actual);

};