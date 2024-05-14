#include "Functionalities.h"
#include "PetrolCar.h"
#include "DeiselCar.h"

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<PetrolCar>(1, "tata", 1235000, 40));
    data.emplace_back(std::make_shared<DeiselCar>(101, "mahindra", 154500, 55));
}

float AveragePrice(Container &data)
{
        float total=0.0f;

    for(int i=0; i< data.size();i++)
    {
        total=total+data[i]->price();
    }

    return total/data.size();
}