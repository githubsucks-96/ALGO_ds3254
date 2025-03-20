#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    auto start = high_resolution_clock::now();

   
    for (int i = 0; i < 1000000; i++);

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
}


#seq 1 10 | shuf > input1.txt
#shellcommand