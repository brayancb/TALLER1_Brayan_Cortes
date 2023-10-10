#pragma once
#include "software.h"
class juego : public software{
private:
    string genero;
public:
juego(string nombre, string deloper, int edad, int precio, string genero) 
        : software("Juego",nombre, deloper, edad, precio) {
        this->genero = genero;
    };

    // Getter y Setter para tipo
    string getTipo(){
        return this ->genero;
    };

    void setTipo(string genero) {
        this -> genero = genero;
    };

};