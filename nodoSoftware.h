#pragma once
#include <iostream>
#include <string>
#include "software.h"
#include "ofimatica.h"
using namespace std;

class nodoSoftware {
    private:
    software software1;
    public:
     nodoSoftware* siguiente;
     nodoSoftware* anterior;
     nodoSoftware(software s) : software1(s),  siguiente(nullptr), anterior(nullptr) {}

     nodoSoftware* getSiguiente() {
        return siguiente;
    }
    virtual string getTipo() const {
        return "Software base";
    }

    nodoSoftware* getAnterior() {
        return anterior;
    }

    void setSiguiente(nodoSoftware* siguiente) {
        this->siguiente = siguiente;
    }

    void setAnterior(nodoSoftware* anterior) {
        this->anterior = anterior;
    }

    software getSoftware() {
        return software1;
    }
};