#include "assignment2.hpp"
#include <string>
#include <vector>
#include <array>
#include <typeinfo>

//Konstandid (const, constexpr, muutujad)
bool RG::Homework2::assignment2()
{
    using namespace std::literals;
    int i{ 3 };
    const int ci = 5;
    constexpr int cxpi = 4;
    const int* cip = &ci;
    int const* ipc = &i;
    const int* const cipc = &ci;

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    return (typeid(ci) == typeid(int))  // const int ja int on sama typeid
    && (ci == 5)
    && (typeid(cxpi) == typeid(int))  // constexpr int ja int on sama typeid
    && (cxpi == 4)
    && (typeid(cip) == typeid(const int *))  // Korras nii nagu ta on
    && (*cip == ci) 
    && (typeid(ipc) == typeid(const int *))  // Parandatud: typeid ei suuda eristada int* ja const int*
    && (*ipc == i)
    && (typeid(cipc) == typeid(const int *))  //  Parandatud: typeid ei suuda eristada const int* const ja const int*
    && (*cipc == ci);
}
