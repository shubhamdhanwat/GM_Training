#include <iostream>
/*
- a callback function is a function that is passed as an argument to another function
 and is intended to be called at a later time.
 
*/
//  a function that takes a callback function as an argument
void performOperation(int x, int y, void (*callback)(int)) {
    int result = x + y;
    // Call the callback function with the result
    callback(result);
}

// Define a callback function
void displayResult(int result) {
    std::cout << "The result is: " << result << std::endl;
}

int main() {
    // Call the performOperation function with the displayResult callback
    performOperation(5, 3, displayResult);

    return 0;
}
