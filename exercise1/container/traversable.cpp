
namespace lasd {

//Esiste:
template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& valoreDaTrovare) const noexcept{
    bool esiste = false;
    Traverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [valoreDaTrovare, &esiste](const Data& datoPassato){
            esiste = esiste || (datoPassato == valoreDaTrovare); //potrei scrivere |=
        }
    );

    return esiste;
}

// Fold:

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> funzione, Accumulator acc) const noexcept{
    Traverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> funzione, Accumulator acc) const noexcept{
    PreOrderTraverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> funzione, Accumulator acc) const noexcept{
    PostOrderTraverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> funzione ,Accumulator acc) const noexcept{

    InOrderTraverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator BreadthTraversableContainer<Data>::BreadthOrderFold(FoldFun<Accumulator> funzione ,Accumulator acc) const noexcept{
    
    BreadthOrderTraverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

//Traverse:

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const noexcept{
    PreOrderTraverse(funzione);
}

template <typename Data>
inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const noexcept{
    PostOrderTraverse(funzione);
}

template <typename Data>
inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const noexcept{
    InOrderTraverse(funzione);
}

template <typename Data>
inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun funzione) const noexcept{
    BreadthOrderTraverse(funzione);
}

}




