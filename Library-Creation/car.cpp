#include "car.h"
#include "fuel_efficiency.h"

Car::Car(const std::string& make, const std::string& model, double distanceTraveled, double fuelConsumed)
    : make(make), model(model), distanceTraveled(distanceTraveled), fuelConsumed(fuelConsumed) {}

double Car::getFuelEfficiency() const {
    return FuelEfficiencyCalculator::calculateFuelEfficiency(distanceTraveled, fuelConsumed);
}
