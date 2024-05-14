#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> mymap;
    mymap = {
        {"1-1", 10},
        {"1-2", 20},
        {"1-3", 80}};
    // mymap["1-1"] = 10;
    // mymap["1-2"] = 20;
    // std::pair<std::string, int> p1("1-3", 30);
    // mymap.insert(p1);

    // std::cout << mymap["1-4"] << std::endl;
    std::cout << mymap["1-3"] << std::endl;
    // here auto is mymap<std::string , int>::iterator
    for (auto itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        std::cout << itr->first << std::endl;
    }
}