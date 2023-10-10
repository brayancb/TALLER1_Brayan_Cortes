#pragma once
#include "software.h"
#include <list>
class ofimatica : public software {
private:
    int cantidadArchivos;
    string archivo;
    list <string> archivos;
    string todos ;
public:
    ofimatica(string nombre, string deloper, int edad, int precio) 
        : software("Ofimatica",nombre, deloper, edad, precio) {
        //this->cantidadArchivos = cantidadArchivos;
    };

    int getCantidadArchivos() {
        return cantidadArchivos;
    };

    void setArchivos(string arch) {
       archivos.push_back(arch);
       cantidadArchivos ++;
    };

    list<string> getLista(){
        return archivos;
    }
    void eliminarArchivo(string elemento){
    for (int i = 0; i <cantidadArchivos; ) {
        if (archivos.front() == elemento) {
            archivos.pop_front(); // Elimina el primer elemento si coincide
        } else {
            archivos.push_back(archivos.front()); // Mueve el primer elemento al final
            i++;
            }
        }
    }

    string mostrarArchivos(){
        
        for(string contenido : archivos) {
            todos = todos + "," + contenido;   
    }
    return todos;
    }

    
    
};