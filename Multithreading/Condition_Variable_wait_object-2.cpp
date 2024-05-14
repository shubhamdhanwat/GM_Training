#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool itemReady = false;
int sharedData = 0;

void producer() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulating some work
    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedData = 42; // Produce an item
        itemReady = true; // Indicate that the item is ready
    }
    cv.notify_one(); // Notify the consumer
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return itemReady; }); // Wait until the item is ready
    std::cout << "Consumed: " << sharedData << std::endl;
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
