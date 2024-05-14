#include "PetrolCar.h"

std::ostream &operator<<(std::ostream &os, const PetrolCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuelcapacity: " << rhs._fuelcapacity;
    return os;
}

void PetrolCar::CalculateRegistrationCharge()
{
    std::cout<<"Tax on petrol is 13 % "<<0.13f*price()
    <<"\n";
    
    //we are accepting price by getter we can set price  as protected and it will be assisible to child class
    //function in the class is the behaviour/action.

}
PetrolCar::PetrolCar(int id, std::string name, float price, float fuelcapacity)
    : Vehicle(id, name, price), _fuelcapacity(fuelcapacity)
{
    
}
