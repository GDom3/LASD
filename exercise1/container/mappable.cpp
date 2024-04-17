

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
        PostOrderMap(funz);
    }

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun funz){
        InOrderMap(funz);
    }
    
    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun funz){
        BreadthOrderMap(funz);
    }

    template <typename Data>
    inline bool PreOrderMappableContainer<Data>::Exists(const Data& dato) const noexcept{
        return PreOrderTraversableContainer<Data>::Exists(dato);
    }

    template <typename Data>
    inline bool PostOrderMappableContainer<Data>::Exists(const Data& dato) const noexcept{
       return PostOrderTraversableContainer<Data>::Exists(dato);
    }

    template <typename Data>
    inline bool InOrderMappableContainer<Data>::Exists(const Data& dato) const noexcept{ 
        return InOrderTraversableContainer<Data>::Exists(dato);
    }
    
    template <typename Data>
    inline bool BreadthMappableContainer<Data>::Exists(const Data& dato) const noexcept{
        return BreadthOrderTraversableContainer<Data>::Exists(dato);
    }


}
