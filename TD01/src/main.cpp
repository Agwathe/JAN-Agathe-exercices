#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };
    Fraction f3 { f1 + f2 }; //Test pour l'opérateur +
    Fraction f4 { 1, 2 };

    std::cout << "f1 = ";
    std::cout << f1;
    std::cout << " f2 = ";
    std::cout << f2;
    std::cout << std::endl;

    // Test de l'opérateur + :
    std::cout << "add(f1, f2) = ";
    std::cout << f3;

    // Test de l'opérateur - :
    std::cout << std::endl << "sub(f1, f2) = ";
    std::cout << f1 - f2;

    // Test de l'opérateur * :
    std::cout << std::endl << "mul(f1, f2) = ";
    std::cout << f1*f2;

    // Test de l'opérateur / :
    std::cout << std::endl << "div(f1, f2) = ";
    std::cout << f1/f2;

    std::cout << std::endl << "add(1/6, 2/6) = ";
    std::cout << Fraction {1, 6} + Fraction {2, 6} << std::endl;
    
    // Test de l'opérateur == :
    std::cout << (f1 == f2) << std::endl;

    // Test de l'opérateur != :
    std::cout << (f1 != f2) << std::endl;

    // Test de l'opérateur < :
    std::cout << (f1 < f2) << std::endl;

    // Test de l'opérateur > : 
    std::cout << (f1 > f2) << std::endl;

    // Test de l'opérateur <= :
    std::cout << (f2 <= f4) << std::endl;

    // Test de l'opérateur >= :
    std::cout << (f2 >= f4) << std::endl;

    std::cout << "f1 = " << f1.to_float() << std::endl;

    float d1 {static_cast<float>(f1)};
    std::cout << "d1 = " << d1 ;

    return 0;
}