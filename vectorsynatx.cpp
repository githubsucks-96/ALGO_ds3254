#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    v.push_back(6);  // Add element at end
    v.pop_back();     // Remove last element
    v.insert(v.begin() + 2, 99); // Insert at index 2
    v.erase(v.begin() + 3); // Remove element at index 3
    v.resize(3);  // Resize to 3 elements
    v.reserve(10); // Reserve capacity for 10 elements

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
    cout << "First Element: " << v.front() << ", Last Element: " << v.back() << endl;

    // Iterate and print
    cout << "Vector Elements: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
vector<int> vec(5, 0);  // 1D vector with 5 elements, initialized to 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // Declare a 2D vector (Matrix) initialized with 0s
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // Assign values
    matrix[1][2] = 5;

    // Print Matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x = 3, y = 4, z = 2;

    // Declare a 3D vector initialized with 0s
    vector<vector<vector<int>>> tensor(x, vector<vector<int>>(y, vector<int>(z, 0)));

    // Assign a value
    tensor[1][2][1] = 7;

    // Print the 3D vector
    for (int i = 0; i < x; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << tensor[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to create an N-dimensional vector
template <typename T, typename... Args>
auto createNDVector(size_t first, Args... sizes) {
    return vector<decltype(createNDVector<T>(sizes...))>(first, createNDVector<T>(sizes...));
}

// Base case (1D Vector)
template <typename T>
auto createNDVector(size_t size) {
    return vector<T>(size);
}

int main() {
    // Create a 4D vector (2x3x4x5)
    auto vec4D = createNDVector<int>(2, 3, 4, 5);

    // Assign values
    vec4D[1][2][3][4] = 42;

    // Print assigned value
    cout << "vec4D[1][2][3][4] = " << vec4D[1][2][3][4] << endl;

    return 0;
}
