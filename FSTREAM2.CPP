#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input1.txt");  // Open the file
    vector<int> numbers;          // Vector to store numbers
    string line;

    while (getline(file, line)) {   // Read file line by line
        stringstream ss(line);      // Use stringstream to check if it's a number
        int num;
        if (ss >> num) {            // If conversion succeeds, store the number
            numbers.push_back(num);
        }
    }

    file.close(); // Close the file

    // Display the numbers read from the file
    cout << "Numbers in the file: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <string>
#include <iostream>
#include <fstream>

int read() {
    std::ifstream file;
    file.open("file.txt");

    int val;

    while(file >> val) {
        std::cout << val << std::endl;
    }

    file.close();
    return 0;
}

int write() {
    std::ofstream file;
    file.open("file.txt");

    file << 1 << std::endl;

    file.close();
    return 0;
}

int main() {
    read();
    return 0;
}