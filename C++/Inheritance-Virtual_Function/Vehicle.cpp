#include "Vehicle.h"

Vehicle::Vehicle(int id, std::string name, float price):_id(id), _name(name),_price(price)
{
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price;
    return os;
}
