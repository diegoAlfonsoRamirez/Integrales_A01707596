#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap{
    private:
        T *data;
        unsigned int sizeT;
        unsigned int count;
        unsigned int parent(unsigned int) const;
        unsigned int left(unsigned int) const;
        unsigned int right(unsigned int) const;
        void heapify(unsigned int);
        void swap(unsigned int, unsigned int);

    public:
        Heap(unsigned int);
        ~Heap();
        bool empty() const;
        void push(T);
        int size();
		
};

template <class T>
Heap<T>::Heap(unsigned int sizeAux){
    sizeT = sizeAux;
    data = new T[sizeT];
    count = 0;
	
}

template <class T>
Heap<T>::~Heap(){
    delete [] data;
    data = 0;
    sizeT = 0;
    count = 0;
	
}

template <class T> 
unsigned int Heap<T>::parent(unsigned int pos) const{
    return ((pos -1) / 2);
	
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const{
    return ((2 * pos) + 1);
	
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const{
    return ((2 * pos) + 2);
	
}

template <class T>
void Heap<T>::swap(unsigned int val_1, unsigned int val_2){
    T aux = data[val_1];
    data[val_1] = data[val_2];
    data[val_2] = aux;
	
}

template <class T>
void Heap<T>::heapify(unsigned int pos){
    unsigned int leftaux = left(pos);
    unsigned int rightaux = right(pos);
    unsigned int posaux = pos;;
    if((leftaux <= count) && (data[leftaux] < data[posaux])){
        posaux = leftaux;
		
    }
	
    if((rightaux <= count) && (data[rightaux] < data[posaux])){
        posaux = rightaux;
		
    }
	
    if(posaux != pos){
        swap(pos, posaux);
        heapify(posaux);
		
    }
	
}

template <class T>
void Heap<T>::push(T val){
    unsigned int pos;
    pos = count;
    count++;
    while((pos > 0) && (val < data[parent(pos)])){
        data[pos] = data[parent(pos)];
        pos = parent(pos);
		
    }
	
    data[pos] = val;
	
}

template <class T>
int Heap<T>::size(){
    return count;
	
}

#endif