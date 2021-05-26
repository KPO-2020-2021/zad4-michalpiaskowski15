#pragma once


#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
template <int wymiar>
class Matrix {

private:
    double value[wymiar][wymiar];               // Wartosci macierzy

public:
    Matrix(double [wymiar][wymiar]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    void macierz_obrotu(double kat_stopnie, char oms); 
    
    Vector<wymiar> operator * (Vector<wymiar> tmp);           // Operator mnożenia przez wektor

    Matrix<wymiar> operator + (Matrix<wymiar> tmp);           // Operator dodawania

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    void macierz_jednostkowa(Matrix<wymiar> jajo);
    
    /*int wyznacznik_macierzy();       niestety nie potrafie skonczyc*/
    
};

/*int Matrix::wyznacznik_macierzy() 
{
    int tablica_macierzy[SIZE*10][SIZE*10];
    int rozmiar_macierzy=0;
    int wyznacznik=0;
    std::cout << "Podaj rozmiar macierzy" << std::endl;
    std::cin >> rozmiar_macierzy;
    std::cout << "Podaj kolejno elementy Twojej macierzy" << std::endl;
    
    for(int i=0;i<rozmiar_macierzy; i++)
        {
            for(int j=0; j<rozmiar_macierzy; j++)
                {
                    std::cin >> tablica_macierzy[i][j];        
                }
        }
    std::cout << tablica_macierzy << std::endl;
    for(int a=0; a<SIZE*10; a++)
        {
        for(int b=0; b<rozmiar_macierzy; b++)
            {
                ((tablica_macierzy[a][b]*tablica_macierzy[a+1][b+1])-(tablica_macierzy[a+1][b]*tablica_macierzy[a][b+1]));
            }
        }
}*/

/**
 * @brief Identity matrix
 * 
 * @tparam wymiar 
 * @param jajo 
 */
template <int wymiar>
void Matrix<wymiar>::macierz_jednostkowa(Matrix<wymiar> jajo)
{
     if(wymiar==2)
    {
        value[0][0] = 1;                          
        value[0][1] = 0;
        value[1][0] = 0;
        value[1][1] = 1;
    }
       if(wymiar==3)
    {
        value[0][0] = 1;                     
        value[0][1] = 0;
        value[0][2] = 0;
        value[1][0] = 0;
        value[1][1] = 1;               
        value[1][2] = 0;
        value[2][0] = 0;
        value[2][1] = 0;
        value[2][2] = 1;
    }
}

/**
 * @brief Rotation matrix
 * 
 * @tparam wymiar 
 * @param kat_stopnie 
 * @param oms 
 */
template <int wymiar>
void Matrix<wymiar>::macierz_obrotu(double kat_stopnie, char oms)
{
    double kat_radiany = (kat_stopnie*M_PI) / 180;                  /*zamiana miary kata w stopniach na radiany*/ 
    

    if(wymiar==2)
    {
        value[0][0] = cos(kat_radiany);                                 /*obliczanie macierzy obrotu dla rotacji*/
        value[0][1] = -sin(kat_radiany);
        value[1][0] = sin(kat_radiany);
        value[1][1] = cos(kat_radiany);
    }
    if(wymiar==3)
    {
        switch(oms){
            case 'x':
                value[0][0] = 1;                            
                value[0][1] = 0;
                value[0][2] = 0;
                value[1][0] = 0;
                value[1][1] = cos(kat_radiany);                              
                value[1][2] = -sin(kat_radiany);
                value[2][0] = 0;
                value[2][1] = sin(kat_radiany);
                value[2][2] = cos(kat_radiany);
            break;
            
            case 'y':
                value[0][0] = cos(kat_radiany);                          
                value[0][1] = 0;
                value[0][2] = sin(kat_radiany);
                value[1][0] = 0;
                value[1][1] = 1;                             
                value[1][2] = 0;
                value[2][0] = -sin(kat_radiany);
                value[2][1] = 0;
                value[2][2] = cos(kat_radiany);
            break;

            case 'z':
                value[0][0] = cos(kat_radiany);                        
                value[0][1] = -sin(kat_radiany);
                value[0][2] = 0;
                value[1][0] = sin(kat_radiany);
                value[1][1] = cos(kat_radiany);               
                value[1][2] = 0;
                value[2][0] = 0;
                value[2][1] = 0;
                value[2][2] = 1;
            break;

            default:
            std::cout << "Niepoprawna oms" << std::endl;
            break;
        }
    }
}

template <int wymiar>
std::istream &operator>>(std::istream &in, Matrix<wymiar> &mat);
template <int wymiar>
std::ostream &operator<<(std::ostream &out, Matrix<wymiar> const &mat);

/**
 * @brief Construct a new Matrix<wymiar>:: Matrix object (zeroes)
 * 
 * @tparam wymiar 
 */
 template <int wymiar>
Matrix<wymiar>::Matrix() {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            value[i][j] = 0;
        }
    }
}

/**
 * @brief Construct a new Matrix<wymiar>:: Matrix object
 * 
 * @tparam wymiar 
 * @param tmp 
 */
 template <int wymiar>
Matrix<wymiar>::Matrix(double tmp[wymiar][wymiar]) {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

/**
 * @brief Matrix and vector multiplication
 * 
 * @tparam wymiar 
 * @param tmp 
 * @return Vector<wymiar> 
 */
template <int wymiar>
Vector<wymiar> Matrix<wymiar>::operator * (Vector <wymiar> tmp) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/**
 * @brief Matrix functor
 * 
 * @tparam wymiar 
 * @param row 
 * @param column 
 * @return double& 
 */
 template <int wymiar>
double &Matrix<wymiar>::operator()(unsigned int row, unsigned int column) {

    if (row >= wymiar) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= wymiar) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}




/**
 * @brief Matrix functor
 * 
 * @tparam wymiar 
 * @param row 
 * @param column 
 * @return const double& 
 */
 template <int wymiar>
const double &Matrix<wymiar>::operator () (unsigned int row, unsigned int column) const {            

    if (row >= wymiar) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= wymiar) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}



/**
 * @brief Matrix addition overload
 * 
 * @tparam wymiar 
 * @param tmp 
 * @return Matrix<wymiar> 
 */
 template <int wymiar>
Matrix<wymiar> Matrix<wymiar>::operator + (Matrix<wymiar> tmp) {
    Matrix result;
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/**
 * @brief >> operator overload (for Matrix)
 * 
 * @tparam wymiar 
 * @param in 
 * @param mat 
 * @return std::istream& 
 */
 template <int wymiar>
std::istream &operator>>(std::istream &in, Matrix<wymiar> &mat) {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/**
 * @brief << operator overload (for Matrix)
 * 
 * @tparam wymiar 
 * @param out 
 * @param mat 
 * @return std::ostream& 
 */
 template <int wymiar>
std::ostream &operator<<(std::ostream &out, const Matrix<wymiar> &mat) {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

