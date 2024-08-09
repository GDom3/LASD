
namespace lasd {

    //Esiste:
    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data& valoreDaTrovare) const noexcept{
        bool esiste = false;

        Traverse(
            [valoreDaTrovare, &esiste](const Data& datoPassato){
                esiste |= (datoPassato == valoreDaTrovare); 
            }
        );

        return esiste;
    }

    // Fold:
    template <typename Data>
    template <typename Accumulator>
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> funzione, Accumulator acc) const{
        Traverse(
            //Lambda Function 
            [funzione, &acc](const Data& datoPassato){
                acc = funzione(datoPassato, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> funzione, Accumulator acc) const{
        PreOrderTraverse(
            [funzione, &acc](const Data& datoPassato){
                acc = funzione(datoPassato, acc);
            }
        );

        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> funzione, Accumulator acc) const{
        PostOrderTraverse(
            [funzione, &acc](const Data& datoPassato){
                acc = funzione(datoPassato, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> funzione ,Accumulator acc) const{
        InOrderTraverse(
            [funzione, &acc](const Data& datoPassato){
                acc = funzione(datoPassato, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> funzione ,Accumulator acc) const{
        BreadthTraverse(
            [funzione, &acc](const Data& datoPassato){
                acc = funzione(datoPassato, acc);
            }
        );
        return acc;
    }

    //Traverse:

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const {
        PreOrderTraverse(funzione);
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const {
        PostOrderTraverse(funzione);
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const {
        InOrderTraverse(funzione);
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun funzione) const {
        BreadthTraverse(funzione);
    }

}
