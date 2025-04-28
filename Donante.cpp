    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco    - 2438545
                 Daniel Escobar Escobar         - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura     - 2439620

    Fecha: Abril 2025
    */

#include "Donante.h"
#include <regex>
using namespace std;

Donante::Donante() : cedula(""), nombre(""), direccion(""), tipoSangre(Sangre()), telefono("") {
}

Donante::Donante(const string& cedula, const string& nombre,
                 const string& direccion, const Sangre& tipoSangre,
                 const string& telefono)
    : cedula(cedula), nombre(nombre), direccion(direccion), tipoSangre(tipoSangre), telefono(telefono) {
}

string Donante::getCedula() const {
    return cedula;
}

void Donante::setCedula(const string& cedula) {
    this->cedula = cedula;
}

string Donante::getNombre() const {
    return nombre;
}

void Donante::setNombre(const string& nombre) {
    this->nombre = nombre;
}

string Donante::getDireccion() const {
    return direccion;
}

void Donante::setDireccion(const string& direccion) {
    this->direccion = direccion;
}

Sangre Donante::getTipoSangre() const {
    return tipoSangre;
}

void Donante::setTipoSangre(const Sangre& tipoSangre) {
    this->tipoSangre = tipoSangre;
}

string Donante::getTelefono() const {
    return telefono;
}

void Donante::setTelefono(const string& telefono) {
    this->telefono = telefono;
}

bool Donante::validarCedula(const string& cedula) {
    // Valida que la cédula tenga entre 6 y 15 dígitos
    regex cedulaRegex("^[0-9]{6,15}$");
    return regex_match(cedula, cedulaRegex);
}

bool Donante::validarNombre(const string& nombre) {
    // Valida que el nombre tenga letras, espacios y al menos 3 caracteres
    regex nombreRegex("^[A-Za-zÁáÉéÍíÓóÚúÑñ ]{3,50}$");
    return regex_match(nombre, nombreRegex);
}

bool Donante::validarDireccion(const string& direccion) {
    // Valida que la dirección tenga al menos 5 caracteres
    regex direccionRegex("^[A-Za-z0-9ÁáÉéÍíÓóÚúÑñ .,#-]{5,100}$");
    return regex_match(direccion, direccionRegex);
}

bool Donante::validarTelefono(const string& telefono) {
    // Valida que el teléfono tenga el formato correcto (números y guiones opcionales)
    regex telefonoRegex("^[0-9]{3}[-]?[0-9]{3}[-]?[0-9]{4}$");
    return regex_match(telefono, telefonoRegex);
}
