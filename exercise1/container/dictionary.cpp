
namespace lasd {
    
    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& strutturaDaCopiare) {
        bool copiatiTutti = true;

        strutturaDaCopiare.Traverse(
        
            [this,&copiatiTutti](const Data& datoPassato){
                copiatiTutti &= this->Insert(datoPassato);
            }
        );

        return copiatiTutti;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& strutturaDaSpostare)  {
        bool spostatiTutti = true;

        strutturaDaSpostare.Map(

            [this,&spostatiTutti](Data& datoPassato){
                spostatiTutti &= this->Insert(std::move(datoPassato));
            }
        );

        return spostatiTutti;
    }


    template <typename Data>
    bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& strutturaDaRimuovere) {
        bool rimossiTutti = true;

        strutturaDaRimuovere.Traverse(
        
            [this,&rimossiTutti](const Data& datoPassato){
                rimossiTutti &= this->Remove(datoPassato);
            }
        );

        return rimossiTutti;

    }


    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& strutturaDaCopiare) {
        bool copiatiAlcuni = false;

        strutturaDaCopiare.Traverse(
        
            [this,&copiatiAlcuni](const Data& datoPassato){
                copiatiAlcuni |= this->Insert(datoPassato);
            }
        );

        return copiatiAlcuni;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& strutturaDaSpostare) {
    bool spostatiAlcuni = false;

        strutturaDaSpostare.Map(

            [this,&spostatiAlcuni](Data& datoPassato){
                spostatiAlcuni |= this->Insert(std::move(datoPassato));
            }
        );

        return spostatiAlcuni;
    }


    template <typename Data>
    bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& strutturaDaRimuovere) {
        bool rimossiAlcuni = false;

        strutturaDaRimuovere.Traverse(
        
            [this,&rimossiAlcuni](const Data& datoPassato){
                rimossiAlcuni |= this->Remove(datoPassato);
            }
        );

        return rimossiAlcuni;

    }


}
