#ifndef DONOR_H
#define DONOR_H

#include <string>
using namespace std;

class Donor
{
public:
    /// Constructor y destructor
    Donor(int _donorId, int _district, int _number, const string& _name, const string& _address, const string& _bloodType);
    virtual ~Donor();

    /// Setters
    void setDonorId(int _donorId);
    void setDistrict(int _district);
    void setNumber(int _number);
    void setName(const string& _name);
    void setAddress(const string& _address);
    void setBloodType(const string& _bloodType);

    /// Getters
    int getDonorId() const;
    int getDistrict() const;
    int getNumber() const;
    string getName() const;
    string getAddress() const;
    string getBloodType() const;

    /// Métodos funcionales
    string getDonorInfo() const;                 // Devuelve toda la info del donante como string
    void updateInfo(const string& _address, int _district); // Actualiza dirección y distrito

private:
    // Atributos
    int donorId, district, number;
    string name, address, bloodType;

    // (Opcional) Validación
    bool isValidBloodType(const string& type) const;
};

#endif // DONOR_H
