// main.cpp
#include "math_operations.h"
#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;

    cout << "Addition: " << add(a, b) << endl;
    cout << "Subtraction: " << subtract(a, b) << endl;

    return 0;
}

/*
kpit@L-10158:~/GM_Training/lib$ touch math_operations.h 
kpit@L-10158:~/GM_Training/lib$ g++ -c math_operations.cpp -o math_operations.o
kpit@L-10158:~/GM_Training/lib$ ar rcs libmath_operations.a math_operations.o
kpit@L-10158:~/GM_Training/lib$ touch main.cpp
kpit@L-10158:~/GM_Training/lib$ g++ main.cpp -L. -lmath_operations -o main_executable
kpit@L-10158:~/GM_Training/lib$ ./main_executable 
Addition: 15*/