#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

/*
    -std::condition_variable allows threads to wait until a certain condition is met before proceeding.
    Display Square
        -It should print the square of the number received as input from the user

    Main-
        Main will take the cin input and store value in a global variable

*/
int number = 0;
bool flag = false;
std::mutex mt;

std::condition_variable cv;

void Square()
{
    // CONDITION  check :each time t1 thread is scheduled , condition must be checked
    std::unique_lock<std::mutex> lock(mt);
    cv.wait(lock, []()
            { return flag; });
    std::cout << "Square of " << number << " is " << number * number << "\n";
}
int main()
{
    // step 1: thread is registered (instanitated and handed over to os)
    std::thread t1(&Square);

    // step 2: user input arrives(this can take a very long time)
    std::cout<<"Enter the number :";
    std::cin >> number;

    // set the flag to true
    flag = true; // this specifies condition is met!

    // step 3: send a signal
    cv.notify_all(); // signal send to main that we can now invoke the waiting thread;

    t1.join();

    return 0;
}