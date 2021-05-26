#pragma once

#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>

class Cuboid {                                   /*klasa prostopadloscianu*/

private:
    Vector<3> wspolrzedna[8];
public:
    Cuboid();               /*konstruktor klasy*/
    Cuboid(Vector<3> tmp[8]);
    friend std::ostream & operator << (std::ostream & strm, const Cuboid &_cuboid);
    void rotacja(Matrix<3> mamcierz);
    void translacja(Vector<3> tmp);
    void sprawdz_dlugosc();
};

/**
 * @brief Construct a new Cuboid:: Cuboid object filled with zeros.
 * 
 */
Cuboid::Cuboid()
{
    for(int i=0; i<8; i++)
    {
        wspolrzedna[i]=0;
    }
}

/**
 * @brief Construct a new Cuboid:: Cuboid object
 * 
 * @param tmp 
 */
Cuboid::Cuboid(Vector<3> tmp[8])
{
    for(int i=0; i<8; i++)
    {
        wspolrzedna[i]=tmp[i];
    }
}
/**
 * @brief 
 * 
 * @param strm 
 * @param _cuboid 
 * @return std::ostream& 
 */
std::ostream & operator << (std::ostream & strm, const Cuboid &_cuboid)                     /*wczytywanie wspolrzednych*/
{
    strm << _cuboid.wspolrzedna[0][0] << " " << _cuboid.wspolrzedna[0][1] << " " << _cuboid.wspolrzedna[0][2] << std::endl;      
    strm << _cuboid.wspolrzedna[1][0] << " " << _cuboid.wspolrzedna[1][1] << " " << _cuboid.wspolrzedna[1][2] << std::endl; 
    strm << _cuboid.wspolrzedna[2][0] << " " << _cuboid.wspolrzedna[2][1] << " " << _cuboid.wspolrzedna[2][2] << std::endl; 
    strm << _cuboid.wspolrzedna[3][0] << " " << _cuboid.wspolrzedna[3][1] << " " << _cuboid.wspolrzedna[3][2] << std::endl; 
    strm << _cuboid.wspolrzedna[0][0] << " " << _cuboid.wspolrzedna[0][1] << " " << _cuboid.wspolrzedna[0][2] << std::endl;
    strm << _cuboid.wspolrzedna[5][0] << " " << _cuboid.wspolrzedna[5][1] << " " << _cuboid.wspolrzedna[5][2] << std::endl;
    strm << _cuboid.wspolrzedna[6][0] << " " << _cuboid.wspolrzedna[6][1] << " " << _cuboid.wspolrzedna[6][2] << std::endl;
    strm << _cuboid.wspolrzedna[1][0] << " " << _cuboid.wspolrzedna[1][1] << " " << _cuboid.wspolrzedna[1][2] << std::endl;
    strm << _cuboid.wspolrzedna[6][0] << " " << _cuboid.wspolrzedna[6][1] << " " << _cuboid.wspolrzedna[6][2] << std::endl;
    strm << _cuboid.wspolrzedna[7][0] << " " << _cuboid.wspolrzedna[7][1] << " " << _cuboid.wspolrzedna[7][2] << std::endl;
    strm << _cuboid.wspolrzedna[2][0] << " " << _cuboid.wspolrzedna[2][1] << " " << _cuboid.wspolrzedna[2][2] << std::endl;
    strm << _cuboid.wspolrzedna[7][0] << " " << _cuboid.wspolrzedna[7][1] << " " << _cuboid.wspolrzedna[7][2] << std::endl;
    strm << _cuboid.wspolrzedna[4][0] << " " << _cuboid.wspolrzedna[4][1] << " " << _cuboid.wspolrzedna[4][2] << std::endl;
    strm << _cuboid.wspolrzedna[3][0] << " " << _cuboid.wspolrzedna[3][1] << " " << _cuboid.wspolrzedna[3][2] << std::endl; 
    strm << _cuboid.wspolrzedna[4][0] << " " << _cuboid.wspolrzedna[4][1] << " " << _cuboid.wspolrzedna[4][2] << std::endl;
    strm << _cuboid.wspolrzedna[5][0] << " " << _cuboid.wspolrzedna[5][1] << " " << _cuboid.wspolrzedna[5][2] << std::endl;
     
    return strm;
}
/**********************************************************************************************************************************************************/

/**
 * @brief Rotation
 * 
 * @param mamcierz 
 */
void Cuboid::rotacja(Matrix<3> mamcierz)           
{
    
    for(int i=0; i<8; i++)
        {
           wspolrzedna[i]=mamcierz*wspolrzedna[i];
        }
    
}
/*********************************************************************************************************************************************************/

/**
 * @brief Translation
 * 
 * @param tmp 
 */
void Cuboid::translacja(Vector<3> tmp)                               
{
    
    for(int i=0; i<8; i++)
        {
           wspolrzedna[i]=tmp+wspolrzedna[i];
        }
}
/****************************************************************************************************************************************************************/

/**
 * @brief Checking opposite lenghts(not fully functionable)
 * 
 */
void Cuboid::sprawdz_dlugosc()         /*sprawdzanie dlugosci przeciwleglych bokow _cuboida*/
{
        
        int i=0;
        if(sqrt((pow((wspolrzedna[i+1][0]-wspolrzedna[i][0]),2))+(pow((wspolrzedna[i+1][1]-wspolrzedna[i][1]),2)))==sqrt((pow((wspolrzedna[i+3][0]-wspolrzedna[i+2][0]),2))+(pow((wspolrzedna[i+3][1]-wspolrzedna[i+2][1]),2)))&&sqrt((pow((wspolrzedna[i+2][0]-wspolrzedna[i+1][0]),2))+(pow((wspolrzedna[i+2][1]-wspolrzedna[i+1][1]),2)))==sqrt((pow((wspolrzedna[i+3][0]-wspolrzedna[i][0]),2))+(pow((wspolrzedna[i+3][1]-wspolrzedna[i][1]),2))))
        {
            std::cout << "Dlugosci bokow sa zgodne" << std::endl;
        }
        else
        {
            std::cerr << "To nie jest poprawny _cuboid" << std::endl;
        }
}


