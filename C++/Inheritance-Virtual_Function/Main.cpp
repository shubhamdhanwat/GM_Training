
#include <iostream>
#include "Vehicle.h"
#include "Functionalities.h"
#include "DeiselCar.h"
#include "PetrolCar.h"

int main()
{
    Container data;
    CreateObjects(data);
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << *(data[i]) << "\n";
        data[i]->CalculateRegistrationCharge();
    }
    // display(data);
    std::cout << "\nAverage price :" << AveragePrice(data)<<std::endl;
}