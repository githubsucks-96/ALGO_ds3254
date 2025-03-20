#include <iostream>
using namespace std;


class Polynomial {
private:
    
    class Node {
        public:
        int coeff;
        int exp;
        Node* next;
    
        Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
    };
    Node* head;
    

public:
    Polynomial() : head(nullptr) {}


    void insertTerm(int coeff, int exp) {
        if (coeff == 0) return;
        Node* newNode = new Node(coeff, exp);
        if (!head || head->exp < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp && temp->exp > exp) {
                prev = temp;
                temp = temp->next;
            }
            if (temp && temp->exp == exp) {
                temp->coeff += coeff;
                if (temp->coeff == 0) {
                    if (prev) prev->next = temp->next;
                    else head = temp->next;
                    delete temp;
                }
                delete newNode;
            } else {
                newNode->next = temp;
                if (prev) prev->next = newNode;
                else head = newNode;
            }
        }
    }


    void display() {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (temp->coeff != 0) {
                if (!first) {
                    cout << (temp->coeff > 0 ? " + " : " - ");
                    cout << abs(temp->coeff) << "x^" << temp->exp;
                } else {
                    cout << temp->coeff << "x^" << temp->exp;
                    first = false;
                }
            }
            temp = temp->next;
        }
        cout << endl;
    }


    Polynomial add(Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;
        while (p1 || p2) {
            if (!p1) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            } else if (!p2) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp > p2->exp) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }


    Polynomial multiply(Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        while (p1) {
            Node* p2 = other.head;
            while (p2) {
                result.insertTerm(p1->coeff * p2->coeff, p1->exp + p2->exp);
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        return result;
    }


    int evaluate(int x) {
        int result = 0;
        Node* temp = head;
        while (temp) {
            result += temp->coeff * pow(x, temp->exp);
            temp = temp->next;
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2;
    p1.insertTerm(3, 2);
    p1.insertTerm(5, 1);
    p1.insertTerm(6, 3);
    
    p2.insertTerm(4, 2);
    p2.insertTerm(2, 1);
    p2.insertTerm(3, 0);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.display();

    int x = 2;
    cout << "Evaluation of Polynomial 1 at x=" << x << ": " << p1.evaluate(x) << endl;
    return 0;
}
