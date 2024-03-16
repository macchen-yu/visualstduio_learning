#include <vector>
#include <iostream>

float add(float a, float b)
{
    return a + b;
}

float acc(const std::vector<float>& vec)
{
    float result = 0.0f;
    for (auto& value : vec)
        result += value;

    return result;
}

int main()
{
    float a = 10.01f;
    float b = 2.5f;

    auto result = add(a, b);
    std::cout << "The Add result: " << result << std::endl;

    std::vector<float> vec{ 1, 2, 3, 4, 5 };
    result = acc(vec);
    std::cout << "The Acc result: " << result << std::endl;
    
    return 0;
}