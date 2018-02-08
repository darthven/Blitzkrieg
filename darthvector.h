#include <iostream>

template<class T>
class DarthVector {

    private:
        int vec_size;
        int vec_capacity;
        T *elements;
        void resize(int new_capacity) {
            this->vec_capacity = capacity;
        }
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
        void delete_(int index);
        void remove(T item);
        T find(int index);
};

template<typename T>
DarthVector<T>::DarthVector(int capacity) {
    this->vec_capacity = capacity;
    this->vec_size = 0;
    this->elements = (T *) malloc(this->vec_capacity * sizeof(T));
}

template<typename T>
DarthVector<T>::~DarthVector() {
    free(this->elements);
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
    T *shifted = (T *) malloc(this->vec_size * sizeof(T));
    for(int i = 0; i < this->vec_size; i++) {
        *(shifted + i) = *(this->elements + i);
    }   
    this->vec_size++;
    for(int j = 1; j < this->vec_size; j++) {
        *(this->elements + j) = *(shifted + j - 1);
    }        
    free(shifted);
    *(this->elements + 0) = item;   
}

template<typename T>
void DarthVector<T>::insert(int index, T item) {
    if(index == 0) {
        this->prepend(item);
    } else if(index == this->vec_size) {
        this->push(item);
    } else {
        T *shifted = (T *) malloc((this->vec_size - index) * sizeof(T));
        for(int i = 0; i < this->vec_size - index; i++) {
            *(shifted + i) = *(this->elements + i + index);            
        }        
        this->vec_size++;         
        for(int j = 0; j < this->vec_size - index; j++) {
            *(this->elements + j + index) = *(shifted + j - 1);           
        }
        *(this->elements + index) = item;        
    }
}
