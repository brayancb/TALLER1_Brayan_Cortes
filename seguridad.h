#pragma once
#include "software.h"
class seguridad : public software {
private:
    string tipoMalware;

public:
    seguridad(string nombre, string deloper, int edad, int precio, string tipoMalware) 
        : software("Seguridad",nombre, deloper, edad, precio) {
        this->tipoMalware = tipoMalware;
    }

    string getTipoMalware() {
        return tipoMalware;
    }

    void setTipoMalware(string Tipo) {
       this -> tipoMalware = Tipo;
    }
};