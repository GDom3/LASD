#include <iostream>
// #include "..."

#include "../vector/vector.hpp"

#include "../list/list.hpp"
/* ************************************************************************** */



using namespace std;
unsigned long int numErrori = 0;
unsigned long int numTest = 0;
/* ************************************************************************** */




void TestVettori(){
     lasd::SortableVector<int> vec;
  try{
    numTest++;
    vec.Resize(0); //Test resize 0
    if(vec.Size() > 0)
      numErrori++;
  }catch(...){
    numErrori++;
  }
 
  try{
    numTest++; 
    vec[0] = 12; //testinserimeto in un vettore nullo
    
    numErrori++;

  }catch(...){
    

  }
  
  try{
    numTest++;
    vec.Resize(8); // Test resize più grande
    if(vec.Size() != 8)
      numErrori++;
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    //Test inserimento
    for(unsigned long int i = 0; i < vec.Size(); i++){
      vec[i] = vec.Size() - i;
    }


  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    //test copia
    lasd::SortableVector<int> vetTmp(8);
    for(unsigned long int i = 0; i < vetTmp.Size(); i++){
      vetTmp[i] = vetTmp.Size() - i ;
    }

    //Test conftornti (!=)
    if(vetTmp != vec)
      numErrori++;

  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec.Sort(); //Test ordinamento 
    
    for(unsigned long int i = 0; i < vec.Size(); i++){
      if(vec[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }


  try{
    numTest++;
    vec.Resize(4); // test resize più piccola
    if(vec.Size() != 4)
      numErrori++;
    

  }catch(...){
    numErrori++;

  }



  try{
    numTest++; //test del risultato della resize
    for(unsigned long int i = 0; i < vec.Size(); i++){
      if(vec[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }

  lasd::Vector<int>vetcp(vec);
  try{
    numTest++; //test del costruttore copy
    for(unsigned long int i = 0; i < vetcp.Size(); i++){
      if(vetcp[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }

  lasd::Vector<int>vetmv(move(vetcp));
  try{
    numTest++; //test del costruttore move
    for(unsigned long int i = 0; i < vetmv.Size(); i++){
      if(vetmv[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vetcp.Clear(); //test della clear
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    if(vetcp.Empty() == false) //Test dell'empty
      numErrori++; 
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec[3]; //Test della lettura in range

  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec[12]; //test lettura out range
    numErrori++;
  }catch(...){
    

  }

  try{
    numTest++; //Test del front
    if(vec.Front() != 1)
      numErrori++;
    
  }catch(...){
    numErrori++;

  }

  try{
    numTest++; // test del back
    if(vec.Back() != 4)
      numErrori++;
    
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vetcp = vec;// test del assegnamento copia (=)
    for(unsigned long int i = 0; i < vetcp.Size(); i++)
      if(vetcp[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
    
  }catch(...){
    numErrori++;

  }
  try{
    numTest++;

    vetmv = move(vetcp); //test del assegnamento move (=)
    for(unsigned long int i = 0; i < vetmv.Size(); i++)
      if(vetmv[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
    
  }catch(...){
    numErrori++;

  }

  try{
    
    numTest++; //test dell esiste presente
    if(vetmv.Exists(3) == false)
      numErrori++;
  }catch(...){
    numErrori++;

  }

  try{
    
    numTest++; //test dell esiste assente
    if(vetmv.Exists(12) == true)
      numErrori++;
  }catch(...){
    numErrori++;

  }
   

}
void TestListe(){
 lasd::List<int>list;
 try{
    
    numTest++; //Test inserimenti per copia
    list.InsertAtFront(0);
    list.InsertAtBack(6);
    list.InsertAtFront(2);
    list.InsertAtBack(2);
    list.InsertAtFront(1);
    list.InsertAtBack(0);
    list.InsertAtBack(0);
    list.InsertAtBack(3);
    list.Stampa();
  }catch(...){
    numErrori++;

  }

  try{
    
    numTest++; //Test [],Front e back
    if(list.Front()!=1)
      numErrori++;
    else if (list.Back() != 3)
      numErrori++;
    else if (list[1] != 2)
      numErrori++;
    else if (list[2] != 0)
      numErrori++;
    else if (list[3] != 6)
      numErrori++;
    else if (list[4] != 2)
      numErrori++;
    else if (list[5] != 0)
      numErrori++;
    else if (list[6] != 0)
      numErrori++;
 

  }catch(...){
    numErrori++;

  }

  try{
    
    numTest++; //Test [],Front e back
    list[8];

    numErrori++;
 
  }catch(...){
   

  }


  
}
void StackList(){
  
}
void StackVector(){
  
}
void TestStack(){
  
  unsigned long int numErroriTemp = 0;
  unsigned long int numTestTemp = 0;
  StackList();
  numErroriTemp = numErrori;
  numTestTemp = numTest;
  cout<<"  Errori Stack Lista : "<<numErrori<<"/"<<numTest<<endl;
  numErrori = 0;
  numTest = 0;
  StackVector();
  cout<<"  Errori Stack Vettore : "<<numErrori<<"/"<<numTest<<endl;
  numErrori += numErroriTemp;
  numTest += numTestTemp;
  
}

void CodeList(){
  
}
void CodeVector(){
}

  
void TestCode(){
  unsigned long int numErroriTemp = 0;
  unsigned long int numTestTemp = 0;
  CodeList();
  numErroriTemp = numErrori;
  numTestTemp = numTest;
  cout<<"  Errori Stack Lista : "<<numErrori<<"/"<<numTest<<endl;
  numErrori = 0;
  numTest = 0;
  CodeVector();
  cout<<"  Errori Stack Vettore : "<<numErrori<<"/"<<numTest<<endl;
  numErrori += numErroriTemp;
  numTest += numTestTemp;
}




void mytest() {
 
  cout << endl << "~*~#~*~ Domenico Gagliotti Test ~*~#~*~ " << endl;
  
  unsigned long int numErroriTot = 0;
  unsigned long int numTestTot = 0;
  
  cout<<endl<<"[Vettori]";
  TestVettori();
  cout<<"\nErrori Vettore : "<<numErrori<<"/"<<numTest<<endl;
  
  numErroriTot += numErrori;
  numTestTot += numTest;
  numErrori = 0;
  numTest = 0;

  cout<<endl<<"[Liste]";
  TestListe();
  cout<<"\nErrori Liste : "<<numErrori<<"/"<<numTest<<endl;
  
  numErroriTot += numErrori;
  numTestTot += numTest;
  numErrori = 0;
  numTest = 0;
  
  cout<<endl<<"[Stack]"<<endl;
  TestStack();
  cout<<"\nErrori Stack : "<<numErrori<<"/"<<numTest<<endl;
  
  numErroriTot += numErrori;
  numTestTot += numTest;
  numErrori = 0;
  numTest = 0;
  
  cout<<endl<<"[Code]"<<endl;
  TestCode();
  cout<<"\nErrori Code : "<<numErrori<<"/"<<numTest<<endl;
  
  numErroriTot += numErrori;
  numTestTot += numTest;
  numErrori = 0;
  numTest = 0;

  cout<<"\n[Totale]\nErrori Totali : "<<numErroriTot<<"/"<<numTestTot<<endl;
  
}
