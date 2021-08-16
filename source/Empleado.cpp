#include "Empleado.h"

Empleado::Empleado(int id, const std::string &primerApellido, const std::string &segundoApellido,
                   const std::string &nombre, const std::string &fechaNacimiento, float salarioBruto) : id(id),
                                                                                                        primerApellido(
                                                                                                                primerApellido),
                                                                                                        segundoApellido(
                                                                                                                segundoApellido),
                                                                                                        nombre(nombre),
                                                                                                        fechaNacimiento(
                                                                                                                fechaNacimiento),
                                                                                                        salarioBruto(
                                                                                                                salarioBruto) {}

int Empleado::getId() const {
    return id;
}

void Empleado::setId(int id) {
    Empleado::id = id;
}

const std::string &Empleado::getPrimerApellido() const {
    return primerApellido;
}

void Empleado::setPrimerApellido(const std::string &primerApellido) {
    Empleado::primerApellido = primerApellido;
}

const std::string &Empleado::getSegundoApellido() const {
    return segundoApellido;
}

void Empleado::setSegundoApellido(const std::string &segundoApellido) {
    Empleado::segundoApellido = segundoApellido;
}

const std::string &Empleado::getNombre() const {
    return nombre;
}

void Empleado::setNombre(const std::string &nombre) {
    Empleado::nombre = nombre;
}

const std::string &Empleado::getFechaNacimiento() const {
    return fechaNacimiento;
}

void Empleado::setFechaNacimiento(const std::string &fechaNacimiento) {
    Empleado::fechaNacimiento = fechaNacimiento;
}

float Empleado::getSalarioBruto() const {
    return salarioBruto;
}

void Empleado::setSalarioBruto(float salarioBruto) {
    Empleado::salarioBruto = salarioBruto;
}

Empleado::~Empleado() {

}

Empleado::Empleado() {}
