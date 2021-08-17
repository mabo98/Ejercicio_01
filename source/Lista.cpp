#include "Lista.h"

Nodo::Nodo(Empleado *info, Nodo *sig) : info(info), sig(sig) {}

Empleado *Nodo::getInfo() const {
    return info;
}

void Nodo::setInfo(Empleado *info) {
    Nodo::info = info;
}

Nodo *Nodo::getSig() const {
    return sig;
}

void Nodo::setSig(Nodo *sig) {
    Nodo::sig = sig;
}

Nodo::Nodo() {}

Nodo::~Nodo() {
    delete info;
}

std::string Nodo::toStringNodo() {
    return info->toString();
}

Lista::Lista() {
    primero = NULL;
    actual = NULL;
}

Lista::~Lista() {
    while (!listaVacia())
    {
        eliminaInicio();
    }
}

void Lista::insertarInicio(Empleado * e) {
    primero = new Nodo(e, primero);
}

bool Lista::eliminaInicio() {
    if (primero == NULL)
        {
        return false;
        }
    else
    {
        actual = primero;
        primero = primero->getSig();
        delete actual;
        return true;
    }
}

std::string Lista::toString() {
    actual = primero;
    std::stringstream s;
    int i = 1;
    while (actual != NULL)
    {
        s << "-" << i++ << "-" << std::endl;
        s << actual->toStringNodo() << std::endl;
        actual = actual->getSig();
    }
    return s.str();
}

int Lista::cuentaNodos() {
    actual = primero;
    int can = 0;
    while (actual != NULL)
    {
        can++;
        actual = actual->getSig();
    }
    return can;
}

bool Lista::listaVacia() {
    return (primero == NULL) ? true : false;
}

void Lista::guardar(std::string nombreArchivo) {
    salida.open(nombreArchivo.c_str());
    if (salida.good())
    {
        actual = primero;
        std::stringstream s;
        while (actual != NULL)
        {
            actual->getInfo()->guardaEmpleado(salida);
            actual = actual->getSig();
        }
    }
    else
    {
        std::cout << std::endl << "          ¡Error al abrir archivo de salida!" << std::endl << std::endl;
    }
}

void Lista::recuperar(std::string nombreArchivo) {
    if (entrada.is_open())
    {
        return;
    }
    entrada.open(nombreArchivo.c_str());
    if (entrada)
    {
        std::cout << std::endl << "<<Leyendo Archivos>>" << std::endl << std::endl;
        Empleado *eAux;
        while (entrada.good()) {
            eAux = Empleado::recuperaEmpleado(entrada);
            if (entrada.good()) {
                this->insertarInicio(eAux);
            }
        }
    }
    else
    {
        std::cout << std::endl << "          ¡Error al abrir archivo de salida!" << std::endl << std::endl;
    }
}

bool Lista::archivoAbierto() {
    return entrada.is_open();
}

void Lista::cierraArchivo() {
    entrada.close();
    salida.close();
}
