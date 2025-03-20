// Bhambhu.Jetharam.Meharamram@dsc001:/usr/include/c++/13/bits

#include <iostream>
#include <fstream>  // File handling
using namespace std;

int main() {
    ofstream file("example.txt"); // Open file for writing

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "Hello, this is a test file.\n";
    file << "Writing data to the file.\n";

    file.close(); // Close the file
    cout << "Data written successfully.\n";

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>  // For reading lines
using namespace std;

int main() {
    ifstream file("example.txt"); // Open file for reading

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) { // Read file line by line
        cout << line << endl;
    }

    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("data.txt", ios::in | ios::out | ios::app); // Open for both read & write

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Writing to file
    file << "Appending new data!\n";

    // Move back to the beginning to read
    file.seekg(0, ios::beg);

    // Reading from file
    string line;
    cout << "File contents:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("array.txt"); // Open file for writing

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    file << size << endl; // Store the array size first
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }

    file.close();
    cout << "Array written successfully.\n";
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("array.txt"); // Open file for reading

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int size;
    file >> size; // Read array size

    int* arr = new int[size]; // Dynamically allocate array

    for (int i = 0; i < size; i++) {
        file >> arr[i]; // Read array elements
    }

    file.close();

    cout << "Array read from file: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free allocated memory
    return 0;
}
