#include <iostream>
using namespace std;

class Queue {
    private:
        class Node {
        public:
            int data;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
        
        Node* head;
        Node* tail;
        int _size;
        int _cap;

    public:
        Queue(int cap ) : head(nullptr), tail(nullptr), _size(0), _cap(cap) {}

        ~Queue() {
            Node* temp;
            while (head) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void append(int val) {
            if (_size == _cap) {
                cout << "Queue is full!" << endl;
                return;
            }
            
            Node* newNode = new Node(val);
            if (_size == 0) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            _size++;
        }

        int _delete() {
            if (_size == 0) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            
            Node* temp = head;
            int removedValue = temp->data;
            head = head->next;
            
            if (head == nullptr) {
                tail = nullptr;
            }

            delete temp;
            _size--;
            return removedValue;
        }

        int size() {
            return _size;
        }

        bool isEmpty() {
            return _size == 0;
        }
        void Display(){
            Node* temp=head;
            while(temp){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"Null\n";
        }
};

int main(){
    Queue Q(5);
    Q.append(10);
    Q.append(9);
    Q.append(2);
    Q.append(3);
    Q.append(5);
    Q.append(11);
    Q.Display();
    Q._delete();
    Q.append(10);
    Q.Display();
    Q.append(11);
    


}
// int main() {
//     {
//         Queue Q(5); // Queue created inside a block
//         Q.append(1);
//         Q.append(2);
//         Q.append(3);
//         Q.Display();
//     } // Destructor is automatically called here when Q goes out of scope

//     cout << "Queue object destroyed!" << endl;
//     return 0;
// }