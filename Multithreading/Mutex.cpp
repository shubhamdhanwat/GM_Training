#include <iostream>
#include <thread>
#include <mutex>

/*
100 withdraw transactions of 10 units each
100 deposit transactions of 10 units each
*/

std::mutex mt;
int amount = 1000;

void withdraw()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        // critical section start --here the shared memory is been modified
        mt.lock();
        amount -= 10;
        mt.unlock();
        // critical section ends
    }
}

void Deposite()
{

    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        // critical section starts
        mt.lock();
        amount += 10;
        mt.unlock();
        // critical section ends
    }
}

int main()
{
    std::thread t1(withdraw);
    std::thread t2(Deposite);

    // write operation is perfoming at the same location by 2 threads so we had to add mutex to the critical part


    t1.join();
    t2.join();

    std::cout << amount << "\n";
}