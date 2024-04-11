

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
   
    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(MapFun funz) override{
        PreOrderMap(funz);
    }

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun funz) override{
        InOrderMap(funz);
    }

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun funz) override{
        InOrderMap(funz);
    }
    
    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun funz) override{
        BreadthOrderMap(funz);
    }

}
