#ifndef PETROLCAR_H
#define PETROLCAR_H

#include <iostream>
#include "Vehicle.h"

class PetrolCar : public Vehicle
{
private:
    float _fuelcapacity{};

public:
    // default constructor
    PetrolCar() = default;

    // copy constructor
    PetrolCar(const PetrolCar &) = delete;

    // copy assignment
    PetrolCar &operator=(const PetrolCar &) = delete;

    // move constructor
    PetrolCar(PetrolCar &&) = delete;

    // move assignment
    PetrolCar &operator=(PetrolCar &&) = delete;

    // default destructor
    ~PetrolCar() = default;

    void CalculateRegistrationCharge() override;

    // override key words check if the virtual function is present in the parent class.
    // it is used for conrfirming

    PetrolCar(int id, std::string name, float price, float fuelcapacity);

    friend std::ostream &operator<<(std::ostream &os, const PetrolCar &rhs);
};

#endif // PETROLCAR_H
