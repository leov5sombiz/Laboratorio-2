    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco    - 2438545
                 Daniel Escobar Escobar         - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura     - 2439620
    Fecha: Abril 2025
    */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <limits>
#include "Donante.h"
#include "Sangre.h"
using namespace std;

// Funciones del menu principal
void mostrarMenu();
void registrarDonante(vector<Donante>& donantes);
void buscarDonante(const vector<Donante>& donantes);
void eliminarDonante(vector<Donante>& donantes);
void mostrarDonantes(const vector<Donante>& donantes);
void mostrarEstadisticas(const vector<Donante>& donantes);
void limpiarPantalla();
void pausar();

int main() {
    vector<Donante> donantes;
    int opcion;

    do {
        limpiarPantalla();
        mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número del 1 al 6." << endl;
            pausar();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                registrarDonante(donantes);
                break;
            case 2:
                buscarDonante(donantes);
                break;
            case 3:
                eliminarDonante(donantes);
                break;
            case 4:
                mostrarDonantes(donantes);
                break;
            case 5:
                mostrarEstadisticas(donantes);
                break;
            case 6:
                cout << "Gracias por utilizar el sistema de gestión de donantes de sangre." << endl;
                break;
            default:
                cout << "Opcion inválida. Por favor, ingrese un número del 1 al 6." << endl;
                pausar();
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    cout << "===== SISTEMA DE GESTION DE DONANTES DE SANGRE =====" << endl;
    cout << "1. Registrar donante" << endl;
    cout << "2. Buscar donante" << endl;
    cout << "3. Eliminar donante" << endl;
    cout << "4. Mostrar registro completo de donantes" << endl;
    cout << "5. Mostrar estadisticas por tipo de sangre" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese su opcion (1-6): ";
}

void registrarDonante(vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== REGISTRAR NUEVO DONANTE =====" << endl;

    string cedula, nombre, direccion, tipoSangre, telefono;
    bool datoValido;

    // Validar cédula
    do {
        cout << "Ingrese la cedula (solo numeros de 6-15 dígitos): ";
        getline(cin, cedula);

        datoValido = Donante::validarCedula(cedula);

        // Verificar si la cédula ya existe
        if (datoValido) {
            auto it = find_if(donantes.begin(), donantes.end(),
                [&cedula](const Donante& d) { return d.getCedula() == cedula; });

            if (it != donantes.end()) {
                cout << "¡Error! Esta cédula ya esta registrada en el sistema." << endl;
                datoValido = false;
            }
        } else {
            cout << "¡Error! Formato de cedula invalido." << endl;
        }
    } while (!datoValido);

    // Validar nombre
    do {
        cout << "Ingrese el nombre completo: ";
        getline(cin, nombre);

        datoValido = Donante::validarNombre(nombre);
        if (!datoValido) {
            cout << "¡Error! Nombre invalido. Debe contener solo letras y espacios (mínimo 3 caracteres)." << endl;
        }
    } while (!datoValido);

    // Validar dirección
    do {
        cout << "Ingrese la direccion: ";
        getline(cin, direccion);

        datoValido = Donante::validarDireccion(direccion);
        if (!datoValido) {
            cout << "¡Error! Direccion invalida. Debe tener al menos 5 caracteres." << endl;
        }
    } while (!datoValido);

    // Validar tipo de sangre
    do {
        cout << "Ingrese el tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-): ";
        getline(cin, tipoSangre);

        datoValido = Sangre::esValido(tipoSangre);
        if (!datoValido) {
            cout << "¡Error! Tipo de sangre invalido." << endl;
        }
    } while (!datoValido);

    // Validar teléfono
    do {
        cout << "Ingrese el número de telefono (formato: 123-456-7890 o 1234567890): ";
        getline(cin, telefono);

        datoValido = Donante::validarTelefono(telefono);
        if (!datoValido) {
            cout << "¡Error! Formato de telefono invalido." << endl;
        }
    } while (!datoValido);

    // Crear y guardar el donante
    Donante nuevoDonante(cedula, nombre, direccion, Sangre(tipoSangre), telefono);
    donantes.push_back(nuevoDonante);

    cout << "\n¡Donante registrado exitosamente!" << endl;
    pausar();
}

void buscarDonante(const vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== BUSCAR DONANTE =====" << endl;

    if (donantes.empty()) {
        cout << "No hay donantes registrados en el sistema." << endl;
        pausar();
        return;
    }

    string cedula;
    cout << "Ingrese la cedula del donante a buscar: ";
    getline(cin, cedula);

    auto it = find_if(donantes.begin(), donantes.end(),
        [&cedula](const Donante& d) { return d.getCedula() == cedula; });

    if (it != donantes.end()) {
        cout << "\nDonante encontrado:" << endl;
        cout << "Cedula: " << it->getCedula() << endl;
        cout << "Nombre: " << it->getNombre() << endl;
        cout << "Dirección: " << it->getDireccion() << endl;
        cout << "Tipo de sangre: " << it->getTipoSangre().getTipo() << endl;
        cout << "Telefono: " << it->getTelefono() << endl;
    } else {
        cout << "\nNo se encontro ningun donante con la cedula " << cedula << endl;
    }

    pausar();
}

void eliminarDonante(vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== ELIMINAR DONANTE =====" << endl;

    if (donantes.empty()) {
        cout << "No hay donantes registrados en el sistema." << endl;
        pausar();
        return;
    }

    string cedula;
    cout << "Ingrese la cedula del donante a eliminar: ";
    getline(cin, cedula);

    auto it = find_if(donantes.begin(), donantes.end(),
        [&cedula](const Donante& d) { return d.getCedula() == cedula; });

    if (it != donantes.end()) {
        cout << "\nDonante encontrado:" << endl;
        cout << "Cedula: " << it->getCedula() << endl;
        cout << "Nombre: " << it->getNombre() << endl;
        cout << "Tipo de sangre: " << it->getTipoSangre().getTipo() << endl;

        char confirmacion;
        cout << "\n¿Esta seguro que desea eliminar este donante? (S/N): ";
        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirmacion == 'S' || confirmacion == 's') {
            donantes.erase(it);
            cout << "\nDonante eliminado exitosamente." << endl;
        } else {
            cout << "\nOperación cancelada." << endl;
        }
    } else {
        cout << "\nNo se encontro ningun donante con la cedula " << cedula << endl;
    }

    pausar();
}

void mostrarDonantes(const vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== REGISTRO COMPLETO DE DONANTES =====" << endl;

    if (donantes.empty()) {
        cout << "No hay donantes registrados en el sistema." << endl;
        pausar();
        return;
    }

    cout << left << setw(15) << "CÉDULA"
              << setw(30) << "NOMBRE"
              << setw(10) << "SANGRE"
              << setw(15) << "TELÉFONO"
              << "DIRECCIÓN" << endl;

    cout << string(80, '-') << endl;

    for (const auto& donante : donantes) {
        cout << left << setw(15) << donante.getCedula()
                  << setw(30) << donante.getNombre()
                  << setw(10) << donante.getTipoSangre().getTipo()
                  << setw(15) << donante.getTelefono()
                  << donante.getDireccion() << endl;
    }

    cout << "\nTotal de donantes: " << donantes.size() << endl;

    pausar();
}

void mostrarEstadisticas(const vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== ESTADISTICAS POR TIPO DE SANGRE =====" << endl;

    if (donantes.empty()) {
        cout << "No hay donantes registrados en el sistema." << endl;
        pausar();
        return;
    }

    // Inicializar contador para cada tipo de sangre
    map<string, int> contadorTipoSangre;
    for (const auto& tipo : Sangre::getTiposValidos()) {
        contadorTipoSangre[tipo] = 0;
    }

    // Contar donantes por tipo de sangre
    for (const auto& donante : donantes) {
        contadorTipoSangre[donante.getTipoSangre().getTipo()]++;
    }

    // Mostrar las estadísticas
    cout << left << setw(10) << "TIPO"
              << setw(15) << "CANTIDAD"
              << setw(10) << "PORCENTAJE" << endl;

    cout << string(35, '-') << endl;

    for (const auto& tipo : Sangre::getTiposValidos()) {
        int cantidad = contadorTipoSangre[tipo];
        double porcentaje = donantes.empty() ? 0 : (static_cast<double>(cantidad) / donantes.size()) * 100;

        cout << left << setw(10) << tipo
                  << setw(15) << cantidad
                  << fixed << setprecision(2) << porcentaje << "%" << endl;
    }

    cout << "\nTotal de donantes: " << donantes.size() << endl;

    pausar();
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}
