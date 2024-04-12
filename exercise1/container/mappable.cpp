

namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
   
    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(MapFun funz){
        PreOrderMap(funz);
    }

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun funz){
        InOrderMap(funz);
    }

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun funz){
        InOrderMap(funz);
    }
    
    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun funz){
        BreadthOrderMap(funz);
    }

}
