#ifndef EJERCICIO_01_LISTA_H
#define EJERCICIO_01_LISTA_H
#include "Empleado.h"
struct Nodo{
private:
    Empleado* info;
    Nodo* sig;
public:
    Nodo(Empleado *info, Nodo *sig);

    Empleado *getInfo() const;

    void setInfo(Empleado *info);

    Nodo *getSig() const;

    void setSig(Nodo *sig);

    std::string toStringNodo();

    Nodo();

    virtual ~Nodo();
};

class Lista {
private:
    Nodo* primero;
    Nodo* actual;
    std::ifstream entrada;
    std::ofstream salida;
public:
    void insertarInicio(Empleado*);

    bool eliminaInicio();

    std::string toString();

    int cuentaNodos();

    bool listaVacia();

    void guardar(std::string);

    void recuperar(std::string);

    bool archivoAbierto();

    void cierraArchivo();

    virtual ~Lista();

    Lista();
};


#endif //EJERCICIO_01_LISTA_H
