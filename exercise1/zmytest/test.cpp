#include <iostream>
// #include "..."

#include "../vector/vector.hpp"

#include "../list/list.hpp"
/* ************************************************************************** */



using namespace std;
unsigned long int numErrori = 0;
unsigned long int numTest = 0;
/* ************************************************************************** */

void VettoriDiInteri(){
  lasd::SortableVector<int> vec;
  try{
    numTest++;
    vec.Resize(0); //Test resize 0
    if(vec.Size() > 0)
      numErrori++;
  }catch(...){
    numErrori++;
  }
  vec.Stampa();
  try{
    numTest++; 
    vec[0] = 12;
    
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
  vec.Stampa();
  try{
    numTest++;

    for(unsigned long int i = 0; i < vec.Size(); i++){
      vec[i] = vec.Size() - i;
    }


  }catch(...){
    numErrori++;

  }
  vec.Stampa();
  try{
    numTest++;

    lasd::SortableVector<int> vetTmp(8);
    for(unsigned long int i = 0; i < vetTmp.Size(); i++){
      vetTmp[i] = vetTmp.Size() - i ;
    }

    if(vetTmp != vec)
      numErrori++;

  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec.Sort(); 
    
    for(unsigned long int i = 0; i < vec.Size(); i++){
      if(vec[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }
  vec.Stampa();

  try{
    numTest++;
    vec.Resize(4); // test resize più piccola
    if(vec.Size() != 4)
      numErrori++;
    
    numTest++;
    for(unsigned long int i = 0; i < vec.Size(); i++){
      if(vec[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
        
    }

  }catch(...){
    numErrori++;

  }
  vec.Stampa();


  try{
    numTest++;
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
    numTest++;
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
    numTest++;
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
    vetcp.Clear();
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    if(vetcp.Empty() == false)
      numErrori++; 
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec[3];

  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vec[12];
    numErrori++;
  }catch(...){
    

  }

  try{
    numTest++;
    if(vec.Front() != 1)
      numErrori++;
    
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    if(vec.Back() != 4)
      numErrori++;
    
  }catch(...){
    numErrori++;

  }

  try{
    numTest++;
    vetcp = vec;
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

    vetmv = move(vetcp);
    for(unsigned long int i = 0; i < vetmv.Size(); i++)
      if(vetmv[i] != (int) i + 1 ){
        numErrori++;
        break;
      }
    
  }catch(...){
    numErrori++;

  }

  try{
    
    numTest++;
    if(vetmv.Exists(3) == false)
      numErrori++;
  }catch(...){
    numErrori++;

  }

}

void TestVettori(){
    VettoriDiInteri();


}
void TestListe(){
  
}
void TestStack(){
  
}
void TestCode(){
  
}




void mytest() {
  // ...
  cout << endl << "~*~#~*~ Domenico Gagliotti Test ~*~#~*~ " << endl;
  TestVettori();
  cout<<"\nErrori : "<<numErrori<<"/"<<numTest<<endl;
  TestListe();
  TestStack();
  TestCode();



}
