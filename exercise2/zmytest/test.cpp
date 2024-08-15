#include <iostream>
#include <string>

#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/vector/vector.hpp"
#include "../zlasdtest/stack/stack.hpp"
#include "../zlasdtest/queue/queue.hpp"
#include "../zlasdtest/binarytree/binarytree.hpp"


#include "../list/list.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../vector/vector.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

#include "test.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ Welcome to the Domenico Gagliotti LASD Test Suite ~*~#~*~ " << endl;

  unsigned int numeroLocaleTest, numeroLocaleErrori;
  unsigned int stestnum = 0, stesterr = 0;

  numeroLocaleTest = 0; numeroLocaleErrori = 0;
  testVettoreMio(numeroLocaleTest, numeroLocaleErrori);
  stestnum += numeroLocaleTest; stesterr += numeroLocaleErrori;

  numeroLocaleTest = 0; numeroLocaleErrori = 0;
  testListaMio(numeroLocaleTest, numeroLocaleErrori);
  stestnum += numeroLocaleTest; stesterr += numeroLocaleErrori;
  
  numeroLocaleTest = 0; numeroLocaleErrori = 0;
  testStackaMio(numeroLocaleTest, numeroLocaleErrori);
  stestnum += numeroLocaleTest; stesterr += numeroLocaleErrori;

  numeroLocaleTest = 0; numeroLocaleErrori = 0;
  testQueueMio(numeroLocaleTest, numeroLocaleErrori);
  stestnum += numeroLocaleTest; stesterr += numeroLocaleErrori;
  
  numeroLocaleTest = 0; numeroLocaleErrori = 0;
  testAlberoMio(numeroLocaleTest, numeroLocaleErrori);
  stestnum += numeroLocaleTest; stesterr += numeroLocaleErrori;
  
  cout << endl << "Risultati Test (Errors/Tests: " << stesterr << "/" << stestnum << ")\n\n";
}

void testAlberoMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  testAlberoIntMio(numeroTest,numeroErrori);
  testAlberoDoubleMio(numeroTest,numeroErrori);
}

void testVettoreMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  testVettoreIntMio(numeroTest,numeroErrori);
  testVettoreStringMio(numeroTest,numeroErrori);
}

void testListaMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  testListaIntMio(numeroTest,numeroErrori);
  testListaStringMio(numeroTest,numeroErrori);
}

void testStackaMio(unsigned int &numeroTest, unsigned int &numeroErrori) {
  testStackVecIntMio(numeroTest, numeroErrori);
  testStackVecStringMio(numeroTest, numeroErrori);

  testStackLstIntMio(numeroTest, numeroErrori);
  testStackLstStringMio(numeroTest, numeroErrori); 
}

void testQueueMio(unsigned int &numeroTest, unsigned int &numeroErrori){
  testQueueVecIntMio(numeroTest, numeroErrori);
  testQueueVecStringMio(numeroTest, numeroErrori);

  testQueueLstIntMio(numeroTest, numeroErrori);
  testQueueLstStringMio(numeroTest, numeroErrori); 
}

void testVettoreStringMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio Vettore<String> Test DG :" << endl;
        
  lasd::SortableVector<string> VettoreSort; 
        
  // Controllo Che sia vuoto il vettore 
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort , true);

  lasd::SortableVector<string> VettoreSortDodici(12); 
        
  // Verifica Se ha fatto bene la copia e quindi che non sia più vuota
  VettoreSort = VettoreSortDodici;
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreSortDodici, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false);
    
  lasd::SortableVector<string> VettoreSort2; 

  // testo nuovamente la copia con un vettore vuoto con uno già con size
  VettoreSortDodici = VettoreSort2;
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0); // verifico le dimensioni
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, VettoreSort2, true); // la loro uguaglianza
        
  //Verifico la vecchia uguaglianza
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreSortDodici, false);
        
  // Provo a mettere in un vettore vuoto
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 0, string("0"));
        
  // Testo la Resize e la verifico
  VettoreSort2.Resize(5);
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 5);
        
  // Metto in VettoreSort2 [5,4,3,2,1]
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 0, string("5"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 1, string("4"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 2, string("3"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 3, string("2"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 4, string("1"));
        
  //Stampo tutti
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, TraversePrint<string>);

  //controllo valori random
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 0, string("4"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 1, string("2"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 3, string("1"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 3, string("3"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 4, string("5"));
        
  // Testo l'uscire fuori ai bordi
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 5, string("1"));

  // Verifico VettoreSortDodici è vuoto
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true);
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0);
        
  // provo l'assegnazione move
  VettoreSortDodici = (std::move(VettoreSort2));
        
  // essendo VettoreSortDodici precedentemente vuoto ora lo è anche VettoreSort2
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 0);
  // Controllo se sia vuoto ora VettoreSort2
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true);

  //Stampa
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, TraversePrint<string>);
        
  //Faccio lo stesso controllo di prima
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 0, string("4"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 1, string("2"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 3, string("1"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 3, string("3"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 4, string("5"));

  // Ordino diventa [1,2,3,4,5] , Stampo e Controllo
  VettoreSortDodici.Sort();
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, TraversePrint<string>);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0, string("1"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 1, string("2"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 2, string("3"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 3, string("4"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 4, string("5"));

  //Test la resize 
  VettoreSortDodici.Resize(2);
  //e controllo se sforo
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 2, string("1"));
  //Vedo la dimensione
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 2);
  // controllo se sia [1,
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0, string("1"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 1, string("2"));
       
  lasd::SortableVector<string> VettoreSortCopy(VettoreSortDodici);

  //Verifica se nono siano vuoti
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, false);

  lasd::SortableVector<string> VettoreSortMove(std::move(VettoreSortDodici));
        
  //Verifico che VettoreSortDodici sia vuoto ma VettoreSortMove no
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false);

  //Controllo che siano uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreSortCopy, true);
        
  lasd::SortableVector<string> VettoreSort3;
        
  //Controllo che VettoreSort3 sia uguale VettoreSortDodici e quindi siano vuote
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, VettoreSort3, true);
  Size(numeroLocaleTest,numeroLocaleErrori,VettoreSort3,true,0);
  Empty(numeroLocaleTest,numeroLocaleErrori,VettoreSort3,true);

  //Provo la Resize a 1 e verifico [1]
  VettoreSortCopy.Resize(1);
  Size(numeroLocaleTest,numeroLocaleErrori,VettoreSortCopy,true,1);
  Empty(numeroLocaleTest,numeroLocaleErrori,VettoreSortCopy,false);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,0,string("1"));
        
  //Quindi Ora non sono più uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, false);
        
  // Aggiungo un elemento e lo faccio diventare [1,2]
  VettoreSortCopy.Resize(2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 1, string("2"));
        
  //Stampo e Verifico Se siano uguali
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, TraversePrint<string>);
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, true, TraversePrint<string>);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, true);
        
  //Faccio diventare di 10 e diventa [12,6,2003,4,7,1971,1,8,1933,11,7,1938]
  VettoreSortCopy.Resize(12);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 0, string("12"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 1, string("6"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 2, string("2003"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 3, string("4"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 4, string("7"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 5, string("1971"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 6, string("1"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 7, string("8"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 8, string("1933"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 9, string("11"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 10, string("7"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 11, string("1938"));
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, TraversePrint<string>);
        
  //Faccio la reduce sommando tutti gli elementi
  Fold(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, FoldAdd<string>, string(""), string("12620034719711819331171938"));
  
  //Tramite una funzione lambda moltiplico per dieci tutto e stampo
  auto lambdaFunctionPerDieci = [](string &dato) 
    {
      dato+= string("10"); 
    };
  Map(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, lambdaFunctionPerDieci);
        

  //Rifaccio la reduce sommando tutti gli elementi
  Fold(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, FoldAdd<string>, string(""), string("12106102003104107101971101108101933101110710193810"));
  
  unsigned long int count = 0;
  auto lambdaFunctionAddPari = [&count](string &i) { 
    i += (count++%2); 
  };
        
  Map(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, lambdaFunctionAddPari);

  Traverse(numeroLocaleTest, numeroLocaleErrori,VettoreSortCopy,true,TraversePrint<string>);
     
  /*** Testo con le Liste ***/ 
        
  // Creo una lista 120 -> 61 -> 20030 -> 41 -> 70 -> 19711 -> 10 -> 81 -> 19330 -> 111 -> 70 -> 19381
  lasd::List<string> lista(VettoreSortCopy);
  // Creo la copia in un vettore
  lasd::SortableVector<string> VettoreCopiatoDaLista(lista);

  //Verifico che siano due linear conteiner uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreCopiatoDaLista, true);

  //Provo Il = copy
  VettoreSort = VettoreSortMove; //[1,2]

  //Provo il costruttore move
  lasd::SortableVector<string> VettoreSortListaMove(std::move(lista));
  // VettoreSortListaMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
  // lista = 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0

  //Verifico se siano uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, VettoreSortListaMove, true);
        
  //Provo il = move
  VettoreSortMove = std::move(VettoreCopiatoDaLista);
  // VettoreSortMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
  // VettoreCopiatoDaLista = [1,2]
        

  /* Verifico le uguaglianze , considerando : 
      VettoreSortCopy = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSortMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSortListaMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSort = [1,2]
      VettoreCopiatoDaLista = [1,2]
  */
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortListaMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreSortListaMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreCopiatoDaLista, true);
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreCopiatoDaLista, false);
           
  // Verifico Empty
  Empty(numeroLocaleTest, numeroLocaleErrori, lista, false);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false);

  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, TraversePrint<string>);
        
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false, string("12"));
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, string("1"));

  count = 0;

  // Provo la clear e la verifico
  VettoreSortMove.Clear(); //[]
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, true, 0);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreCopiatoDaLista, false);
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreCopiatoDaLista, true);
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, string("1"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 0, string("0"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 0, string("0"));
        
  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, string("1"));
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, string("2"));
  SetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, string("3"));
  SetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, string("5"));
  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false, string("1"));
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false, string("2"));

  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, string("1"));
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, string("2"));
        
  cout<<"Fine Vettore<string> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testVettoreIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio Vettore<int> Test DG :" << endl;
        
  lasd::SortableVector<int> VettoreSort; 
        
  // Controllo Che sia vuoto il vettore 
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort , true);

  lasd::SortableVector<int> VettoreSortDodici(12); 
  
  // Verifica Se ha fatto bene la copia e quindi che non sia più vuota
  VettoreSort = VettoreSortDodici;
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreSortDodici, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false);
    


  lasd::SortableVector<int> VettoreSort2; 

  // testo nuovamente la copia con un vettore vuoto con uno già con size
  VettoreSortDodici = VettoreSort2;
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0); // verifico le dimensioni
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, VettoreSort2, true); // la loro uguaglianza
        
  //Verifico la vecchia uguaglianza
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreSortDodici, false);
        
  // Provo a mettere in un vettore vuoto
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 0, 0);
        
  // Testo la Resize e la verifico
  VettoreSort2.Resize(5);
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 5);
        
  // Metto in VettoreSort2 [5,4,3,2,1]
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 0, 5);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 1, 4);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 2, 3);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 3, 2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 4, 1);
        
  //Stampo tutti
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, TraversePrint<int>);

  //controllo valori random
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 0, 4);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 1, 2);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 3, 1);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 3, 3);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 4, 5);
        
  // Testo l'uscire fuori ai bordi
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, false, 5, 1);

  // Verifico VettoreSortDodici è vuoto
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true);
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0);
        
  // provo l'assegnazione move
  VettoreSortDodici = (std::move(VettoreSort2));
        
  // essendo VettoreSortDodici precedentemente vuoto ora lo è anche VettoreSort2
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true, 0);
  // Controllo se sia vuoto ora VettoreSort2
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSort2, true);

  //Stampa
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, TraversePrint<int>);
        
  //Faccio lo stesso controllo di prima
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 0, 4);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 1, 2);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 3, 1);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 3, 3);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 4, 5);

  // Ordino diventa [1,2,3,4,5] , Stampo e Controllo
  VettoreSortDodici.Sort();
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, TraversePrint<int>);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0, 1);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 1, 2);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 2, 3);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 3, 4);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 4, 5);

  //Test la resize 
  VettoreSortDodici.Resize(2);
  //e controllo se sforo
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false, 2, 1);
  //Vedo la dimensione
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 2);
  // controllo se sia [1,
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 0, 1);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true, 1, 2);
  
  lasd::SortableVector<int> VettoreSortCopy(VettoreSortDodici);

  //Verifica se nono siano vuoti
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, false);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, false);

  lasd::SortableVector<int> VettoreSortMove(std::move(VettoreSortDodici));
  
  //Verifico che VettoreSortDodici sia vuoto ma VettoreSortMove no
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false);

  //Controllo che siano uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreSortCopy, true);
        
  lasd::SortableVector<int> VettoreSort3;
        
  //Controllo che VettoreSort3 sia uguale VettoreSortDodici e quindi siano vuote
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortDodici, VettoreSort3, true);
  Size(numeroLocaleTest,numeroLocaleErrori,VettoreSort3,true,0);
  Empty(numeroLocaleTest,numeroLocaleErrori,VettoreSort3,true);

  //Provo la Resize a 1 e verifico [1]
  VettoreSortCopy.Resize(1);
  Size(numeroLocaleTest,numeroLocaleErrori,VettoreSortCopy,true,1);
  Empty(numeroLocaleTest,numeroLocaleErrori,VettoreSortCopy,false);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,0,1);
        
  //Quindi Ora non sono più uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, false);
  
  // Aggiungo un elemento e lo faccio diventare [1,2]
  VettoreSortCopy.Resize(2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 1, 2);

  //Stampo e Verifico Se siano uguali
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, TraversePrint<int>);
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, true, TraversePrint<int>);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, true);
  
  //Faccio diventare di 10 e diventa [12,6,2003,4,7,1971,1,8,1933,11,7,1938]
  VettoreSortCopy.Resize(12);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 0, 12);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 1, 6);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 2, 2003);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 3, 4);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 4, 7);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 5, 1971);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 6, 1);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 7, 8);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 8, 1933);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 9, 11);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 10, 7);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, 11, 1938);
  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, TraversePrint<int>);
  
  //Faccio la reduce sommando tutti gli elementi
  Fold(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, FoldAdd<int>, 0, 7901);
        
  //Tramite una funzione lambda moltiplico per dieci tutto e stampo
  auto lambdaFunctionPerDieci = [](int &dato) 
    {
      dato*=10; 
    };
  Map(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, lambdaFunctionPerDieci);
  //Diventando [120,60,20030,40,70,19710,10,80,19330,110,70,19380]

  //Rifaccio la reduce sommando tutti gli elementi
  Fold(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, FoldAdd<int>, 0, 79010);
        
  unsigned long int count = 0;
  auto lambdaFunctionAddPari = [&count](int &i) { 
    i += (count++%2); 
  };
  
  Map(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, true, lambdaFunctionAddPari);

  // Verifico [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,0,120);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,1,61);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,2,20030);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,3,41);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,4,70);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,5,19711);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,6,10);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,7,81);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,8,19330);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,9,111);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,10,70);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy,true,11,19381);
     
  /*** Testo con le Liste ***/ 
      
  // Creo una lista 120 -> 61 -> 20030 -> 41 -> 70 -> 19711 -> 10 -> 81 -> 19330 -> 111 -> 70 -> 19381
  lasd::List<int> lista(VettoreSortCopy);
  // Creo la copia in un vettore
  lasd::SortableVector<int> VettoreCopiatoDaLista(lista);

  //Verifico che siano due linear conteiner uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreCopiatoDaLista, true);

  //Provo Il = copy
  VettoreSort = VettoreSortMove; //[1,2]

  //Provo il costruttore move
  lasd::SortableVector<int> VettoreSortListaMove(std::move(lista));
  // VettoreSortListaMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
  // lista = 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0

  //Verifico se siano uguali
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, VettoreSortListaMove, true);
        
  //Provo il = move
  VettoreSortMove = std::move(VettoreCopiatoDaLista);
  // VettoreSortMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
  // VettoreCopiatoDaLista = [1,2]
        

  /* Verifico le uguaglianze , considerando : 
      VettoreSortCopy = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSortMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSortListaMove = [120,61,20030,41,70,19711,10,81,19330,111,70,19381]
      VettoreSort = [1,2]
      VettoreCopiatoDaLista = [1,2]
  */
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortCopy, VettoreSortListaMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreSortListaMove, true);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreCopiatoDaLista, true);
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSort, VettoreCopiatoDaLista, false);
               
  // Verifico Empty
  Empty(numeroLocaleTest, numeroLocaleErrori, lista, false);
  Empty(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false);

  Traverse(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, TraversePrint<int>);
    
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false, 12);
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, 1);

  count = 0;

  // Provo la clear e la verifico
  VettoreSortMove.Clear(); //[]
  Size(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, true, 0);
  EqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreCopiatoDaLista, false);
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, VettoreCopiatoDaLista, true);
  Exists(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 1);
  GetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 0, 0);
  SetAt(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 0, 0);
        
  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, 1);
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, 2);

  SetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, 3);
  SetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, true, 5);

  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false, 1);
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSort, false, 2);


  GetFront(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 1);
  GetBack(numeroLocaleTest, numeroLocaleErrori, VettoreSortMove, false, 2);
        
  cout<<"Fine Vettore<int> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
  
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testListaIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;
  cout << endl << "Inizio Lista<int> Test DG :" << endl;
  
  //Creo Una lista e verifico sia vuota
  lasd::List<int> lista;
  Empty(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  //Creo un vettore [12,6,2003]
  lasd::Vector<int> Vettore(3);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, 12);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, 6);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, 2003);
  //Sfrutto i dizionari vacendo diventare la lista 12 -> 6 -> 2003
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  // Ora non riusciro a inserire nessuno di Vettore 
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, false, Vettore);
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, lista, false, Vettore);
  //Faccio diventare il vettore [6,6,2003]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, 6);
  
  // Costruisco una altraLista 6 -> 2003
  lasd::List<int> altraLista;
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore); // Da falso poichè ci sono due 6
  //Provo la Clear
  altraLista.Clear();
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0);
  //Provo il move InsertAll divenendo altraLista = 6 -> 2003 e Vettore = [0,6,0]
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore)); 
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0, 6);
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1, 2003);
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, 0);
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, 6);
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, 0);
  //Ripulisco
  altraLista.Clear();
  //Controllo se mi lancia l'eccezione
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, false, 0, 6);
  //Faccio diventare [3,2,1]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, 3);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, 2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, 1);
  //Move insert all [3,2,1] e vettore diviene [0,0,0]
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  
  // Faccio diventare il vetore [1,2,3]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, 1);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, 2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, 3);
  //Vedo se li rimuove tutti divenendo vuota
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, true);
  //Provo a mettere alcuni con insert some move
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  /* Divenendo:
      Vettore [0,0,0]
      altraLista [1,2,3]
  */
  //Faccio Diventare Vettore [0,2,0]
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0 , 0);
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1 , 2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 2 , 0);
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, false, 3 , -1);
  // Rimuovo tutti i zero divenendo altraLista = 2 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  
  //Faccio diventare il vettore [1,2,3]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0 , 1);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1 , 2);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2 , 3); 
  
  //Pulisco altralista
  altraLista.Clear();
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  //Faccio diventare il vettore [4,5,6]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0 , 4);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1 , 5);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2 , 6); 
  
  //Vedo se non rimuove nessuno
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  
  //Vedo se vanno in contrasto
  Vettore.Resize(0);
  Vettore.Clear();
  Empty(numeroLocaleTest, numeroLocaleErrori, Vettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0);
  
  //Vedo se insert all funziona quando la struttura da copiare è vuota (sia move che copy)
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  
  //Provo la insert all con struttura da copiare è vuota (move e copy)
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
  
  //Provo la remove some con struttura da cui prendere quelli da eliminare è vuota 
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  //Provo la remove all con struttura da cui prendere quelli da eliminare è vuota 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  
  //Pulisco e riprovo con la struttura oggetto vuota
  altraLista.Clear();
  
  //Provo la insert all con le strutture vuote (move e copy)
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  //Provo la insert some con le strutture vuote (move e copy)
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
  
  //Provo la remove some con le strutture vuote 
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  //Provo la remove all con le strutture vuote 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  //Faccio diventare la altralista 5 -> 4 -> 3 -> 2 -> 1   
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1);
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 2);
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 3);
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 4);
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 5);
  
  //Provo il =copy facendo diventare lista 5 -> 4 -> 3 -> 2 -> 1
  lista = altraLista;

  Size(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 5);
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, false);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Vedo se facendo diventare lista 5 -> 4 -> 3 -> 2 -> 1 -> 0 
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  //Ora sono diverse
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 6);

  //lista 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 4);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);

  //lista 4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);

  //lista 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 9);

  //lista 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 8);
  
  //lista 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1  
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 7);
  
  //lista 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 6);

  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  
  //lista 5 -> 4 -> 3 -> 2 -> 1 
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Faccio diventae la lista vuota
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 4);
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
  //Provo a sforare
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, false, 1);

  //Rifaccio diventare lista 5 -> 4 -> 3 -> 2 -> 1 e ovviamente ora uguale a altraLista
  lista = altraLista;
  NonEqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
   
  //Faccio diventare lista 5 -> 4 -> 3 -> 2 -> 1 -> 1 -> 2 -> 0 -> 6 -> 2 -> 0 -> 0 -> 3 -> 78 -> 65 -> 73
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 6);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, int('N'));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, int('A'));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, int('I'));

  NonEqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Provo nuovamente
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  altraLista = lista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);


  /* Faccio diventare :
        Vettore [100,...,199]
        lista 100 -> ... -> 199]
  */
  Vettore.Resize(100);
  int centoCount = 100;
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);

  //Provo il costruttore Traverse
  lasd::List<int> listaVettore(Vettore);
  //Provo il costruttore copy List
  lasd::List<int> listaLista(lista);
  //Vedo se sono uguali
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaVettore, listaLista, true);
  
  // faccio diventare listaVettore e listaLista uguale 1
  listaVettore.Clear();
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, listaVettore, true, 1 );
  listaLista = listaVettore;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaVettore, listaLista, true);
  
  //Provo a farlo con liste vuote
  lista.Clear();
  altraLista.Clear();
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  
  //Faccio diventare lista e altraLista uguale a 1
  lista.InsertAtFront(1);
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  altraLista.InsertAtFront(1);
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  

  
  
  //Faccio diventare lista 1 -> [100,...,199]
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  //Faccio diventare Vettore [100,...,149]
  Vettore.Resize(50);
  //Faccio diventare altraLista 1 -> [100,...,149]
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  //Faccio diventare Vettore [100,...,134]
  Vettore.Resize(35);

  //Faccio diventare listaVettore 100 -> ... -> 134
  listaVettore.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, listaVettore, true, Vettore);
  //Faccio diventare altraLista 1 -> [100,...,199]
  altraLista = lista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  //Faccio diventare lista 100 -> ... -> 134
  lista = listaVettore;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, listaVettore, true);

  //Faccio diventare Vettore [0,...,99]
  centoCount = 0;
  Vettore.Resize(100);
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  
  //Faccio diventare listaLista 0 -> ... -> 99
  listaLista.Clear();
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, listaLista, true, Vettore);

  //Provo il costruttore Map facendo listaMap = 0 -> ... -> 99
  lasd::List<int> listaMap(std::move(Vettore));
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaLista, listaMap, true);
  Size(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 100);
  Size(numeroLocaleTest, numeroLocaleErrori, listaMap, true, 100);

  //Faccio diventare di nuovo Vettore [0,...,99]
  centoCount = 0;
  Vettore.Resize(100);
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;

  //Faccio diventare lista 0 -> ... -> 99
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  //Faccio diventare altraLista 0 -> ... -> 99
  altraLista = lista;
  
  //Facciodiventare listaVettore = 0 -> ... -> 99 e lista = null
  listaVettore.Clear();
  listaVettore = std::move(lista);
  EqualList(numeroLocaleTest, numeroLocaleErrori, altraLista, listaVettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);

  //Creo listaNuova vuota
  lasd::List<int> listaNuova;
  //Creo listaCopy vuota
  lasd::List<int> listaCopy(listaNuova);
  
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);
  Size(numeroLocaleTest, numeroLocaleErrori, listaNuova, true, 0);
  
  //Provo Il copy= con liste vuote
  listaNuova = listaCopy;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);
  //Provo Il move= con liste vuote
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);

  //Faccio diventare listaNuova = 0 -> ... -> 99
  listaNuova.InsertAll(Vettore);
  //Faccio diventare listaCopy = 0 -> ... -> 99
  listaCopy = listaNuova;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 100);

  //Faccio diventare listaNuova = 0 -> ... -> 99 e listaCopy = 0 -> ... -> 99
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 100);

  //Faccio diventare listaNuova = 0 -> ... -> 99 e listaCopy = null
  listaNuova.Clear();
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, false);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);  

  //Faccio diventare listaNuova 0 -> ... -> 99
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, listaNuova, false, Vettore);

  //Creo listaCostruttoreMoveL = 0 -> ... -> 99 e listaNuova = null
  lasd::List<int> listaCostruttoreMoveL(std::move(listaNuova));
  //Creo listaCostruttoreMoveV = 0 -> ... -> 99 e Vettore = [0, ... ,0]
  lasd::List<int> listaCostruttoreMoveV(std::move(Vettore));
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaCostruttoreMoveL, listaCostruttoreMoveV, true);

  //Faccio diventare Vettore = [0,...,9]
  Vettore.Clear();
  Vettore.Resize(10);
  centoCount = 0;
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  //Faccio diventare lista = 0 -> ... -> 9
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);

  //Faccio diventare Vettore [] e lo uso come maschera
  Vettore.Resize(2);
  Vettore[0] = 4;
  Vettore[1] = 8;
  //Faccio Diventare la lista = 0 -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 9
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  //Faccio diventare lista = 0 -> 1 -> 2 -> 3 -> 4
  lista.Clear();
  for (unsigned long int i = 0; i < 5; i++)
    lista.InsertAtBack(i);

  //Provo la insert Move passando senza &&
  InsertM(numeroLocaleTest, numeroLocaleErrori, lista, false, 0);
  //Faccio diventare la lista = 1 -> 2 -> 3 -> 4
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  //Faccio diventare la lista = 2 -> 3 -> 4
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
  //Faccio diventare la lista = 2 -> 3
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, lista.Back()); 
  //Faccio diventare la lista = 3
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  //Faccio diventare la lista = null
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);

  //Faccio diventare  Vettore = [0,...,9]
  Vettore.Clear();
  Vettore.Resize(10);
  centoCount = 0;
  for (unsigned long int i = 0; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  
  //Creo una lista 0 -> ... -> 9
  lasd::List<int> ultimaLista(Vettore);

  //Creo un vettore ultimoVettore = [0,...,9] e Vettore = [0,...,0]
  lasd::SortableVector<int> ultimoVettore;
  ultimoVettore = std::move(Vettore);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, true);

  //Faccio diventare Vettore [9]
  Vettore.Resize(1);
  Vettore[0] = 9;

  //Faccio diventare ultimaLista = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
  ultimaLista.RemoveAll(Vettore);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, false);
  ultimoVettore.Resize(ultimoVettore.Size() - 1);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, true);

  cout<<"Fine Lista<int> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;

}

void testListaStringMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;
  cout << endl << "Inizio Lista<string> Test DG :" << endl;
  
  //Creo Una lista e verifico sia vuota
  lasd::List<string> lista;
  Empty(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
  //Creo un vettore [12,6,2003]
  lasd::Vector<string> Vettore(3);
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, string("12"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, string("6"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, string("2003"));
  //Sfrutto i dizionari vacendo diventare la lista 12 -> 6 -> 2003
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  // Ora non riusciro a inserire nessuno di Vettore 
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, false, Vettore);
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, lista, false, Vettore);
  //Faccio diventare il vettore [6,6,2003]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, string("6"));
  
  // Costruisco una altraLista 6 -> 2003
  lasd::List<string> altraLista;
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore); // Da falso poichè ci sono due 6
  //Provo la Clear
  altraLista.Clear();
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0);
  //Provo il move InsertAll divenendo altraLista = 6 -> 2003 e Vettore = [0,6,0]
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore)); 
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0, string("6"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1, string("2003"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, string(""));
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, string("6"));
  GetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, string(""));
  //Ripulisco
  altraLista.Clear();
  //Controllo se mi lancia l'eccezione
  GetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, false, 0, string("6"));
  //Faccio diventare [3,2,1]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, string("3"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, string("2"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, string("1"));
  //Move insert all [3,2,1] e vettore diviene [0,0,0]
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  
  // Faccio diventare il vetore [1,2,3]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0, string("1"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1, string("2"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2, string("3"));
  //Vedo se li rimuove tutti divenendo vuota
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, true);
  //Provo a mettere alcuni con insert some move
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  /* Divenendo:
      Vettore [0,0,0]
      altraLista [1,2,3]
  */
  //Faccio Diventare Vettore [0,2,0]
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 0 , string("0"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1 , string("2"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 2 , string("0"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, altraLista, false, 3 , string("-1"));
  // Rimuovo tutti i zero divenendo altraLista = 2 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  
  //Faccio diventare il vettore [1,2,3]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0 , string("1"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1 , string("2"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2 , string("3")); 
  
  //Pulisco altralista
  altraLista.Clear();
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  //Faccio diventare il vettore [4,5,6]
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0 , string("4"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 1 , string("5"));
  SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 2 , string("6")); 
  
  //Vedo se non rimuove nessuno
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  
  //Vedo se vanno in contrasto
  Vettore.Resize(0);
  Vettore.Clear();
  Empty(numeroLocaleTest, numeroLocaleErrori, Vettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 0);
  
  //Vedo se insert all funziona quando la struttura da copiare è vuota (sia move che copy)
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  
  //Provo la insert all con struttura da copiare è vuota (move e copy)
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
  
  //Provo la remove some con struttura da cui prendere quelli da eliminare è vuota 
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  //Provo la remove all con struttura da cui prendere quelli da eliminare è vuota 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  
  //Pulisco e riprovo con la struttura oggetto vuota
  altraLista.Clear();
  
  //Provo la insert all con le strutture vuote (move e copy)
  InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  //Provo la insert some con le strutture vuote (move e copy)
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
  
  //Provo la remove some con le strutture vuote 
  RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
  //Provo la remove all con le strutture vuote 
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);

  //Faccio diventare la altralista 5 -> 4 -> 3 -> 2 -> 1   
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, string("1"));
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, string("2"));
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, string("3"));
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, string("4"));
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, string("5"));
  
  //Provo il =copy facendo diventare lista 5 -> 4 -> 3 -> 2 -> 1
  lista = altraLista;

  Size(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 5);
  Empty(numeroLocaleTest, numeroLocaleErrori, altraLista, false);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Vedo se facendo diventare lista 5 -> 4 -> 3 -> 2 -> 1 -> 0 
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  //Ora sono diverse
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 6);

  //lista 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("5"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("4"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("3"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("2"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("1"));

  //lista 4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);

  //lista 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 9);

  //lista 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 8);
  
  //lista 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1  
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("2"));
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 7);
  
  //lista 0 -> 5 -> 4 -> 3 -> 2 -> 1 
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 6);

  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  
  //lista 5 -> 4 -> 3 -> 2 -> 1 
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Faccio diventae la lista vuota
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("5"));
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("4"));
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("3"));
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("2"));
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("1"));
  //Provo a sforare
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, false, string("1"));

  //Rifaccio diventare lista 5 -> 4 -> 3 -> 2 -> 1 e ovviamente ora uguale a altraLista
  lista = altraLista;
  NonEqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
   
  //Faccio diventare lista 5 -> 4 -> 3 -> 2 -> 1 -> 1 -> 2 -> 0 -> 6 -> 2 -> 0 -> 0 -> 3 -> 78 -> 65 -> 73
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("1"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("2"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("6"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("2"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("3"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("N"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("A"));
  InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, string("I"));

  NonEqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);

  //Provo nuovamente
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  altraLista = lista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);


  /* Faccio diventare :
        Vettore [100,...,199]
        lista 100 -> ... -> 199]
  */
  Vettore.Resize(100);
  int centoCount = 100;
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);

  //Provo il costruttore Traverse
  lasd::List<string> listaVettore(Vettore);
  //Provo il costruttore copy List
  lasd::List<string> listaLista(lista);
  //Vedo se sono uguali
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaVettore, listaLista, true);
  
  // faccio diventare listaVettore e listaLista uguale 1
  listaVettore.Clear();
  InsertAtFront(numeroLocaleTest, numeroLocaleErrori, listaVettore, true, string("1") );
  listaLista = listaVettore;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaVettore, listaLista, true);
  
  //Provo a farlo con liste vuote
  lista.Clear();
  altraLista.Clear();
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  
  //Faccio diventare lista e altraLista uguale a 1
  lista.InsertAtFront(string("1"));
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  altraLista.InsertAtFront(string("1"));
  lista = altraLista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  

  
  
  //Faccio diventare lista 1 -> [100,...,199]
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  //Faccio diventare Vettore [100,...,149]
  Vettore.Resize(50);
  //Faccio diventare altraLista 1 -> [100,...,149]
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
  //Faccio diventare Vettore [100,...,134]
  Vettore.Resize(35);

  //Faccio diventare listaVettore 100 -> ... -> 134
  listaVettore.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, listaVettore, true, Vettore);
  //Faccio diventare altraLista 1 -> [100,...,199]
  altraLista = lista;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
  //Faccio diventare lista 100 -> ... -> 134
  lista = listaVettore;
  EqualList(numeroLocaleTest, numeroLocaleErrori, lista, listaVettore, true);

  //Faccio diventare Vettore [0,...,99]
  centoCount = 0;
  Vettore.Resize(100);
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  
  //Faccio diventare listaLista 0 -> ... -> 99
  listaLista.Clear();
  InsertSomeC(numeroLocaleTest, numeroLocaleErrori, listaLista, true, Vettore);

  //Provo il costruttore Map facendo listaMap = 0 -> ... -> 99
  lasd::List<string> listaMap(std::move(Vettore));
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaLista, listaMap, true);
  Size(numeroLocaleTest, numeroLocaleErrori, Vettore, true, 100);
  Size(numeroLocaleTest, numeroLocaleErrori, listaMap, true, 100);

  //Faccio diventare di nuovo Vettore [0,...,99]
  centoCount = 0;
  Vettore.Resize(100);
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;

  //Faccio diventare lista 0 -> ... -> 99
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  //Faccio diventare altraLista 0 -> ... -> 99
  altraLista = lista;
  
  //Facciodiventare listaVettore = 0 -> ... -> 99 e lista = null
  listaVettore.Clear();
  listaVettore = std::move(lista);
  EqualList(numeroLocaleTest, numeroLocaleErrori, altraLista, listaVettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);

  //Creo listaNuova vuota
  lasd::List<string> listaNuova;
  //Creo listaCopy vuota
  lasd::List<string> listaCopy(listaNuova);
  
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);
  Size(numeroLocaleTest, numeroLocaleErrori, listaNuova, true, 0);
  
  //Provo Il copy= con liste vuote
  listaNuova = listaCopy;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);
  //Provo Il move= con liste vuote
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);

  //Faccio diventare listaNuova = 0 -> ... -> 99
  listaNuova.InsertAll(Vettore);
  //Faccio diventare listaCopy = 0 -> ... -> 99
  listaCopy = listaNuova;
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 100);

  //Faccio diventare listaNuova = 0 -> ... -> 99 e listaCopy = 0 -> ... -> 99
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 100);

  //Faccio diventare listaNuova = 0 -> ... -> 99 e listaCopy = null
  listaNuova.Clear();
  listaNuova = std::move(listaCopy);
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaNuova, listaCopy, false);
  Size(numeroLocaleTest, numeroLocaleErrori, listaCopy, true, 0);  

  //Faccio diventare listaNuova 0 -> ... -> 99
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, listaNuova, false, Vettore);

  //Creo listaCostruttoreMoveL = 0 -> ... -> 99 e listaNuova = null
  lasd::List<string> listaCostruttoreMoveL(std::move(listaNuova));
  //Creo listaCostruttoreMoveV = 0 -> ... -> 99 e Vettore = [0, ... ,0]
  lasd::List<string> listaCostruttoreMoveV(std::move(Vettore));
  EqualList(numeroLocaleTest, numeroLocaleErrori, listaCostruttoreMoveL, listaCostruttoreMoveV, true);

  //Faccio diventare Vettore = [0,...,9]
  Vettore.Clear();
  Vettore.Resize(10);
  centoCount = 0;
  for (unsigned long int i{0}; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  //Faccio diventare lista = 0 -> ... -> 9
  lista.Clear();
  InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);

  //Faccio diventare Vettore [] e lo uso come maschera
  Vettore.Resize(2);
  Vettore[0] = 4;
  Vettore[1] = 8;
  //Faccio Diventare la lista = 0 -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 9
  RemoveAll(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
  
  //Faccio diventare lista = 0 -> 1 -> 2 -> 3 -> 4
  lista.Clear();
  for (unsigned long int i = 0; i < 5; i++)
    lista.InsertAtBack(to_string(i));

  //Provo la insert Move passando senza &&
  InsertM(numeroLocaleTest, numeroLocaleErrori, lista, false, string("0"));
  //Faccio diventare la lista = 1 -> 2 -> 3 -> 4
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("0"));
  //Faccio diventare la lista = 2 -> 3 -> 4
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("1"));
  //Faccio diventare la lista = 2 -> 3
  Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, lista.Back()); 
  //Faccio diventare la lista = 3
  RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
  //Faccio diventare la lista = null
  FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, string("3"));
  Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);

  //Faccio diventare  Vettore = [0,...,9]
  Vettore.Clear();
  Vettore.Resize(10);
  centoCount = 0;
  for (unsigned long int i = 0; i < Vettore.Size(); ++i)
    Vettore[i] = centoCount++;
  
  //Creo una lista 0 -> ... -> 9
  lasd::List<string> ultimaLista(Vettore);

  //Creo un vettore ultimoVettore = [0,...,9] e Vettore = [0,...,0]
  lasd::SortableVector<string> ultimoVettore;
  ultimoVettore = std::move(Vettore);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, true);

  //Faccio diventare Vettore [9]
  Vettore.Resize(1);
  Vettore[0] = 9;

  //Faccio diventare ultimaLista = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
  ultimaLista.RemoveAll(Vettore);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, false);
  ultimoVettore.Resize(ultimoVettore.Size() - 1);
  EqualLinear(numeroLocaleTest, numeroLocaleErrori, ultimaLista, ultimoVettore, true);

  cout<<"Fine Lista<string> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;

}

void testStackVecIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio StackVec<int> Test DG :" << endl;

  lasd::StackVec<int> prova{};
  prova.Resize(0);
  PushC(numeroLocaleTest, numeroLocaleErrori, prova, 12);
  TopNPop(numeroLocaleTest, numeroLocaleErrori, prova, true, 12);

  //Creo uno stack
  lasd::StackVec<int> primoStack;
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, true);

  const unsigned int grandezza = 12;

  //Creo un vettore [0, ... , 'grandezza']
  lasd::Vector<int> vettore(grandezza);
  for (unsigned int i = 0; i < grandezza; ++i)
    vettore[i] = i;

  //Creo un vettore copia
  lasd::Vector<int> vettoreCopia(vettore);
  //PCreo uno stack da un vettore
  lasd::StackVec<int> stackVettore(vettore);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, grandezza);

  //Creo Una lista
  lasd::List<int> lista(vettore);
  //Creo uno stack da una lista
  lasd::StackVec<int> stackLista(lista);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackLista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackLista, true, grandezza);

  //Vedo le uguaglianze
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, false);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackLista, false);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackLista, true);

  //Provo la Clear
  stackVettore.Clear();
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, 0);

  //Provo il costruttore move da una lista
  lasd::StackVec<int> stackListaMove(std::move(lista));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackLista, stackListaMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackListaMove, true, grandezza);

  //Provo il costruttore move da un vettore
  lasd::StackVec<int> stackVettoreMove(std::move(vettore));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackLista, stackVettoreMove, true);  
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, vettore, vettoreCopia, grandezza - 1);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackListaMove, stackVettoreMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettoreMove, true, grandezza);

  //Provo il copy=
  primoStack = stackListaMove;
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackListaMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, primoStack, true, grandezza);

  //Provo il move=
  stackVettore = std::move(stackVettoreMove);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettoreMove, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, primoStack, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackVettoreMove, false);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, grandezza);

  //Creo un altro vettore
  lasd::Vector<int> nuovoVettore(grandezza);
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, false);

  //Costruisco il vettore svotando primoStack
  for (unsigned int i = 0; i < grandezza; ++i)
    nuovoVettore[grandezza - 1 - i] = primoStack.TopNPop();
  Pop(numeroLocaleTest, numeroLocaleErrori, primoStack, false);
  TopNPop(numeroLocaleTest, numeroLocaleErrori, primoStack, false, nuovoVettore[grandezza - 1]);
  Size(numeroLocaleTest, numeroLocaleErrori, primoStack, true, 0);
    
  //Svuoto stackListaMove
  for (unsigned int i = grandezza; i != 0; --i)
    stackListaMove.Pop();
  Empty(numeroLocaleTest, numeroLocaleErrori, stackListaMove, true);

  //Pulisco
  vettore.Clear();
  lista.Clear();

  //Creo uno stack da un vettore vuoto
  lasd::StackVec<int> stackVettore2(vettore);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore2, true);
  
  //Creo uno stack da un lista vuoto
  lasd::StackVec<int> stackLista2(lista);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackLista2, true);

  //RiTesto il =copy
  stackVettore = stackVettore2;
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);
  
  //RiTesto il =move
  stackLista = std::move(stackLista2);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);


  cout << "Fine StackVec<int> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testStackVecStringMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio StackVec<int> Test DG :" << endl;

  //Creo uno stack
  lasd::StackVec<string> primoStack; 
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, true);

  lasd::Vector<string> vettore(5);
  vettore[0] = "Ciao";
  vettore[1] = ",";
  vettore[2] = "Mi";
  vettore[3] = "Chiamo";
  vettore[4] = "Domenico";
  lasd::Vector<string> vettoreCopy(vettore);

  //Provo il costruttore move
  lasd::StackVec<string> stackMove(std::move(vettore));
  Size(numeroLocaleTest, numeroLocaleErrori, stackMove, true, 5);
  
  //Inserisvo nel vettore scuotando
  unsigned long grandezza = stackMove.Size();
  for(unsigned int i = 0; i < grandezza; i++)
    vettore[i] = stackMove.TopNPop();

  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, vettore, vettoreCopy, true);
  FoldPreOrder(numeroLocaleTest, numeroLocaleErrori, vettore, true, FoldStringConcatenate, string(""), string("DomenicoChiamoMi,Ciao"));

  FoldPostOrder(numeroLocaleTest, numeroLocaleErrori, vettoreCopy, true, FoldStringConcatenate, string(""), string("DomenicoChiamoMi,Ciao"));
  
  //Provo i costruttori
  lasd::StackVec<string> stackVettore(vettoreCopy);
  lasd::StackVec<string> stackVettoreMove(std::move(vettoreCopy));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackVettoreMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, 5);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackMove, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, false);

  //Provo con la struttura vuota
  stackMove.Clear();
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackMove, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackMove, true);

  //Provo il copy=
  primoStack = stackVettoreMove;
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettoreMove, true);
  primoStack.Clear();
  
  //creo uno stack da costruttore move
  lasd::StackVec<string> stackNuovo(std::move(vettore));
  //Riprovo il =move
  stackMove = std::move(stackNuovo);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackNuovo, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackNuovo, primoStack, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackMove, stackNuovo, false);

  cout << "Fine StackVec<int> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testStackLstIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio StackLst<int> Test DG :" << endl;

  //Creo uno stack
  lasd::StackLst<int> primoStack;
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, true);

  const unsigned int grandezza = 12;

  //Creo un vettore [0, ... , 'grandezza']
  lasd::Vector<int> vettore(grandezza);
  for (unsigned int i = 0; i < grandezza; ++i)
    vettore[i] = i;

  //Creo un vettore copia
  lasd::Vector<int> vettoreCopia(vettore);
  //PCreo uno stack da un vettore
  lasd::StackLst<int> stackVettore(vettore);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, grandezza);

  //Creo Una lista
  lasd::List<int> lista(vettore);
  //Creo uno stack da una lista
  lasd::StackLst<int> stackLista(lista);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackLista, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackLista, true, grandezza);

  //Vedo le uguaglianze
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, false);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackLista, false);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackLista, true);

  //Provo la Clear
  stackVettore.Clear();
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, 0);

  //Provo il costruttore move da una lista
  lasd::StackLst<int> stackListaMove(std::move(lista));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackLista, stackListaMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackListaMove, true, grandezza);

  //Provo il costruttore move da un vettore
  lasd::StackLst<int> stackVettoreMove(std::move(vettore));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackLista, stackVettoreMove, true);  
  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, vettore, vettoreCopia, grandezza - 1);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackListaMove, stackVettoreMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettoreMove, true, grandezza);

  //Provo il copy=
  primoStack = stackListaMove;
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackListaMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, primoStack, true, grandezza);

  //Provo il move=
  stackVettore = std::move(stackVettoreMove);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettoreMove, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, primoStack, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackVettoreMove, false);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, grandezza);

  //Creo un altro vettore
  lasd::Vector<int> nuovoVettore(grandezza);
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, false);

  //Costruisco il vettore svotando primoStack
  for (unsigned int i = 0; i < grandezza; ++i)
    nuovoVettore[grandezza - 1 - i] = primoStack.TopNPop();
  Pop(numeroLocaleTest, numeroLocaleErrori, primoStack, false);
  TopNPop(numeroLocaleTest, numeroLocaleErrori, primoStack, false, nuovoVettore[grandezza - 1]);
  Size(numeroLocaleTest, numeroLocaleErrori, primoStack, true, 0);
    
  //Svuoto stackListaMove
  for (unsigned int i = grandezza; i != 0; --i)
    stackListaMove.Pop();
  Empty(numeroLocaleTest, numeroLocaleErrori, stackListaMove, true);

  //Pulisco
  vettore.Clear();
  lista.Clear();

  //Creo uno stack da un vettore vuoto
  lasd::StackLst<int> stackVettore2(vettore);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore2, true);
  
  //Creo uno stack da un lista vuoto
  lasd::StackLst<int> stackLista2(lista);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackLista2, true);

  //RiTesto il =copy
  stackVettore = stackVettore2;
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);
  
  //RiTesto il =move
  stackLista = std::move(stackLista2);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackVettore, true);


  cout << "Fine StackLst<int> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;

}

void testStackLstStringMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio StackVec<string> Test DG :" << endl;

  //Creo uno stack
  lasd::StackLst<string> primoStack; 
  Empty(numeroLocaleTest, numeroLocaleErrori, primoStack, true);

  lasd::Vector<string> vettore(5);
  vettore[0] = "Ciao";
  vettore[1] = ",";
  vettore[2] = "Mi";
  vettore[3] = "Chiamo";
  vettore[4] = "Domenico";
  lasd::Vector<string> vettoreCopy(vettore);

  //Provo il costruttore move
  lasd::StackLst<string> stackMove(std::move(vettore));
  Size(numeroLocaleTest, numeroLocaleErrori, stackMove, true, 5);
  
  //Inserisvo nel vettore scuotando
  unsigned long grandezza = stackMove.Size();
  for(unsigned int i = 0; i < grandezza; i++)
    vettore[i] = stackMove.TopNPop();

  NonEqualVector(numeroLocaleTest, numeroLocaleErrori, vettore, vettoreCopy, false);
  FoldPreOrder(numeroLocaleTest, numeroLocaleErrori, vettore, true, FoldStringConcatenate, string(""), string("Ciao,MiChiamoDomenico"));

  FoldPostOrder(numeroLocaleTest, numeroLocaleErrori, vettoreCopy, true, FoldStringConcatenate, string(""), string("DomenicoChiamoMi,Ciao"));
  
  //Provo i costruttori
  lasd::StackLst<string> stackVettore(vettoreCopy);
  lasd::StackLst<string> stackVettoreMove(std::move(vettoreCopy));
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackVettore, stackVettoreMove, true);
  Size(numeroLocaleTest, numeroLocaleErrori, stackVettore, true, 5);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackMove, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettore, false);

  //Provo con la struttura vuota
  stackMove.Clear();
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackMove, true);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackMove, true);

  //Provo il copy=
  primoStack = stackVettoreMove;
  EqualStack(numeroLocaleTest, numeroLocaleErrori, primoStack, stackVettoreMove, true);
  primoStack.Clear();
  
  //creo uno stack da costruttore move
  lasd::StackLst<string> stackNuovo(std::move(vettore));
  //Riprovo il =move
  stackMove = std::move(stackNuovo);
  Empty(numeroLocaleTest, numeroLocaleErrori, stackNuovo, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackNuovo, primoStack, true);
  EqualStack(numeroLocaleTest, numeroLocaleErrori, stackMove, stackNuovo, false);

  cout << "Fine StackVec<string> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;

}

void testQueueVecIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio QueueVec<int> Test DG :" << endl;

  lasd::QueueVec<int> prova{};
  prova.Resize(0);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, prova, 12);
  Head(numeroLocaleTest, numeroLocaleErrori, prova, true, 12);

  //Creo una Coda
  lasd::QueueVec<int> coda;
  Empty(numeroLocaleTest, numeroLocaleErrori, coda, true);
    
  //Creo altre coda
  lasd::QueueVec<int> altraCoda;
  Empty(numeroLocaleTest, numeroLocaleErrori, altraCoda, true);

  lasd::QueueVec<int> codaCopy(altraCoda);
  Empty(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);

  lasd::QueueVec<int> codaMove(std::move(altraCoda));
  Empty(numeroLocaleTest, numeroLocaleErrori, codaMove, true);

  // Faccio diventare codaCopy 4 5 6
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 1);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 2);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 3);

  // Faccio diventare coda 1 2 3
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 3);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);

  //Verifico che siano divverse
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  // Faccio diventare coda [1,...,16]
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 4);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 5);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 6);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 7);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 8);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 9);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 9);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 10);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 10);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 11);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 11);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 12);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 12);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 13);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 13);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 14);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 14);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 15);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 16);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);


  //Levo e metto 1, coda = [2,...,16,1]
  Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, true);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);
  //Dequeue e estraggo 2, coda = [3,...,16,1]
  HeadNDequeue(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  //Dequeue e estraggo 3, coda = [4,...,16,1]
  Head(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);
  // coda = [4,...,16,1,1,...,7]
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 17);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 3);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 18);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 19);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 20);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 21);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 7);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 22);

  // coda = [4,...,16,1,1,...,7,0,...29]
  for (unsigned long i = 0; i < 30; i++) {
    EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, (int)i);
    Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 22 + 1 + i);
  }

  //Rimuovo i primi 52 , dopo che diniscono provo il dequeue vuoto
  for (unsigned long i = 0; i < 60; i++) {
    bool chk = !(coda.Empty());
    Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, chk);
    if (!(i % 12)) //Però ogni multiplo di 12 lo inserisco
      EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, (int)i);
  }
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);

  cout << "Fine QueueVec<int> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testQueueVecStringMio(unsigned int & numeroTest, unsigned int &numeroErrori){

  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio QueueVec<String> Test DG :" << endl;
  //Creo una coda
  lasd::QueueVec<string> coda;
  Empty(numeroLocaleTest, numeroLocaleErrori, coda, true);
  
  //Creo un'altra coda
  lasd::QueueVec<string> altraCoda;
  Empty(numeroLocaleTest, numeroLocaleErrori, altraCoda, true);
  //Creo una coda con costruttore copy
  lasd::QueueVec<string> codaCopy(altraCoda);
  Empty(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  //Creo una coda con costruttore move
  lasd::QueueVec<string> codaMove(std::move(altraCoda));
  Empty(numeroLocaleTest, numeroLocaleErrori, codaMove, true);

  //Faccio diventare codaCopy Domenico Gagliotti 2003
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("Domenico"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("Gagliotti"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("2003"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 3);

  //Faccio diventare coda 1 2 3
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("2"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("3"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);

  //Vedo sono diversi
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  //Faccio diventare coda 1 2 3 4 5 6 7 8
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("4"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 4);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("5"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 5);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("6"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 6);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("7"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("8"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);

  //Faccio diventare coda 2 3 4 5 6 7 8
  Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, true);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  //Faccio diventare coda 1 2 3 4 5 6 7 8 1
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);
  //Faccio diventare coda 3 4 5 6 7 8
  HeadNDequeue(numeroLocaleTest, numeroLocaleErrori, coda, true, string("2"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  Head(numeroLocaleTest, numeroLocaleErrori, coda, true, string("3"));

  //Creo un vettore ["1","2","3","4","5","6","7"]
  lasd::Vector<string> Vettore(8);
  for (unsigned long i = 0; i < Vettore.Size(); ++i)
    SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, i, to_string(i + 1));
  
  //Costrusco una coda da un vettore in copy
  lasd::QueueVec<string> codaVettoreCopy(Vettore);
  //Costrusco una coda da un vettore in move
  lasd::QueueVec<string> codaVettoreMove(std::move(Vettore));
  Empty(numeroLocaleTest, numeroLocaleErrori, Vettore, false);
  
  Size(numeroLocaleTest, numeroLocaleErrori, codaVettoreCopy, true, 8);
  Size(numeroLocaleTest, numeroLocaleErrori, codaVettoreMove, true, 8);
  
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaVettoreCopy, false);
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, codaVettoreCopy, codaVettoreMove, true);

  // codaCopy = ["1","2","3","4","5","6","7","3","4","5","6","7","8","1"]
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("3"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 4);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("4"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 5);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("5"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 6);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("6"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 7);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("7"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 8);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("8"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 9);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 10);  
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  // Rimuovo i primi 3
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 9); 
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 8); 
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 7); 

  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, true);

  //Aggiungo altri 30 elementi
  for (unsigned long i = 0; i < 30; i++){
    EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, to_string(i));
    Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7 + i + 1); 
  }
    
  //Rimuovo i primi 52 , dopo che diniscono provo il dequeue vuoto
  for (unsigned long i = 0; i < 60; i++) {
    bool chk = !(coda.Empty());
    Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, chk);
    if (!(i % 12)) //Però ogni multiplo di 12 lo inserisco
      EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, to_string(i));
  }


  cout << "Fine QueueVec<String> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testQueueLstIntMio(unsigned int & numeroTest, unsigned int &numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio QueueLst<int> Test DG :" << endl;

  //Creo una Coda
  lasd::QueueLst<int> coda;
  Empty(numeroLocaleTest, numeroLocaleErrori, coda, true);
    
  //Creo altre coda
  lasd::QueueLst<int> altraCoda;
  Empty(numeroLocaleTest, numeroLocaleErrori, altraCoda, true);

  lasd::QueueLst<int> codaCopy(altraCoda);
  Empty(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);

  lasd::QueueLst<int> codaMove(std::move(altraCoda));
  Empty(numeroLocaleTest, numeroLocaleErrori, codaMove, true);

  // Faccio diventare codaCopy 4 5 6
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 1);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 2);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, codaCopy, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 3);

  // Faccio diventare coda 1 2 3
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 3);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);

  //Verifico che siano divverse
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  // Faccio diventare coda [1,...,16]
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 4);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 5);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 6);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 7);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 8);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 9);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 9);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 10);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 10);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 11);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 11);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 12);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 12);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 13);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 13);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 14);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 14);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 15);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  EnqueueM(numeroLocaleTest, numeroLocaleErrori, coda, 16);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);


  //Levo e metto 1, coda = [2,...,16,1]
  Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, true);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);
  //Dequeue e estraggo 2, coda = [3,...,16,1]
  HeadNDequeue(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 15);
  //Dequeue e estraggo 3, coda = [4,...,16,1]
  Head(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);
  // coda = [4,...,16,1,1,...,7]
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 16);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 2);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 17);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 3);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 18);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 4);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 19);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 5);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 20);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 6);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 21);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 7);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 22);

  // coda = [4,...,16,1,1,...,7,0,...29]
  for (unsigned long i = 0; i < 30; i++) {
    EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, (int)i);
    Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 22 + 1 + i);
  }

  //Rimuovo i primi 52 , dopo che diniscono provo il dequeue vuoto
  for (unsigned long i = 0; i < 60; i++) {
    bool chk = !(coda.Empty());
    Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, chk);
    if (!(i % 12)) //Però ogni multiplo di 12 lo inserisco
      EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, (int)i);
  }
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, 1);

  cout << "Fine QueueLst<int> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testQueueLstStringMio(unsigned int &numeroTest, unsigned int &numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  cout << endl << "Inizio QueueLst<String> Test DG :" << endl;
  //Creo una coda
  lasd::QueueLst<string> coda;
  Empty(numeroLocaleTest, numeroLocaleErrori, coda, true);
  
  //Creo un'altra coda
  lasd::QueueLst<string> altraCoda;
  Empty(numeroLocaleTest, numeroLocaleErrori, altraCoda, true);
  //Creo una coda con costruttore copy
  lasd::QueueLst<string> codaCopy(altraCoda);
  Empty(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  //Creo una coda con costruttore move
  lasd::QueueLst<string> codaMove(std::move(altraCoda));
  Empty(numeroLocaleTest, numeroLocaleErrori, codaMove, true);

  //Faccio diventare codaCopy Domenico Gagliotti 2003
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("Domenico"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("Gagliotti"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("2003"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 3);

  //Faccio diventare coda 1 2 3
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 1);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("2"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 2);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("3"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 3);

  //Vedo sono diversi
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  //Faccio diventare coda 1 2 3 4 5 6 7 8
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("4"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 4);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("5"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 5);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("6"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 6);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("7"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("8"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);

  //Faccio diventare coda 2 3 4 5 6 7 8
  Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, true);
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  //Faccio diventare coda 1 2 3 4 5 6 7 8 1
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 8);
  //Faccio diventare coda 3 4 5 6 7 8
  HeadNDequeue(numeroLocaleTest, numeroLocaleErrori, coda, true, string("2"));
  Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7);
  Head(numeroLocaleTest, numeroLocaleErrori, coda, true, string("3"));

  //Creo un vettore ["1","2","3","4","5","6","7"]
  lasd::Vector<string> Vettore(8);
  for (unsigned long i = 0; i < Vettore.Size(); ++i)
    SetAt(numeroLocaleTest, numeroLocaleErrori, Vettore, true, i, to_string(i + 1));
  
  //Costrusco una coda da un vettore in copy
  lasd::QueueLst<string> codaVettoreCopy(Vettore);
  //Costrusco una coda da un vettore in move
  lasd::QueueLst<string> codaVettoreMove(std::move(Vettore));
  Empty(numeroLocaleTest, numeroLocaleErrori, Vettore, false);
  
  Size(numeroLocaleTest, numeroLocaleErrori, codaVettoreCopy, true, 8);
  Size(numeroLocaleTest, numeroLocaleErrori, codaVettoreMove, true, 8);
  
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaVettoreCopy, false);
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, codaVettoreCopy, codaVettoreMove, true);

  // codaCopy = ["1","2","3","4","5","6","7","3","4","5","6","7","8","1"]
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("3"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 4);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("4"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 5);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("5"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 6);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("6"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 7);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("7"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 8);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("8"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 9);
  EnqueueC(numeroLocaleTest, numeroLocaleErrori, codaCopy, string("1"));
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 10);  
  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, false);

  // Rimuovo i primi 3
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 9); 
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 8); 
  Dequeue(numeroLocaleTest, numeroLocaleErrori, codaCopy, true);
  Size(numeroLocaleTest, numeroLocaleErrori, codaCopy, true, 7); 

  EqualQueue(numeroLocaleTest, numeroLocaleErrori, coda, codaCopy, true);

  //Aggiungo altri 30 elementi
  for (unsigned long i = 0; i < 30; i++){
    EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, to_string(i));
    Size(numeroLocaleTest, numeroLocaleErrori, coda, true, 7 + i + 1); 
  }
    
  //Rimuovo i primi 52 , dopo che diniscono provo il dequeue vuoto
  for (unsigned long i = 0; i < 60; i++) {
    bool chk = !(coda.Empty());
    Dequeue(numeroLocaleTest, numeroLocaleErrori, coda, chk);
    if (!(i % 12)) //Però ogni multiplo di 12 lo inserisco
      EnqueueC(numeroLocaleTest, numeroLocaleErrori, coda, to_string(i));
  }


  cout << "Fine QueueLst<String> Test DG : (Errors/Tests: " << numeroLocaleErrori << "/" << numeroLocaleTest << ")" << endl;
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

void testAlberoIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  unsigned int albTest = 0;
  unsigned int albErr = 0;

  cout << endl << "Inizio Albero<Int> Test DG :" << endl;
  
  cout << endl << "Inizio Albero(Vettore)<Int> Test DG :" << endl;
  testAlberoGenericoIntMio<lasd::BinaryTreeVec<int>>(albTest,albErr);
  cout<<"Fine Albero(Vettore)<Int> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout << endl << "Inizio Albero(Lista)<Int> Test DG :" << endl;
  testAlberoGenericoIntMio<lasd::BinaryTreeLnk<int>>(albTest,albErr);
  cout<<"Fine Albero(Lista)<Int> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout << endl << "Inizio Albero(Ambedue)<Int> Test DG :" << endl;
  testAmbedueAlberoIntMio(albTest,albErr);
  cout<<"Fine Albero(Ambedue)<Int> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout<<"Fine Albero<Int> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

template <typename Albero>
void testAlberoGenericoIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  lasd::List<int> lista{};
  for(int i = 1; i <= 7 ; i++)
    lista.InsertAtBack(i);

  //Provo Il Traverse Costruttore
  Albero alberoOrdinato{lista};
  Empty(numeroTest,numeroErrori,alberoOrdinato,false);
  Size(numeroTest,numeroErrori,alberoOrdinato,true,7);

  //Controllo se sia Breath>> 1 2 3 4 5 6 7
  Root(numeroTest,numeroErrori,alberoOrdinato,true,1);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root(),true);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true,2);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true,3);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),true,4);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),false);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),true,5);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),false);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),true,6);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),false);
  GetElement(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),true,7);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),false);

  IsLeaf<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),true);


  lista.Clear();
  for(int i = 1; i <= 7 ; i++)
    lista.InsertAtFront(i);
  
  //Provo Il Map Costruttore
  Albero alberoDeOrdinato{std::move(lista)};
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Size(numeroTest,numeroErrori,alberoDeOrdinato,true,7);

  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),false); 
  HasLeftChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),false);
  Root(numeroTest,numeroErrori,alberoDeOrdinato,true,7);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true,6);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true,5);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),true,4);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),true,3);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),true,2);
  GetElement(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),true,1);


  IsLeaf<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),true);

  //Provo la Copia di Alberi
  Albero alberoCopia{alberoDeOrdinato};
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Size(numeroTest,numeroErrori,alberoCopia,true,7);

  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false); 
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);

  Root(numeroTest,numeroErrori,alberoCopia,true,7);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,6);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,5);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,3);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,2);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,1);


  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);
  

  //Provo Le uguaglianze
  NonEqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoDeOrdinato);
  NonEqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoCopia);
  EqualBT(numeroTest,numeroErrori,alberoDeOrdinato,alberoCopia);


  //Faccio diventare alberoCopia Breath>> 1 2 3 4 5 6 7
  SetElement(numeroTest,numeroErrori,alberoCopia.Root(),true,1);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,2);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,3);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,5);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,6);
  SetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,7);

  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  NonEqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoDeOrdinato);
  EqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoCopia);
  NonEqualBT(numeroTest,numeroErrori,alberoDeOrdinato,alberoCopia);

  //Provo la move
  Albero alberoMove{std::move(alberoCopia)};
  Empty(numeroTest,numeroErrori,alberoCopia,true);
  Empty(numeroTest,numeroErrori,alberoMove,false);
  Size(numeroTest,numeroErrori,alberoMove,true,7);
  Size(numeroTest,numeroErrori,alberoCopia,true,0);

  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false); 
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  Root(numeroTest,numeroErrori,alberoMove,true,1);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true,2);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true,3);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true,4);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true,5);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true,6);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true,7);

  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true);
  
  //Provo Le uguaglianze
  NonEqualBT(numeroTest,numeroErrori,alberoMove,alberoDeOrdinato);
  NonEqualBT(numeroTest,numeroErrori,alberoMove,alberoCopia);
  EqualBT(numeroTest,numeroErrori,alberoMove,alberoOrdinato);

  //Provo la clear su un albero già pulito
  alberoCopia.Clear();
  
  //Provo = copy
  alberoCopia = alberoDeOrdinato;
  Empty(numeroTest,numeroErrori,alberoCopia,false);
  Size(numeroTest,numeroErrori,alberoCopia,true,7);
  
  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false); 
  HasLeftChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  Root(numeroTest,numeroErrori,alberoCopia,true,7);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,6);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,5);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,3);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,2);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,1);


  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  EqualBT(numeroTest,numeroErrori,alberoCopia,alberoDeOrdinato);
  NonEqualBT(numeroTest,numeroErrori,alberoMove,alberoCopia);
  NonEqualBT(numeroTest,numeroErrori,alberoCopia,alberoOrdinato);
  
  //Provo = move
  alberoMove.Clear();
  alberoMove = std::move(alberoCopia);
  Empty(numeroTest,numeroErrori,alberoMove,false);
  Empty(numeroTest,numeroErrori,alberoCopia,true);
  Size(numeroTest,numeroErrori,alberoMove,true,7);
  
  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false); 
  HasLeftChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  HasRightChild<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  Root(numeroTest,numeroErrori,alberoMove,true,7);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true,6);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true,5);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true,4);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true,3);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true,2);
  GetElement(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true,1);


  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true);
  IsLeaf<int>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  EqualBT(numeroTest,numeroErrori,alberoMove,alberoDeOrdinato);
  NonEqualBT(numeroTest,numeroErrori,alberoMove,alberoCopia);
  NonEqualBT(numeroTest,numeroErrori,alberoMove,alberoOrdinato);


  // Moltiptico Per 32 Tutti i numeri
  alberoCopia = alberoOrdinato;
  Map(numeroTest, numeroErrori, alberoCopia, true, MapDouble<int>);
  MapBreadth(numeroTest, numeroErrori, alberoCopia, true, MapDouble<int>);
  MapPreOrder(numeroTest, numeroErrori, alberoCopia, true, MapDouble<int>);
  MapPostOrder(numeroTest, numeroErrori, alberoCopia, true, MapDouble<int>);
  MapInOrder(numeroTest, numeroErrori, alberoCopia, true, MapDouble<int>);

  Root(numeroTest,numeroErrori,alberoCopia,true,32);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,64);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,96);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,128);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,160);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,192);
  GetElement(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,224);

  alberoCopia = alberoDeOrdinato;

    int inc = 0;
    // 0*7 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1 = 56
    FoldBreadth(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 56);
    
    // 0*7 + 1*6 + 2*4 + 3*3 + 4*5 + 5*2 + 6*1 = 59 
    inc = 0;
    FoldPreOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 59);

    // 0*4 + 1*3 + 2*6 + 3*2 + 4*1 + 5*5 + 6*7 = 92 
    inc = 0;
    FoldPostOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
          }, 
          0, 92);
    
    // 0*4 + 1*6 + 2*3 + 3*7 + 4*2 + 5*5 + 6*1 = 72
    inc = 0;
    FoldInOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 72);
}

void testAmbedueAlberoIntMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  lasd::List<int> lista{};
  for(int i = 1; i <= 7 ; i++)
    lista.InsertAtBack(i);

  //Creo Albero
  lasd::BinaryTreeLnk<int> AlberoLista{lista};
  lasd::BinaryTreeVec<int> AlberoVettore{lista};

  //Controllo Uguaglianza
  EqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Modifico e controllo che siano diverse
  SetElement<int>(numeroTest, numeroErrori, AlberoLista.Root(), true, 12);
  NonEqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Provo il = Copy
  AlberoVettore = AlberoLista;
  AlberoLista = AlberoVettore;

  Root<int>(numeroTest,numeroErrori,AlberoLista,true,12);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild(),true,2);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().RightChild(),true,3);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild().LeftChild(),true,4);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild().RightChild(),true,5);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().RightChild().LeftChild(),true,6);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista.Root().RightChild().RightChild(),true,7);

  Root<int>(numeroTest,numeroErrori,AlberoVettore,true,12);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild(),true,2);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild(),true,3);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild().LeftChild(),true,4);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild().RightChild(),true,5);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild().LeftChild(),true,6);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild().RightChild(),true,7);

  EqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Provo i costruttori
  lasd::BinaryTreeLnk<int> AlberoLista2{AlberoVettore};
  lasd::BinaryTreeVec<int> AlberoVettore2{AlberoLista};

  Root<int>(numeroTest,numeroErrori,AlberoLista2,true,12);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild(),true,2);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild(),true,3);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild().LeftChild(),true,4);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild().RightChild(),true,5);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild().LeftChild(),true,6);
  GetElement<int>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild().RightChild(),true,7);

  Root<int>(numeroTest,numeroErrori,AlberoVettore2,true,12);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild(),true,2);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild(),true,3);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild().LeftChild(),true,4);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild().RightChild(),true,5);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild().LeftChild(),true,6);
  GetElement<int>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild().RightChild(),true,7);

  EqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore2);

  //Provo Cotruttore copi e move
  lasd::BinaryTreeLnk<int> AlberoLista3{AlberoLista2};
  lasd::BinaryTreeVec<int> AlberoVettore4{std::move(AlberoLista3)};

  AlberoVettore.Clear();
  Empty(numeroTest, numeroErrori, AlberoVettore, true);

  // Provo il = move
  AlberoVettore = std::move(AlberoLista2);

  //Verifico Uguaglianze
  NonEqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore);
  Empty(numeroTest, numeroErrori, AlberoLista2, false);
  NonEqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore2);
  EqualBT(numeroTest, numeroErrori, AlberoVettore, AlberoVettore2);
  EqualBT(numeroTest, numeroErrori, AlberoLista3, AlberoLista2);

  //Provo il move construct
  lasd::BinaryTreeVec<int> AlberoVettore3{std::move(AlberoLista)};
  Empty(numeroTest, numeroErrori, AlberoLista, false);
}

void testAlberoDoubleMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  unsigned int numeroLocaleTest = 0;
  unsigned int numeroLocaleErrori = 0;

  unsigned int albTest = 0;
  unsigned int albErr = 0;

  cout << endl << "Inizio Albero<Double> Test DG :" << endl;
  cout << endl << "Inizio Albero(Vettore)<Double> Test DG :" << endl;
  testAlberoGenericoDoubleMio<lasd::BinaryTreeVec<double>>(albTest,albErr);
  cout<<"Fine Albero(Vettore)<Double> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout << endl << "Inizio Albero(Lista)<Double> Test DG :" << endl;
  testAlberoGenericoDoubleMio<lasd::BinaryTreeLnk<double>>(albTest,albErr);
  cout<<"Fine Albero(Lista)<Double> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout << endl << "Inizio Albero(Ambedue)<Double> Test DG :" << endl;
  testAmbedueAlberoDoubleMio(albTest,albErr);
  cout<<"Fine Albero(Ambedue)<Double> Test DG : (Errors/Tests: "<<albErr<<"/"<<albTest<<")"<<endl;

  numeroLocaleTest += albTest;
  numeroLocaleErrori += albErr;
  albTest = 0;
  albErr = 0;

  cout<<"Fine Albero<Double> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
  numeroTest += numeroLocaleTest;
  numeroErrori += numeroLocaleErrori;
}

template <typename Albero>
void testAlberoGenericoDoubleMio(unsigned int & numeroTest, unsigned int & numeroErrori){
 lasd::List<double> lista{};
  for(double i = 1; i <= 7 ; i++)
    lista.InsertAtBack(i);

  //Provo Il Traverse Costruttore
  Albero alberoOrdinato{lista};
  Empty(numeroTest,numeroErrori,alberoOrdinato,false);
  Size(numeroTest,numeroErrori,alberoOrdinato,true,7);

  //Controllo se sia Breath>> 1 2 3 4 5 6 7
  Root<double>(numeroTest,numeroErrori,alberoOrdinato,true,1);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root(),true);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true,2);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild(),true);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true,3);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild(),true);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),true,4);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),false);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),true,5);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),false);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),true,6);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),false);
  GetElement<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),true,7);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),false);

  IsLeaf<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoOrdinato.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoOrdinato.Root().RightChild().RightChild(),true);


  lista.Clear();
  for(double i = 1; i <= 7 ; i++)
    lista.InsertAtFront(i);
  
  //Provo Il Map Costruttore
  Albero alberoDeOrdinato{std::move(lista)};
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Size(numeroTest,numeroErrori,alberoDeOrdinato,true,7);

  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),false); 
  HasLeftChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),false);
  Root<double>(numeroTest,numeroErrori,alberoDeOrdinato,true,7);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),true,1);


  IsLeaf<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoDeOrdinato.Root().RightChild().RightChild(),true);

  //Provo la Copia di Alberi
  Albero alberoCopia{alberoDeOrdinato};
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Empty(numeroTest,numeroErrori,alberoDeOrdinato,false);
  Size(numeroTest,numeroErrori,alberoCopia,true,7);

  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false); 
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);

  Root<double>(numeroTest,numeroErrori,alberoCopia,true,7);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,1);


  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);
  

  //Provo Le uguaglianze
  NonEqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoDeOrdinato);
  NonEqualBT(numeroTest,numeroErrori,alberoOrdinato,alberoCopia);
  EqualBT(numeroTest,numeroErrori,alberoDeOrdinato,alberoCopia);


  //Faccio diventare alberoCopia Breath>> 1 2 3 4 5 6 7
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root(),true,1);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,2);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,3);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,5);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,6);
  SetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,7);

  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  NonEqualBT<double>(numeroTest,numeroErrori,alberoOrdinato,alberoDeOrdinato);
  EqualBT<double>(numeroTest,numeroErrori,alberoOrdinato,alberoCopia);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoDeOrdinato,alberoCopia);

  //Provo la move
  Albero alberoMove{std::move(alberoCopia)};
  Empty(numeroTest,numeroErrori,alberoCopia,true);
  Empty(numeroTest,numeroErrori,alberoMove,false);
  Size(numeroTest,numeroErrori,alberoMove,true,7);
  Size(numeroTest,numeroErrori,alberoCopia,true,0);

  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false); 
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  Root<double>(numeroTest,numeroErrori,alberoMove,true,1);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true,7);

  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true);
  
  //Provo Le uguaglianze
  NonEqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoDeOrdinato);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoCopia);
  EqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoOrdinato);

  //Provo la clear su un albero già pulito
  alberoCopia.Clear();
  
  //Provo = copy
  alberoCopia = alberoDeOrdinato;
  Empty(numeroTest,numeroErrori,alberoCopia,false);
  Size(numeroTest,numeroErrori,alberoCopia,true,7);
  
  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),false); 
  HasLeftChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),false);
  Root<double>(numeroTest,numeroErrori,alberoCopia,true,7);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,1);


  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  EqualBT<double>(numeroTest,numeroErrori,alberoCopia,alberoDeOrdinato);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoCopia);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoCopia,alberoOrdinato);
  
  //Provo = move
  alberoMove.Clear();
  alberoMove = std::move(alberoCopia);
  Empty(numeroTest,numeroErrori,alberoMove,false);
  Empty(numeroTest,numeroErrori,alberoCopia,true);
  Size(numeroTest,numeroErrori,alberoMove,true,7);
  
  //Controllo se sia Breath>> 7 6 5 4 3 2 1
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),false);
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),false); 
  HasLeftChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  HasRightChild<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),false);
  Root<double>(numeroTest,numeroErrori,alberoMove,true,7);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true,1);


  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().LeftChild().RightChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().LeftChild(),true);
  IsLeaf<double>(numeroTest,numeroErrori,alberoMove.Root().RightChild().RightChild(),true);

  //Provo Le uguaglianze
  EqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoDeOrdinato);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoCopia);
  NonEqualBT<double>(numeroTest,numeroErrori,alberoMove,alberoOrdinato);


  // Moltiptico Per 32 Tutti i numeri
  alberoCopia = alberoOrdinato;
  Map<double>(numeroTest, numeroErrori, alberoCopia, true, MapDouble<double>);
  MapBreadth<double>(numeroTest, numeroErrori, alberoCopia, true, MapDouble<double>);
  MapPreOrder<double>(numeroTest, numeroErrori, alberoCopia, true, MapDouble<double>);
  MapPostOrder<double>(numeroTest, numeroErrori, alberoCopia, true, MapDouble<double>);
  MapInOrder<double>(numeroTest, numeroErrori, alberoCopia, true, MapDouble<double>);

  Root<double>(numeroTest,numeroErrori,alberoCopia,true,32);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild(),true,64);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild(),true,96);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().LeftChild(),true,128);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().LeftChild().RightChild(),true,160);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().LeftChild(),true,192);
  GetElement<double>(numeroTest,numeroErrori,alberoCopia.Root().RightChild().RightChild(),true,224);

  alberoCopia = alberoDeOrdinato;

    double inc = 0;
    // 0*7 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1 = 56
    FoldBreadth(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 56);
    
    // 0*7 + 1*6 + 2*4 + 3*3 + 4*5 + 5*2 + 6*1 = 59 
    inc = 0;
    FoldPreOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 59);

    // 0*4 + 1*3 + 2*6 + 3*2 + 4*1 + 5*5 + 6*7 = 92 
    inc = 0;
    FoldPostOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
          }, 
          0, 92);
    
    // 0*4 + 1*6 + 2*3 + 3*7 + 4*2 + 5*5 + 6*1 = 72
    inc = 0;
    FoldInOrder(numeroTest, numeroErrori, alberoCopia, true,
        [&inc](const int &d, const int &res) { 
          return res + d * (inc++); 
        }, 
        0, 72);



}

void testAmbedueAlberoDoubleMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  lasd::List<double> lista{};
  for(double i = 1; i <= 7 ; i++)
    lista.InsertAtBack(i);

  //Creo Albero
  lasd::BinaryTreeLnk<double> AlberoLista{lista};
  lasd::BinaryTreeVec<double> AlberoVettore{lista};

  //Controllo Uguaglianza
  EqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Modifico e controllo che siano diverse
  SetElement<double>(numeroTest, numeroErrori, AlberoLista.Root(), true, 12);
  NonEqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Provo il = Copy
  AlberoVettore = AlberoLista;
  AlberoLista = AlberoVettore;

  Root<double>(numeroTest,numeroErrori,AlberoLista,true,12);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().LeftChild().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().RightChild().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista.Root().RightChild().RightChild(),true,7);

  Root<double>(numeroTest,numeroErrori,AlberoVettore,true,12);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().LeftChild().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore.Root().RightChild().RightChild(),true,7);

  EqualBT(numeroTest, numeroErrori, AlberoLista, AlberoVettore);

  //Provo i costruttori
  lasd::BinaryTreeLnk<double> AlberoLista2{AlberoVettore};
  lasd::BinaryTreeVec<double> AlberoVettore2{AlberoLista};

  Root<double>(numeroTest,numeroErrori,AlberoLista2,true,12);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().LeftChild().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,AlberoLista2.Root().RightChild().RightChild(),true,7);

  Root<double>(numeroTest,numeroErrori,AlberoVettore2,true,12);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild(),true,2);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild(),true,3);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild().LeftChild(),true,4);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().LeftChild().RightChild(),true,5);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild().LeftChild(),true,6);
  GetElement<double>(numeroTest,numeroErrori,AlberoVettore2.Root().RightChild().RightChild(),true,7);

  EqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore2);

  //Provo Cotruttore copi e move
  lasd::BinaryTreeLnk<double> AlberoLista3{AlberoLista2};
  lasd::BinaryTreeVec<double> AlberoVettore4{std::move(AlberoLista3)};

  AlberoVettore.Clear();
  Empty(numeroTest, numeroErrori, AlberoVettore, true);

  // Provo il = move
  AlberoVettore = std::move(AlberoLista2);

  //Verifico Uguaglianze
  NonEqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore);
  Empty(numeroTest, numeroErrori, AlberoLista2, false);
  NonEqualBT(numeroTest, numeroErrori, AlberoLista2, AlberoVettore2);
  EqualBT(numeroTest, numeroErrori, AlberoVettore, AlberoVettore2);
  EqualBT(numeroTest, numeroErrori, AlberoLista3, AlberoLista2);

  //Provo il move construct
  lasd::BinaryTreeVec<double> AlberoVettore3{std::move(AlberoLista)};
  Empty(numeroTest, numeroErrori, AlberoLista, false);

}

