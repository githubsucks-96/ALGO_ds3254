#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class SequenceADT {
private:
    Node* head;
    Node* tail;
    int size;

public:
    SequenceADT() : head(nullptr), tail(nullptr), size(0) {}

    int length() {
        return size;
    }

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int At(int i) {
        if (i < 0 || i >= size) throw std::out_of_range("Index out of range");
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        return temp->data;
    }

    void replace(int i, int x) {
        if (i < 0 || i >= size) throw std::out_of_range("Index out of range");
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        temp->data = x;
    }

    void insert(int i, int x) {
        if (i < 0 || i > size) throw std::out_of_range("Index out of range");
        Node* newNode = new Node(x);
        if (i == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = head;
        } else {
            Node* temp = head;
            for (int j = 0; j < i - 1; j++) temp = temp->next;
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            if (!newNode->next) tail = newNode;
        }
        size++;
    }

    int remove(int i) {
        if (i < 0 || i >= size) throw std::out_of_range("Index out of range");
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;
        int data = temp->data;
        delete temp;
        size--;
        return data;
    }

    int removeLast() {
        if (!tail) throw std::out_of_range("No elements to remove");
        int data = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
        return data;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~SequenceADT() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SequenceADT seq;
    seq.append(10);
    seq.append(20);
    seq.append(30);
    seq.insert(1, 15);
    seq.display();
    std::cout << "Element at index 2: " << seq.At(2) << "\n"; 
    seq.replace(1, 25);
    seq.display();
    seq.remove(2);
    seq.display();
    seq.removeLast();
    seq.display();
    return 0;
}
