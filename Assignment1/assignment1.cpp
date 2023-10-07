#include "assignment1.hpp"
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <iostream>

// Viited ja viidad (pointers and references) muutujates
//bool assignment1()
bool RG::Homework2::assignment1()
{
    using namespace std::literals;

    int i{ 5 };
    // Loo muutuja ilr1 mis on int lreference tüüpi ja i väärtusega
    int& ilr1 = i;
    // Loo muutuja irr mis on int rreference tüüpi ja väärtusega 5
    int&& irr = 5;
    // Loo muutuja ilr2 mis on int lreference tüüpi ja väärtusega i
    int& ilr2 = i;
    // Loo muutuja ip mis on int pointer tüüpi ja väärtusega i
    int* ip = &i;
    // Loo muutuja ipp mis on int pointer pointer tüüpi ja väärtusega ip
    int** ipp = &ip;
    // Loo muutuja i2 mis on int tüüpi ja väärtusega millele ip viitab
    int i2 = *ip;
    // Loo muutuja up mis on ainulaadne smartpointer tüüpi ja väärtusega 4
    std::unique_ptr<int> up = std::make_unique<int>(4);
    // Loo muutuja sp mis on jagatud smartpointer tüüpi ja väärtusega 3
    std::shared_ptr<int> sp = std::make_shared<int>(3);
    // Loo muutuja wp mis on nõrk smartpointer tüüpi ja seosta sp-ga
    std::weak_ptr<int> wp = sp;
    // Loo muutuja up mis on raw pointer tüüpi, väärtusega 6,
    // (muutuja nimi peaks olema rp mitte up, mis on juba loodud)
    int* rp = new int(6);
    // siis kustuta see ning seejärel määra nullptr.
    delete rp;
    rp = nullptr;
    
    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    return (typeid(ilr1) == typeid(int&))
    && (ilr1 == 5)
    && (typeid(irr) == typeid(int&&))
    && (irr == 5) // irr == 2 oli algselt, mis ei ole õige
    && (typeid(ilr2) == typeid(int&))
    && (ilr2 == 5)
    && (typeid(ip) == typeid(int*))
    && (*ip == 5)
    && (typeid(ipp) == typeid(int**))
    && (**ipp == 5)
    && (typeid(i2) == typeid(int))
    && (i2 == 5)
    && (typeid(up) == typeid(std::unique_ptr<int>))
    && (*up == 4)
    && (typeid(sp) == typeid(std::shared_ptr<int>))
    && (*sp == 3)
    && (typeid(wp) == typeid(std::weak_ptr<int>))
    && (*wp.lock() == 3)
    && (typeid(rp) == typeid(int*))
    && (rp == nullptr);
}