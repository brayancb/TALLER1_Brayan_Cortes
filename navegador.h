#pragma once
#include "software.h"
#include <vector>
class navegador: public software{
    private:
    vector<string> historial;

    public:
    navegador(string nombre, string deloper, int edad, int precio) 
        : software("Navegador",nombre, deloper, edad, precio){

        };

    void setPagina(string pag){
        historial.push_back(pag);
    };
};