#ifndef DSVECTOR_H
#define DSVECTOR_H
using namespace std;
#include<iostream>
#include<exception>
template <class T>
class DSVector{
public:
    typedef T* iterator;

    DSVector();
    DSVector(int mysize);
    DSVector(int mysize, const T & initial);
    DSVector(const DSVector<T> &V);
    ~DSVector();
    DSVector& operator=(const DSVector<T> &V);

    iterator begin();
    iterator end();
    T& front();
    T& back();
    bool empty();
    void push_back(const T& value);
    void pop_back();
    void reserve(int new_capacity);
    int getSize() const;
    int getCapacity()const;
    void reSize(int newsize);
    T & operator[]( int index);
    void clear();
    void insert(const T& value, int i);
private:
    int size;
    int capacity;
    T* Buffer;

};

//default constructor for DSVector
//set size to 0 and capacity to 10
template <class T>
DSVector<T>::DSVector(){
     size = 0;
     capacity = 10;
     Buffer = new T[capacity];
}

//set size to 0
//set capacity and buffer equal to each other
template<class T>
DSVector<T>::DSVector(int mysize){
    size = 0;
    capacity = mysize;
    Buffer = new T[capacity];
}

//set size to mysize
//set buffer to to that size and all values to a selected value
template<class T>
DSVector<T>::DSVector(int mysize, const T & initial){
    size = 0;
    capacity = mysize;
    Buffer = new T[size];
    for(int i = 0; i < mysize; i++){
        Buffer[i] = initial;
        //T();
    }
}


//copy constructor to copy all fields.
template<class T>
DSVector<T>::DSVector(const DSVector<T> & V ){
    size = V.size;
    capacity = V.capacity;
    Buffer = new T[size];
    for(int i = 0; i < size; i++){
        Buffer[i] = V.Buffer[i];
    }
}


//destructor for vector class
template<class T>
DSVector<T>::~DSVector(){
    delete [] Buffer;
}

//overloaded assignment operator
//delete original and assign
//buffer to new values.
template<class T>
DSVector<T>&DSVector<T>::operator=(const DSVector<T> &V){
    delete [] Buffer;
    size = V.size;
    capacity = V.capacity;
    Buffer = new T[size];
    for(int i = 0; i < size; i++){
        Buffer[i] = V.Buffer[i];
    }
    return *this;
}


//insert value at specific position
//if index is greater than capacity
//double the capacity and insert value at that index
//set all values between the size and the capacity to
//default values.
//if index is greater than size set that index to specificed value
//increment size by one. otherwise if in between 0 and size shift all elements
//back 1 and set that index equal to the value.
template<class T>
void DSVector<T>::insert(const T& value, int i){
    if(i > capacity){
        resize(getCapacity() * 2);
    }
    if(i >= size){
        Buffer[i] = value;
        for(int j = size; j < i; j++){
            Buffer[j]= T();
        }
        size = i + 1;
    }
    else if(i >= 0){
        for(int j = size; j> i; j--){
            Buffer[j]= Buffer[j-1];
        }
        Buffer[i] = value;
        size++;
    }

    else{
        cout << "error" << endl;
        throw exception();
    }
}

//access element at specific index
template<class T>
T&DSVector<T>::operator[](int index){
    return Buffer[index];
}

//return pointer to first element
template<class T>
typename DSVector<T>::iterator DSVector<T>::begin(){
    return Buffer;

}

//return pointer to last element.
template<class T>
typename DSVector<T>::iterator DSVector<T>::end(){
    return Buffer + size - 1;
}

//return first element
template<class T>
T& DSVector<T>::front(){
    return Buffer[0];
}

//return last element
template<class T>
T& DSVector<T>::back(){
    return Buffer[size - 1];
}

//add element to end of vector
template<class T>
void DSVector<T>::push_back(const T & V){
    if(size >= capacity){
         reserve(capacity * 2);
    }

    Buffer[size] = V;
    size++;
}

//remove last element
template<class T>
void DSVector<T>::pop_back(){
    size--;
}

//set capacity for vector
template<class T>
void DSVector<T>::reserve(int new_capacity){
    if(Buffer == 0){
        size = 0;
        capacity = 0;
    }
    T* newBuffer = new T[new_capacity];
    int l_Size = capacity < size ? new_capacity : size;

    for ( int i = 0; i < l_Size; i++)
           newBuffer[i] = Buffer[i];

       capacity = new_capacity;
       delete[] Buffer;
       Buffer = newBuffer;
}



//return size of vector
template<class T>
int DSVector<T>::getSize()const{
    return size;
}

//return capacity of vector
template<class T>
int DSVector<T>::getCapacity()const{
    return capacity;
}

//set new size of vector.
template<class T>
void DSVector<T>::reSize(int newsize){
   reserve(newsize);
   size = newsize;
}


//remove all elements from the vector
template<class T>
void DSVector<T>::clear(){
    size = 0;
}


//check to see whether a vector is empty
template<class T>
bool DSVector<T>:: empty(){
    if(size == 0){
        return true;
    }
    return false;
}

#endif // DSVECTOR_H
