#include <iostream>

template<typename T>
T square(void*);

template<>
void square(void* num) {
    int* intNum = static_cast<int*>(num);
    int result = (*intNum) * (*intNum);
    std::cout << "The square of " << *intNum << " is " << result << std::endl;
};

// Works: Variant 1
template<typename T = int>
T square(void* num) {
    int* intNum = static_cast<int*>(num);
    int result = (*intNum) * (*intNum);
    std::cout << "The square of " << *intNum << " is " << result << std::endl;
    return result;
};

// Works: Variant 2
// template<>
// int square(void* num) {
//     int* intNum = static_cast<int*>(num);
//     int result = (*intNum) * (*intNum);
//     std::cout << "The square of " << *intNum << " is " << result << std::endl;
//     return result;
// };

template<>
float square(void* num) {
    float* intNum = static_cast<float*>(num);
    float result = (*intNum) * (*intNum);
    std::cout << "The float square of " << *intNum << " is " << result << std::endl;
    return result;
};

template<typename T = void>
T square(void) { // (void num) is not works
    std::cout << "The square of square(void) is void" << std::endl;
};

int main(void) {
    int number_a = 2;
    square<void>(&number_a);

    auto __type__ = square(&number_a);

    int number_b = 3;
    square<int>(&number_b);

    float number_c = 2.5;
    square<float>(&number_c);

    square<void>();
    square<>();
    square();

    int a;
    int* b = &a;

    // auto __type__ = square<void>(&number); // error
    return 0;
}
