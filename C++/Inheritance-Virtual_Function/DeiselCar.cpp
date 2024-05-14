#include "DeiselCar.h"

DeiselCar::DeiselCar(int id, std::string name, float price, int fuel_capacity)
:Vehicle(id, name, price), _fuel_tank_capacity(fuel_capacity)
{
}

void DeiselCar::CalculateRegistrationCharge()
{
    std::cout<<"THe tax on the car is :"<<0.12*price()<<std::endl;
}

std::ostream &operator<<(std::ostream &os, const DeiselCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity;
    return os;
}


