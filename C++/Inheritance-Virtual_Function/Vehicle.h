#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle
{
private:
    int _id;
    std::string _name{""};
    float _price{0.0f};

public:
    // default constructor
    Vehicle() = default;

    // copy constructor
    Vehicle(const Vehicle &) = delete;

    // copy assignment
    Vehicle &operator=(const Vehicle &) = delete;

    // move constructor
    Vehicle(Vehicle &&) = delete;

    // move assignment
    Vehicle &operator=(Vehicle &&) = delete;

    // default destructor
    ~Vehicle() = default;

    Vehicle(int id, std::string name, float price);

    int id() const { return _id; }

    std::string name() const { return _name; }

    float price() const { return _price; }

    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

    virtual void CalculateRegistrationCharge() = 0;
    // user can not make the objects of vehicle class
};

#endif // VEHICLE_H
