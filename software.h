#pragma once
using namespace std;
#include "Usuario.h"
#include <string>
class software{
private:
    string tipo;
    string nombre;
    string deloper;
    int edad;
    int precio;
public:
software(string tipo,string nombre, string deloper,int edad, int precio){
    this -> tipo = tipo;
    this -> nombre = nombre;
    this -> deloper = deloper;
    this -> edad = edad;
    this -> precio = precio;
};

// Getters
    string getTipo(){
        return tipo;
    }
    string getNombre()  {
        return nombre;
    };

    string getDeloper() const {
        return deloper;
    };

    int getEdad() const {
        return edad;
    };

    int getPrecio() const {
        return precio;
    };
    virtual void operacionEspecifica() {
    // Operación por defecto o una operación genérica
    }

    // Setters
    void setNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    };

    void setDeloper(const string& nuevoDeloper) {
        deloper = nuevoDeloper;
    };

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    };

    void setPrecio(int nuevoPrecio) {
        precio = nuevoPrecio;
    };
    

};