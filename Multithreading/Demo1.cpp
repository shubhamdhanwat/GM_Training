#include <iostream>
#include <array>
#include <thread>
//when we include thread library we had to use -lpthread to compile

std::array<int, 10> result;

void square(std::array<int, 5> &data)
{
    int k = 0;
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val * val;
    }
}

void cube(std::array<int, 5> &data)
{

    int k = 5;
    for (int val : data)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val * val * val;
    }
}

int main()
{
    std::array<int, 5> data{1, 2, 3, 4, 5};
    //request os to seperate the main program into 3 parts main squrare and cube
    //to make the thread there should be no dependancy the square and cube should be independent function

    std::thread t1(&square,std::ref(data)   );
    std::thread t2(&cube,std::ref(data) );
    std::thread t3(
        [](std::array<int, 5> &data){
            int k = 10;
            for (int val : data){
                std::this_thread::sleep_for(std::chrono::seconds(1) );
                result[k++] = val * val /val;
            }
        },
        std::ref(data)
    );

    t1.join();//main should not proceed further untill this line  t1 sends a signal "that it is finished"
    t2.join();
    t3.join();

    //here the main thread is blocked 

    for(int val:result)
    {
        std::cout<<val<<"\t";

    }
    std::cout<<"\n";
}