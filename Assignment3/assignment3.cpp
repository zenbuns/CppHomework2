#include "assignment3.hpp"
#include <string>
#include <vector>
#include <array>
#include <typeinfo>
#include <iostream>

// Funktsioonid (functions)
// Looge funktsioon funk, mis ei tagasta midagi
// ja prindib (cout) "Hello World!" konsoolile
void funk(){
    std::cout << "Hello World!";
}
// Looge funktsioon funk5, mis tagastab int väärtuse 5
int funk5(){
    return 5;
}
// Looge funktsiooni sum deklaratsioon, 
// mis tagastab kahe int väärtuse summa
// Looge funktsioon sum, mis tagastab kahe int väärtuse summa
int sum(int x, int y){
    return x+y;
}
// Looge funktsioon sum, mis tagastab kahe double väärtuse summa
double sum(double x, double y){
    return x+y;
}
// Looge funktsioon increase, mis suurendab int väärtust 1 võrra
int increase(int x){
    return ++x;  // Pre-increment
}
// Looge funktsioon decrease, mis vähendab int väärtust 1 võrra
// kasutades pointerit
int decrease(int* ptr) {
    return --(*ptr);  // Pre-decrement
}
// Looge constexpr funktsioon square, mis tagastab int väärtuse ruudu
constexpr int square(int x){
    return x*x;
}
// Looge consteval funktsioon cube, mis tagastab int väärtuse kuupi
consteval int cube(int x){
    return x*x*x;
}
//Funktsioonide kutsumine
bool RG::Homework2::assignment3()
{
    using namespace std::literals;
    int i1{ 3 };
    int i2{ 8 };

    // Kutsuge funktsiooni funk
    funk();
    // Kutsuge funktsiooni funk5
    // ja salvestage tulemus muutujasse a1
    int a1{funk5()};
    // Kutsuge funktsiooni sum argumentidega 3, 2 
    // ja salvestage tulemus muutujasse a2
    int a2{sum(3, 2)};
    // Kutsuge funktsiooni sum argumentidega 5.4, 4.5 
    // ja salvestage tulemus muutujasse a3
    double a3{sum(5.4, 4.5)};
    // Kutsuge funktsiooni increase argumentidega i1
    i1 = increase(i1);
    // Kutsuge funktsiooni decrease argumentidega i2
    i2 = decrease(&i2);
    // Kutsuge funktsiooni square argumentidega 3
    // ja salvestage tulemus muutujasse a4
    int a4{square(3)};
    // Kutsuge funktsiooni cube argumentidega 3
    // ja salvestage tulemus muutujasse a5
    int a5{cube(3)};

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    static_assert(square(5) == 25);
    return (typeid(&funk) == typeid(void(*)()))
    && (typeid(&funk5) == typeid(int(*)()))
    && (a1 == 5)
    && (a2 == 5)
    && (a3 == 9.9)
    && (typeid(&increase) == typeid(int(*)(int)))  // // Parandatud 
    && (i1 == 4)
    && (typeid(&decrease) == typeid(int(*)(int*)))  // // Parandatud 
    && (i2 == 7)
    && (typeid(&square) == typeid(int(*)(int)))
    && (a4 == 9)
    && (typeid(&cube) == typeid(int(*)(int)))
    && (a5 == 27);
}