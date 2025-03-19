// 1. Queue 2. stack 3. linkedlist 4. matrix 5. poly
#include <iostream>

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int _length;

public:
    LinkedList() : head(nullptr), tail(nullptr), _length(0) {}

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        _length++;
    }

    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        _length++;
    }


    void remove(const T& value) {
        if (!head) return;


        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            _length--;

            if (!head) tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) { 
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            if (!temp->next) tail = temp; 
            delete toDelete;
            _length--;
        }
    }


    T removeLast() {
        if (!head) throw std::runtime_error("List is empty");

        if (head == tail) {
            T val = head->data;
            delete head;
            head = tail = nullptr;
            _length = 0;
            return val;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        T val = tail->data;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        _length--;

        return val;
    }

    T removeFirst() {
        if (!head) throw std::runtime_error("List is empty");

        Node* temp = head;
        T val = temp->data;
        head = head->next;
        delete temp;
        _length--;

        if (!head) tail = nullptr;

        return val;
    }
    int length() const {
        return _length;
    }

 
    void printList() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};


int main() {
    LinkedList<int> list;
    list.append(10);
    list.append(20);
    list.prepend(5);
    list.printList(); 

    list.remove(10);
    list.printList(); 

    list.removeFirst();
    list.printList(); 

    list.removeLast();
    list.printList(); 

    return 0;
}
