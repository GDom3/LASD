

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
   
    template <typename Data>
    void PreOrderMappableContainer<Data>::Map(MapFun funz) override{
        PreOrderMap(funz);
    }

    template <typename Data>
    void PostOrderMappableContainer<Data>::Map(MapFun funz) override{
        InOrderMap(funz);
    }

    template <typename Data>
    void InOrderMappableContainer<Data>::Map(MapFun funz) override{
        InOrderMap(funz);
    }
    
    template <typename Data>
    void BreadthMappableContainer<Data>::Map(MapFun funz) override{
        BreadthOrderMap(funz);
    }

}
