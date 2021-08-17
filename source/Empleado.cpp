#include "Empleado.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'
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

void Empleado::calcularSalarioNeto() {

}

void Empleado::calcularDeducciones() {

}

std::string Empleado::toString() {

    std::stringstream r;
        r << "Id: " << getId() << std::endl;
        r << "Primer Apellido: " << getPrimerApellido() << std::endl;
        r << "Segundo Apellido: " << getSegundoApellido() << std::endl;
        r << "Nombre: " << getNombre() << std::endl;
        r << "Fecha de Nacimiento: " << getFechaNacimiento() << std::endl;
        r << "Deducciones: " << getNombre() << std::endl;

        return r.str();
}
 int convertible::convertibleInt(std::string i) {
    std::stringstream r(i);
    int v;
    r >> v;
    return v;
}

float convertible::convertiblefloat(std::string f) {
    std::stringstream r(f);
    float v;
    r >> v;
    return v;
}


Empleado *Empleado::recuperaEmpleado(std::ifstream &entrada) {
    std::string id;
    std::string primerApellido;
    std::string segundoApellido;
    std::string nombre;
    std::string fechaNacimiento;
    std::string salarioBruto;

    std::getline(entrada, id, DELIMITA_CAMPO);
    std::getline(entrada, primerApellido, DELIMITA_CAMPO);
    std::getline(entrada, segundoApellido, DELIMITA_CAMPO);
    std::getline(entrada, nombre, DELIMITA_CAMPO);
    std::getline(entrada, fechaNacimiento, DELIMITA_CAMPO);
    std::getline(entrada, salarioBruto, DELIMITA_REGISTRO);

    float salarioBrutoF = convertible::convertiblefloat(salarioBruto);
    int idEmpleado = convertible::convertibleInt(id);
        if (!idEmpleado) { return NULL; }
        else{
            return new Empleado(idEmpleado,primerApellido,segundoApellido,nombre,fechaNacimiento,salarioBrutoF);
        }
}

void Empleado::guardaEmpleado(std::ofstream &salida) {

    salida << id << DELIMITA_CAMPO;
    salida << primerApellido << DELIMITA_CAMPO;
    salida << segundoApellido << DELIMITA_CAMPO;
    salida << fechaNacimiento << DELIMITA_CAMPO;
    salida << salarioBruto << DELIMITA_REGISTRO;
}

