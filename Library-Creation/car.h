#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string make;
    std::string model;
    double distanceTraveled;
    double fuelConsumed;

public:
    // default constructor
    Car() = default;

    // copy constructor
    Car(const Car &) = delete;

    // copy assignment
    Car &operator=(const Car &) = delete;

    // move constructor
    Car(Car &&) = delete;

    // move assignment
    Car &operator=(Car &&) = delete;

    // default destructor
    ~Car() = default;

    Car(const std::string& make, const std::string& model, double distanceTraveled, double fuelConsumed);
    
    double getFuelEfficiency() const;
};

#endif
