#pragma once
#include "software.h"
#include <list>
class social : public software {
private:
    list<string> amigos;

public:
    social(string nombre, string deloper, int edad, int precio) 
        : software("Social",nombre, deloper, edad, precio) {
    }

    void setAmigo(string amigo) {
        amigos.push_back(amigo) ;
    }

    void eliminarAmigo(string amigo) {
    for (auto it = amigos.begin(); it != amigos.end(); ++it) {
        if (*it == amigo) {
            it = amigos.erase(it); // Borra el amigo si se encuentra y actualiza el iterador
            return; // Termina la función después de eliminar al amigo
        }
    }
}

};