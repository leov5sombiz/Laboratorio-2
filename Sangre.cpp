    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco    - 2438545
                 Daniel Escobar Escobar         - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura     - 2439620
    Fecha: Abril 2025
    */

#include "Sangre.h"
#include <algorithm>
using namespace std;

Sangre::Sangre() : tipo("") {
}

Sangre::Sangre(const string& tipo) : tipo(tipo) {
}

string Sangre::getTipo() const {
    return tipo;
}

void Sangre::setTipo(const string& tipo) {
    this->tipo = tipo;
}

bool Sangre::esValido(const string& tipo) {
    vector<string> tiposValidos = getTiposValidos();
    return find(tiposValidos.begin(), tiposValidos.end(), tipo) != tiposValidos.end();
}

vector<string> Sangre::getTiposValidos() {
    return {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
}
