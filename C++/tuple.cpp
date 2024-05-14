#include <iostream>
#include <tuple>
int main()
{
    std::tuple<int, std::string> person(15, "ketan"); // inline initialization
    std::cout << std::get<1>(person);
    std::get<1>(person) = "patil";
    // get is use to print the value of the tuple and modify the value in the tuple

    std::cout << std::get<1>(person);

    // declaration of the tuples with the help of the make_tuple function
    std ::tuple<int, char> things;
    things = std::make_tuple(12, 'c');
    std::cout << std::get<1>(things);

    // concatination of the 2 tuples into one tuples
    auto t3 = std::tuple_cat(person, things);
    std::cout << std::get<0>(t3);
    std::cout << std::get<1>(t3);
    std::cout << std::get<2>(t3);
    std::cout << std::get<3>(t3);


    // swap the tuples
    std::tuple <int, char> t1(10,'a');
    std::tuple <int, char> t2=std::make_tuple(15,'z');
    t1.swap(t2);
    std::cout << std::get<0>(t1);
    std::cout << std::get<1>(t1);

}