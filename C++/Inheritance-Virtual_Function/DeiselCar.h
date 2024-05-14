#ifndef DEISELCAR_H
#define DEISELCAR_H

#include<iostream>
#include"Vehicle.h"

class DeiselCar:public Vehicle
{
private:
    int _fuel_tank_capacity{};
public:
    // default constructor
    DeiselCar() = default;

    // copy constructor
    DeiselCar(const DeiselCar &) = delete;

    // copy assignment
    DeiselCar &operator=(const DeiselCar &) = delete;

    // move constructor
    DeiselCar(DeiselCar &&) = delete;

    // move assignment
    DeiselCar &operator=(DeiselCar &&) = delete;

    // default destructor
    ~DeiselCar() = default;

    DeiselCar(int id, std::string name, float price, int fuel_capacity);

    void CalculateRegistrationCharge() override;

    int fuelTankCapacity() const { return _fuel_tank_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const DeiselCar &rhs);


    // override key words check if the virtual function is present in the parent class.
    // it is used for conrfirming
};


#endif // DEISELCAR_H
