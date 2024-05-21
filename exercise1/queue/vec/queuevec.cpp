
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> &struttura ){
    
    struttura.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );

    if(struttura.Size() > 0){
        testa = 0;
        coda = struttura.Size() - 1;
            
    }
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &&struttura ){
    if(struttura.Size() > 0){
        testa = 0;
        coda = struttura.Size() - 1;
    }

    struttura.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec & quevec){
    coda = quevec.coda;
    testa = quevec.testa;

    quevec.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );

}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec && quevec){
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);

    quevec.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );
}

template <typename Data>
QueueVec<Data>::~QueueVec(){
    Vector<Data>::Clear();
    coda = 1;
    testa = 0;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec & quevec){
    coda = quevec.coda;
    testa = quevec.testa;
    return Vector<Data>::operator=((Vector<Data>) quevec);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec && quevec){
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);
    return Vector<Data>::operator=((Vector<Data>) quevec);
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec & quevec) const noexcept{
    return !operator==(quevec);

}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec & quevec) const noexcept{
    return Vector<Data>::operator==((Vector<Data>)quevec);

}

template <typename Data>
void QueueVec<Data>::Espandi(){
    if(Size() == size - 1){
        QueueVec<Data> *temp = new QueueVec<Data>();
        temp->Resize(size * indiceResizeEnq);
        ScambioVettoriCircolari(*temp);
        delete temp;
    }


}

template <typename Data>
void QueueVec<Data>::Riduci(){
    if(Size() <= size / (indiceResizeDeq * 2)){
        QueueVec<Data> *temp = new QueueVec<Data>();
        temp->Resize(size / indiceDeq);
        ScambioVettoriCircolari(*temp);
        delete temp;
    }


}

template <typename Data>
void QueueVec<Data>::ScambioVettoriCircolari(QueueVec<Data> &q){
    unsigned long int indice = 0;

    for(unsigned long int i = testa; i != coda; i = ((i + 1)%size)){
        std::swap(elementi[i],q.elementi[i]);
        indice++;
    }

    q.testa = 0;
    q.coda = indice;
    std::swap(elementi,q.elementi);
    std::swap(size,q.size);
    std::swap(testa,q.testa);
    std::swap(coda,q.coda);

}


template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(Empty()){
        throw std::length_error("Queue Vuota!");
    }
    

    return elementi[coda]; 

}

template <typename Data>
Data& QueueVec<Data>::Head(){
    if(Empty()){
        throw std::length_error("Queue Vuota!");
    }

    return elementi[coda]; 

}

template <typename Data>
inline void QueueVec<Data>::Dequeue(){
    if(testa == coda)
        throw std::length_error("Queue Vuota!");

    Riduci();
    coda--;

}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){

    Data elem = elementi[coda];
    Dequeue();
    return elem;

}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
    Espandi();
    elementi[coda] = elem;
    coda++;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    Espandi();
    std::swap(elementi[coda],elem);
    coda++;

}

}
