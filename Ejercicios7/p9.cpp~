#include <iostream>
#include <chrono>

using namespace std;

chrono::time_point<chrono::system_clock> s, e;

int main() {
    const int n = 10000000;

    s = chrono::system_clock::now();
    int ansi = 0;

    for (int i = 0; i < n; ++i) {
        ansi += i;
    }

    e = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(e-s).count() << " microseconds" << endl;

    s = chrono::system_clock::now();
    double ansd = 0;

    for (int i = 0; i < n; ++i) {
        ansd += i;
    }

    e = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(e-s).count() << " microseconds" << endl;

    return 0;
}
