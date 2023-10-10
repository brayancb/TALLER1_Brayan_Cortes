#include "Usuario.h"


Usuario::Usuario(string tipo, string nombre, string contrasena, int edad, string correo, bool log) {
    this->tipo = tipo;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->edad = edad;
    this->correo = correo;
    this->log = log;
}

Usuario::~Usuario() {
    // Aquí puedes realizar cualquier limpieza necesaria al destruir un objeto Usuario
}

string Usuario::getTipo(){
    return tipo;
}

string Usuario::getNombre() {
    return nombre;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getContrasena() {
    return contrasena;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

int Usuario::getEdad() {
    return edad;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

string Usuario::getCorreo() {
    return correo;
}

void Usuario::setCorreo(string correo) {
    this->correo = correo;
}

bool Usuario::getLog() {
    return log;
}

void Usuario::setLog(bool log) {
    this->log = log;
}
void Usuario::setSoftware1(software s){
   softwares->setSoftware(s);
}

void Usuario::getSoftwares(){
    nodoSoftware* cabeza = softwares->getCabeza();
    cout<<"Los softwares que posee son"<<endl;
    int cont = 1;
    while (cabeza != nullptr   )
    {
        cout<<cont <<"-Tipo: "<< cabeza->getSoftware().getTipo() <<" -Nombre: "<< cabeza->getSoftware().getNombre() << " -Deloper: " << cabeza->getSoftware().getDeloper() <<" -Para mayores de: " << cabeza->getSoftware().getEdad()<<" -Precio: " << cabeza->getSoftware().getPrecio()<<endl;
        cabeza = cabeza->getSiguiente();
        cont++;
    }
    
}


listaSoftware* Usuario::getLista(){
    return softwares;
}

bool Usuario::tieneSoftwareInstalado(string nombreSoftware) {
    nodoSoftware* actual = softwares->getCabeza();

    while (actual != nullptr) {
        if (actual->getSoftware().getNombre() == nombreSoftware) {
            return true;
        }
        actual = actual->getSiguiente();
    }

    return false; // El software no está instalado
}

bool Usuario::instalarSoftware(software agreg, Usuario actual){
    if(actual.getTipo() == "Admin"){
        return true;
    }
    else if(actual.getTipo() == "Nino"){
        if(agreg.getTipo() == "Seguridad" || agreg.getEdad() >= actual.getEdad()){
            return false;
        }
        return true;
    }
    else if(actual.getTipo() == "Usuario Normal"){
         if(agreg.getTipo() == "Seguridad"){
            return false;
        }
        return true;       
    }
    return true;
}
   

    


    



