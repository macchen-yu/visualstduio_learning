#include <iostream>
#include <string>

std::string build_string()
{
    return std::string("hello") + "world";
}

int main()
{
    std::cout << build_string() << std::endl;
    return 0;
}
