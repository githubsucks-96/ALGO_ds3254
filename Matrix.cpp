#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows,cols;

public:
    Matrix(int r,int c):rows(r),cols(c),mat(r, vector<int>(c, 0)) {}

    void set(int i,int j,int value){
        mat[i][j]=value;
    }

    int get(int i,int j)const{
        return mat[i][j];
    }

    
    void print() const {
        for (const auto& row : mat) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions do not match for addition.");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];

        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows)
            throw invalid_argument("Matrix dimensions do not match for multiplication.");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];

        return result;
    }


    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.mat[j][i] = mat[i][j];

        return result;
    }
};

int main() {
    Matrix A(2, 3);
    A.set(0, 0, 1); A.set(0, 1, 2); A.set(0, 2, 3);
    A.set(1, 0, 4); A.set(1, 1, 5); A.set(1, 2, 6);

    cout << "Matrix A:\n";
    A.print();

    Matrix B(2, 3);
    B.set(0, 0, 6); B.set(0, 1, 5); B.set(0, 2, 4);
    B.set(1, 0, 3); B.set(1, 1, 2); B.set(1, 2, 1);

    cout << "\nMatrix B:\n";
    B.print();


    Matrix C = A + B;
    cout << "\nA + B:\n";
    C.print();


    Matrix X(3, 2);
    X.set(0, 0, 1); X.set(0, 1, 2);
    X.set(1, 0, 3); X.set(1, 1, 4);
    X.set(2, 0, 5); X.set(2, 1, 6);

    cout << "\nMatrix X:\n";
    X.print();

    Matrix D = A * X;
    cout << "\nA * X:\n";
    D.print();


    Matrix T = A.transpose();
    cout << "\nTranspose of A:\n";
    T.print();

    return 0;
}
