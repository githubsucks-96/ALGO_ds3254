#include <iostream>
using namespace std;

template<class T>
class CircularQueue {
private:
    T* _arr;
    int _front;
    int _rear;
    int _cap; 

public:
    CircularQueue(int cap):_front(0),_rear(0),_cap(cap + 1) {
        _arr=new T[_cap];
    }

    ~CircularQueue(){
        delete[] _arr; 
    }

    bool is_empty(){
        return _rear==_front;
    }

    bool is_full(){
        return (_rear + 1)%_cap==_front;
    }

    void enqueue(const T& val){
        if (is_full()){
            cout<<"Queue is full!\n";
            return;
        }
        _arr[_rear]=val; 
        _rear=(_rear+1)% _cap;
    }

    T dequeue(){
        if (is_empty()){
            throw runtime_error("Queue is empty!");
        }
        T val =_arr[_front]; 
        _front=(_front+1)% _cap;
        return val;
    }

    void display() {
        if (is_empty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout<<"Queue:";
        for (int i=_front; i!=_rear; i=(i+1)%_cap){
            cout<<_arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    
    CircularQueue<int> Q(4);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.enqueue(8);
    Q.display();
    cout<<Q.dequeue();

}
