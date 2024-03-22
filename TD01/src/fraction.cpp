#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>


std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator; // On affiche d'abord la numérateur puis le dénominateur
}

float Fraction::to_float() const {
    return static_cast<float>(numerator)/static_cast<float>(denominator); //Transforme le numérateur et le dénominateur en float
}

Fraction::operator float() const {
    return to_float(); //Utilise l'opérateur to_float
}



// Ancienne définition de l'opérateur + :
// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction& Fraction::operator+=(Fraction const& f) {
    return simplify({
        numerator*f.denominator + f.numerator*denominator,
        denominator*f.denominator
    });
}

// Nouvelle définition de l'opérateur + en utilisant += :
Fraction operator+(Fraction f1, Fraction const& f2) {
    return f1 += f2; // On ajoute f2 à la fraction f1 déjà présente dans la structure Fraction
}



// Ancienne définition de l'opérateur - :
// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction& Fraction::operator-=(Fraction const& f) {
    return simplify({
        numerator*f.denominator - f.numerator*denominator,
        denominator*f.denominator
    });
}

// Nouvelle définition de l'opérateur - en utilisant -= :
Fraction operator-(Fraction f1, Fraction const& f2) {
    return f1 -= f2; // On soustrait f2 à la fraction f1 déjà présente dans la structure Fraction
}



// Ancienne définition de l'opérateur * :
// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction& Fraction::operator*=(Fraction const& f) {
    return simplify({
        numerator*f.numerator ,
        denominator*f.denominator
    });
}

// Nouvelle définition de l'opérateur * en utilisant *= :
Fraction operator*(Fraction f1, Fraction const& f2) {
    return f1 *= f2; // On multiplie f2 à la fraction f1 déjà présente dans la structure Fraction
}



// Ancienne définition de l'opérateur / :
// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }

Fraction& Fraction::operator/=(Fraction const& f) {
    return simplify({
        numerator*f.denominator,
        denominator*f.denominator
    });
}

// Nouvelle définition de l'opérateur / en utilisant /= :
Fraction operator/(Fraction f1, Fraction const& f2) {
    return f1 /= f2; // On ajoute la fraction f1 déjà présente dans la structure Fraction par f2
}



bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator; // On compare séparément les dénominateurs et les numérateurs
};

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2); //On utilise l'opérateur ==, si le résultat n'est pas f1 == f2, alors f1 != f2
};

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator < f2.numerator || (f1.numerator == f2.numerator && f1.denominator < f2.denominator); // On compare les numérateurs si les dénominateurs sont égaux, les dénominateurs sinon
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1; // On utilise l'opérateur < pour montrer le cas inverse
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1.numerator <= f2.numerator || (f1.numerator == f2.numerator && f1.denominator <= f2.denominator); // Même chose que pour l'opérateur < mais en incluant le cas d'égalité
};

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return f1.numerator >= f2.numerator || (f1.numerator == f2.numerator && f1.denominator >= f2.denominator); // Même chose que pour l'opérateur > mais en incluant le cas d'égalité
};