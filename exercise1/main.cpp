
#include "zmytest/test.hpp"

#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  unsigned int scelta = 0;
  std::cout << "Inserire Test Da Eseguire : \n 1) Domenico Gagliotti Test;\n 2) Prof Test;\n Inserire ---> ";
  std::cin>>scelta;
  
  switch (scelta){
    case 1:
      mytest();
    break;
      
    case 2:
      lasdtest();
    break;

    default:
      std::cout<<"Devi Inserire Un Numero Tra 1 e 2;\n";
    break;
  }

  
  return 0;
}
