#include <iostream>
#include "Usuario.h"
#include "Usuario.cpp"
#include "admin.h"
#include "nino.h"
#include "usuarioNormal.h"
#include "listaUsuario.h"
#include "software.h"
#include "listaSoftware.h"
#include "juego.h"
#include "ofimatica.h"
#include "produccion.h"
#include "navegador.h"
#include "seguridad.h"
#include "social.h"

#include <fstream>
#include <string>
#include <sstream>
#include <locale>
using namespace std;

void mostrarTodos(listaSoftware* todos, nodoUsuario* actual) {
    nodoSoftware* softwareActual = todos->getCabeza();
    bool cumple;

    while (softwareActual != nullptr) {
        software soft = softwareActual->getSoftware();  // Obtenemos el software actual
        bool puede = actual->getUsuario().instalarSoftware(soft,actual->getUsuario());
        if (actual->getUsuario().getLista()->buscarSoftware(soft.getNombre()) == nullptr && puede == true) {
            cout << "-Tipo: " << soft.getTipo() 
                 << " -Nombre: " << soft.getNombre() 
                 << " -Developer: " << soft.getDeloper() 
                 << " -Para mayores de: " << soft.getEdad() 
                 << " -Precio: " << soft.getPrecio() << endl;
        }

        softwareActual = softwareActual->getSiguiente();
    }
}

void almacenarSinRepetir(listaSoftware* todos, software s) {
    nodoSoftware* actual = todos->getCabeza();

    // Verificar si el software ya está en la lista
    while (actual != nullptr) {
        if (actual->getSoftware().getNombre() == s.getNombre()) {
            // El software ya esta en la lista, no se almacena nuevamente
            return;
        }
        actual = actual->getSiguiente();
    }

    // Si el software no se encontro en la lista se agrega
    todos->setSoftware(s);
}

bool transformarLog(const string& log) {
    if (log == "Si"){
        return true;
        }else{
            return false;
        }
    };

void leerUsuarios(listaUsuario* lista)
{ 
    ifstream archivo("usuarios.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string tipo, nombre, contrasena, edad, correo, log;

            getline(ss, tipo, ',');
            getline(ss, nombre, ',');
            getline(ss, contrasena, ',');
            getline(ss, edad, ',');
            getline(ss, correo, ',');
            getline(ss, log, ',');
            int edad1 = stoi(edad);
            bool logTransformado = transformarLog(log);

            if(tipo == "Admin"){
                admin u(tipo, nombre, contrasena, edad1, correo, logTransformado);
                lista->agregarUsuario(u);
            }else if(tipo == "Usuario Normal"){
                usuarioNormal u(tipo, nombre, contrasena, edad1, correo, logTransformado);
                lista->agregarUsuario(u);
            }else if(tipo == "Nino"){
                nino u(tipo, nombre, contrasena, edad1, correo, logTransformado);
                lista->agregarUsuario(u);
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void leerSoftwares(listaSoftware* softwares, listaUsuario* lista, listaSoftware* todos) {
    ifstream archivo("softwares.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string tipo2, nombre, Developer, edad, usuario, Precio, genero, test1;

            getline(ss, tipo2, ',');
            getline(ss, nombre, ',');
            getline(ss, Developer, ',');
            getline(ss, edad, ',');
            getline(ss, usuario, ',');
            getline(ss, Precio, ',');
            int edad1 = stoi(edad);
            int precio1 = stoi(Precio);


            if (tipo2 == "Juegos") {
                getline(ss, genero, ',');
                juego j(nombre, Developer, edad1, precio1, genero);
                almacenarSinRepetir(todos,j);
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                usuarioEncontrado->getUsuario().setSoftware1(j);
                    }
            } else if (tipo2 == "Ofimatica") {
                int numArchivos = 6; // 6 elementos en comun que toda linea minimo tiene
                string restoDeLinea;
                getline(ss, restoDeLinea);
                // Contamos las comas que quedan para saber cuantos elementos hay
                for (char c : restoDeLinea) {
                    if (c == ',') {
                        numArchivos++;
                    }
                }
                ofimatica o (nombre, Developer, edad1, precio1);
                o.setArchivos(restoDeLinea);
                almacenarSinRepetir(todos,o);
               // Leemos y agregamos los archivos adicionales a la lista que se encuentra en el objeto
                for (int i = 0; i < numArchivos - 1; ++i) {
                     string nombreArchivo;
                     getline(ss, nombreArchivo, ',');
                     o.setArchivos(nombreArchivo);
                }              
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                    usuarioEncontrado->getUsuario().setSoftware1(o);
                    }
            } else if (tipo2 == "Produccion") {
                getline(ss, genero, ',');
                produccion p(nombre, Developer, edad1, precio1, genero);
                almacenarSinRepetir(todos,p);
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                        usuarioEncontrado->getUsuario().setSoftware1(p);
                    }
            } else if(tipo2 == "Navegador"){
                int numArchivos = 6; 
                string restoDeLinea;
                getline(ss, restoDeLinea);
                
                for (char c : restoDeLinea) {
                    if (c == ',') {
                        numArchivos++;
                    }
                }
                navegador o(nombre, Developer, edad1, precio1);
                almacenarSinRepetir(todos,o);
                
                for(int i = 0; i < numArchivos; ++i) {
                    string nombreArchivo;
                    getline(ss, nombreArchivo, ',');
                    o.setPagina(nombreArchivo);
                }                
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                    usuarioEncontrado->getUsuario().setSoftware1(o);
                    }
            }else if(tipo2 == "Seguridad"){
                getline(ss, genero, ',');
                seguridad j(nombre, Developer, edad1, precio1, genero);
                almacenarSinRepetir(todos,j);
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                usuarioEncontrado->getUsuario().setSoftware1(j);
                }
            }else if(tipo2 == "Social"){
                int numArchivos = 6; 
                string restoDeLinea;
                getline(ss, restoDeLinea);
                
                for (char c : restoDeLinea) {
                    if (c == ',') {
                        numArchivos++;
                    }
                }
                social o(nombre, Developer, edad1, precio1);
                almacenarSinRepetir(todos,o);
                for(int i = 0; i < numArchivos; ++i) {
                    string nombreArchivo;
                    getline(ss, nombreArchivo, ',');
                    o.setAmigo(nombreArchivo);
                }                
                nodoUsuario* usuarioEncontrado = lista->buscarUsuario(usuario);
                if (usuarioEncontrado != nullptr) {
                    usuarioEncontrado->getUsuario().setSoftware1(o);
                    }  
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
};

void menuConsola(nodoUsuario * actual,listaUsuario* usuarios,listaSoftware* todos ){
    int opcion;//eleccion de apartado de menu
    string opcion2;//eleccion el nombre del software que se quiere agregar/instalar
    nodoSoftware* nodo;
    string opcion3;//eleccion de que software eliminar
    bool loggedIn = true;  // si el usuario está autenticado
    cout<<"----------------------Menu Usuario-------------------------"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    do{
        cout << "0) Cambiar de usuario" << endl; 
        cout<<"1) Ver Softwares del usuario"<<endl;
        cout<<"2) Agregar un software"<<endl;
        cout<<"3) Eliminar un software"<<endl;
        if(actual->getUsuario().getLista()->getSoftwareTipoOfimatica() == true){
                    cout<<"4) Eliminar un documento Ofimatica"<<endl;
                }
        cin >> opcion;

        switch(opcion) {
            case 1:
                actual->getUsuario().getSoftwares();
                break;
            case 2:
                cout << "Escribe el nombre del software que quieres agregar" << endl;
                mostrarTodos(todos,actual);
                cin>>opcion2;
                nodo = todos->buscarSoftware(opcion2);
                if (nodo != nullptr) {
                    software agregar = nodo->getSoftware();
                    actual->getUsuario().setSoftware1(agregar);
                } else {
                    cout << "No se encontró el software." << endl;
                }
                break;
            
            case 3:
                actual->getUsuario().getSoftwares();
                cout<<"Escribe el nombre del software cual quieres eliminar: "<<endl;
                cin >> opcion3;
                usuarios->eliminarSoftware(opcion3, usuarios, actual);
                
                break;
            case 4:
                actual->getUsuario().getLista()->MostrarSoftwareTipo("Ofimatica");
                
                break;
            case 5:
                std::cout << "Opción 5 seleccionada." << std::endl;
                break;
            case 6:
                std::cout << "Opción 6 seleccionada." << std::endl;
                break;
            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no válida." << std::endl;
                break;
        }
    } while(opcion != 0 && loggedIn);
}

void login(listaUsuario* usuarios, listaSoftware* todos) {
    string nombreUsuario, contrasena;
    bool loggedIn = false;  // Agregamos una bandera para saber si está autenticado

    while (!loggedIn) {  // Cambiamos a un bucle mientras no esté autenticado
        cout << "Ingrese su nombre de usuario: ";
        cin >> nombreUsuario;
        cout << "Ingrese su contrasenia: ";
        cin >> contrasena;

        nodoUsuario* actual = usuarios->getCabeza();

        while (actual != nullptr) {
            if (actual->getUsuario().getNombre() == nombreUsuario && actual->getUsuario().getContrasena() == contrasena) {
                cout << "                    Bienvenido, " << actual->getUsuario().getNombre() << "!" << endl;
                menuConsola(actual,usuarios,todos);
                loggedIn = true;  // Cambiamos el estado a autenticado
                break;  // Salimos del bucle interno
            }

            actual = actual->getSiguiente();
        }

        if (!loggedIn) {
            cout << "Usuario o contraseña incorrectos. ¿Desea intentar de nuevo? (s/n): ";
            char respuesta;
            cin >> respuesta;

            if (respuesta != 's' && respuesta != 'S') {
                break;  // Si la respuesta no es 's' o 'S', salimos del bucle externo
            }
        }
    }
}

int main(){
    listaUsuario* usuarios = new listaUsuario();//lista de nodos usuarios
    leerUsuarios(usuarios);//se lee el txt de usuarios, se crea el objeto tipo Usuario y se almacenan 
    listaSoftware* softwares = new listaSoftware();//lista de softwares 
    listaSoftware* todos = new listaSoftware();//lista de softwares unicos, no se almacena el si el nombre del software ya se encuentra
    leerSoftwares(softwares,usuarios,todos);//se lee el txt de softwares, se crean los objetos de tipo Juego, Navegador, Ofimatica, Produccion, Seguridad, Social, y se almacenan 
    login(usuarios,todos);//login y llama al menu
    return 0;
};
