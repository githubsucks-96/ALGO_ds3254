#include <iostream>
using namespace std; 
template <class T>

class Vector{
    private:
    T* _arr;
    int _Capacity;
    int _Size;

    public:
    Vector(int cap=1){
        _arr= new T[cap];
        _capacity=cap;
        _size=0;
    }
    private:
    void ReviseCap(int new_cap){
        T* new_arr= new T[new_cap];
        for(int i=0;i<_size;i++){
            new_arr[i]=_arr[i]
        }
        delete [] _arr;
        _arr=new_arr;
        _Capacity=new_cap;
    void append(const T& val){
        if(_size==_Capacity);
        ReviseCap(2*_size);
        _arr[_size]=val;
        _size++;
    }

    }
};