#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include "Vehicle.h"
#include <vector>
// step1: create a alias pointer which is an alternate name
// for std::shared_ptr to vehicle
using Pointer = std::shared_ptr<Vehicle>;

// step2: now specify alternate container which indicates'
//  a standard vector of pointer where pointers is explained above

using Container = std::vector<Pointer>;

void CreateObjects(Container &data);

float AveragePrice(Container &data);


#endif // FUNCTIONALITIES_H
