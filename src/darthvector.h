#include <iostream>

template<class T>
class DarthVector {

    private:
        int vec_size;
        int vec_capacity;
        T *elements;
        void resize(int new_capacity);
        T *copy(T *array, int from_index, int to_index);
    public:
        DarthVector<T>(int capacity);
        ~DarthVector<T>();
        int size();
        int capacity();
        bool isEmpty();
        T at(int index);
        void push(T item);
        void insert(int index, T item);
        void prepend(T item);
        T pop();
        T shift();
        void delete_(int index);
        void remove(T item);
        int find(T item);
        T *values();
};

template<typename T>
void DarthVector<T>::resize(int new_capacity) {
    this->vec_capacity = capacity;
}      

template<typename T>
T * DarthVector<T>::copy(T *array, int from_index, int to_index) {
    T *copy = new T[to_index - from_index];
    for(int i = 0; i < to_index - from_index; i++) {
        *(copy + i) = *(array + i + from_index);
    }
    return copy;
}

template<typename T>
DarthVector<T>::DarthVector(int capacity) {
    this->vec_capacity = capacity;
    this->vec_size = 0;
    this->elements = new T[this->vec_capacity];
}

template<typename T>
DarthVector<T>::~DarthVector() {
    delete[] this->elements;
    std::cout << "Vector was destroyed" << std::endl;
}

template<typename T>
int DarthVector<T>::size() {
    return this->vec_size;
}

template<typename T>
int DarthVector<T>::capacity() {
    return this->vec_capacity;
}

template<typename T>
bool DarthVector<T>::isEmpty() {
    return this->size == 0;
}

template<typename T>
T DarthVector<T>::at(int index) {
    if(index < this->vec_capacity) {
        return *(this->elements + index);
    }
    return 1;
}

template<typename T>
void DarthVector<T>::push(T item) {
    *(this->elements + this->vec_size) = item;
    this->vec_size++;
}

template<typename T>
void DarthVector<T>::prepend(T item) {
    T *copied = this->copy(this->elements, 0, this->vec_size);
    this->vec_size++;
    for(int j = 1; j < this->vec_size; j++) {        
        *(this->elements + j) = *(copied + j - 1);
    }        
    delete[] copied;
    *(this->elements + 0) = item;   
}

template<typename T>
void DarthVector<T>::insert(int index, T item) {
    if(index == 0) {
        this->prepend(item);
    } else if(index == this->vec_size - 1) {
        this->push(item);
    } else {       
        T *copied = this->copy(this->elements, index, this->vec_size);         
        this->vec_size++;         
        for(int j = 0; j < this->vec_size - index; j++) {
            *(this->elements + j + index + 1) = *(copied + j);           
        }        
        *(this->elements + index) = item;        
        delete[] copied;
    }
}

template<typename T>
T DarthVector<T>::pop() {
    T item = *(this->elements + this->vec_size - 1);     
    this->vec_size--;
    return item;
}

template<typename T>
T DarthVector<T>::shift() { 
    T item = *(this->elements + 0);     
    T *copied = this->copy(this->elements, 1, this->vec_size);     
    this->vec_size--;
    for(int j = 0; j < this->vec_size; j++) {
        *(this->elements + j) = *(copied + j);
    }      
    delete[] copied;       
    return item;
}

template<typename T>
void DarthVector<T>::delete_(int index) {
    if(index == 0) {
        this->shift();
    } else if(index == this->vec_size - 1) {
        this->pop();
    } else {
        T *copied = this->copy(this->elements, index + 1, this->vec_size);       
        this->vec_size--;    
        for(int j = 0; j < this->vec_size - index; j++) {
            *(this->elements + j + index) = *(copied + j);           
        }
        delete[] copied;
    }   
}

template<typename T>
int DarthVector<T>::find(T item) {
    for(int i = 0; i < this->vec_size; i++) {
        if(this->at(i) == item) {
            return i;
        }
    }
    return -1;
}

template<typename T>
T * DarthVector<T>::values() {         
    return this->copy(this->elements, 0, this->vec_size);
}