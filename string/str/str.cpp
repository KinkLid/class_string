#include <iostream>
#include "String.h"
#include "cin_cout.h"

int main()
{
    String s;
    s = "AHAHAHHA";
    String s1("aboba");
    String s2{ "abbudabi" };
    for (auto x : s) {
        std::cout << x;
    }
    for (auto x : s1) {
        std::cout << x;
    }
    for (auto x : s2) {
        std::cout << x;
    }
}
