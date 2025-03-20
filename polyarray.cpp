#include <iostream>
using namespace std;

#define MAX 100  


void printPolynomial(int poly[], int degree) {
    bool firstTerm = true;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!firstTerm) cout << " + ";
            cout << poly[i];
            if (i > 0) cout << "x^" << i;
            firstTerm = false;
        }
    }
    cout << endl;
}


void addPolynomials(int poly1[], int deg1, int poly2[], int deg2, int result[], int &degR) {
    degR = max(deg1, deg2);
    for (int i = 0; i <= degR; i++) {
        result[i] = (i <= deg1 ? poly1[i] : 0) + (i <= deg2 ? poly2[i] : 0);
    }
}


void multiplyPolynomials(int poly1[], int deg1, int poly2[], int deg2, int result[], int &degR) {

    for (int i = 0; i <= deg1 + deg2; i++)
        result[i] = 0;


    for (int i = 0; i <= deg1; i++)
        for (int j = 0; j <= deg2; j++)
            result[i + j] += poly1[i] * poly2[j];

    degR = deg1 + deg2;
}

int main() {
    int poly1[MAX] = {2, 0, 3};  
    int poly2[MAX] = {1, 4};     
    int deg1 = 2, deg2 = 1;      
    cout << "Polynomial 1: ";
    printPolynomial(poly1, deg1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2, deg2);

    
    int sum[MAX], degSum;
    addPolynomials(poly1, deg1, poly2, deg2, sum, degSum);
    cout << "Sum: ";
    printPolynomial(sum, degSum);

    
    int product[MAX], degProduct;
    multiplyPolynomials(poly1, deg1, poly2, deg2, product, degProduct);
    cout << "Product: ";
    printPolynomial(product, degProduct);

    return 0;
}
