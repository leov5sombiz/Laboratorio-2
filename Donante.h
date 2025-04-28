    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar     - 2437924
                 Elbert Moreno Castillo     - 2436884
                 Jesus Giovanny Mora Segura - 2439620
    Fecha: Abril 2025
    */

#ifndef DONANTE_H
#define DONANTE_H

#include <string>
#include "Sangre.h"
using namespace std;

//Clase del donante
class Donante {
private:
    string cedula;
    string nombre;
    string direccion;
    Sangre tipoSangre;
    string telefono;

public:

     //Constructor
    Donante();

    Donante(const string& cedula, const string& nombre,
            const string& direccion, const Sangre& tipoSangre,
            const string& telefono);

    // Getters y setters
    string getCedula() const;
    void setCedula(const string& cedula);

    string getNombre() const;
    void setNombre(const string& nombre);

    string getDireccion() const;
    void setDireccion(const string& direccion);

    Sangre getTipoSangre() const;
    void setTipoSangre(const Sangre& tipoSangre);

    string getTelefono() const;
    void setTelefono(const string& telefono);


     //Validaciones de datos utilizando expresiones regulares
    static bool validarCedula(const string& cedula);
    static bool validarNombre(const string& nombre);
    static bool validarDireccion(const string& direccion);
    static bool validarTelefono(const string& telefono);
};

#endif // DONANTE_H
