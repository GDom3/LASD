
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  
  unsigned short int scelta = 1;

  
  std::cout << "Inserisci La Scelta Desiderata : \n 1) Prof Test ; \n 2) Domenico Gagliotti Test ; \nRisposta ----> ";
  std::cin>>scelta;

  switch (scelta){
    case 1:
      lasdtest();
    break;

    case 2:
      mytest();
    break;

    default:
      std::cout<<"\nInserisci Un Numero Compreso Tra 1 e 2 , I Quali Corrispondono Alle Azioni Trascritte Sopra!\n";
    break;
    


  }
  
  
  
  
  return 0;
}
