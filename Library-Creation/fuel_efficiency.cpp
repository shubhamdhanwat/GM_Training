#include "fuel_efficiency.h"

double FuelEfficiencyCalculator::calculateFuelEfficiency(double distance, double fuelConsumed) {
    if (fuelConsumed <= 0 || distance <= 0)
        return 0;
    return distance / fuelConsumed;
}
