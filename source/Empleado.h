#ifndef EJERCICIO_01_EMPLEADO_H
#define EJERCICIO_01_EMPLEADO_H
#include <iostream>
#include <string>

class Empleado {
private:
    int id = 0;
    std::string primerApellido = 0 ;
    std::string segundoApellido = 0;
    std::string nombre = 0;
    std::string fechaNacimiento = 0;
    float salarioBruto = 0;

public:
    Empleado(int id, const std::string &primerApellido, const std::string &segundoApellido, const std::string &nombre,
             const std::string &fechaNacimiento, float salarioBruto);

    Empleado();

    int getId() const;

    void setId(int id);

    const std::string &getPrimerApellido() const;

    void setPrimerApellido(const std::string &primerApellido);

    const std::string &getSegundoApellido() const;

    void setSegundoApellido(const std::string &segundoApellido);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const std::string &getFechaNacimiento() const;

    void setFechaNacimiento(const std::string &fechaNacimiento);

    float getSalarioBruto() const;

    void setSalarioBruto(float salarioBruto);

    virtual ~Empleado();
};


#endif //EJERCICIO_01_EMPLEADO_H
