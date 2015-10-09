#include <chrono>
#include <iostream>

const int size = 10000, rep = 100000;

int static_array(int x) {
    static int a[size];
    long long sum = 0;
    for (int i = 0; i < size; ++i) {
        a[i] = i & x;
        sum += a[i];
    }
    return sum;
}

int stack_array(int x) {
    int a[size];
    long long sum = 0;
    for (int i = 0; i < size; ++i) {
        a[i] = i & x;
        sum += a[i];
    }
    return sum;
}

int heap_array(int x) {
    int *a = new int[size];
    long long sum = 0;
    for (int i = 0; i < size; ++i) {
        a[i] = i & x;
        sum += a[i];
    }
    delete[] a;
    return sum;
}

using namespace std;

int main() {
    chrono::time_point<chrono::system_clock> start, end;

    long long opt = 0;

    start = chrono::system_clock::now();
    for (int i = 0; i < rep; ++i)
        opt += static_array(i);
    end = chrono::system_clock::now();
    cout << "Time for static: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < rep; ++i)
        opt += stack_array(i);
    end = chrono::system_clock::now();
    cout << "Time for stack: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < rep; ++i)
        opt += heap_array(i);
    end = chrono::system_clock::now();
    cout << "Time for heap: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    cout << "Dummy result: " << opt << endl;

    return 0;
}
