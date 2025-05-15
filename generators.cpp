#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // Seed for randomness

    int T = 20;  // Number of test cases you want to generate
    cout << T << "\n";

    for (int i = 0; i < T; i++) {
        int N = 1 + rand() % 9;  // Random N in [1,9]
        cout << N << "\n";
    }

    return 0;
}
