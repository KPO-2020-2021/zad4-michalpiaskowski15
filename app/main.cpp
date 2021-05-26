// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "exampleConfig.h"
#include "exampleConfig.h.in"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "../include/lacze_do_gnuplota.hh"
/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i _cuboida
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
  
 


void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream&  StrmWy, Cuboid _cuboid)
{
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << _cuboid;        /*wrzucamy na strumien wspolrzedne _cuboida*/
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i _cuboida
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool PrzykladZapisuWspolrzednychDoPliku(const char  *sNazwaPliku, Cuboid _cuboid)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  
  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, _cuboid);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main() {                                                                         

int wybor;
double p1[3]={100,100, 300};            /*ustalamy poczatkowe wspolrzedne _cuboida*/
double p2[3]={500,100, 300};
double p3[3]={500,400, 300};
double p4[3]={100,400, 300};
double p5[3]={100,400, 100};            
double p6[3]={100,100, 100};
double p7[3]={500,100, 100};
double p8[3]={500,400, 100};



Vector<3> wierzcholki[8]={p1,p2,p3,p4,p5,p6,p7,p8};
for(int i=0; i<8; i++)
       {
              std::cout << wierzcholki[i] << std::endl;
       }
Cuboid _cuboid(wierzcholki);
PzG::LaczeDoGNUPlota  Lacze;

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "_cuboid.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("_cuboid.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("_cuboid.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);
/**************************************************************************************/

do{
       std::cout << "Menu programu Rotacja3D" << std::endl;        /*menu programu*/
       std::cout << "Dostepne opcje:" << std::endl;
       std::cout << "1)     Translacja" << std::endl;
       std::cout << "2)     Rotacja" << std::endl;
       std::cout << "3)     Wyjscie" << std::endl;
       std::cout << "Wybierz opcje:" << std::endl;
       std::cin >> wybor;

       switch(wybor){
              
              case 1:   /*translacja*/
              {
              int wsp1,wsp2, wsp3;
              Vector<3> wektor;

              std::cout << "Wprowadz pojedynczo wspolrzedne wektora" << std::endl;
              std::cout << "Wspolrzedna x:" << std::endl;        /*wczytujemy osie*/
              std::cin >> wsp1;
              std::cout << "Wspolrzedna y:" << std::endl;
              std::cin >> wsp2;
              std::cout << "Wspolrzedna z:" << std::endl;
              std::cin >> wsp3;
              wektor[0] = wsp1;                                   /*tworzymy wektory*/
              wektor[1] = wsp2;
              wektor[2] = wsp3;
              _cuboid.translacja(wektor);
              
              PrzykladZapisuWspolrzednychDoStrumienia(std::cout, _cuboid);
              
              if (!PrzykladZapisuWspolrzednychDoPliku("_cuboid.dat", _cuboid))return 1;
              
              Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
              std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
              std::cin.ignore(100000,'\n');
              break;
              }
              case 2:       /*rotacja*/
              {
              int kat;
              int ilosc_powtorzen;
              char oms;
              Matrix<3> temp;
              std::cout << "Podaj kat obrotu" << std::endl;
              std::cin >> kat;
              std::cout << "Podaj ilosc powtorzen" << std::endl;
              std::cin >> ilosc_powtorzen;
              std::cout << "Podaj Os" << std::endl;
              std::cin >> oms;
              temp.macierz_obrotu(kat*ilosc_powtorzen, oms);
              _cuboid.rotacja(temp);
       
              PrzykladZapisuWspolrzednychDoStrumienia(std::cout, _cuboid);
              if (!PrzykladZapisuWspolrzednychDoPliku("_cuboid.dat", _cuboid)) return 1;
              Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
              std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
              std::cin.ignore(100000,'\n');
              break;
              }
              case 3:
              {break;}
              default:
              {break;}
       }
}while(wybor!=3);

  

  // Z bazy projektu-wydmuszki Boiler Plate C++:
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}