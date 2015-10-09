#include <chrono>
#include <iostream>

#define size 66666
#define times 66666

using namespace std;

void static_array(int x) {
    static int a[size];
    for (int i = 0; i < size; i++)
        a[i] = i + x;
}

void stack_array(int x) {
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = i + x;
}

void heap_array(int x) {
    int *a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = i + x;
}

int main() {
    chrono::time_point<chrono::system_clock> start, end;

    long long opt = 0;

    start = chrono::system_clock::now();
    for (int i = 0; i < times; ++i)
        opt += static_array(i);
    end = chrono::system_clock::now();
    cout << "Time for static: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < times; ++i)
        opt += stack_array(i);
    end = chrono::system_clock::now();
    cout << "Time for stack: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < times; ++i)
        opt += heap_array(i);
    end = chrono::system_clock::now();
    cout << "Time for heap: " <<
            chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    cout << "Dummy result: " << opt << endl;

    return 0;
}
