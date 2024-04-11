
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer& strutturaDaCopiare){
    bool copiatiTutti = true;
    
    strutturaDaCopiare.Traverse(
      
        [&copiatiTutti](const Data& datoPassato){
            copiatiTutti = copiatiTutti && *this.Insert(datoPassato);
        }
    )

    return copiatiTutti;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer&& strutturaDaSpostare){
bool spostatiTutti = true;
    
    strutturaDaSpostare.Map(
        
        [&spostatiTutti](Data& datoPassato){
            spostatiTutti = spostatiTutti && *this.Insert(datoPassato);
        }
    )

    return spostatiTutti;
}


template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer& strutturaDaRimuovere){
    bool rimossiTutti = true;
    
    strutturaDaCopiare.Traverse(
      
        [&rimossiTutti](const Data& datoPassato){
            rimossiTutti = rimossiTutti && *this.Remove(datoPassato);
        }
    )

    return rimossiTutti;

}


template <typename Data>
bool DictionaryContainer<Data>::InsertSome(const TraversableContainer& strutturaDaCopiare){
    bool copiatiAlcuni = false;
    
    strutturaDaCopiare.Traverse(
      
        [&copiatiAlcuni](const Data& datoPassato){
            copiatiAlcuni = copiatiAlcuni || *this.Insert(datoPassato);
        }
    )

    return copiatiAlcuni;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer&& strutturaDaSpostare){
bool spostatiAlcuni = false;
    
    strutturaDaSpostare.Map(
        
        [&spostatiAlcuni](Data& datoPassato){
            spostatiAlcuni = spostatiAlcuni || *this.Insert(datoPassato);
        }
    )

    return spostatiAlcuni;
}


template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer& strutturaDaRimuovere){
    bool rimossiAlcuni = false;
    
    strutturaDaCopiare.Traverse(
      
        [&rimossiAlcuni](const Data& datoPassato){
            rimossiAlcuni = rimossiAlcuni || *this.Remove(datoPassato);
        }
    )

    return rimossiAlcuni;

}


}
