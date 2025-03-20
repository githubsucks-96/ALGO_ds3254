#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("data.csv"); // Open file in write mode

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Writing header
    file << "ID,Name,Score" << endl;
    
    // Writing data
    file << "1,John,85" << endl;
    file << "2,Emma,90" << endl;
    file << "3,Alex,78" << endl;

    file.close();
    cout << "Data written successfully.\n";
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("data.csv"); // Open file in read mode

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line, id, name, score;

    // Reading header
    getline(file, line);
    cout << "Header: " << line << endl;

    // Reading data line by line
    while (getline(file, line)) {
        stringstream ss(line); // Convert line into a stream
        getline(ss, id, ',');  // Extract ID
        getline(ss, name, ','); // Extract Name
        getline(ss, score, ','); // Extract Score

        cout << "ID: " << id << ", Name: " << name << ", Score: " << score << endl;
    }

    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("matrix.csv");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            file << matrix[i][j];
            if (j < 2) file << ","; // Add comma except at end
        }
        file << endl;
    }

    file.close();
    cout << "Matrix written successfully.\n";
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("matrix.csv");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int matrix[3][3], row = 0;

    while (getline(file, line) && row < 3) {
        stringstream ss(line);
        string value;
        int col = 0;

        while (getline(ss, value, ',') && col < 3) {
            matrix[row][col] = stoi(value); // Convert string to int
            col++;
        }
        row++;
    }

    file.close();

    // Printing the matrix
    cout << "Matrix read from file:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
