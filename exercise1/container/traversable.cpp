
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> funzione, Accumulator acc) const{
    Traverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}


template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& valoreDaTrovare) const noexcept{
    bool esiste = false;
    Traverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [valoreDaTrovare, &esiste](const Data& datoPassato){
            esiste = esiste || (datoPassato = valoreDaTrovare); //potrei scrivere |=
        }
    );

    return esiste;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> funzione, Accumulator acc) const{
    PreOrderTraverse(
        //[] è il contesto, sono valore che passo da Exists a Traverse(default è copia)
        [funzione, &acc](const Data& datoPassato){
            acc = funzione(datoPassato, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun funzione) const{
    PreOrderTraverse(funzione);
}

}
