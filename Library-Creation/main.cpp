#include <iostream>
#include "car.h"

int main() {
    Car myCar("Toyota", "Camry", 500, 20);
    double fuelEfficiency = myCar.getFuelEfficiency();
    std::cout << "Fuel Efficiency: " << fuelEfficiency << " km/l" << std::endl;
    return 0;
}

/*
commands to generate  the library file and compile it.
kpit@L-10158:~/GM_Training/Library-Generation$ 
g++ -c -Wall -Werror -fpic fuel_efficiency.cpp -o fuel_efficiency.o
g++ -shared -o libfuel_efficiency.so fuel_efficiency.o

kpit@L-10158:~/GM_Training/Library-Generation$ touch car.h
kpit@L-10158:~/GM_Training/Library-Generation$ touch car.cpp
kpit@L-10158:~/GM_Training/Library-Generation$ touch main.cpp

g++ -c -Wall -Werror car.cpp -o car.o
g++ -c -Wall -Werror main.cpp -o main.o
g++ car.o main.o -L. -lfuel_efficiency -o car
kpit@L-10158:~/GM_Training/Library-Generation$ ./car

./car: error while loading shared libraries: libfuel_efficiency.so: cannot open shared object file: No such file or directory
kpit@L-10158:~/GM_Training/Library-Generation$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:Library-Creation/libfuel_efficiency.so
kpit@L-10158:~/GM_Training/Library-Generation$ ./car
Fuel Efficiency: 25 km/l



*/