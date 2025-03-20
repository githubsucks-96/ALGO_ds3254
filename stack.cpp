#include <iostream>
using namespace std;

template <typename T>
class Stack{
private:
    T* _arr;      
    int top;
    int capacity;

public:
    Stack(int size){
        capacity=size;
        arr=new T[capacity];
        top=-1;
    }


    ~Stack() {
        delete[] arr;
    }

    void push(const T& val){
        if (isFull()){
            cout<<"Stack overflow! Cannot push "<<val<< endl;
            return;
        }
        arr[++top]=val;
    }

    T pop() {
        if (isEmpty()){
            throw runtime_error("Stack underflow! Cannot pop.");
        }
        return arr[top--];
    }

    T peek(){
        if (isEmpty()){
            throw runtime_error("Stack is empty! No top element.");
        }
        return arr[top];
    }


    bool isEmpty(){
        return top==-1;
    }


    bool isFull(){
        return top==capacity-1;
    }

    int size(){
        return top+1;
    }
};

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    class Node{
        public:
        T data;
        Node* next;
        Node(const T& val):data(val),next(nullptr){}
    };

    Node* top;
    int size;

public:

    Stack():top(nullptr),size(0){}

    ~Stack(){
        while (!isEmpty()){
            pop();
        }
    }

    void push(const T& val){
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
        size++;
    }

    T pop(){
        if (isEmpty()) {
            throw runtime_error("Stack underflow! Cannot pop.");
        }
        Node* temp=top;
        T poppedValue=temp->data;
        top=top->next;
        delete temp;
        size--;
        return poppedValue;
    }


    T peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty! No top element.");
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get current stack size
    int getSize() {
        return size;
    }
};
