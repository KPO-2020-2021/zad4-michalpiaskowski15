#pragma once

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


/**
 * @brief Construct a new Vector<wymiar>:: Vector object (zeroes)
 * 
 * @tparam wymiar 
 */
template <int wymiar>
Vector<wymiar>::Vector() {
    for (int i = 0; i < wymiar; i++) {
        size[i] = 0;
    }
}

/**
 * @brief Construct a new Vector<wymiar>:: Vector object
 * 
 * @tparam wymiar 
 * @param tmp 
 */
template <int wymiar>
Vector<wymiar>::Vector(double tmp[wymiar]) {
    for (int i = 0; i < wymiar; i++) {
        size[i] = tmp[i];
    }
}

/**
 * @brief Addition of two new vectors.
 * 
 * @tparam wymiar 
 * @param v 
 * @return Vector<wymiar> (Sum)
 */
template <int wymiar>
Vector<wymiar> Vector<wymiar>::operator + (const Vector<wymiar> &v) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] + v[i];
    }
    return result;
}

/**
 * @brief Substraction of two vectors.
 * 
 * @tparam wymiar 
 * @param v 
 * @return Vector<wymiar> 
 */
template <int wymiar>
Vector<wymiar> Vector<wymiar>::operator - (const Vector &v) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/**
 * @brief Multiplication of vector and floating point number.
 * 
 * @tparam wymiar 
 * @param tmp 
 * @return Vector<wymiar> 
 */
template <int wymiar>
Vector<wymiar> Vector<wymiar>::operator * (const double &tmp) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/**
 * @brief Division of two vectors.
 * 
 * @tparam wymiar 
 * @param tmp 
 * @return Vector<wymiar> 
 */
template <int wymiar>
Vector<wymiar> Vector<wymiar>::operator / (const double &tmp) {
    Vector<wymiar> result;

    for (int i = 0; i < wymiar; i++) {
        result[i] = size[i] / tmp;
    }

    return result;
}

/**
 * @brief Vector functor.
 * 
 * @tparam wymiar 
 * @param index 
 * @return const double& 
 */
template <int wymiar>
const double &Vector<wymiar>::operator [] (int index) const {
    if (index < 0 || index >= wymiar) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/**
 * @brief  Vector functor.
 * 
 * @tparam wymiar 
 * @param index 
 * @return double& 
 */
template <int wymiar>
double &Vector<wymiar>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/**
 * @brief << operator overload (for Vector)
 * 
 * @tparam wymiar 
 * @param out 
 * @param tmp 
 * @return std::ostream& 
 */
template <int wymiar>
std::ostream &operator << (std::ostream &out, Vector <wymiar> const &tmp) {
    for (int i = 0; i < wymiar; i++) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/**
 * @brief >> operator overload (for Vector)
 * 
 * @tparam wymiar 
 * @param in 
 * @param tmp 
 * @return std::istream& 
 */
template <int wymiar>
std::istream &operator >> (std::istream &in, Vector <wymiar> &tmp) {
    for (int i = 0; i < wymiar; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
