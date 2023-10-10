#pragma once
#include "software.h"
class produccion : public software {
private:
    string tipoSolucion;

public:
    produccion(string nombre, string deloper, int edad, int precio, string tipoSolucion) 
        : software("Produccion",nombre, deloper, edad, precio) {
        this->tipoSolucion = tipoSolucion;
    };

    string getTipoSolucion() {
        return tipoSolucion;
    };

    void setTipoSolucion(string Tipo) {
        this ->  tipoSolucion = Tipo;
    };

};