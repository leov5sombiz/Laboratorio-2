    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco    - 2438545
                 Daniel Escobar Escobar         - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura     - 2439620

    Fecha: Abril 2025
    */

#ifndef SANGRE_H
#define SANGRE_H

#include <string>
#include <vector>
using namespace std;

//Clase de la sangre del donante
class Sangre {
private:
    string tipo; // Tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-)

public:

    //Constructor por defecto
    Sangre();

    Sangre(const string& tipo);


     //Obtiene el tipo de sangre
    string getTipo() const;


    //Establece el tipo de sangre
    void setTipo(const string& tipo);

    //Verifica si el tipo de sangre es válido
    static bool esValido(const string& tipo);

    //Obtiene todos los tipos de sangre válidos
    static vector<string> getTiposValidos();
};

#endif // SANGRE_H
