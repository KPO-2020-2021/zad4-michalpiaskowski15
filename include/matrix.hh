#pragma once

#include "size.hh"
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
std::istream &operator>>(std::istream &in, Matrix &mat);
template <int wymiar>
std::ostream &operator<<(std::ostream &out, Matrix const &mat);

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
 template <int wymiar>
Matrix<wymiar>::Matrix() {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
 template <int wymiar>
Matrix<wymiar>::Matrix(double tmp[wymiar][wymiar]) {
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int wymiar>
Vector<wymiar> Matrix<wyiar>::operator * (Vector <wymiar> tmp) {
    Vector<wymiar> result;
    for (int i = 0; i < wymiar; i++) {
        for (int j = 0; j < wymiar; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
 template <int wymiar>
double &Matrix::operator()(unsigned int row, unsigned int column) {

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


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
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

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
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

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
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


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
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

