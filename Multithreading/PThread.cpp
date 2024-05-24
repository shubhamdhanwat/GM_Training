#include <iostream>
#include <pthread.h>
#include <unistd.h> // for sleep function

// Function to be executed by the new thread
void* threadFunction(void* arg) {
    // Cast the argument to int* and dereference to get thread ID
    int thread_id = *((int*)arg);
    
    // Print message indicating thread is running
    std::cout << "Thread " << thread_id << " is running" << std::endl;
    
    //  sleepbr 3 seconds
    sleep(3);
    
    // Print message indicating thread is exiting
    std::cout << "Thread " << thread_id << " is exiting" << std::endl;
    
    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2; // Thread identifiers
    int thread_id1 = 1, thread_id2 = 2; // Thread IDs
    
    // Create thread 1
    if (pthread_create(&thread1, NULL, threadFunction, (void*)&thread_id1) != 0) {
        // If pthread_create fails, print error message and return 1
        std::cerr << "Error creating thread 1" << std::endl;
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, threadFunction, (void*)&thread_id2) != 0) {
        // If pthread_create fails, print error message and return 1
        std::cerr << "Error creating thread 2" << std::endl;
        return 1;
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print message indicating both threads have finished
    std::cout << "Both threads have finished" << std::endl;

    return 0;
}
//g++ -o threads threads.cpp -pthread
