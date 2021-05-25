#pragma once

#include "size.hh"
#include <iostream>
template <int wymiar>
class Vector {

private:

    double size[wymiar];     //Tablica wektora
    friend class Rectangle;
public:

    Vector();        /*konstruktor klasy*/

    Vector(double [wymiar]);

    Vector operator + (const Vector <wymiar> &v);    /*operator dodwania*/

    Vector operator - (const Vector <wymiar> &v);    /*operator odejmowania*/

    Vector operator * (const double &tmp);  /*operator mnozenia*/

    Vector operator / (const double &tmp);  /*operator dzielenia*/

    const double &operator [] (int index) const;

    double &operator [] (int index);

    

};
template <int wymiar>
std::ostream &operator << (std::ostream &out, Vector <wymiar> const &tmp);
template <int wymiar>
std::istream &operator >> (std::istream &in, Vector <wymiar> &tmp);

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int wymiar>
Vector<wymiar>::Vector() {
    for (int i = 0; i < wymiar; i++) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int wymiar>
Vector<wymiar>::Vector(double tmp[wymiar]) {
    for (int i = 0; i < wymiar; i++) {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int wymiar>
Vector Vector<wymiar>::operator + (const Vector<wymiar> &v) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int wymiar>
Vector Vector<wymiar>::operator - (const Vector &v) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] -= v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int wymiar>
Vector Vector<wymiar>::operator * (const double &tmp) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int wymiar>
Vector Vector<wymiar>::operator / (const double &tmp) {
    Vector<wymiar> result;

    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector<wymiar>::operator [] (int index) const {
    if (index < 0 || index >= wymiar) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int wymiar>
double &Vector<wymiar>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int wymiar>
std::ostream &operator << (std::ostream &out, Vector <wymiar> const &tmp) {
    for (int i = 0; i < wymiar; i++) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int wymiar>
std::istream &operator >> (std::istream &in, Vector <wymiar> &tmp) {
    for (int i = 0; i < wymiar; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
