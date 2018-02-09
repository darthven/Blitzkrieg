/** 
 *  @file    darthvector.h
 *  @author  Konstantin Kharlambov (darthven)
 *  @date    2/9/2018  
 *  @version 0.1 
 *  
 *  @brief DarthVector data structure
 *
 *  @section DESCRIPTION
 *  
 *  This is custom implementation of array-based data structure like vector.
 *  Basic functions of the common-used array's API are implemented.
 */
template<class T>
class DarthVector {

    private:
        int vec_size;
        int vec_capacity;
        T *elements;
        void reallocate(int new_size);
        void resize(int new_size);
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

/** 
  *   @brief Reallocates memory for elements according to the new size.   
  *  
  *   @param  new_size is new size of vector  
  *   @return void
  */  
template<typename T>
void DarthVector<T>::reallocate(int new_size) {
    T *copied = this->copy(this->elements, 0, new_size);
    this->elements = new T[this->vec_capacity];
    for(int i = 0; i < new_size; i++) {
        *(this->elements + i) = *(copied + i);
    }        
    delete[] copied;
}

/** 
  *   @brief Changes size and capacity accoring to the new size.
  *   If the capacity is reached, it is resized to double.
  *   If size is 1/4 of capacity, it is resized to half.
  *  
  *   @param  new_size is new size of vector  
  *   @return void
  */  
template<typename T>
void DarthVector<T>::resize(int new_size) {
    if(new_size == this->vec_capacity) {
        this->vec_capacity *= 2;    
        this->reallocate(new_size);
    } else if(new_size == this->vec_capacity / 4) {
        this->vec_capacity /= 2;          
        this->reallocate(new_size);
    }
    this->vec_size = new_size;
}      

/** 
  *   @brief  Makes a copy of current elements in vector   
  *  
  *   @param  array is pointer to array which will be copied 
  *   @param  from_index is start position from which source array will be copied 
  *   @param  to_index is end position to which source array will be copied 
  *   @return T * is pointer to new elements' sequence of type T
  */  
template<typename T>
T * DarthVector<T>::copy(T *array, int from_index, int to_index) {
    T *copy = new T[to_index - from_index];
    for(int i = 0; i < to_index - from_index; i++) {
        *(copy + i) = *(array + i + from_index);
    }
    return copy;
}

/** 
  *   @brief  Constructor of vector's class.   
  *  
  *   @param  capacity  
  *   @return void
  */  
template<typename T>
DarthVector<T>::DarthVector(int capacity) {
    this->vec_capacity = capacity;
    this->vec_size = 0;
    this->elements = new T[this->vec_capacity];
}

/** 
  *   @brief  Destructor of vector's class.   
  *   
  *   @return void
  */  
template<typename T>
DarthVector<T>::~DarthVector() {
    delete[] this->elements;   
}

/** 
  *   @brief  Returns current size of vector
  *  
  *   @return int current size of vector
  */  
template<typename T>
int DarthVector<T>::size() {
    return this->vec_size;
}

/** 
  *   @brief  Returns current capacity of vector
  *  
  *   @return int current capacity of vector
  */    
template<typename T>
int DarthVector<T>::capacity() {
    return this->vec_capacity;
}

/** 
  *   @brief  Checks if vector is empty. 
  *
  *   @return bool result of check
  */  
template<typename T>
bool DarthVector<T>::isEmpty() {
    return this->size == 0;
}

/** 
  *   @brief  Returns element by index.   
  *  
  *   @param  index
  *   @return T element
  */  
template<typename T>
T DarthVector<T>::at(int index) {
    if(index < this->vec_capacity) {
        return *(this->elements + index);
    }
    return 1;
}

/** 
  *   @brief Adds new element to vector's end.   
  *  
  *   @param  item is new element in vector 
  *   @return void
  */  
template<typename T>
void DarthVector<T>::push(T item) {
    *(this->elements + this->vec_size) = item;
    this->resize(this->vec_size + 1);
}

/** 
  *   @brief Adds new element in front of vector.   
  *  
  *   @param  item is new element in vector 
  *   @return void
  */   
template<typename T>
void DarthVector<T>::prepend(T item) {
    T *copied = this->copy(this->elements, 0, this->vec_size);
    this->resize(this->vec_size + 1);
    for(int j = 1; j < this->vec_size; j++) {        
        *(this->elements + j) = *(copied + j - 1);
    }        
    delete[] copied;
    *(this->elements + 0) = item;   
}


/** 
  *   @brief Adds new element of vector by index.   
  *  
  *   @param  index 
  *   @param  item is new element in vector 
  *   @return void
  */   
template<typename T>
void DarthVector<T>::insert(int index, T item) {
    if(index == 0) {
        this->prepend(item);
    } else if(index == this->vec_size - 1) {
        this->push(item);
    } else {       
        T *copied = this->copy(this->elements, index, this->vec_size);         
        this->resize(this->vec_size + 1);   
        for(int j = 0; j < this->vec_size - index; j++) {
            *(this->elements + j + index + 1) = *(copied + j);           
        }        
        *(this->elements + index) = item;        
        delete[] copied;
    }
}

/** 
  *   @brief  Removes and returns last element of vector.   
  *   
  *   @return T element
  */  
template<typename T>
T DarthVector<T>::pop() {
    T item = *(this->elements + this->vec_size - 1);     
    this->resize(this->vec_size - 1);
    return item;
}

/** 
  *   @brief  Removes and returns first element of vector.   
  *   
  *   @return T element
  */  
template<typename T>
T DarthVector<T>::shift() { 
    T item = *(this->elements + 0);     
    T *copied = this->copy(this->elements, 1, this->vec_size);     
    this->resize(this->vec_size - 1);
    for(int j = 0; j < this->vec_size; j++) {
        *(this->elements + j) = *(copied + j);
    }      
    delete[] copied;       
    return item;
}

/** 
  *   @brief  Removes and element of vector by index.   
  *  
  *   @param  index  
  *   @return void
  */  
template<typename T>
void DarthVector<T>::delete_(int index) {
    if(index == 0) {
        this->shift();
    } else if(index == this->vec_size - 1) {
        this->pop();
    } else {
        T *copied = this->copy(this->elements, index + 1, this->vec_size);       
        this->resize(this->vec_size - 1);
        for(int j = 0; j < this->vec_size - index; j++) {
            *(this->elements + j + index) = *(copied + j);           
        }
        delete[] copied;
    }   
}

/** 
  *   @brief  Returns the first index of element that was found.   
  *  
  *   @param  item is element that will be searched in vector
  *   @return int index of the element if found or -1 if not
  */  
template<typename T>
int DarthVector<T>::find(T item) {
    for(int i = 0; i < this->vec_size; i++) {
        if(this->at(i) == item) {
            return i;
        }
    }
    return -1;
}

/** 
  *   @brief  Returns all values of vector.   
  *   
  *   @return T * pointer to vector's elements 
  */  
template<typename T>
T * DarthVector<T>::values() {         
    return this->copy(this->elements, 0, this->vec_size);
}