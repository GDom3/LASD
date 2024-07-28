#include <iostream>

#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/vector/vector.hpp"


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

  cout << endl << "Risultati Test (Errors/Tests: " << stesterr << "/" << stestnum << ")\n\n";

}

void testVettoreMio(unsigned int & numeroTest, unsigned int & numeroErrori){
    testVettoreIntMio(numeroTest,numeroErrori);
    testVettoreStringMio(numeroTest,numeroErrori);

}

void testListaMio(unsigned int & numeroTest, unsigned int & numeroErrori){
  testListaIntMio(numeroTest,numeroErrori);
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
        
        Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, string("1"));
        Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false, string("12"));

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
        
        Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, true, 1);
        Exists(numeroLocaleTest, numeroLocaleErrori, VettoreCopiatoDaLista, false, 12);

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
        
    

        /* 
        Traverse(numeroLocaleTest, numeroLocaleErrori, Vettore, true, TraversePrint<int>);
        Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
        Traverse(numeroLocaleTest, numeroLocaleErrori, altraLista, true, TraversePrint<int>);


    
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = (int)i + 1;
    altraLista.Clear();
    InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = 10;
    RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
    Vettore.Resize(0);
    Vettore.Clear();
    Empty(numeroLocaleTest, numeroLocaleErrori, Vettore, true);
    InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
    InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
    InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
    InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
    RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
    RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
    altraLista.Clear();
    InsertAllM(numeroLocaleTest, numeroLocaleErrori, altraLista, true, std::move(Vettore));
    InsertAllC(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
    InsertSomeC(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
    InsertSomeM(numeroLocaleTest, numeroLocaleErrori, altraLista, false, std::move(Vettore));
    RemoveSome(numeroLocaleTest, numeroLocaleErrori, altraLista, false, Vettore);
    RemoveAll(numeroLocaleTest, numeroLocaleErrori, altraLista, true, Vettore);
    InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 1);
    InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 2);
    InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 3);
    InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 4);
    InsertAtFront(numeroLocaleTest, numeroLocaleErrori, altraLista, true, 5);
    Traverse(numeroLocaleTest, numeroLocaleErrori, altraLista, true, TraversePrint<int>);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    lista = altraLista;
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 4);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    Traverse(numeroLocaleTest, numeroLocaleErrori, altraLista, true, TraversePrint<int>);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 5);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 4);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 3);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 2);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
    FrontNRemove(numeroLocaleTest, numeroLocaleErrori, lista, false, 1);
    lista = altraLista;
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    NonEqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, false);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    InsertAtBack(numeroLocaleTest, numeroLocaleErrori, lista, true, 10);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    lista = altraLista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);
    altraLista = lista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    Vettore.Resize(100);
    int x{100};
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = x++;
    lista.Clear();
    InsertAllC(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
    lasd::List<int> lst3(Vettore);
    lasd::List<int> lst4(lista);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lst3, lst4, true);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lst4, true, TraversePrint<int>);
    lst3.Clear();
    lst3.InsertAtFront(1);
    lst4 = lst3;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lst3, lst4, true);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lst4, true, TraversePrint<int>);
    lista.Clear();
    altraLista.Clear();
    lista = altraLista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    lista.InsertAtFront(1);
    lista = altraLista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    altraLista.InsertAtFront(1);
    lista = altraLista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    lista.InsertAll(Vettore);
    Vettore.Resize(50);
    altraLista.InsertAll(Vettore);
    Vettore.Resize(35);
    lst3.Clear();
    lst3.InsertAll(Vettore);
    altraLista = lista;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, altraLista, true);
    lista = lst3;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista, lst3, true);
    x = 0;
    Vettore.Resize(100);
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = x++;
    lst4.Clear();
    lst4.InsertSome(Vettore);
    lasd::List<int> lst5(std::move(Vettore));
    EqualList(numeroLocaleTest, numeroLocaleErrori, lst4, lst5, true);
    x = 0;
    Vettore.Resize(100);
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = x++;
    lista.Clear();
    lista.InsertAll(Vettore);
    altraLista = lista;
    lst3.Clear();
    lst3 = std::move(lista);
    EqualList(numeroLocaleTest, numeroLocaleErrori, altraLista, lst3, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
    lasd::List<int> lista0;
    lasd::List<int> lista1(lista0);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 0);
    lista0 = lista1;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 0);
    lista0 = std::move(lista1);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 0);
    lista0.InsertAll(Vettore);
    lista1 = lista0;
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 100);
    lista0 = std::move(lista1);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, true);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 100);
    lista0.Clear();
    lista0 = std::move(lista1);
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista0, lista1, false);
    Size(numeroLocaleTest, numeroLocaleErrori, lista1, true, 0);
    lista0.InsertAll(Vettore);
    lasd::List<int> lista2(std::move(lista0));
    lasd::List<int> lista3(std::move(Vettore));
    EqualList(numeroLocaleTest, numeroLocaleErrori, lista2, lista3, true);
    Vettore.Clear();
    Vettore.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = x++;
    lista.Clear();
    lista.InsertAll(Vettore);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);
    Vettore.Resize(2);
    Vettore[0] = 8;
    Vettore[1] = 3;
    RemoveAll(numeroLocaleTest, numeroLocaleErrori, lista, true, Vettore);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lista, true, TraversePrint<int>);

    lista.Clear();
    for (unsigned long int i{0}; i < 5; ++i)
      lista.InsertAtBack(i);

    InsertM(numeroLocaleTest, numeroLocaleErrori, lista, false, 0);
    Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, 0);
    Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, 1);
    Remove(numeroLocaleTest, numeroLocaleErrori, lista, true, lista.Back());

    RemoveFromFront(numeroLocaleTest, numeroLocaleErrori, lista, true);

    Vettore.Clear();
    Vettore.Resize(10);
    x = 0;
    for (unsigned long int i{0}; i < Vettore.Size(); ++i)
      Vettore[i] = x++;
    Traverse(numeroLocaleTest, numeroLocaleErrori, Vettore, true, TraversePrint<int>);
    lasd::List<int> lst666(Vettore);
    Traverse(numeroLocaleTest, numeroLocaleErrori, lst666, true, TraversePrint<int>);
    lasd::SortableVector<int> vec666;
    vec666 = std::move(Vettore);
    Traverse(numeroLocaleTest, numeroLocaleErrori, vec666, true, TraversePrint<int>);
    EqualLinear(numeroLocaleTest, numeroLocaleErrori, lst666, vec666, true);
    Vettore.Resize(1);
    Vettore[0] = 9;
    lst666.RemoveAll(Vettore);
    EqualLinear(numeroLocaleTest, numeroLocaleErrori, lst666, vec666, false);
    vec666.Resize(vec666.Size() - 1);
    EqualLinear(numeroLocaleTest, numeroLocaleErrori, lst666, vec666, true);

        */

        cout<<"Fine Lista<int> Test DG : (Errors/Tests: "<<numeroLocaleErrori<<"/"<<numeroLocaleTest<<")"<<endl;
        
        numeroTest += numeroLocaleTest;
        numeroErrori += numeroLocaleErrori;
}












